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
#include "PhotoFile.cpp"
using namespace std;
int main(int argc, const char * argv[]) {
    PhotoFile photo;
    string file_name;
    //cout << "enter a file name: ";
    //getline(cin,file_name);
    photo.grey_scale("testcolor.ppm");
    return 0;
}
