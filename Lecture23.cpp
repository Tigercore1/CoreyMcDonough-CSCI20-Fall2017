#include <iostream>
using namespace std;



class Salary //Class salary stores annual amount of money and has appropriate mutator functions that take inputs of salary. This is stored as annual_ in the class.
{
    private: 
        double annual_;
    public:
        Salary() //constructor
        {
            annual_ = 0;
        }
        Salary(double salary){ //overloaded constructor
            annual_ = salary;   
        }
        void SetAnnualSalary(double salary) //sets argument salary to annual_ if the salary is above 0.
        {
            if (salary > 0){
                annual_ = salary;
            }
            else
                annual_ = 0;
        }
        double GetAnnualSalary() //gets annual_
        {
            return annual_;
        }
        void Print() //outputs annual_
        {
             cout<<"$"<<annual_<<endl;
        }
};

int main(){
    Salary None;
    Salary Negative(-2);
    Salary Appropriate(5);
    
    None.Print();
    Negative.Print();
    Appropriate.Print();
        
        
        
        
        
}
//Comment the class per the class style guide
//Identify the following parts of the class
//      constructor
//      overload the constructor to accept an input for salary 
//      and set the salary to the input
//Create a main function that creates an object with no input
//  creates an object with input that is negative
//  and creates an object with input that is appropriate.
//and outputs the salary for each object.