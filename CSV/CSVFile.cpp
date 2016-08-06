//
//  CSVFile.cpp
//  CSV
//
//  Created by SLIN63 on 8/3/16.
//  Copyright © 2016 SLIN63. All rights reserved.
//

#include "CSVFile.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <array>

// file doc: http://www.cplusplus.com/doc/tutorial/files/
// stream_readtream constructor: http://www.cplusplus.com/forum/general/17771/#msg89650
CSVFile::CSVFile(const string& file_name) {
    stream_read.open(file_name);
    stream_write.open(file_name, ios_base::app); // ::app -- Append mode
    bool line_is_header = true; // First line assumed to be the header
    while (stream_read) {
        // Grab whole row
        string s;
        if (!getline(stream_read, s))
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

void CSVFile::write_row(const map<string,string>& row) {
    // ##TODO - Broken
    // Need to find a separate way to do this. Probably put out all the indices and THEN separate them by commas.
    vector<string> row_vec(header.size(), ",");
    for(auto it = row.begin(); it != row.end(); ++it) {
        int index = index_from_string(it->first);
        cout << index << " : " << it->first << endl;
        cout << header.size() << endl;
        row_vec[(index == 0) ? index : index + 1] = it->second;
        row_vec.push_back(",,");
    }

    string v_string = merge_row_vector(row_vec);

    cout << v_string << endl;

    stream_write << endl << v_string;
}

// http://stackoverflow.com/questions/1430757/c-vector-to-string
string CSVFile::merge_row_vector(const vector<string>& row_vector) {
    ostringstream stream;
    copy(row_vector.begin(), row_vector.end(), ostream_iterator<string>(stream));
    string v_string = stream.str();
    v_string.erase(v_string.length() - 1);
    return v_string;
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

CSVFile::CsvVector CSVFile::get_column(const int& index) {
    CSVFile::CsvVector column_data;
    vector<string> buffer;

    for(unsigned i = 0; i < contents.size(); ++i) {
        buffer.push_back(contents[i][index]);
    }
    column_data.push_back(buffer);
    return column_data;
}

CSVFile::CsvVector CSVFile::get_column(const vector<int>& indices) {
    CSVFile::CsvVector column_data;
    for(auto&& index : indices)
    {
        vector<string> buffer;
        for(unsigned i = 0; i < contents.size(); ++i)
        {
            buffer.push_back(contents[i][index]);
        }
        column_data.push_back(buffer);
    }
    return column_data;
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

vector<string> CSVFile::get_row(const int& i) {
    return contents[i];
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
