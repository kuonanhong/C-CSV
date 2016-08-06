//
//  main.cpp
//  CSV
//
//  Created by SLIN63 on 8/3/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

// TODO: map<vector<string>:vector<string>>

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "CSVFile.hpp"
#include "Etc.hpp"


int main(int argc, const char * argv[]) {
    // Make sure CSV in path
    string file_name = "Sample.csv";
    CSVFile csv_obj(file_name);
    csv_obj.headers();
    map<string,string> row_map;
    row_map["Experiment Name"] = "Wow! Experiment!";
    row_map["Block"] = "Wow! A BLOCK!";
    row_map["Comments"] = "I love comments";
    row_map["Row"] = " I hate rows";
    cout << endl;
    csv_obj.write_row(row_map);


    return 0;
}
