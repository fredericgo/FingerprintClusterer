//
//  Keyer.hpp
//  FingerprintKeyer
//
//  Created by fredericstgo on 9/18/15.
//  Copyright © 2015 fredericstgo. All rights reserved.
//

#ifndef Keyer_hpp
#define Keyer_hpp

#include <stdio.h>
#include <string>
#include <regex>

using namespace std;

class Keyer {
    
public:
    ~Keyer() {};
    virtual string key(string string, ...) = 0;
};



#endif /* Keyer_hpp */

