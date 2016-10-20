//
//  PhotoFile.hpp
//  file_color_converter
//
//  Created by Tyree Stevenson on 10/18/16.
//  Copyright © 2016 Tyree Stevenson. All rights reserved.
//

#ifndef PhotoFile_hpp
#define PhotoFile_hpp
#include <iostream>
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
   fstream file; // stores the file
    void show_array_value(Pixels array[],int number_of_pixels);
    void store_pixels_in_array(Pixels *array,int number_of_pixels,string file_name);
   int get_number_of_pixels(string file_name); // returns number of pixels
public:
     void grey_scale(string file_name); // edits the file in the file variable
};

#endif /* PhotoFile_hpp */
