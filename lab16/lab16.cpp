//Created By: Corey McDonough
//Created On: 9/11/2017
//

#include <iostream>
#include <string> 
 using namespace std;
 
     // Struct variables for each stock
     struct stock_info{
         string stock_name;
         char stock_sector;
         double share_price;
         int number_shares;
         double total_value;
         
     };
     // each of these are a different object
     stock_info stock1;
     stock_info stock2;
     stock_info stock3;
     stock_info stock4;
     
      int main()
 {
     // All inputs with help
     cout << "Stock #  Stock name   stock sector   share price   number of shares" << endl;  
     cout << "Stock 1: ";
     cin >> stock1.stock_name >> stock1.stock_sector >> stock1.share_price >> stock1.number_shares;
     cout << "Stock 2: ";
     cin >> stock2.stock_name >> stock2.stock_sector >> stock2.share_price >> stock2.number_shares;
     cout << "Stock 3: "; 
     cin >> stock3.stock_name >> stock3.stock_sector >> stock3.share_price >> stock3.number_shares;
     cout << "Stock 4: ";
     cin >> stock4.stock_name >> stock4.stock_sector >> stock4.share_price >> stock4.number_shares;
     
     // calculations
     stock1.total_value = stock1.number_shares * stock1.share_price; // calculation for stock total value
     stock2.total_value = stock2.number_shares * stock2.share_price;
     stock3.total_value = stock3.number_shares * stock3.share_price;
     stock4.total_value = stock4.number_shares * stock4.share_price;
     
     double total_portfolio = stock1.total_value + stock2.total_value + stock3.total_value + stock4.total_value; //calculation for total portfolio value
     
     // outputs 
     cout << "Stock Name    No of Shares    Current Value   Total Value" << endl;
     cout << "----------    ------------    -------------   -----------" << endl;
     cout << stock1.stock_name << "        " << stock1.number_shares << "        " << stock1.share_price << "        " << stock1.total_value << endl;
     cout << stock2.stock_name << "        " << stock2.number_shares << "        " << stock2.share_price << "        " << stock2.total_value << endl;
     cout << stock3.stock_name << "        " << stock3.number_shares << "        " << stock3.share_price << "        " << stock3.total_value << endl;
     cout << stock4.stock_name << "        " << stock4.number_shares << "        " << stock4.share_price << "        " << stock4.total_value << endl;
     
     cout << "Total Portfolio: $" << total_portfolio;
     
     /* 
     Output:
Stock #  Stock name   stock sector   share price   number of shares
Stock 1: FordM A 18.76 87
Stock 2: Albertsn C 34.39 542
Stock 3: AAPL T 145.91 5
Stock 4: Hershey C 1337 42
Stock Name    No of Shares    Current Value   Total Value
----------    ------------    -------------   -----------
FordM        87        18.76        1632.12
Albertsn        542        34.39        18639.4
AAPL        5        145.91        729.55
Hershey        42        1337        56154
Total Portfolio: $77155.1
     
     
 }