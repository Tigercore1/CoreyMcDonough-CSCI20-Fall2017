#include <iostream>
using namespace std;

int main()
{
    int number = 1; //the problem was the int number was 12, which is larger than 10, so it never ran. This is the variable used in the while.
    // this loop outputs the numbers 1-10. It starts at 1 and outputs it. Then it adds a 1 onto the number and runs it again until number=10.
    while (number<=10) //number<= 10 is the condition.
    {
        cout<<number;
        number = number + 1; //this is the change of the condition variable.
    }
    
    int userNumber = 0, x = 1; //initial variable value
    //inputs for numbers
    cout<<" Enter a number: ";
    cin>>userNumber; 
    
    while(x <= number) //condition
    {
        if (x%10 == 0)
        {
            cout<<x<<endl;;
        }
        else
        {
            cout<<x<<" ";
        }
        x++; //change of variable
    }
}

//The first loop doesn't work.  It should print the nubers from 1 to 10 but it doesn't.
//Identify and correct the problem.
//Comment the code as the pseudocode
//Identify the different parts of the loop.