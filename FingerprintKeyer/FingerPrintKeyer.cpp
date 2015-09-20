//
//  FingerPrintKeyer.cpp
//  FingerprintKeyer
//
//  Created by fredericstgo on 9/19/15.
//  Copyright © 2015 fredericstgo. All rights reserved.
//

#include "FingerPrintKeyer.hpp"
#include <iostream>
#include <codecvt>
#include <set>
#include "helpers.hpp"

using namespace std;

// trim from start
static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}




const regex FingerPrintKeyer::punctctrl = regex("[[:punct:]]|[[:cntrl:]]");

FingerPrintKeyer::FingerPrintKeyer() {
    
}

string FingerPrintKeyer::key(string s, ...) {
    s = trim(s); // first off, remove whitespace around the string
    transform(s.begin(), s.end(), s.begin(), ::tolower); // to lower case
    s = regex_replace(s, punctctrl, " ", regex_constants::match_any);
    
    vector<string> frags = split(s, ' ');
    set<string> fragset;
    for (string ss : frags) {
        fragset.insert(ss);
    }
    
    string b;
    for (set<string>::iterator iter = fragset.begin(); iter != fragset.end(); ++iter) {
        b += *iter;
        if (iter != fragset.end()) b += " ";
    }
    /* s = punctctrl.matcher(s).replaceAll(""); // then remove all punctuation and control chars
    */
    return asciify(b);
}

string FingerPrintKeyer::asciify(string s) {
    
    string output;
    wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
    
    for (auto c: conv.from_bytes(s)) {
        output += translate(c);
    }
    
    return output;
}

char FingerPrintKeyer::translate(wchar_t c) {
    switch(c) {
        case L'\u00C0':
        case L'\u00C1':
        case L'\u00C2':
        case L'\u00C3':
        case L'\u00C4':
        case L'\u00C5':
        case L'\u00E0':
        case L'\u00E1':
        case L'\u00E2':
        case L'\u00E3':
        case L'\u00E4':
        case L'\u00E5':
        case L'\u0100':
        case L'\u0101':
        case L'\u0102':
        case L'\u0103':
        case L'\u0104':
        case L'\u0105':
            return 'a';
        case L'\u00C7':
        case L'\u00E7':
        case L'\u0106':
        case L'\u0107':
        case L'\u0108':
        case L'\u0109':
        case L'\u010A':
        case L'\u010B':
        case L'\u010C':
        case L'\u010D':
            return 'c';
        case L'\u00D0':
        case L'\u00F0':
        case L'\u010E':
        case L'\u010F':
        case L'\u0110':
        case L'\u0111':
            return 'd';
        case L'\u00C8':
        case L'\u00C9':
        case L'\u00CA':
        case L'\u00CB':
        case L'\u00E8':
        case L'\u00E9':
        case L'\u00EA':
        case L'\u00EB':
        case L'\u0112':
        case L'\u0113':
        case L'\u0114':
        case L'\u0115':
        case L'\u0116':
        case L'\u0117':
        case L'\u0118':
        case L'\u0119':
        case L'\u011A':
        case L'\u011B':
            return 'e';
        case L'\u011C':
        case L'\u011D':
        case L'\u011E':
        case L'\u011F':
        case L'\u0120':
        case L'\u0121':
        case L'\u0122':
        case L'\u0123':
            return 'g';
        case L'\u0124':
        case L'\u0125':
        case L'\u0126':
        case L'\u0127':
            return 'h';
        case L'\u00CC':
        case L'\u00CD':
        case L'\u00CE':
        case L'\u00CF':
        case L'\u00EC':
        case L'\u00ED':
        case L'\u00EE':
        case L'\u00EF':
        case L'\u0128':
        case L'\u0129':
        case L'\u012A':
        case L'\u012B':
        case L'\u012C':
        case L'\u012D':
        case L'\u012E':
        case L'\u012F':
        case L'\u0130':
        case L'\u0131':
            return 'i';
        case L'\u0134':
        case L'\u0135':
            return 'j';
        case L'\u0136':
        case L'\u0137':
        case L'\u0138':
            return 'k';
        case L'\u0139':
        case L'\u013A':
        case L'\u013B':
        case L'\u013C':
        case L'\u013D':
        case L'\u013E':
        case L'\u013F':
        case L'\u0140':
        case L'\u0141':
        case L'\u0142':
            return 'l';
        case L'\u00D1':
        case L'\u00F1':
        case L'\u0143':
        case L'\u0144':
        case L'\u0145':
        case L'\u0146':
        case L'\u0147':
        case L'\u0148':
        case L'\u0149':
        case L'\u014A':
        case L'\u014B':
            return 'n';
        case L'\u00D2':
        case L'\u00D3':
        case L'\u00D4':
        case L'\u00D5':
        case L'\u00D6':
        case L'\u00D8':
        case L'\u00F2':
        case L'\u00F3':
        case L'\u00F4':
        case L'\u00F5':
        case L'\u00F6':
        case L'\u00F8':
        case L'\u014C':
        case L'\u014D':
        case L'\u014E':
        case L'\u014F':
        case L'\u0150':
        case L'\u0151':
            return 'o';
        case L'\u0154':
        case L'\u0155':
        case L'\u0156':
        case L'\u0157':
        case L'\u0158':
        case L'\u0159':
            return 'r';
        case L'\u015A':
        case L'\u015B':
        case L'\u015C':
        case L'\u015D':
        case L'\u015E':
        case L'\u015F':
        case L'\u0160':
        case L'\u0161':
        case L'\u017F':
            return 's';
        case L'\u0162':
        case L'\u0163':
        case L'\u0164':
        case L'\u0165':
        case L'\u0166':
        case L'\u0167':
            return 't';
        case L'\u00D9':
        case L'\u00DA':
        case L'\u00DB':
        case L'\u00DC':
        case L'\u00F9':
        case L'\u00FA':
        case L'\u00FB':
        case L'\u00FC':
        case L'\u0168':
        case L'\u0169':
        case L'\u016A':
        case L'\u016B':
        case L'\u016C':
        case L'\u016D':
        case L'\u016E':
        case L'\u016F':
        case L'\u0170':
        case L'\u0171':
        case L'\u0172':
        case L'\u0173':
            return 'u';
        case L'\u0174':
        case L'\u0175':
            return 'w';
        case L'\u00DD':
        case L'\u00FD':
        case L'\u00FF':
        case L'\u0176':
        case L'\u0177':
        case L'\u0178':
            return 'y';
        case L'\u0179':
        case L'\u017A':
        case L'\u017B':
        case L'\u017C':
        case L'\u017D':
        case L'\u017E':
            return 'z';
    }
    return c;
}

