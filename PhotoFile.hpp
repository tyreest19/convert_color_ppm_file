//
//  PhotoFile.hpp
//  file_color_converter
//
//  Created by Tyree Stevenson on 10/18/16.
//  Copyright © 2016 Tyree Stevenson. All rights reserved.
//

#ifndef PhotoFile_hpp
#define PhotoFile_hpp
#include <fstream>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
class PhotoFile {
    // creates fuccitons to upload file and edit it.
protected:
    struct Pixels {
        int r,g,b;
    };
    ifstream *infile;  // input file
    ofstream *outfile; // output file location
    int numPixels, width, height;
    string headers[4];
    Pixels* pixels;   // Store the pixels when constructed
    
    void parse_file();
    void apply_grayscale();
    
public:
    PhotoFile(string infile, string outfile);
    void grey_scale(); // edits the file in the file variable and writes to outfile
};

#endif /* PhotoFile_hpp */
