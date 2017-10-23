#include <iostream>
using namespace std;

int main()
{
    int number = 0, product = 0;
    while (number >=0)
    {
        for (int i = 0; i<3; i++)
        { 
            product = number * i;
        }
        cout<<"Please enter a positive integer: ";
        cin >> number;
    }
    cout<<"The product is: "<<product<<endl;
}

//Comment the code as pseudocode
//Determine how many times each loop executes if the numbers input are 5, 4, 3, 2, 1,-1
//What is the value of i at the end of the program?

/*
while input number is greater than 0...
product = number * 0
product = number * 1
product = number * 2
it then asks for another input number.
If the number is greater than 0...
product = number * 2
it then asks for another input.
if the number is greater than 0...
product = number * 2
This repeats.
Once a negative number is inputted, the loops ends, and the product is outputted.
product = number * 2.

for loop executes 15 times.  
while loop executes 6 times.
i = 3
*/