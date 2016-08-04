//
//  CSVFile.cpp
//  CSV
//
//  Created by SLIN63 on 8/3/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "CSVFile.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// ifstream constructor: http://www.cplusplus.com/forum/general/17771/#msg89650
CSVFile::CSVFile(ifstream& ifs) {
    bool line_is_header = true; // First line assumed to be the header
    while (ifs) {
        // Grab whole row
        string s;
        if (!getline(ifs, s))
            break;
        
        istringstream ss (s);
        vector<string> record;
        
        while(ss) {
            // Split string by comma delimiter
            string s;
            if (!getline(ss, s, ','))
                break;
            record.push_back(s);
        }
        
        if (line_is_header)
            header = record;
        else
            contents.push_back(record);
        line_is_header = false; // First iteration clears through the header
    }
}

vector<string> CSVFile::column_info(const string& s) {
    // Returns all data in the passed column(s)
    // Need to overload this function later
    vector<string> data;
    int index = index_from_string(s);
    
    for (auto&& i : contents) {
        data.push_back(i[index]);
    }
    
    return data;
}

CSVFile::CsvVector CSVFile::get_column(const string& s) {
    CSVFile::CsvVector column_data;
    column_data.push_back(column_info(s));
    return column_data;
}

CSVFile::CsvVector CSVFile::get_column(const vector<string>& col_vec) {
    CSVFile::CsvVector column_data;
    for (auto&& column : col_vec) {
        column_data.push_back(column_info(column));
    }
    return column_data;
}

int CSVFile::index_from_string(const string& s) {
    // Given column string, returns index of column
    int pos = find(header.begin(), header.end(), s) - header.begin();
    return pos;
}

ostream& print(ostream& os, const CSVFile& csv) {
    string csv_string;
    for (auto&& i : csv.contents) {
        stringstream s;
        for (auto&& j : i) {
            s << j << ' ';
        }
        s << "\n";
        csv_string += s.str();
    }
    os << csv_string;
    return os;
}