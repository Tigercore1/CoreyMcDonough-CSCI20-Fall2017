//Created By: Corey McDonough
//Created On: 10/17/2017
//This app is a guessing game. It has the user input a number between 1-50 and compares it to a randomly generated number. The computer then outputs "Higher" or "Lower". The person must
//then provide another guess. Before providing a response, the app outputs "5,4,3,2,1...". The computer also keeps track of how many guesses it takes the user. It keeps track of this
//through an initial score of 10. Each guess subtracts 1 from 10.

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
INPUT: None
OUTPUT: 5, 4, 3, 2, 1...
Function CountDown couts a countdown from 5 to 1. It outputs a space and a comma between numbers. After 1 it outputs "..."
*/
void CountDown(){
    int count_down = 5;
    for (count_down = 5; count_down != 0; --count_down){ //This counts down from 5. The if else makes sure there is a "..." after 1.
            if (count_down !=1){
                cout << count_down << ", ";
            }
            else{
                cout << count_down << "... ";
            }
    }
}


int main(){
    //INITIALIZE
    int user_num = 0;
    int random = 0;
    int score = 10;
    
    //INPUT
    cout << "Enter a whole number between 1 and 50: ";
    cin >> user_num;
    
    srand(time(0)); //creates a random number between 1-50.
    random = (rand() % 50) + 1;
    
    for (score = 10; user_num != random; --score){ //This is the for loop to keep track of the user score. After every incorrect guess, it subtracts 1.
        while ((user_num < 1) || (user_num > 50)){ //checkes that the users input is between 1 and 50.
            cout << "Please re-enter a valid number: ";
            cin >> user_num;
        }
        CountDown(); //Function call for countdown.
        if (user_num > random){
            cout << "Too High. Guess again: "; //Appropriate output response
            cin >> user_num;
        }
        else{
            cout << "Too Low. Guess again: "; //Appropriate output response
            cin >> user_num;
        }
    }   
    
    CountDown(); //Function call once the user guesses correctly
    
    cout << "Just Right! Your score: " << score; //output for correct guess
    
    if (score < 0){
        cout << " ~ Wow! You're really bad!!!"; //Extra output if someone gets a negative score.
    }
}

/* TESTS:
Enter a whole number between 1 and 50: 30
5, 4, 3, 2, 1... Too High. Guess again: 29
5, 4, 3, 2, 1... Too High. Guess again: 2999
Please re-enter a valid number: 28
5, 4, 3, 2, 1... Too High. Guess again: 27
5, 4, 3, 2, 1... Too High. Guess again: 2
5, 4, 3, 2, 1... Too Low. Guess again: 20
5, 4, 3, 2, 1... Too High. Guess again: 17
5, 4, 3, 2, 1... Too High. Guess again: 15
5, 4, 3, 2, 1... Too High. Guess again: 13
5, 4, 3, 2, 1... Too High. Guess again: 11
5, 4, 3, 2, 1... Too High. Guess again: 5
5, 4, 3, 2, 1... Too Low. Guess again: 7
5, 4, 3, 2, 1... Too Low. Guess again: 8
5, 4, 3, 2, 1... Too Low. Guess again: 9
5, 4, 3, 2, 1... Too Low. Guess again: 10
5, 4, 3, 2, 1... Just Right! Your score: -4 ~ Wow! You're really bad!!!


Enter a whole number between 1 and 50: 30
5, 4, 3, 2, 1... Too Low. Guess again: 40
5, 4, 3, 2, 1... Too High. Guess again: 35
5, 4, 3, 2, 1... Too Low. Guess again: 37
5, 4, 3, 2, 1... Too Low. Guess again: 38
5, 4, 3, 2, 1... Too Low. Guess again: 39
5, 4, 3, 2, 1... Just Right! Your score: 5
*/