//
//  PhotoFile.cpp
//  file_color_converter
//
//  Created by Tyree Stevenson on 10/18/16.
//  Copyright © 2016 Tyree Stevenson. All rights reserved.
//
#include <sstream>
#include "PhotoFile.hpp"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;

int PhotoFile:: get_number_of_pixels(string file_name) {
    // parse file for pixels stores them as string and then mulitplies the pixels and return the value
    file.open(file_name);
    int line_where_pixels_exist = 3;
    string line;
    string pixels[2] = {"empty", "empty"}; // two pixels
    string number = " "; // used to stores the number into a array
    for (int i = 0; i < line_where_pixels_exist ; i++) {
        getline(file,line);
    }
    line += " ";
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ' && number != " ") {
            if (pixels[0] == "empty" ) {
                pixels[0] = number;
            }
            else {
                pixels[1] = number;
                break;
            }
            number.clear();
        }
        if (line[i] == ' ') {
            number.clear();
        }
        number += line[i];
    }
    return stoi(pixels[0]) * stoi(pixels[1]);
}
void PhotoFile:: store_pixels_in_array(PhotoFile::Pixels *array, int number_of_pixels,string file_name) {
    //cout << "where the words coming from" << endl;
    string num1,num2,num3;
    fstream new_file;
    new_file.open(file_name);
    for (int i = 0; i < number_of_pixels * 3; i++) {
        new_file >> num1 >> num2 >> num3;
        if (i > 1) {
            array[i].r = stoi(num1);
            array[i].b = stoi(num2);
            array[i].g = stoi(num3);
        }
    }
}

void PhotoFile:: show_array_value(PhotoFile::Pixels *array,int number_of_pixels) {
    int a1,a2,a3;
    int gray;
    for (int i = 0; i < number_of_pixels; i++) {
        a1 = array[i].r *= 0.3;
        a2 = array[i].g *= 0.11;
        a3 = array[i].b *0.59;
        gray = a1 + a2 + a3;
        array[i].r = gray;
        array[i].b = gray;
        array[i].g = gray;
        cout << array[i].r << " " <<array[i].b << " "<< array[i].g << endl;
        
    }
}
void PhotoFile:: grey_scale(string file_name) {
    string test;
    int number_of_pixels = get_number_of_pixels(file_name);
    Pixels *array_of_pixels = new Pixels[number_of_pixels *3];
    cout << "-----------------im reading the numbers in the file--------------" << endl;
    store_pixels_in_array(array_of_pixels, number_of_pixels, file_name);
    file.open(file_name);
    file >> test;
    file >> test;
    file >> test;
    for (int i = 0; i < number_of_pixels; i++) {
        file << array_of_pixels[i].r  << array_of_pixels[i].b << array_of_pixels[i].g;
    }
}









