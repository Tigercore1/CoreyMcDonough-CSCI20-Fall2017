/* Created by: April Browne
*  Commented by: Corey McDonough
*  Commented on: 11/27/2017
*  This program tests out knowledge of dynamic arrays and pointers. It is broken, but the comments describe what is happening and why it doesn't work.
*/

#include <iostream>
#include <iostream> 
#include <cstring> 
using namespace std;   

int main() {
    int nameLength = 0; //declare and initialize variable nameLength
    char * name = new char[]; //declare a pointer of type char. Then create a new char array. The address of this array is stored in the pointer.

    cout << "Please enter a 10 letter word or less" << endl; //cout
    cin >> name; //cin. This stores input as a char array at the address of the pointer.

    char * head  = name; //create another pointer and set it to the char array stored at name.
    char * tail = name; //create another pointer and set it to the char array stored at name.
    nameLength = strlen(*name); //sets nameLength to the string length of *name. This should just be name. Right now, this is finding the string length of the first char value in name.

    cout << "Your word is " << firststr << endl; //cout. I think the cout should just be name instead of firststr.

    if (nameLength<10) //if nameLength is less than 10...
    {
         while (*head != '\0') //while the char at the address of head is not null...
         {
                cout << *head; //outputs the char at the address of head
                head++; //add one onto the address of head (moves onto next char)
         }
     }
     else //if nameLength is 10 or over...
     {
          cout << "WARNING WORD TOO BIG TO DISPLAY!!" << endl; //cout warning
     }

     cout << endl;

     tail = &name[strlen(name) - 1]; //set tail to the address of the last char in name.

     if (nameLength < 10) //if nameLength is less than 10... This loop will not print the last char because the loop will end once the address is at that location. It will never be able to cout it.
     {
          while (tail != name) //while the address of tail does not equal the address of the first char. 
          {
                 cout << *tail; //output the value at the address of tail
                 tail--; //subtract one from the address (move one char to the left.)
          }
     }
     cout << endl;

     head = name; //set head to the array at name's address.
     tail = &name[strlen(name) - 1]; //set tail to the address of the last char in name.

     head++; //add one onto the address of head.
     tail--; //subtrace one from the address of tail.

     if (*head == *tail) //if the char at the address of head is the same as the char at the address of tail... This really doesn't check if name is a palindrome at all. It compares the second char and the second to last char.
     {
         cout << "It is an palindrome!" << endl; //cout palindrome
     }
     else
     {
         cout << "It is not an palindrome" << endl; //cout not palindrom if chars don't match.
     }

     return 0; 
}

