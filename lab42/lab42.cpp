/*Created By: Corey McDonough
* Created On: 11/6/2017
* Our goal is to create a virtual shopping cart with at least 10 items. The cart should use parallel arrays. Each item must have a name, amount in stock, and price. Once the user 
* is done, the user should be prompted with a shopping cart that shows what they purchased and how many. It should also show the total cost for all the items.
*/

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main(){
    //INITIALIZE
    double total = 0;
    
    string name[10];
    int inventory[10];
    double price[10];
    int purchased[10];
    int response = 9999;
    int number = 0;
    
    for (int i = 0; i < 10; i++){ //Initializing amount of items purchased to 0.
        purchased[i] = 0;
    }
    
    name[0] = "Potato        "; //name of items
    name[1] = "Sick Kicks    ";
    name[2] = "Mac and Cheese";
    name[3] = "Hoodie        ";
    name[4] = "Salad         ";
    name[5] = "Onesie        ";
    name[6] = "Ipod Shuffle  ";
    name[7] = "Lava Lamp     ";
    name[8] = "Backpack      ";
    name[9] = "Shoelace     ";
    
    inventory[0] = 72; //amount of items in stock
    inventory[1] = 2;
    inventory[2] = 5;
    inventory[3] = 11;
    inventory[4] = 0;
    inventory[5] = 17;
    inventory[6] = 1;
    inventory[7] = 3;
    inventory[8] = 6;
    inventory[9] = 1;
    
    price[0] = .50; //price of each item
    price[1] = 200;
    price[2] = .40;
    price[3] = 20;
    price[4] = 4;
    price[5] = 23;
    price[6] = 2;
    price[7] = 15;
    price[8] = 20;
    price[9] = 3;
    
    
    while (response != 0){ //user can enter "0" to end.
        cout << "What would you like to add to your cart? Enter the item number. Type \"0\" to checkout." << endl; //menu setup
        cout << "Name  ~  Amount in Stock  ~  Price" << endl;
        cout << "----------------------------------" << endl;
    
    
        for (int i = 0; i < 10; i++){ //Shows the menu
            cout << (i+1) << ") " << name[i] << "   " << inventory[i] << "   $" << price[i] << endl;
        }
        
        
        cin >> response; //ITEM INPUT AND END IF 0
            if (response == 0){
                break;
            }
            else if ((response >= 1) && (response <= 10)){ //there are only 10 items on the list
                cout << "How many would you like to add to your cart?" << endl;
                cin >> number; //NUMBER OF ITEMS INPUT
                if (inventory[response - 1] - number < 0){ //checks to see if there is enough items in stock to support purchase
                    cout << "Could not add items to cart. Not enough in stock." << endl;
                    number = 0;
                    response = 9999;
                }
                else {
                    inventory[response - 1] = inventory[response - 1] - number;
                    purchased [response -1] = purchased[response - 1] + number;
                    total = total + (number * price[response - 1]);
                    number = 0;
                    response = 9999;
                }
            }
            else{
                cout << "INVALID RESPONSE." << endl;
            }
    }
    
    
    cout << "Your cart:" << endl; //CART
    cout << "Name  ~  Number Purchased  ~  Price" << endl;
    cout << "-----------------------------------" << endl;
    
    for (int i = 0; i < 10; i++){//loop to display cart
            cout << (i+1) << ") " << name[i] << "   " << purchased[i] << "   $" << price[i] << endl;
        }
    cout << "Total purchased: $" << total << endl;
}

/* TESTS:
What would you like to add to your cart? Enter the item number. Type "0" to checkout.
Name  ~  Amount in Stock  ~  Price
----------------------------------
1) Potato           72   $0.5
2) Sick Kicks       2   $200
3) Mac and Cheese   5   $0.4
4) Hoodie           11   $20
5) Salad            0   $4
6) Onesie           17   $23
7) Ipod Shuffle     1   $2
8) Lava Lamp        3   $15
9) Backpack         6   $20
10) Shoelace        1   $3
13
INVALID RESPONSE.
What would you like to add to your cart? Enter the item number. Type "0" to checkout.
Name  ~  Amount in Stock  ~  Price
----------------------------------
1) Potato           72   $0.5
2) Sick Kicks       2   $200
3) Mac and Cheese   5   $0.4
4) Hoodie           11   $20
5) Salad            0   $4
6) Onesie           17   $23
7) Ipod Shuffle     1   $2
8) Lava Lamp        3   $15
9) Backpack         6   $20
10) Shoelace        1   $3
2
How many would you like to add to your cart?
7
Could not add items to cart. Not enough in stock.
What would you like to add to your cart? Enter the item number. Type "0" to checkout.
Name  ~  Amount in Stock  ~  Price
----------------------------------
1) Potato           72   $0.5
2) Sick Kicks       2   $200
3) Mac and Cheese   5   $0.4
4) Hoodie           11   $20
5) Salad            0   $4
6) Onesie           17   $23
7) Ipod Shuffle     1   $2
8) Lava Lamp        3   $15
9) Backpack         6   $20
10) Shoelace        1   $3
2
How many would you like to add to your cart?
1
What would you like to add to your cart? Enter the item number. Type "0" to checkout.
Name  ~  Amount in Stock  ~  Price
----------------------------------
1) Potato           72   $0.5
2) Sick Kicks       1   $200
3) Mac and Cheese   5   $0.4
4) Hoodie           11   $20
5) Salad            0   $4
6) Onesie           17   $23
7) Ipod Shuffle     1   $2
8) Lava Lamp        3   $15
9) Backpack         6   $20
10) Shoelace        1   $3
2
How many would you like to add to your cart?
1
What would you like to add to your cart? Enter the item number. Type "0" to checkout.
Name  ~  Amount in Stock  ~  Price
----------------------------------
1) Potato           72   $0.5
2) Sick Kicks       0   $200
3) Mac and Cheese   5   $0.4
4) Hoodie           11   $20
5) Salad            0   $4
6) Onesie           17   $23
7) Ipod Shuffle     1   $2
8) Lava Lamp        3   $15
9) Backpack         6   $20
10) Shoelace        1   $3
7
How many would you like to add to your cart?
12
Could not add items to cart. Not enough in stock.
What would you like to add to your cart? Enter the item number. Type "0" to checkout.
Name  ~  Amount in Stock  ~  Price
----------------------------------
1) Potato           72   $0.5
2) Sick Kicks       0   $200
3) Mac and Cheese   5   $0.4
4) Hoodie           11   $20
5) Salad            0   $4
6) Onesie           17   $23
7) Ipod Shuffle     1   $2
8) Lava Lamp        3   $15
9) Backpack         6   $20
10) Shoelace        1   $3
7
How many would you like to add to your cart?
1
What would you like to add to your cart? Enter the item number. Type "0" to checkout.
Name  ~  Amount in Stock  ~  Price
----------------------------------
1) Potato           72   $0.5
2) Sick Kicks       0   $200
3) Mac and Cheese   5   $0.4
4) Hoodie           11   $20
5) Salad            0   $4
6) Onesie           17   $23
7) Ipod Shuffle     0   $2
8) Lava Lamp        3   $15
9) Backpack         6   $20
10) Shoelace        1   $3
10
How many would you like to add to your cart?
1
What would you like to add to your cart? Enter the item number. Type "0" to checkout.
Name  ~  Amount in Stock  ~  Price
----------------------------------
1) Potato           72   $0.5
2) Sick Kicks       0   $200
3) Mac and Cheese   5   $0.4
4) Hoodie           11   $20
5) Salad            0   $4
6) Onesie           17   $23
7) Ipod Shuffle     0   $2
8) Lava Lamp        3   $15
9) Backpack         6   $20
10) Shoelace        0   $3
13
INVALID RESPONSE.
What would you like to add to your cart? Enter the item number. Type "0" to checkout.
Name  ~  Amount in Stock  ~  Price
----------------------------------
1) Potato           72   $0.5
2) Sick Kicks       0   $200
3) Mac and Cheese   5   $0.4
4) Hoodie           11   $20
5) Salad            0   $4
6) Onesie           17   $23
7) Ipod Shuffle     0   $2
8) Lava Lamp        3   $15
9) Backpack         6   $20
10) Shoelace        0   $3
9 
How many would you like to add to your cart?
6
What would you like to add to your cart? Enter the item number. Type "0" to checkout.
Name  ~  Amount in Stock  ~  Price
----------------------------------
1) Potato           72   $0.5
2) Sick Kicks       0   $200
3) Mac and Cheese   5   $0.4
4) Hoodie           11   $20
5) Salad            0   $4
6) Onesie           17   $23
7) Ipod Shuffle     0   $2
8) Lava Lamp        3   $15
9) Backpack         0   $20
10) Shoelace        0   $3
0
Your cart:
Name  ~  Amount Purchased  ~  Price
-----------------------------------
1) Potato           0   $0.5
2) Sick Kicks       2   $200
3) Mac and Cheese   0   $0.4
4) Hoodie           0   $20
5) Salad            0   $4
6) Onesie           0   $23
7) Ipod Shuffle     1   $2
8) Lava Lamp        0   $15
9) Backpack         6   $20
10) Shoelace        1   $3
Total purchased: $525






What would you like to add to your cart? Enter the item number. Type "0" to checkout.
Name  ~  Amount in Stock  ~  Price
----------------------------------
1) Potato           72   $0.5
2) Sick Kicks       2   $200
3) Mac and Cheese   5   $0.4
4) Hoodie           11   $20
5) Salad            0   $4
6) Onesie           17   $23
7) Ipod Shuffle     1   $2
8) Lava Lamp        3   $15
9) Backpack         6   $20
10) Shoelace        1   $3
8
How many would you like to add to your cart?
3
What would you like to add to your cart? Enter the item number. Type "0" to checkout.
Name  ~  Amount in Stock  ~  Price
----------------------------------
1) Potato           72   $0.5
2) Sick Kicks       2   $200
3) Mac and Cheese   5   $0.4
4) Hoodie           11   $20
5) Salad            0   $4
6) Onesie           17   $23
7) Ipod Shuffle     1   $2
8) Lava Lamp        0   $15
9) Backpack         6   $20
10) Shoelace        1   $3
0
Your cart:
Name  ~  Amount Purchased  ~  Price
-----------------------------------
1) Potato           0   $0.5
2) Sick Kicks       0   $200
3) Mac and Cheese   0   $0.4
4) Hoodie           0   $20
5) Salad            0   $4
6) Onesie           0   $23
7) Ipod Shuffle     0   $2
8) Lava Lamp        3   $15
9) Backpack         0   $20
10) Shoelace        0   $3
Total purchased: $45
*/