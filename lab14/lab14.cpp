//Created By: Corey McDonough
//Created On: 8/30/2017
//A change amount is inputted. It then calculates the most efficient change 
//value and states the amount of money in dollars and cents. A fee is deducted
//and then it says the amount of money given back.

 #include <iostream>
 #include <iomanip> // this allows the use of "setprecision"
 using namespace std;
 
 int main()
 {
     int change = 0; // Cent amount of change inputted
     int quarters = 0; // The amount of coins put in
     int dimes = 0;
     int nickels = 0;
     int pennies = 0;
     
     double fee = 10.9; // Fee percent
     double money = 0; // Amount of money in dollars and cents
     
     
     cout << "Enter change amount in cents: ";
     cin >> change;
     
     money = static_cast<double>(change) / 100.00; // Calculation for money amount in dollars and cents
     
     
     quarters = change / 25; // Calculations for the most efficient coins put in
     change = change - quarters  * 25;
     dimes = change / 10;
     change = change - dimes * 10;
     nickels = change / 5;
     change = change - nickels * 5;
     pennies = change / 1;
     change = change - pennies * 1;
     
     
     cout << "You put in... " << endl; // Output for coins put in
     cout << "Quarters: " << quarters << endl;
     cout << "Dimes: " << dimes << endl;
     cout << "Nickels: " << nickels << endl;
     cout << "Pennies: " << pennies << endl;
     
     
     cout << "The total is $"; // Output for the total money and money after fee
     cout << setprecision(2) << fixed; // This allows the output of 2 decimal places, even if they are zeros.
     cout << money;
     cout << ". After the fee, you get $";
     fee = 1 - (fee / 100); // Calculation for fee as a decimal value
     money = money * fee;
     cout << money;
     cout << " in cash.";
     
 }
 
/*
I used this cite for help figuring out precision:
https://stackoverflow.com/questions/22515592/how-to-use-setprecision-in-c

Output:
Enter change amount in cents: 440
You put in... 
Quarters: 17
Dimes: 1
Nickels: 1
Pennies: 0
The total is $4.40. After the fee, you get $3.92 in cash.

*/


