//Revised By: Corey McDonough
//Revised On: 10/23/17
//Sum of numbers 
//Write a program that reads in positive integers from the user, each separated by a space, and the whole terminated by a negative number (e.g. 3 22 10 -2),and 
//outputs the sum of the numbers entered (notincluding the terminated negative number!).
#include <iostream>
using namespace std; 
int main(){
    // initialization
    int num;
    int sum=0;
    cout << "Enter numbers separated by spaces"             << " and terminated with a negative number." << endl;
    // read first number
    cin >> num;
    
    while (num >= 0) {
        // add in to the sum
        sum = sum + num;
        // read in next number (getting ready for next loop test)
        cin >> num;
    }
    cout << "Sum is " << sum << endl;
    return 0;
}

/* 
EXPLANATION/PROCESS:
I first tried running the code to see what happened. I was met with no response.
I then examined the code and compared it to the comments. I realized the code did not match
the comments in some parts, so I changed the code to match the comments.
In the while loop, the equation was wrong and it was reading in the sum instead of the new number,
I changed those things and it now logically makes sense and works. I understand how comments
can be very useful now when it comes to debugging.


OUTPUT:
Enter numbers separated by spaces and terminated with a negative number.
5 8 7 3 -2
Sum is 23

Enter numbers separated by spaces and terminated with a negative number.
1 3 4 5 9 -23
Sum is 22
*/