//
//  Etc.hpp
//  CSV
//
//  Created by SLIN63 on 8/3/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#ifndef Etc_hpp
#define Etc_hpp

#include <iostream>
#include <vector>

using namespace std;

inline void array_print(const vector<string>& v) {
    for (auto&& i : v)
        cout << i << ',';
}

void array_print(const vector<vector<string>>&);

#endif /* Etc_hpp */
