//
//  main.cpp
//  CSV
//
//  Created by SLIN63 on 8/3/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

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
    
    vector<vector<string>> cols = csv_obj.get_column(query);
    csv_obj.get_column("Plot Name");
    
    array_print(cols);

    
    return 0;
}
