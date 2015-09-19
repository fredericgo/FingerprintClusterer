//
//  FingerPrintKeyer.hpp
//  FingerprintKeyer
//
//  Created by fredericstgo on 9/19/15.
//  Copyright © 2015 fredericstgo. All rights reserved.
//

#ifndef FingerPrintKeyer_hpp
#define FingerPrintKeyer_hpp

#include <stdio.h>
#include "Keyer.hpp"

class FingerPrintKeyer :public Keyer {
    
    static const regex punctctrl;
    
public:
    FingerPrintKeyer();
    string key(string s, ...);
    
protected:
    string asciify(string s);
    
private:
    char translate(wchar_t c);
};

#endif /* FingerPrintKeyer_hpp */

