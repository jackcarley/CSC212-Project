#include "hilb_curve.h"
#include <iostream>
#include <string>
#include <math.h>

int main(int argc,  char*argv[]){
    
    int order = std::stoi(argv[1]);

    //Output file name
    std::string fname = std::string(argv[2]);

    int count = order * 2;
    int start = (6 * pow(2, (order - 1)) );

    Hilb Hilb_object(order, fname);

    Hilb_object.init_vec();

    Hilb_object.main_func(0, 0, start, 0, 0, start, count);

    Hilb_object.output_file();
}
