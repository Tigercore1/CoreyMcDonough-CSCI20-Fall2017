/*Created By: Corey McDonough
* Created On: 10/17/2017
* This program is for a dice game. One plays against a computer to a total score of 100. The player and the computer will take turns rolling dice. A dice roll of 1 yields no points, and
* the turn is over for the roller. If the roll is anything but one, the player/computer will decide whether to roll or stay. If they stay, they keep their points for the turn and it will be added
* to their total score. If they chose to roll again and roll a 1, the player/computer will recieve no points for the turn and the turn is over.
*/

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


/*Function DiceRoll creates a random number between 1 and the number-sided-die chosen.
* Input: The input is the number-sided-die chosen at the beginning of the game.
* Output: An appropriate random number given the input. 
*/
int DiceRoll (int in_number_sided_die){
    int roll = 0;
    
    roll = (rand() % in_number_sided_die) + 1;
     
    return roll;
}


/*Class Computer holds all of the information for the computer. It has appropriate mutator functions that change the computer's score. The class also has a function that decides whether to roll or
* stay depending on the computer's score so far for that turn.
* The class has one private variable for the computer's score.
*/
class Computer {
    public:
        Computer(){  //constructor
            computer_score_ = 0;
        }
        Computer(int in_computer_score){ //overload constructor
            computer_score_ = in_computer_score;
        }
        
        
        void SetComputerScore(int in_computer_score){ //set function
            computer_score_ = in_computer_score;
        }
        int GetComputerScore() const{ //get function
            return computer_score_;
        }
        
        
        string ComputerDecide(int in_temp_score, int in_number_sided_die){//"roll" or "stay" function based on the computer's score for that turn.
            string out_response = "a";
            if (in_temp_score < (in_number_sided_die/2)){//if the computer's score for that turn is less than half the number-sided-die chosen, then roll is returned. If not, then stay.
                out_response = "roll";
            }
            else {
                out_response = "stay";
            }
            return out_response;
        }
        
    private:
        int computer_score_;
};

int main(){
    srand(time(0)); //seed rand
    //INITIALIZE VARIABLES
    int number_sided_die = 0;
    int score_player = 0;
    string response = "a"; //is either "roll" or "stay" during the game.
    int temp_score = 0; //temporary score for each turn
    int temp_roll = 0; //temporary variable for dice number rolled
    bool turn_over = false; //this is changed to true in order to end the loop controlling each turn.
    
    
    //INITIAL INPUT FOR GAME
    cout << "Which sided die would you like to play with? ";
    cin >> number_sided_die;
    
    Computer ComputerTest; //creating object ComputerTest
    
    //START OF GAME
    while ((score_player < 100) && (ComputerTest.GetComputerScore() < 100)){
        //PLAYER TURN
        cout <<"Your total score is: " << score_player << endl;
        while (turn_over == false){ //the turn loops until the variable is changed to true
            cout << "Would you like to roll or stay? ";
            cin >> response;
    
            if (response == "stay"){
                score_player = score_player + temp_score;
                cout << "Turn over." << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                temp_score = 0;
                turn_over = true;
            }
            else if (response == "roll"){
                temp_roll = DiceRoll(number_sided_die);
                cout << "You rolled a " << temp_roll << "." << endl;
                if (temp_roll == 1){
                    temp_score = 0;
                    cout << "Skunk! Turn over." << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    turn_over = true;
                }
                else{
                    temp_score = temp_score + temp_roll;
                    cout << "Your score for this turn is: " << temp_score << endl;
                }
            }
            else {
                cout << "Please enter a valid response. (roll or stay): ";
                cin >> response;
            }
        }
        
        response = "a";//response reset
        turn_over = false;//turn variable reset
        
        if (score_player >= 100){ //If the player's score is over 100, it ends the loop early so the computer does not take another turn and potentially beat the player in points.
            break;
        }
        
        //COMPUTER TURN
        cout << "Computer total score is: " << ComputerTest.GetComputerScore() << endl;
        while (turn_over == false){//turn loops until variable is changed to true
            response = ComputerTest.ComputerDecide(temp_score, number_sided_die);
            cout << "Computer decided to " << response << "." << endl;
    
            if (response == "stay"){
                ComputerTest.SetComputerScore(ComputerTest.GetComputerScore() + temp_score);
                cout << "Computer turn over." << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                temp_score = 0;
                turn_over = true;
            }
            else if (response == "roll"){
                temp_roll = DiceRoll(number_sided_die);
                cout << "Computer rolled a " << temp_roll << endl;
                if (temp_roll == 1){
                    temp_score = 0;
                    cout << "Skunk! Computer turn over." << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    turn_over = true;
                }
                else{
                    temp_score = temp_score + temp_roll;
                    cout << "Computer score for this turn is: " << temp_score << endl;
                }
            }
            else {
                cout << "Please enter a valid response. (roll or stay): ";
                cin >> response;
            }
        }
        
        response = "a"; //response reset
        turn_over = false;//turn variable reset
    }
    
    //GAME OVER (SCORE >= 100)
    cout << "Game over! The winner is the ";
    if (score_player > ComputerTest.GetComputerScore()){
        cout << "player. Well done!" << endl;
    }
    else {
        cout << "computer. Better luck next time." << endl;
    }
    cout << "Player total score: " << score_player << endl;
    cout << "Computer total score: " << ComputerTest.GetComputerScore() << endl;
}

/* TESTS:
Which sided die would you like to play with? 25
Your total score is: 0
Would you like to roll or stay? roll
You rolled a 9.
Your score for this turn is: 9
Would you like to roll or stay? roll
You rolled a 8.
Your score for this turn is: 17
Would you like to roll or stay? roll
You rolled a 9.
Your score for this turn is: 26
Would you like to roll or stay? roll
You rolled a 9.
Your score for this turn is: 35
Would you like to roll or stay? roll
You rolled a 24.
Your score for this turn is: 59
Would you like to roll or stay? roll
You rolled a 24.
Your score for this turn is: 83
Would you like to roll or stay? roll
You rolled a 15.
Your score for this turn is: 98
Would you like to roll or stay? stay
Turn over.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Computer total score is: 0
Computer decided to roll.
Computer rolled a 7
Computer score for this turn is: 7
Computer decided to roll.
Computer rolled a 16
Computer score for this turn is: 23
Computer decided to stay.
Computer turn over.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Your total score is: 98
Would you like to roll or stay? roll
You rolled a 14.
Your score for this turn is: 14
Turn over.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Game over! The winner is the player. Well done!
Player total score: 112
Computer total score: 23




Which sided die would you like to play with? 50
Your total score is: 0
Would you like to roll or stay? stay
Turn over.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Computer total score is: 0
Computer decided to roll.
Computer rolled a 22
Computer score for this turn is: 22
Computer decided to roll.
Computer rolled a 49
Computer score for this turn is: 71
Computer decided to stay.
Computer turn over.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Your total score is: 0
Would you like to roll or stay? stay
Turn over.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Computer total score is: 71
Computer decided to roll.
Computer rolled a 48
Computer score for this turn is: 48
Computer decided to stay.
Computer turn over.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Game over! The winner is the computer. Better luck next time.
Player total score: 0
Computer total score: 119





Which sided die would you like to play with? 10
Your total score is: 0
Would you like to roll or stay? roll
You rolled a 6.
Your score for this turn is: 6
Would you like to roll or stay? roll
You rolled a 1.
Skunk! Turn over.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Computer total score is: 0
Computer decided to roll.
Computer rolled a 1
Skunk! Computer turn over.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Your total score is: 0
Would you like to roll or stay? roll
You rolled a 9.
Your score for this turn is: 9
Would you like to roll or stay? roll
You rolled a 10.
Your score for this turn is: 19
Would you like to roll or stay? roll
You rolled a 3.
Your score for this turn is: 22
Would you like to roll or stay? roll
You rolled a 3.
Your score for this turn is: 25
Would you like to roll or stay? roll
You rolled a 5.
Your score for this turn is: 30
Would you like to roll or stay? roll
You rolled a 2.
Your score for this turn is: 32
Would you like to roll or stay? roll
You rolled a 3.
Your score for this turn is: 35
Would you like to roll or stay? roll
You rolled a 6.
Your score for this turn is: 41
Would you like to roll or stay? roll
You rolled a 5.
Your score for this turn is: 46
Would you like to roll or stay? stay
Turn over.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Computer total score is: 0
Computer decided to roll.
Computer rolled a 9
Computer score for this turn is: 9
Computer decided to stay.
Computer turn over.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Your total score is: 46
Would you like to roll or stay? roll
You rolled a 8.
Your score for this turn is: 8
Would you like to roll or stay? roll
You rolled a 9.
Your score for this turn is: 17
Would you like to roll or stay? roll
You rolled a 3.
Your score for this turn is: 20
Would you like to roll or stay? roll
You rolled a 1.
Skunk! Turn over.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Computer total score is: 9
Computer decided to roll.
Computer rolled a 6
Computer score for this turn is: 6
Computer decided to stay.
Computer turn over.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Your total score is: 46
Would you like to roll or stay? roll
You rolled a 10.
Your score for this turn is: 10
Would you like to roll or stay? roll
You rolled a 8.
Your score for this turn is: 18
Would you like to roll or stay? roll
You rolled a 2.
Your score for this turn is: 20
Would you like to roll or stay? roll
You rolled a 4.
Your score for this turn is: 24
Would you like to roll or stay? roll
You rolled a 7.
Your score for this turn is: 31
Would you like to roll or stay? roll
You rolled a 5.
Your score for this turn is: 36
Would you like to roll or stay? roll
You rolled a 3.
Your score for this turn is: 39
Would you like to roll or stay? stay
Turn over.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Computer total score is: 15
Computer decided to roll.
Computer rolled a 7
Computer score for this turn is: 7
Computer decided to stay.
Computer turn over.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Your total score is: 85
Would you like to roll or stay? roll
You rolled a 6.
Your score for this turn is: 6
Would you like to roll or stay? roll
You rolled a 2.
Your score for this turn is: 8
Would you like to roll or stay? roll
You rolled a 4.
Your score for this turn is: 12
Would you like to roll or stay? roll
You rolled a 4.
Your score for this turn is: 16
Would you like to roll or stay? roll
You rolled a 8.
Your score for this turn is: 24
Would you like to roll or stay? stay
Turn over.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Game over! The winner is the player. Well done!
Player total score: 109
Computer total score: 22

*/