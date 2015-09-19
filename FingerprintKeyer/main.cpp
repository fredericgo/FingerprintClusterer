//
//  main.cpp
//  FingerprintKeyer
//
//  Created by fredericstgo on 9/18/15.
//  Copyright © 2015 fredericstgo. All rights reserved.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "BinningClusterer.hpp"
#include "helpers.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> elems;
    vector<string> column;
    string line;
    BinningClusterer* clusterer = new BinningClusterer("fingerprint");
    
    if (argc < 2) {
        cout << "Usage: ./clusterer filename" << endl;
        exit(EXIT_FAILURE);
    }
    
    string input_fn = argv[1];
    
    //ifstream arq(getenv("MYARQ"));
    //cin.rdbuf(arq.rdbuf());

    cout << "number of arguments: " << argc << endl;
    cout << "arg1: " << argv[1];
    
    int i = 0;
    while(getline(cin, line)) {
        elems = split(line, '\t');
        if (i> 2) break;
        column.push_back(elems[1]);
        /* cout << elems[0] + "\t" + elems[1] << endl; */

        i++;
    }
    
    clusterer->computeClusters(column);
    for (auto s: *clusterer->getClusters()) {
        //cout << "hi";
        for (auto c: s) {
            cout << c.first << "\n";
        }
        cout << "--" << endl;
    }
    
    
    return 0;
}
