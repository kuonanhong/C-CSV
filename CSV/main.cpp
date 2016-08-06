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
using namespace std;

int main(int argc, const char * argv[]) {
    string file_name = "Sample.csv";
    CSVFile csv_obj(file_name);

    typedef vector<vector<string>> CsvVector;

    vector<string> = csv_obj.get_header() // Get available headers in passed CSV

    CsvVector column_one = csv_obj.get_column("Column 1");
    vector<string> row_1 = csv_obj.get_row(1); // Get rows by index
    CsvVector row_1_to_3 = csv_obj.get_row(0, 3); // Get rows by range

    map<string,string> row_map; // Map formatted Column: Column value
    row_map["Column 1"] = "ColumnOneVal";
    row_map["Column 2"] = "ColumnTwoVal";
    row_map["Column 3"] = "ColumnThreeVal";
    cout << endl;
    csv_obj.write_row(row_map); // Use row_map to write a new row

    return 0;
}
