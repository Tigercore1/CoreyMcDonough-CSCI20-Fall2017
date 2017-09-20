//Created By: Corey McDonough
//Created On: 9/18/2017
//This program will have inputs for temperature and windspeed. When provided, it will then calculate windchill using the old and new formula. Then it will compute the difference.

#include <iostream>
#include <string> 
#include <math.h> //this allows for use of math functions
using namespace std;
 

int main()
{
    //initialize
    double temperature;
    double wind_speed_initial;
    double old_style_wind_chill;
    double sqrt_wind_speed;
    double new_style_wind_chill;
    double power_wind_speed;
    double difference;
    
    //inputs
    cout << "Temperature(F): "; 
    cin >> temperature; 
    cout << "Windspeed(velocity): ";
    cin >> wind_speed_initial;
    
    //calculations
    sqrt_wind_speed = pow(wind_speed_initial,0.5); //calc for sqrt windspeed
    old_style_wind_chill = .081 * (3.71 * sqrt_wind_speed + 5.81 - .25 * wind_speed_initial) * (temperature - 91.4) + 91.4; // clac for old style windchill
    power_wind_speed = pow(wind_speed_initial,.16); //calc for windspeed ^ .16
    new_style_wind_chill = 35.74 + 0.6215 * temperature - 35.75 * (power_wind_speed) + .4275 * temperature * (power_wind_speed); //calc for new style windchill
    
    difference = new_style_wind_chill - old_style_wind_chill;
    
    
    //output
    cout << "Wind Speed  Old Formula  New Formula  Difference" << endl;
    cout << wind_speed_initial << "           " << old_style_wind_chill << "      " << new_style_wind_chill << "       " << difference;
    

}

/* 
Outputs:

Temperature(F): 30 
Windspeed(velocity): 4
Wind Speed  Old Formula  New Formula  Difference
4           30.5753      25.767       -4.8083


Temperature(F): 39.25
Windspeed(velocity): 10
Wind Speed  Old Formula  New Formula  Difference
10           27.8601      32.713       4.85286


Temperature(F): 100
Windspeed(velocity): 2
Wind Speed  Old Formula  New Formula  Difference
2           98.7538      105.711       6.95719


*/ 