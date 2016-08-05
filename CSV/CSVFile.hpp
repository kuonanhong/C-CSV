//
//  CSVFile.hpp
//  CSV
//
//  Created by SLIN63 on 8/3/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#ifndef CSVFile_hpp
#define CSVFile_hpp

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class CSVFile {

typedef vector<vector<string>> CsvVector;
friend ostream& print(ostream&, const CSVFile&);

public:
    CSVFile() = default;
    CSVFile(const string&);
    inline vector<string>::size_type get_size();
    inline void headers();
    inline vector<string> get_header();
    CsvVector get_column(const int&);
    CsvVector get_column(const vector<int>&);
    CsvVector get_column(const string&);
    CsvVector get_column(const vector<string>&);
    vector<string> get_row(const int&);
    vector<string> get_row(const int&, const int&); // Rows in range
    vector<string> get_row(const vector<int>&); // Rows in vector
    // Planned: Explicitly declare line to write to.
    // Pass vector of strings to write lines for
    void write_row(const map<string,string>&);
    inline CsvVector rows();

private:
    vector<string> header;
    CsvVector contents;
    ifstream stream_read;
    ofstream stream_write;
    vector<string> column_info(const string&);
    int index_from_string(const string&);
};

ostream& print(ostream&, const CSVFile&);

void CSVFile::headers() {
    for (auto&& i : header)
        cout << i << ", ";
}

vector<string>::size_type CSVFile::get_size() {
    return contents.size();
}

vector<string> CSVFile::get_header() {
    return header;
}


CSVFile::CsvVector CSVFile::rows() {
    return contents;
}
#endif /* CSVFile_hpp */
