#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guessingGame ();

int main()
{
    cout<<"We are going to play the guessing game 3 times"<<endl; //body
    guessingGame(); // function call
    guessingGame();
    guessingGame();
}

void guessingGame () //definition
{
    srand(time(0)); //body
    int randomNumber = rand() % 10 + 1; //declaration

    int userNumber = 0;
    cout<<"Please choose a number between 1 and 10";
    cin>>userNumber;

    cout<<"You picked: "<<userNumber<<"  The number was: "<<randomNumber<<endl;
}

//* The "void guessingGame ()" at the top makes sure the function is read before the main is executed.
//* Because the funtion uses "void", no data is returned to the main. The outputs are given, and nothing is stored after the function has ran.

//? what is the definition of the program?
//? At what time would you use void over something like int or double for the function?


//Identify with //* 2-4 items that are important
//Identify with //? 2-4 items that are incorrect, unclear, or you have questions on.
//Comment the function appropriately
//Identify the following parts of the function:
//  definition
//  declaration
//  body
//  function call