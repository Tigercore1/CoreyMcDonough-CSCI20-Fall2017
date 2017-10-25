/* Created By: April Browne
 * Created On: 9/22/2016
 * This program will run the Temperature Converter Class
 * Revised By: Corey McDonough
 * Revised On: 10/23/2017
 * This program will convert temperatures in Kelvin, Celsius, and Farenheit using one class. It will convert between all of them, but only have a saved variable of Kelvin. It will also have a print function
 * to diplay all the temperatures.
 */
 
#include<iostream>
using namespace std;

// This class is for a temperature converter. It has one variable, kelvin. It has set and get functions for kelvin, as well as set and gets for inputs of celsius and farenheit.
class TemperatureConverter {
    public:
        //CONSTRUCTORS
        TemperatureConverter(){  //constructor
            kelvin_ = 0;
        }
        TemperatureConverter(double in_kelvin){ //overload constructor
            kelvin_ = in_kelvin;
        }
        
        
        void SetTempFromKelvin(double in_kelvin){  //Set Kelvin and check if Kelvin is < 0
            if(in_kelvin > 0){
                kelvin_ = in_kelvin;  
            } 
            else{
                cout << "Error: negative kelvin value inputted.";
            }
        }
        double GetTempFromKelvin() const{
            return kelvin_;
        }
        double SetTempFromCelsius(double in_celsius){ //Set given C
            kelvin_ = in_celsius + 273.15;
        }
        double SetTempFromFahrenheit(double in_fahrenheit){ //Set given F
            kelvin_ = (5 * (in_fahrenheit - 32)/9) + 273.15;
        }
        double GetTempAsCelsius() const{ //converts K to C
            return (kelvin_ - 273.15);
        }
        double GetTempAsFahrenheit() const{ //converts K to F
            return (((kelvin_ - 273.15)*9)/5 + 32);
        }
        void PrintTemperatures (){
            cout << "Kelvin: " << kelvin_ << endl;
            cout << "Celsius: " << GetTempAsCelsius() << endl;
            cout << "Fahrenheit: " << GetTempAsFahrenheit() << endl;
        }
    
    
    private:
        double kelvin_; //variable decleration 
};

int main ()
{
    TemperatureConverter temp1; //testing default constructor
    TemperatureConverter temp2(274); //testing overloaded constructor
    
    temp1.PrintTemperatures();
    temp2.PrintTemperatures();
    
    temp1.SetTempFromKelvin(400.15); //testing mutator function
    cout<<temp1.GetTempFromKelvin()<<endl;//testing accessor function
    temp1.PrintTemperatures();
    
    temp2.SetTempFromCelsius(32); //testing other functions
    cout<<temp2.GetTempAsCelsius()<<endl;
    temp2.PrintTemperatures();
    
    temp2.SetTempFromFahrenheit(32);
    cout<<temp2.GetTempAsFahrenheit()<<endl;
    temp2.PrintTemperatures();
    
    return 0;
}


/*
OUTPUT:

Kelvin: 0
Celsius: -273.15
Fahrenheit: -459.67
Kelvin: 274
Celsius: 0.85
Fahrenheit: 33.53
400.15
Kelvin: 400.15
Celsius: 127
Fahrenheit: 260.6
32
Kelvin: 305.15
Celsius: 32
Fahrenheit: 89.6
32
Kelvin: 273.15
Celsius: 0
Fahrenheit: 32

*/