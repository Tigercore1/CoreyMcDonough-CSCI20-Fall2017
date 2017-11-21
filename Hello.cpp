#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int size = 0;
    
    
    for (int j = 0; j < 3; j++){
        cout << "Loop " << j+1 << endl; 
        cout << "array size: ";
        cin >> size;
        vector<int> array(size);
        for (int i = 0; i < size; i++){
        cin >> array[i];
        }
        for (int i = 0; i < size; i++){
            cout << array[i] << endl;
        }
    }

 
 
 
 
}
 
 
 /*
 Function comments:
 description
 input
 output
 
 
 style guide:
 
 function name: NormalCase
 variable name: cool_beans
 Struct name: NormalCase
 variables in a class: head_weight_ (additional underscore)
 
 Notes:
 A variable is a location in memory that stores a value.
 A parameter is a variable that a function is expecting. (function input)
 An argument is the actual value being sent to the function.
 A condition is anything that evaluates true or false
 

Procedural
Functional
Object Oriented
Event
Logical
Multi

C++ is all but logical

parts of fstream:
#include
declare objects
open
use
close


#include<iostream>
using namespace std;

int main(){
    double x = 5.5;
    double y = 7.7;
    
    x = y;
    y = x;
    
    cout<<x<<"     "<<y<<endl;
}

//Does this swap the values? NO. 
//How would you fix it so it does swap the values? I would create a temporary variable to store either x or y.
//Create a swap function.

void swap (int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
    
}

swap (&x, &y);

//What challenges did you have? Learning pointers. It's weird.


 */ 


 