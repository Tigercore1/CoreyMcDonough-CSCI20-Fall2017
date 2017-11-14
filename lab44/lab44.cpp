/*Created By: Corey McDonough
* Created On: 11/13/2017
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
    char first_name[50];
    char last_name[50];
    int i = 0;
    
    cout << "Please enter first name (<=10 chars):" << endl; //first name input
    cin >> first_name;
    
    
    while (strlen(first_name) > 10){ //check if first name is greater than 10 chars.
        cout << "ERROR. Name is larger than max size." << endl;
        cout << "Please enter first name (<=10 chars):" << endl;
        cin >> first_name;
    }

    cout << "Please enter last name (<=20 chars):" << endl; //last name input
    cin >> last_name;
    
    
    while (strlen(last_name) > 20){ //check if last name is greater than 20 chars
        cout << "ERROR. Name is larger than max size." << endl;
        cout << "Please enter last name (<=20 chars):" << endl;
        cin >> last_name;
    }
    
    if (strcmp (first_name,last_name) == 0){ //warning if first and last name are the same.
        cout << "WARNING. First and last name are the same." << endl;
    }
    
    
    i = 0;
    while (first_name[i]){ //converts each char in first name to lowercase
        first_name[i] = tolower(first_name[i]);
        i++;
    }
    i = 0;
    while (last_name[i]){ //converts each char in last name to lowercase
        last_name[i] = tolower(last_name[i]);
        i++;
    }
    
    //OUTPUT
    cout << "Which of the three user names would you like:" << endl;

    cout << "-" << first_name << last_name << endl;
    cout << "-" << first_name[0] << last_name << endl;
    cout << "-" << first_name[0] << first_name[1] << last_name << endl;
    
}
/* TESTS
Please enter first name (<10 chars):
Corey
Please enter last name (<20 chars):
McDonough
Which of the three user names would you like:
-coreymcdonough
-cmcdonough
-comcdonough


Please enter first name (<10 chars):
April
Please enter last name (<20 chars):
Browne
Which of the three user names would you like:
-aprilbrowne
-abrowne
-apbrowne


Please enter first name (<10 chars):
AnaElizabeth   
ERROR. Name is larger than max size.
Please enter first name (<10 chars):


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
    
    
    