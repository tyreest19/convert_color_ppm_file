//
//  main.cpp
//  file_color_converter
//
//  Created by Tyree Stevenson on 10/18/16.
//  Copyright © 2016 Tyree Stevenson. All rights reserved.
//
#include <iostream>
//
//  main.cpp
//  file_color_converter
//
//  Created by Tyree Stevenson on 10/18/16.
//  Copyright © 2016 Tyree Stevenson. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
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
    void apply_colorize();
    void parse_file();
    void apply_grayscale();
    
public:
    PhotoFile(string infile, string outfile);
    void grey_scale(); // edits the file in the file variable and writes to outfile
    void colorize();
};
PhotoFile::PhotoFile(string i, string o) {
    infile = new ifstream(i);
    outfile = new ofstream(o);
    parse_file();
}


void PhotoFile::parse_file() {
    for (int i = 0; i < 4; i++) {
        getline(*infile,headers[i]);
    }
    istringstream sizestream(headers[2]);
    sizestream >> width;
    sizestream >> height;
    numPixels = width * height;
    pixels = new Pixels[numPixels];
    string num1,num2,num3;
    for (int i = 0; i < numPixels; i++) {
        *infile >> num1 >> num2 >> num3;
        pixels[i].r = stoi(num1);
        pixels[i].g = stoi(num2);
        pixels[i].b = stoi(num3);
    }
    infile->close();
}

void PhotoFile::apply_grayscale() {
    int a1,a2,a3;
    int gray;
    for (int i = 0; i < numPixels; i++) {
        a1 = pixels[i].r;
        a2 = pixels[i].g;
        a3 = pixels[i].b;
        gray = (a1 + a2 + a3)/3;
        pixels[i].r = gray;
        pixels[i].b = gray;
        pixels[i].g = gray;
        cout << pixels[i].r << " " <<pixels[i].b << " "<< pixels[i].g << endl;
    }
}

void PhotoFile:: apply_colorize() {
    for (int i = 0; i < numPixels; i++){
        if ( 200 < pixels[i].r  ) {
            continue;
        }
        if (pixels[i].r < 200 ){
            pixels[i].r *= 0.3;
            pixels[i].g *= 0.59;
            pixels[i].b *= 0.11;
        }
        if ( pixels[i].r < 100 ) {
            pixels[i].r *= 255;
            pixels[i].g *= 0;
            pixels[i].b *= 255;
        }
        if (pixels[i].r < 50 ) {
            pixels[i].r = 0;
            pixels[i].g *= 255;
            pixels[i].b *= 55;
        }
        
        
        cout << pixels[i].r << " " <<pixels[i].b << " "<< pixels[i].g << endl;
    }
}

void PhotoFile:: grey_scale() {
    apply_grayscale();
    *outfile << headers[0] << endl;
    *outfile << headers[1] << endl;
    *outfile << headers[2] << endl;
    *outfile << headers[3] << endl;
    for (int i = 0; i < numPixels; i++) {
        *outfile << pixels[i].r << " " << pixels[i].b << " " << pixels[i].g << endl;
    }
    outfile->close();
}

void PhotoFile:: colorize() {
    apply_colorize();
    *outfile << headers[0] << endl;
    *outfile << headers[1] << endl;
    *outfile << headers[2] << endl;
    *outfile << headers[3] << endl;
    for (int i = 0; i < numPixels; i++) {
        *outfile << pixels[i].r << " " << pixels[i].b << " " << pixels[i].g << endl;
    }
    outfile->close();
}

int main(int argc, const char * argv[]) {
    string file_name;
    string file_conversion_type;
    cout << "enter file name with file extension: ";
    getline(cin,file_name);
    cout << "do you want to colorize or gray scale your photo" << endl;
    cout << "enter color for colorize   or gray for grayscale: ";
    getline(cin,file_conversion_type);
    while (file_conversion_type != "color" && file_conversion_type != "gray") {
        cout << "please enter color or gray: ";
        getline(cin,file_conversion_type);
    }
    if (file_conversion_type == "gray") {
        PhotoFile photo(file_name,"converted_file.ppm");
        photo.grey_scale();
        
    }
    if (file_conversion_type == "color") {
        PhotoFile photo(file_name,"converted_file.ppm");
        photo.colorize();
    }
    return 0;
}