#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Function decleration
/* Compute Sphere uses the equation to calculate the volume of a sphere based on radius.
   Input: Accepts a single integer for radius.
   Output: None */
void ComputeSphere(int);
/* Compute Box uses the equation to calculate the volume of a box based on the height, length, and width.
   Input: An integer for height, length, and width.
   Output: None */
void ComputeBox(int, int, int);
/* Compute Pyramid uses the equation to calculate the volume of a pyramid based on the height and length.
   Input: An integer for height, and length.
   Output: None */
void ComputePyramid(int, int);

int main()
{
    int length = 1; //provides initial inputs for length, width, and height.
    int width = 1;
    int height = 1;

    ComputeSphere(length); //calls for each of the functions with dimensions 1.
    ComputeBox(length, width, height);
    ComputePyramid(length, height);

    cin>>length>>width>>height; //create an input for length, width, and height. This provides the arguments.
    
    ComputeSphere(length); //calls for each of the functions with the inputs provided.
    ComputeBox(length, width, height);
    ComputePyramid(length, height);
}

void ComputeSphere(int l){ //function for Computing volume sphere.
    double v = (4.0/3) * 3.14 * (l * l * l); // equation (v=(4/3) * 3.14 * (l*l*l))
    cout<<"The volume of a sphere is "<<v<<endl; //output for volume
}

void ComputeBox(int l, int w, int h){ //function for computing volume of the box
    double v = l * w * h; //equation (v = l * w * h)
    cout<<"The volume of a rectangular box is "<<v<<endl; //output for volume
}

void ComputePyramid(int l, int h){ //function for computing volume of the pyramid
    double v = (1.0/3) * l * h; //equation (v = (1/3) * l * h)
    cout<<"The volume of a pyramid is "<<v<<endl; //output for volume
} 

//Appropriately comment all of the functions.  Make a note to identify the paramters and input.
//Comment the main function as if it was pseudocode.
//   make note of where the functions are called and the arguments.