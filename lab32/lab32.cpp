//Created By: Corey McDonough
//Created On: 10/15/2017
//This app takes inputs for name, filing status, gross wage, and the amount of tax withheld. From this information, it determines your adjusted gross income, 
//the amount of taxes you owe, and the refund you deserve. It outputs all of this. The app primarilly uses if/else statements.

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){
    //INITIALIZE
    string name;
    string filing_status;
    int filing_num = 0;
    double gross_wage = 0;
    double adjusted_gross_income = 0;
    double tax_withheld = 0;
    double owed_tax = 0;
    double refund = 0;
    double net_owed = 0;
    
    //INPUTS
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Filing status (single or married):";
    cin >> filing_status;
    cout << "Gross wages: ";
    cin >> gross_wage;
    cout << "Amount of tax withheld: ";
    cin >> tax_withheld;
    
    //CALCULATIONS
    if (filing_status == "single"){ // Assigns a number to marriage status. A 0 for single and a 1 to married.
        filing_num = 0;
    }
    else if (filing_status == "Single"){
        filing_num = 0;
    }
    else {
        filing_num = 1;
    }
    
    
    adjusted_gross_income = gross_wage - 4050; //Calculations for adjusted gross income
    
    switch (filing_num){
        case 0:
            adjusted_gross_income = adjusted_gross_income - 6350;
            break;
        default:
            adjusted_gross_income = adjusted_gross_income - 12700;
            break;
    }


    if (adjusted_gross_income < 0){
        owed_tax = 0;
    }
    else{
        if (filing_num == 0){ //Calculations for single status
            if (adjusted_gross_income <= 9325){
                owed_tax = .1 * adjusted_gross_income;
            }
            else if (adjusted_gross_income <= 37950){
                owed_tax = 932.5 + ((adjusted_gross_income - 9325) * .15);
            }
            else if (adjusted_gross_income <= 91900){
                owed_tax = 5226.25 + ((adjusted_gross_income - 37950) * .25);
            }
            else if (adjusted_gross_income <= 191650){
                owed_tax = 18713.75 + ((adjusted_gross_income - 91900) * .28);
            }
            else if (adjusted_gross_income <= 416700){
                owed_tax = 46643.75 + ((adjusted_gross_income - 191650) * .33);
            }
            else{
                owed_tax = 120910.25 + ((adjusted_gross_income - 416700) * .396);
            }
        }
        
        else{ //Calculations for married status
            if (adjusted_gross_income <= 18650){
                owed_tax = .1 * adjusted_gross_income;
            }
            else if (adjusted_gross_income <= 75900){
                owed_tax = 1865 + ((adjusted_gross_income - 18650) * .15);
            }
            else if (adjusted_gross_income <= 153100){
                owed_tax = 10452.5 + ((adjusted_gross_income - 75900) * .25);
            }
            else if (adjusted_gross_income <= 233350){
                owed_tax = 29752.5 + ((adjusted_gross_income - 153100) * .28);
            }
            else if (adjusted_gross_income <= 416700){
                owed_tax = 52222.5 + ((adjusted_gross_income - 233350) * .33);
            }
            else{
                owed_tax = 112728 + ((adjusted_gross_income - 470700) * .396);
            }
        } 
    }


net_owed = owed_tax - tax_withheld;

if (net_owed < 0){
    refund = net_owed * (-1);
    net_owed = 0;
}
else {
    refund = 0;
}

//OUTPUTS
cout << "--------------------------------------" << endl;
cout << "Name: " << name << endl;
cout << "Total Gross Adjusted Income: $" << adjusted_gross_income << endl;
cout << "Total tax owed: $" << net_owed << endl;
cout << name << " is entitled to a REFUND of $" << refund;
}

/*TESTS:
Enter name: Joe Vandal
Filing status (single or married):single
Gross wages: 12100
Amount of tax withheld: 250
--------------------------------------
Name: Joe Vandal
Total Gross Adjusted Income: $1700
Total tax owed: $0
Joe Vandal is entitled to a REFUND of $80


Enter name: Alfonso Haynes
Filing status (single or married):married
Gross wages: 32351
Amount of tax withheld: 3192
--------------------------------------
Name: Alfonso Haynes
Total Gross Adjusted Income: $15601
Total tax owed: $0
Alfonso Haynes is entitled to a REFUND of $1631.9


Enter name: Bridget Rowe
Filing status (single or married):single
Gross wages: 88229
Amount of tax withheld: 12057
--------------------------------------
Name: Bridget Rowe
Total Gross Adjusted Income: $77829
Total tax owed: $3139
Bridget Rowe is entitled to a REFUND of $0


Enter name: Wendy Joseph
Filing status (single or married):married
Gross wages: 73291
Amount of tax withheld: 6972
--------------------------------------
Name: Wendy Joseph
Total Gross Adjusted Income: $56541
Total tax owed: $576.65
Wendy Joseph is entitled to a REFUND of $0
*/