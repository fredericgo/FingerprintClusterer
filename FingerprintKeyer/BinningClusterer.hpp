//
//  BinningClusterer.hpp
//  FingerprintKeyer
//
//  Created by fredericstgo on 9/19/15.
//  Copyright © 2015 fredericstgo. All rights reserved.
//

#ifndef BinningClusterer_hpp
#define BinningClusterer_hpp

#include <stdio.h>


#include <unordered_map>
#include <list>
#include "Keyer.hpp"

class BinningClusterer {
    
public:
    BinningClusterer(string keyername);
    void computeClusters(vector<string>);
    void visit(vector<string> column);
    void visit_modify(int id_col, int string_col, ifstream& inf, ofstream& of, ofstream& ofref);
    unordered_map<string, unordered_map<string, int> >* getMap();
    vector<unordered_map<string, int> >* getClusters();


    
private:
    Keyer* _keyer;
    unordered_map<string, unordered_map<string, int> > _map;
    vector<unordered_map<string, int> > _clusters;

    
protected:
    static unordered_map<string, Keyer*> _keyers;
};

#endif /* BinningClusterer_hpp */
