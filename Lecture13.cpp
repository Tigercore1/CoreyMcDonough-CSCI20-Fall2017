//revised by: Corey McDonough
//revised on: 10/2/17

#include <iostream>
using namespace std;

/*  This class Salary stores data for annual salary. It can be set, retrieved, and printed out. */
class Salary
{
    private: 
        double annual_; //data field
    public:
        void SetAnnualSalary(double salary) //mutator function
        {
            annual_ = salary;
        }
        double GetAnnualSalary() //accessor function
        {
            return annual_;
        }
        void Print()
        {
             cout<<"$"<<annual_<<endl;
        }
};
int main(){
    Salary edgar;
    edgar.SetAnnualSalary(200);
    
    edgar.GetAnnualSalary();
    
    edgar.Print();
  
  
}



//Comment the class per the class style guide
//Identify the following parts of the class
//      data field
//      mutator function
//      accessor function
//Create a main function that creates an object and runs all of the functions in order