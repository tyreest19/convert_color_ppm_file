//
//  PhotoFile.cpp
//  file_color_converter
//
//  Created by Tyree Stevenson on 10/18/16.
//  Copyright © 2016 Tyree Stevenson. All rights reserved.
//
#include "PhotoFile.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
using namespace std;

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
    //cout << "where the words coming from" << endl;
    string num1,num2,num3;
    for (int i = 0; i < numPixels; i++) {
        *infile >> num1 >> num2 >> num3;
        pixels[i].r = stoi(num1);
        pixels[i].b = stoi(num2);
        pixels[i].g = stoi(num3);
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

void PhotoFile:: grey_scale() {
    cout << "-----------------im reading the numbers in the file--------------" << endl;
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









