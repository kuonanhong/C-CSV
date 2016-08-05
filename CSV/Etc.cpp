//
//  Etc.cpp
//  CSV
//
//  Created by SLIN63 on 8/3/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "Etc.hpp"
#include <iostream>
#include <vector>

using namespace std;

void array_print(const vector<vector<string>>& v) {
    // TODO: Fancy print
    for (auto it = v.begin(); it != v.end(); ++it) {
        for (auto&& i : *it) {
            cout << i << endl;
        }
    }
}
