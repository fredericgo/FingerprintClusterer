//
//  helpers.hpp
//  FingerprintKeyer
//
//  Created by fredericstgo on 9/19/15.
//  Copyright © 2015 fredericstgo. All rights reserved.
//

#ifndef helpers_hpp
#define helpers_hpp

#include <stdio.h>

#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elems);
vector<string> split(const string &s, char delim);

#endif /* helpers_hpp */

