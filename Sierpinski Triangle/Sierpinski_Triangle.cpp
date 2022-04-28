// Sierpinski Triangle

// Hassan Bhatti
// CSC 212
// Spring 2022

#include <iostream>
#include <fstream>

using namespace std;

// Defining the function for creating mini-triangles with recursive function
void triangle_Sierpinski(int x){
    // Creating a .txt file for saving the result
    ofstream file("SierpinskiTriangle.txt");
    // Adding the header to the file
    file << "The following diagram depicts the Sierpinski Triangle with "<<x<<" iterations."<< endl;
    
    for (int base = x - 1; base >= 0; base--){

        for (int i = 0; i < base; i++){

            file <<" "<<" ";
        }

        for (int mid = 0; (mid + base) < x; m++){
            if(mid & base){
                file<< " "<<" ";
            }
            else{
                file<< "▲ ";
            }
        }

        file<<endl;
    }
}
 
// Main function
int main(){
    int n;
    //taking the input from the user and printing the triangle
    cout << "Enter the number of triangles: ";
    cin >> n;

    triangle_Sierpinski(n);

    return 0;
}
