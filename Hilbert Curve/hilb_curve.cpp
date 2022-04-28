#include "hilb_curve.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <iostream>

Hilb::Hilb(int order, std::string fname){
    order_count = order;
    file_name = fname;
}

//Creates the pixel grid in the form as a 2d vector
void Hilb::init_vec(){
    //Calculation to create the grid dimensions
    int length = (6 * pow(2, (order_count - 1)) );

    std::vector<int> temp_vec;
    for(int i = 0; i < length; i++){
        temp_vec.push_back(0);
    }
    for(int j = 0; j < length; j++){
        hilb_vec.push_back(temp_vec);
    }
}

void Hilb::connect_points(){
    //point1 and point2's i and j values are extracted and stored as integers
    int point1_i = point_vec[0];
    int point1_j = point_vec[1];
    int point2_i = point_vec[2];
    int point2_j = point_vec[3];

    //temperation i and j values for travering the 2d vector
    int temp1_i = point1_i;
    int temp1_j = point1_j;

    //If point2 is located north of point1
    if(point2_i < point1_i && point1_j == point2_j){
        while(temp1_i != point2_i){
            temp1_i -= 1;
            hilb_vec[temp1_i][point1_j] = 255;
        }
    }
    //If point2 is located south of point1
    if(point2_i > point1_i && point1_j == point2_j){
        while(temp1_i != point2_i){
            temp1_i += 1;
            hilb_vec[temp1_i][point1_j] = 255;
        }

    }
    //If point2 is located east of point1
    if(point2_j > point1_j && point1_i == point2_i){
        while(temp1_j != point2_j){
            temp1_j += 1;
            hilb_vec[point1_i][temp1_j] = 255;
        }

    }
    //If point2 is located west of point1
    if(point2_j < point1_j && point1_i == point2_i){
        while(temp1_j != point2_j){
            temp1_j -= 1;
            hilb_vec[point1_i][temp1_j] = 255;
        }
    }

    //point_vec is cleared and point2's i and j values are added act as the new point1's i and j values
    point_vec.clear();
    point_vec.push_back(point2_i);
    point_vec.push_back(point2_j);
}

int Hilb::main_func(int i, int j, int i2, int j2, int i3, int j3, int count){
    //1 is subtracted from negative integers to round the value up instead of down
    if(count <= 0){
        if(i2 < 0){
            i2 -= 1;
        }
        if(j2 < 0){
            j2 -= 1;
        }
        if(i3 < 0){
            i3 -= 1;
        }
        if(j3 < 0){
            j3 -= 1;
        }
        //i and j coordinates that will be plotted
        int plot_i = i + (i2 + i3)/2;
        int plot_j = j + (j2 + j3)/2;
        
        //the point is plotted on a 2d vector
        hilb_vec[plot_i][plot_j] = 255;

        //point_vec acts as a means to store 2 plot points that will be connected via the connect_points() function
        point_vec.push_back(plot_i);
        point_vec.push_back(plot_j);

        
        if(point_vec.size() == 4){
            connect_points();
        }

    }else{
        main_func(i, j, i3/2, j3/2, i2/2, j2/2, count-2); //green(for SFML output)
        main_func(i+i2/2, j+j2/2, i2/2, j2/2, i3/2, j3/2, count-2); //red(for SFML output)
        main_func(i+i2/2+i3/2, j+j2/2+j3/2, i2/2, j2/2, i3/2, j3/2, count-2); //blue(for SFML output)
        main_func(i+i2/2+i3, j+j2/2+j3, -i3/2, -j3/2, -i2/2, -j2/2, count-2); //yellow(for SFML output)
    }
}

void Hilb::output_file(){

    std::ofstream output_file(file_name);

    // Loop rows
    for(unsigned int i = 0; i < hilb_vec.size(); i++){
        // Loop columns
        for(unsigned int j = 0; j < hilb_vec[i].size(); j++){
            output_file << hilb_vec[i][j] << " ";
        }
        output_file << std::endl;
    }
}
