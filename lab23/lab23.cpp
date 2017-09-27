//Created By: Corey McDonough
//Created On: 9/26/2017
//This program accepts two input numbers. It then swaps the value of those numbers and generates a random number in between them. It outputs that random number.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/* NumSwapper changes swaps the values of the 2 inputs.
   Input: The input is a lower integer and a higher integer.
   Output: The output is the values swapped. */
void NumSwapper (int& first_num, int& second_num){
    
    int place_hold = first_num; //sets a placeholder for the first value.
    first_num = second_num;
    second_num = place_hold;
    
    return;
}

/* NumGenerator creates a random number between the two integers put into the program.
   Input: A lower integer and a higher integer.
   Output: None. */
void NumGenerator (int boundary1, int boundary2){
    
    int difference = boundary1 - boundary2 + 1; //calculation used in random number generator.
    
    srand(time(0)); //sets an initial for rand().
    int random_number = rand() % difference + boundary2; //selects a random number from the two provided.

    cout << "A random number between " << boundary2 << " and " << boundary1 << " is " << random_number << "."; //output
}

int main(){
    int low_num = 0;//initialize and declare variables.
    int high_num = 0;
    
    cout << "Input two numbers seperated by a space. Input the lowest number first." << endl; //inputs for the numbers.
    cin >> low_num >> high_num;
    
    NumSwapper(low_num,high_num); //function call
    
    // cout << low_num << " " << high_num << endl; //This is an output to check the NumSwapper.
    
    NumGenerator(low_num, high_num); //function call
    
}

/* OUTPUT:
Input two numbers seperated by a space. Input the lowest number first.
1 10
A random number between 1 and 10 is 6.

Input two numbers seperated by a space. Input the lowest number first.
5 82
A random number between 5 and 82 is 70.

Input two numbers seperated by a space. Input the lowest number first.
22 73 
A random number between 22 and 73 is 42.
*/