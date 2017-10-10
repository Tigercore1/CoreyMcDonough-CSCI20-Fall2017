//Created By: Corey McDonough
//Created On: 10/9/2017
//This code takes inputs of radius in inches and depth in feet. It then takes these numbers and stores them in a class. The number of gallons the cylindar can hold is calculated
//and all the numbers are returned via a print function.

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

const double PI = 3.141592;
const double FTTOGAL = 7.48052; //number of gallons in 1 ft^3

//This class stores the radius if inches and the depth in feet of a well. It has functions to store that data, a function to calculate the number of gallons that well can hold, 
// and a print function that outputs the radius, depth, and number of gallons.
class Well {
    public:
        void SetRadius(double radius){ 
            radius_ = radius;
        }
        void SetDepth(double depth){ 
            depth_ = depth;
        }
        double CalcGallons() const {
            return (depth_ * (PI * ((radius_/12) * (radius_/12)))) * FTTOGAL;
        }
        void Print(){ 
            cout << "A " << depth_ << " foot well full of water with a radius of " << radius_ << " inches holds about " << CalcGallons() << " gallons of water.";
        }
        
        
    private:
        double radius_;
        double depth_;
};

main(){ 
    Well well1;
    
    //initialize variables
    double radius_inches = 0;
    double depth_feet = 0;
    
    //inputs
    cout << "Well depth in feet: ";
    cin >> depth_feet;
    well1.SetDepth(depth_feet);
    cout << "Well radius in inches: ";
    cin >> radius_inches;
    well1.SetRadius(radius_inches);
    
    //outputs
    well1.Print();
    
    
}

/* Tests:

Well depth in feet: 80
Well radius in inches: 464
A 80 foot well full of water with a radius of 464 inches holds about 2.8109e+06 gallons of water.

Well depth in feet: 67
Well radius in inches: 382
A 67 foot well full of water with a radius of 382 inches holds about 1.59559e+06 gallons of water.

Well depth in feet: 456
Well radius in inches: 153
A 456 foot well full of water with a radius of 153 inches holds about 1.74207e+06 gallons of water.

Well depth in feet: 75
Well radius in inches: 366
A 75 foot well full of water with a radius of 366 inches holds about 1.63962e+06 gallons of water.

Well depth in feet: 11
Well radius in inches: 333
A 11 foot well full of water with a radius of 333 inches holds about 199067 gallons of water.

Well depth in feet: 8
Well radius in inches: 205
A 8 foot well full of water with a radius of 205 inches holds about 54867.7 gallons of water.

Well depth in feet: 10
Well radius in inches: 83
A 10 foot well full of water with a radius of 83 inches holds about 11242.8 gallons of water.

Well depth in feet: 31
Well radius in inches: 98
A 31 foot well full of water with a radius of 98 inches holds about 48588.4 gallons of water.

Well depth in feet: 56     
Well radius in inches: 261
A 56 foot well full of water with a radius of 261 inches holds about 622570 gallons of water.

Well depth in feet: 28
Well radius in inches: 109
A 28 foot well full of water with a radius of 109 inches holds about 54291.3 gallons of water.
*/