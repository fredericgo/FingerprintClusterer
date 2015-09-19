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

using namespace std;
typedef unordered_map<string, unordered_map<string, int> > mmm;

unordered_map<string, Keyer*> BinningClusterer::_keyers;

BinningClusterer::BinningClusterer(string keyername) {
    BinningClusterer::_keyers["fingerprint"] = new FingerPrintKeyer();
    
    auto it = BinningClusterer::_keyers.find(keyername);
    if (it != _keyers.end()) {
        BinningClusterer::_keyer = it->second;
    }
    cout << keyername << endl;
    
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



