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
#include "CSVFile.hpp"
#include "Etc.hpp"


int main(int argc, const char * argv[]) {
    // Make sure CSV in path
    string file_name = "Sample.csv";
    ifstream csv(file_name);

    CSVFile csv_obj(csv);
    print(cout, csv_obj);
    cout << csv_obj.get_size() << " lines of data in " << file_name << endl;

    vector<string> header = csv_obj.get_header();
    csv_obj.headers();

    vector<string> query{"Experiment Name", "Plot ID"};

    vector<int> int_query{1, 2, 3};
    vector<vector<string>> cols = csv_obj.get_column(int_query);

    array_print(cols);

    vector<string> row = csv_obj.get_row(2);
    cout << csv_obj.rows().size() << endl;


    return 0;
}
