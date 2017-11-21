/*Created By: Corey McDonough
* Created On: 11/15/2017
* This program creates a username for a person with inputs of their first and last name. It won't allow a first name over 10 chars and a last name over 20 chars. It warns you if
* your first and last name are the same.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

int main(){
    //INITIALIZE
    string first_name;
    string last_name;
    int i = 0;
    
    cout << "Please enter first name (<=10 chars):" << endl; //first name input
    cin >> first_name;
    
    
    if (first_name.length() > 10){ //check if first name is greater than 10 chars.
        cout << "WARNING. Name is larger than 10 chars." << endl;
    }

    cout << "Please enter last name (<=20 chars):" << endl; //last name input
    cin >> last_name;
    
    
    if (last_name.length() > 20){ //check if last name is greater than 20 chars
        cout << "WARNING. Name is larger than 20 chars." << endl;
    }
    
    if (first_name.compare(last_name) == 0){ //warning if first and last name are the same.
        cout << "WARNING. First and last name are the same." << endl;
    }
    
    
    for( i = 0; i < first_name.length(); i++){ //converts each char in first name to lowercase
        first_name.at(i) = tolower(first_name.at(i));
    }
    for (i = 0; i < last_name.length(); i++){ //converts each char in last name to lowercase
        last_name.at(i) = tolower(last_name.at(i));
    }
    
    //OUTPUT
    cout << "Which of the three user names would you like:" << endl;

    cout << "-" << first_name << last_name << endl;
    cout << "-" << first_name.at(0) << last_name << endl;
    cout << "-" << first_name.at(0) << first_name.at(1) << last_name << endl;
    
}

/* TESTS
Please enter first name (<=10 chars):
Corey 
Please enter last name (<=20 chars):
McDonough
Which of the three user names would you like:
-coreymcdonough
-cmcdonough
-comcdonough


Please enter first name (<=10 chars):
April
Please enter last name (<=20 chars):
Browne
Which of the three user names would you like:
-aprilbrowne
-abrowne
-apbrowne


Please enter first name (<=10 chars):
AnaElizabeth  
WARNING. Name is larger than 10 chars.
Please enter last name (<=20 chars):
Hazeltine-Smith
Which of the three user names would you like:
-anaelizabethhazeltine-smith
-ahazeltine-smith
-anhazeltine-smith


Please enter first name (<=10 chars):
James
Please enter last name (<=20 chars):
James
WARNING. First and last name are the same.
Which of the three user names would you like:
-jamesjames
-jjames
-jajames
*/