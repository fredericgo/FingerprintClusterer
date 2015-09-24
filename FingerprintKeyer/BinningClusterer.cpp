//
//  BinningClusterer.cpp
//  FingerprintKeyer
//
//  Created by fredericstgo on 9/19/15.
//  Copyright © 2015 fredericstgo. All rights reserved.
//

#include "BinningClusterer.hpp"
#include "FingerPrintKeyer.hpp"
#include "Keyer.hpp"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "helpers.hpp"
#include <fstream>

using namespace std;

typedef unordered_map<string, unordered_map<string, int> > mmm;

unordered_map<string, Keyer*> BinningClusterer::_keyers;

BinningClusterer::BinningClusterer(string keyername) {
    BinningClusterer::_keyers["fingerprint"] = new FingerPrintKeyer();
    
    auto it = BinningClusterer::_keyers.find(keyername);
    if (it != _keyers.end()) {
        BinningClusterer::_keyer = it->second;
    }
    
}

void BinningClusterer::visit(vector<string> column) {
    for (string s: column) {
        string key = _keyer->key(s);
        //cout << key << endl;
        if (_map.count(key) > 0) {
            unordered_map<string, int> m = _map[key];
            
            if (m.count(s) > 0) {
                m[s] +=  1;
            } else {
                m[s] = 1;
            }
            _map[key] = m;
        } else {
            unordered_map<string, int> m;
            m[s] = 1;
            _map[key] = m;
        }
    }
}

void BinningClusterer::visit_modify(int id_col, int string_col, ifstream &inf, ofstream& of, ofstream& refof) {
    string line;
    vector<string> elems;
    int l = 0;
    unordered_map<string, string> map;

    while (getline(inf, line)) {
        elems = split(line, '\t');
        //if (l > 10) break;
        bool modify_id = id_col > 0 ? true : false;
        string id = "";
        
        if (modify_id)
            id = elems[id_col - 1];
        
        string s = elems[string_col - 1];
        //cout << id << " " << s << endl;

        string key = _keyer->key(s);
        
        if (map.count(key) > 0) {
            string nid = map[key];
            
            for (auto iter = elems.begin(); iter != elems.end(); iter++) {
                int idx = int(iter - elems.begin());
                if (modify_id && (idx == id_col - 1)) {
                    of << nid;
                } else if (idx == string_col - 1) {
                    of << key;
                } else {
                    of << *iter;
                }
                if (iter != elems.end())
                    of << "\t";
            }
            of << endl;
            if (modify_id) refof << nid << "\t" << id << endl;
        } else {
            map[key] = id;
            of << line << endl;
        }

        l++;
    }
}



bool compareBySize(unordered_map<string, int> m1,
                   unordered_map<string, int> m2) {
    //cout << m1.size()<<" "<< m2.size() << endl;
    return m1.size() > m2.size();
    
}

void BinningClusterer::computeClusters(vector<string> column) {
    visit(column);
    for (auto p: _map) {
        //cout << p.first << endl;
        if (p.second.size() > 1) {
            _clusters.push_back(p.second);
        }
    }
    
    sort(_clusters.begin(), _clusters.end(), compareBySize);
}

vector<unordered_map<string, int> >* BinningClusterer::getClusters() {
    return &_clusters;
}

unordered_map<string, unordered_map<string, int> >* BinningClusterer::getMap() {
    return &_map;
}



