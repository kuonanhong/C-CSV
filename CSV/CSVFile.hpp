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
#include <vector>
#include <sstream>

using namespace std;

class CSVFile {
    
typedef vector<vector<string>> CsvVector;
friend ostream& print(ostream&, const CSVFile&);
    
public:
    CSVFile() = default;
    CSVFile(ifstream&);
    inline vector<string>::size_type get_size();
    inline void headers();
    inline vector<string> get_header();
    CsvVector get_column(const string&);
    CsvVector get_column(const vector<string>&);
    
private:
    vector<string> header;
    CsvVector contents;
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


#endif /* CSVFile_hpp */
