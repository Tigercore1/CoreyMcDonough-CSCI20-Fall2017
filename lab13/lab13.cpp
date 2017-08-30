//Created By: Corey McDonough
//Created On: 8/28/2017

//A variable is a location in memory that stores a value. 
 #include <iostream>
 using namespace std;
 
 int main()
 {
     int population = 325756000; //Initial population
     int current_year = 2017;
     int years_later = 0;
     int net_gain = 12; //net gain of one person every net_gain seconds
     
     cout<< "Years in the future:";
     cin >> years_later;
     population = population + (years_later / net_gain * 60 * 60 * 24 * 365); // seconds in a year * years / seconds until a net gain
     population = population + (years_later % net_gain * 60 * 60 * 24 * 365); // the same equation as above but with modulo to account for remainder
     cout << "In the year " << current_year + years_later << ", the population will be ";
     cout << population << ".";
     
     
     /*
     additional rates I didn't use
     int birth_seconds = 8; //1 birth every birth_seconds
     int death_seconds = 12; // 1 death every death_seconds
     int migrant_seconds = 33; // 1 migrant every migrant_seconds
     
     Output:
     "Years in the future:87
     In the year 2104, the population will be 641116000.""
     
     */
     
     
 
}