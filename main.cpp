//
//  main.cpp
//  file_color_converter
//
//  Created by Tyree Stevenson on 10/18/16.
//  Copyright © 2016 Tyree Stevenson. All rights reserved.
//
#include <fstream>
#include <string>
#include <iostream>
#include "PhotoFile.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    string in, out;
    if (argc == 1) {
        in = "/Users/tyreestevenson/Desktop/c++_assignments/file_color_converter/file_color_converter/testcolor.ppm";
        out = "/Users/tyreestevenson/Desktop/c++_assignments/file_color_converter/file_color_converter/grey_scale.ppm";
    } else if (argc == 3) {
        in = argv[1];
        out = argv[2];
    } else {
        cout << "Usage: " << argv[0] << " infile outfile\n";
        return 1;
    }
    PhotoFile photo(in, out);
    //cout << "enter a file name: ";
    //getline(cin,file_name);
    photo.grey_scale();
    return 0;
}
