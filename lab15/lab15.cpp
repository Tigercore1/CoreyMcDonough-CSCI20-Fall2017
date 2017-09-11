//Created By: Corey McDonough
//Created On: 8/30/2017
//The program outputs a madlib with a list of pre-programmed variables put in the story.
//Madlib : "What's for dinner?" https://i.pinimg.com/736x/f7/7b/49/f77b492883b5eba4ad64b3ed02a51964--mad-lips-an-adjective.jpg

#include <iostream>
#include <string> // this allows for the use of strings
 using namespace std;
 
 int main()
 {
     
    string noun = "chicken thigh"; // list of pre-set variables
    string person_in_room = "Corey";
    string verb = "shower";
    string part_of_the_body = "booty";
    string adjective = "succulent";
    string noun2 = "cheese ball";
    string noun3 = "fart jar";
    string plural_noun = "babies";
    string type_of_liquid = "KFC gravy";
    string part_of_the_body_plural = "armpits";
    
     
    cout << "It was Thanksgiving, and the scent of succulent roast " << noun << endl; // output of the madlib. Each line of code is a line outputted.
    cout << "wafted through my house.\" " << person_in_room << ", it's time to " << endl;
    cout << verb << "!\" my mother called. I couldn't wait to get my " << endl;
    cout << part_of_the_body << " on that " << adjective << " Thanksgiving meal." << endl;
    cout << "My family sat around the dining-room " << noun2 << ". The table" <<endl;
    cout << "was laid out with every kind of " << noun3 << " imaginable. There was" << endl;
    cout << "a basket of hot buttered " << plural_noun << " and glasses of sparkling" << endl;
    cout << type_of_liquid << ". Thanksgiving is my favorite holiday, " << part_of_the_body_plural << " down." << endl;
    
 }
/* 
 Output:
It was Thanksgiving, and the scent of succulent roast chicken thigh
wafted through my house." Corey, it's time to 
shower!" my mother called. I couldn't wait to get my 
booty on that succulent Thanksgiving meal.
My family sat around the dining-room cheese ball. The table
was laid out with every kind of fart jar imaginable. There was
a basket of hot buttered babies and glasses of sparkling
KFC gravy. Thanksgiving is my favorite holiday, armpits down.

*/