//Created By: Corey McDonough
//Created On: 10/1/2017
//This program takes two inputed numbers and generates a random number between them. It then uses that random number and converts it from pounds to kilograms.
//It then converts it from kilograms back to pounds and checks if they are equal. There are outputs for each step.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;

/* NumSwapper changes swaps the values of the 2 inputs.
   Input: The input is a lower integer and a higher integer.
   Output: The output is the values swapped. */
int NumGenerator (int first_num, int second_num){
    int place_hold = 0; //initialize. Local variables.
    int difference = 0;
    int random = 0;
    
    place_hold = first_num; //sets a placeholder for the first value.
    first_num = second_num;
    second_num = place_hold;
    
    difference = fdim(first_num, second_num) + 1; //calculation used in random number generator.
    
    srand(time(0)); //sets an initial for rand().
    random = rand() % difference + second_num; //selects a random number from the two provided.
    
    return random;
}

/* PoundsToKilograms converts pounds to kilograms.
   Input: The input is the random number in pounds.
   Output: The output is the value in kilograms. */
double PoundsToKilograms (int lb){
    double kg = 0; //initialize local variables.
    kg = lb * .45359;

    return kg;
}

/* KilogramsToPounds converts kilograms to pounds.
   Input: The input is the calculated kilogram value.
   Output: The output is the back into pounds. */
double KilogramsToPounds (double kg){
    double lb = 0; //initialize local variables.
    lb = kg * 2.20463;
    
    return lb;
}


int main(){
    //initialize and declare local variables.
    int low_num = 0;
    int high_num = 0;
    int random_number = 0;
    int pounds = 0;
    double kilograms = 0;
    double pounds_final = 0;
        
    //inputs for numbers.
    cout << "Input two numbers seperated by a space. Input the lowest number first." << endl;
    cin >> low_num >> high_num;
    
    //function calls.
    random_number = NumGenerator(low_num, high_num);
    pounds = random_number;
    kilograms = PoundsToKilograms(random_number);
    pounds_final = KilogramsToPounds(kilograms);
    pounds_final = ceil(pounds_final); // This rounds the final pounds up to a whole integer
    
    //outputs
    cout << "Random number: " << random_number << endl;
    cout << "Pounds: " << pounds << endl;
    cout << "Kilograms: " << kilograms << endl;
    cout << "Final Pounds: " << pounds_final << endl;
  
    //This statement checks if the final pounds is the same as the initial pounds.
    if (pounds == pounds_final) {
        cout << "The pounds and final pounds are equal!" << endl;
    }
    else {
        cout << "The pounds and final pounds are not equal." << endl;    
    } 
    
}
/* Outputs:
Input two numbers seperated by a space. Input the lowest number first.
5 10
Random number: 8
Pounds: 8
Kilograms: 3.62872
Final Pounds: 8
The pounds and final pounds are equal!


Input two numbers seperated by a space. Input the lowest number first.
45 20005
Random number: 8115
Pounds: 8115
Kilograms: 3680.88
Final Pounds: 8115
The pounds and final pounds are equal!
*/
