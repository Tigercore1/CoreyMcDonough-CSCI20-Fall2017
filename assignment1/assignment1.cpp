//Created By: Corey McDonough
//Created On: 9/12/2017
//This program will take inputs regarding people's health and calculate the number of calories they must consume in a day and their BMI.
//It will also calculate how many snickers bars they have to eat in a day and output all this information.

#include <iostream>
#include <string> 
using namespace std;
 
struct PersonStats{
    string name;
    int age_months;
    int age_years;
    int weight_pounds;
    double weight_kg;
    int height_feet;
    int height_inches;
    int height_inches_only; // height in just inches. (feet * 12 + height_inches)
    int height_cm; // height in just centimetes

    };


int main()
{
    PersonStats person1; //string object
    
    //Inputs
    cout << "Name: ";
    getline(cin, person1.name);
    cout << "age(months)|weight(lbs)|height(feet inches)" << endl;
    cin >> person1.age_months >> person1.weight_pounds >> person1.height_feet >> person1.height_inches;
    
    //Conversions
    person1.age_years = person1.age_months / 12;
    person1.weight_kg = person1.weight_pounds * 0.453592;
    person1.height_inches_only = (person1.height_feet * 12) + person1.height_inches;
    person1.height_cm = person1.height_inches_only * 2.54;
    
    //Calculations
    double mifflin_calories;
    mifflin_calories = (10 * person1.weight_kg + 6.25 * person1.height_cm - 5 * person1.age_years + 5); // mifflin st joer equation
    
    double benedict_calories;
    benedict_calories = (66.5 + (13.75 * person1.weight_kg) + (5.003 * person1.height_cm) - (6.775 * person1.age_years)); //Harris benedict formula
    
    double bmi;
    bmi = ((703*person1.weight_pounds) / (person1.height_inches_only * person1.height_inches_only)); //BMI equation
    
    int snickers_bars_day;
    snickers_bars_day = mifflin_calories / 250; //number of 250 cal snickers bars needed in one day
    
    //Outputs
    cout << "----------------------" << endl;
    cout << person1.name << endl;
    cout << "age: " << person1.age_years << endl;
    cout << "height: " << person1.height_feet << " ft. " << person1.height_inches << " in." <<endl;
    cout << "weight: " << person1.weight_pounds << " lbs." << endl;
    cout << "BMI: " << bmi << endl;
    cout << "Mifflin st. Joer Calories: " << mifflin_calories << endl;
    cout << "Harris-Benedict Calories: " << benedict_calories << endl;
    cout << "Snickers bars required to eat each day to reach required calories: " << snickers_bars_day << endl;

}
    
/*
Name: Sofia Cameron 
age(months)|weight(lbs)|height(feet inches)
29 35 3 1            
----------------------
Sofia Cameron
age: 2
height: 3 ft. 1 in.
weight: 35 lbs.
BMI: 17
Mifflin st. Joer Calories: 735.007
Harris-Benedict Calories: 736.52
Snickers bars required to eat each day to reach required calories: 2


Name: Richard Watson
age(months)|weight(lbs)|height(feet inches)
78 42 3 8
----------------------
Richard Watson
age: 6
height: 3 ft. 8 in.
weight: 42 lbs.
BMI: 15
Mifflin st. Joer Calories: 859.259
Harris-Benedict Calories: 843.132
Snickers bars required to eat each day to reach required calories: 3


Name: Heather Hunt
age(months)|weight(lbs)|height(feet inches)
312 192 5 10
----------------------
Heather Hunt
age: 26
height: 5 ft. 10 in.
weight: 192 lbs.
BMI: 27
Mifflin st. Joer Calories: 1852.15
Harris-Benedict Calories: 1973.36
Snickers bars required to eat each day to reach required calories: 7


Name: Eddy Hall
age(months)|weight(lbs)|height(feet inches)
162 590 6 1
----------------------
Eddy Hall
age: 13
height: 6 ft. 1 in.
weight: 590 lbs.
BMI: 77
Mifflin st. Joer Calories: 3772.44
Harris-Benedict Calories: 4583.75
Snickers bars required to eat each day to reach required calories: 15

*/


    
    
    
    
    
    
    
    
    


    
    
    