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
    
    if (argc < 3) {
        cout << "Usage: ./clusterer filename" << endl;
        exit(EXIT_FAILURE);
    }
    
    string input_fn = argv[1];
    string output_fn = argv[2];
    int id_col = 0;
    int string_col = 1;
    
    //ifstream arq(getenv("MYARQ"));
    //cin.rdbuf(arq.rdbuf());
    /*
    cout << "number of arguments: " << argc << endl;
    cout << "input filename: " << input_fn << endl;
    cout << "output filename: " << output_fn << endl;
    */
    for (int i = 3; i < argc; i++) {
        if (string(argv[i]) == "-c") {
            vector<string> cols;
            if (i + 1 < argc) {
                cols = split(argv[i+1], ',');
                id_col = stoi(cols[0]);
                string_col = stoi(cols[1]);
            }
            else exit(EXIT_FAILURE);
        }
    }
    /*
    cout << "id col: " << id_col << endl;
    cout << "name col: " << name_col << endl;
    */
    ifstream infile;
    infile.open(input_fn);
    ofstream oufile;
    oufile.open(output_fn);
    ofstream reffile;
    reffile.open(output_fn + "links");
    
    clusterer->visit_modify(id_col, string_col, infile, oufile, reffile);
    infile.close();
    oufile.close();
    reffile.close();
    // read string column to cluster
    
    /*
    while(getline(infile, line)) {
        elems = split(line, '\t');
        if (l > 10) break;
        column.push_back(elems[string_col - 1]);
        l++;
    }
    infile.close();
    
    // compute clusters
    clusterer->computeClusters(column);
    for (auto s: *clusterer->getClusters()) {
        //cout << "hi";
        for (auto c: s) {
            cout << c.first << "\n";
        }
        cout << "--" << endl;
    }
    
    */
    return 0;
}
