//Created By: Corey McDonough
//Created On: 9/24/2017
//This program randomly generates a number from 1-100 when executed and outputs it.

#include <iostream>
#include <cstdlib> //allows access to random number library
#include <ctime> //allows access to time library
using namespace std;
 
void RandomNumber(){ //function name

 srand(time(0)); //beginning of body. Sets the number for random at the current time.
    int random_number = rand() % 100 + 1; //selects a random number from 1-100

    cout << "Your random number is " << random_number << "."; //output

}

int main(){

RandomNumber(); // function call

}

/*
output:

Your random number is 80.

Your random number is 52.

Your random number is 43.
*/



