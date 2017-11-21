/*Created By: Corey McDonough
* Created On: 10/8/2017
* This program is a virtual shopping cart/catalogue. It stores items as an array of objects. It has one class that consists of a constructor, mutator, and accessor functions.
* It displays a list of items and a user can chose which items they'd like to add to their cart. The cart stores all their items and calculates a total price.
*/
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

/*Class Menu has three private variables. The name, price, and stock of an object. Menu has a constructor and an overloaded constructor. The class also has basic get and set
* functions
*/
class Menu{
    private:
    string name_;
    double price_;
    int stock_;
    
    
    public:
    Menu(){ //constructor
        name_ = "NA";
        stock_ = 0;
        price_ = 0;
    }
    
    Menu(string in_name, int in_stock, double in_price){ //overload constructor
        name_ = in_name;
        stock_ = in_stock;
        price_ = in_price;
    }
    
    
    void Print (){
            cout << name_ << "(" << stock_ << ") - $" << price_ << endl;
    }
    
    //GETS
    string GetName() const{
        return name_;
    }
    int GetStock() const{
        return stock_;
    }
    double GetPrice() const{
        return price_;
    }
    
    //SETS
    void SetName(string in_name){
        name_ = in_name;
    }
    void SetStock(int in_stock){
        stock_ = in_stock;
    }
    void SetPrice(double in_price){
        price_ = in_price;
    }
};


int main(){
    double total = 0; //total cart cost
    int response = 9999; //how user chooses which item they want
    int num_response = 0; //how user chooses how many of an item they want
    int cart_num = 0; //keeps track of size of cart
    
    Menu item[10] = { //initialize objects
    {"Potato", 72, .50},
    {"Sick Kicks", 3, 500},
    {"Mac and Cheese", 5, .40},
    {"Lamp", 2, 27},
    {"Eggroll", 10, 1},
    {"Cup of Coffee", 20, 1.5},
    {"Coffee Mug", 4, 10},
    {"Wireless Mouse", 19, 15},
    {"Folding Chair", 7, 20},
    {"Headphones", 1, 10},
    };
    
    Menu cart[20]; //max cart size of 20 objects
    
    while (response != 0){ //catalog continues until user enters "0"
        cout << "ITEM NAME(#IN STOCK) - PRICE" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    
        for (int i = 0; i < 10; i++){ //prints catalog
            cout << i+1 << ". ";
            item[i].Print();
        }
        
        cout << "Enter the number located before the name of the object you wish to purchase. Enter \"0\" to checkout." << endl; 
        cin >> response;//CIN ITEM
        while ((response < 0) || (response > 10)){ //check to make sure response is valid
            cout << "INVALID RESPONSE." << endl;
            cout << "Enter the number located before the name of the object you wish to purchase. Enter \"0\" to checkout." << endl;
            cin >> response;
        }
        
        if(response == 0){
            break; //break not needed. (for clarity)
        }
        else{
            cout << "How many would you like to add to your cart?" << endl;
            cin >> num_response; //CIN QUANTITY
            if ((item[response - 1].GetStock() - num_response) < 0){ //check to make sure enough items in stock
                cout << "Could not add items to cart. Not enough in stock." << endl;
                }
            else if (num_response == 0){//if user choses to add 0 of an item
                cout << "No items added to cart.";
            }
            else {
                cart[cart_num] = {item[response - 1].GetName(), num_response, item[response - 1].GetPrice()};//creates the cart object (cart[i] = {item selected, amount selected, price of item})
                cart_num++;//Keeps track of number of objects in the cart
                item[response - 1].SetStock(item[response - 1].GetStock() - num_response);//subtracts amount requested of item out of the catalog (item's stock = stock - amount selected)
                cout << "Item(s) successfully added. Would you like to purchase anything else?" << endl;
            }
            
            //resets temp variables
            num_response = 0;
            response = 9999;
        }
    }
    
    //CHECKOUT
    cout << "YOUR CART:" << endl;
    for (int i = 0; i < cart_num; i++){
        cout << cart[i].GetName() << " ~ $" << cart[i].GetPrice() << "(" << cart[i].GetStock() << ")" << endl; //prints the user's cart
        total = total + cart[i].GetPrice() * cart[i].GetStock(); //calculates total cost (total = total + (price * stock))
    }
    cout << "Cart total: $" << total;
    
}
/*TESTS:
ITEM NAME(#IN STOCK) - PRICE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Potato(72) - $0.5
2. Sick Kicks(3) - $500
3. Mac and Cheese(5) - $0.4
4. Lamp(2) - $27
5. Eggroll(10) - $1
6. Cup of Coffee(20) - $1.5
7. Coffee Mug(4) - $10
8. Wireless Mouse(19) - $15
9. Folding Chair(7) - $20
10. Headphones(1) - $10
Enter the number located before the name of the object you wish to purchase. Enter "0" to checkout.
78
INVALID RESPONSE.
Enter the number located before the name of the object you wish to purchase. Enter "0" to checkout.
9
How many would you like to add to your cart?
10
Could not add items to cart. Not enough in stock.
ITEM NAME(#IN STOCK) - PRICE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Potato(72) - $0.5
2. Sick Kicks(3) - $500
3. Mac and Cheese(5) - $0.4
4. Lamp(2) - $27
5. Eggroll(10) - $1
6. Cup of Coffee(20) - $1.5
7. Coffee Mug(4) - $10
8. Wireless Mouse(19) - $15
9. Folding Chair(7) - $20
10. Headphones(1) - $10
Enter the number located before the name of the object you wish to purchase. Enter "0" to checkout.
9
How many would you like to add to your cart?
7
Item(s) successfully added. Would you like to purchase anything else?
ITEM NAME(#IN STOCK) - PRICE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Potato(72) - $0.5
2. Sick Kicks(3) - $500
3. Mac and Cheese(5) - $0.4
4. Lamp(2) - $27
5. Eggroll(10) - $1
6. Cup of Coffee(20) - $1.5
7. Coffee Mug(4) - $10
8. Wireless Mouse(19) - $15
9. Folding Chair(0) - $20
10. Headphones(1) - $10
Enter the number located before the name of the object you wish to purchase. Enter "0" to checkout.
10
How many would you like to add to your cart?
1
Item(s) successfully added. Would you like to purchase anything else?
ITEM NAME(#IN STOCK) - PRICE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Potato(72) - $0.5
2. Sick Kicks(3) - $500
3. Mac and Cheese(5) - $0.4
4. Lamp(2) - $27
5. Eggroll(10) - $1
6. Cup of Coffee(20) - $1.5
7. Coffee Mug(4) - $10
8. Wireless Mouse(19) - $15
9. Folding Chair(0) - $20
10. Headphones(0) - $10
Enter the number located before the name of the object you wish to purchase. Enter "0" to checkout.
6
How many would you like to add to your cart?
3
Item(s) successfully added. Would you like to purchase anything else?
ITEM NAME(#IN STOCK) - PRICE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Potato(72) - $0.5
2. Sick Kicks(3) - $500
3. Mac and Cheese(5) - $0.4
4. Lamp(2) - $27
5. Eggroll(10) - $1
6. Cup of Coffee(17) - $1.5
7. Coffee Mug(4) - $10
8. Wireless Mouse(19) - $15
9. Folding Chair(0) - $20
10. Headphones(0) - $10
Enter the number located before the name of the object you wish to purchase. Enter "0" to checkout.
11
INVALID RESPONSE.
Enter the number located before the name of the object you wish to purchase. Enter "0" to checkout.
0
YOUR CART:
Folding Chair ~ $20(7)
Headphones ~ $10(1)
Cup of Coffee ~ $1.5(3)
Cart total: $154.5




ITEM NAME(#IN STOCK) - PRICE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Potato(72) - $0.5
2. Sick Kicks(3) - $500
3. Mac and Cheese(5) - $0.4
4. Lamp(2) - $27
5. Eggroll(10) - $1
6. Cup of Coffee(20) - $1.5
7. Coffee Mug(4) - $10
8. Wireless Mouse(19) - $15
9. Folding Chair(7) - $20
10. Headphones(1) - $10
Enter the number located before the name of the object you wish to purchase. Enter "0" to checkout.
3
How many would you like to add to your cart?
5
Item(s) successfully added. Would you like to purchase anything else?
ITEM NAME(#IN STOCK) - PRICE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Potato(72) - $0.5
2. Sick Kicks(3) - $500
3. Mac and Cheese(0) - $0.4
4. Lamp(2) - $27
5. Eggroll(10) - $1
6. Cup of Coffee(20) - $1.5
7. Coffee Mug(4) - $10
8. Wireless Mouse(19) - $15
9. Folding Chair(7) - $20
10. Headphones(1) - $10
Enter the number located before the name of the object you wish to purchase. Enter "0" to checkout.
7
How many would you like to add to your cart?
2
Item(s) successfully added. Would you like to purchase anything else?
ITEM NAME(#IN STOCK) - PRICE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Potato(72) - $0.5
2. Sick Kicks(3) - $500
3. Mac and Cheese(0) - $0.4
4. Lamp(2) - $27
5. Eggroll(10) - $1
6. Cup of Coffee(20) - $1.5
7. Coffee Mug(2) - $10
8. Wireless Mouse(19) - $15
9. Folding Chair(7) - $20
10. Headphones(1) - $10
Enter the number located before the name of the object you wish to purchase. Enter "0" to checkout.
7
How many would you like to add to your cart?
2
Item(s) successfully added. Would you like to purchase anything else?
ITEM NAME(#IN STOCK) - PRICE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Potato(72) - $0.5
2. Sick Kicks(3) - $500
3. Mac and Cheese(0) - $0.4
4. Lamp(2) - $27
5. Eggroll(10) - $1
6. Cup of Coffee(20) - $1.5
7. Coffee Mug(0) - $10
8. Wireless Mouse(19) - $15
9. Folding Chair(7) - $20
10. Headphones(1) - $10
Enter the number located before the name of the object you wish to purchase. Enter "0" to checkout.
9 
How many would you like to add to your cart?
7
Item(s) successfully added. Would you like to purchase anything else?
ITEM NAME(#IN STOCK) - PRICE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Potato(72) - $0.5
2. Sick Kicks(3) - $500
3. Mac and Cheese(0) - $0.4
4. Lamp(2) - $27
5. Eggroll(10) - $1
6. Cup of Coffee(20) - $1.5
7. Coffee Mug(0) - $10
8. Wireless Mouse(19) - $15
9. Folding Chair(0) - $20
10. Headphones(1) - $10
Enter the number located before the name of the object you wish to purchase. Enter "0" to checkout.
5
How many would you like to add to your cart?
10
Item(s) successfully added. Would you like to purchase anything else?
ITEM NAME(#IN STOCK) - PRICE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Potato(72) - $0.5
2. Sick Kicks(3) - $500
3. Mac and Cheese(0) - $0.4
4. Lamp(2) - $27
5. Eggroll(0) - $1
6. Cup of Coffee(20) - $1.5
7. Coffee Mug(0) - $10
8. Wireless Mouse(19) - $15
9. Folding Chair(0) - $20
10. Headphones(1) - $10
Enter the number located before the name of the object you wish to purchase. Enter "0" to checkout.
8
How many would you like to add to your cart?
19
Item(s) successfully added. Would you like to purchase anything else?
ITEM NAME(#IN STOCK) - PRICE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Potato(72) - $0.5
2. Sick Kicks(3) - $500
3. Mac and Cheese(0) - $0.4
4. Lamp(2) - $27
5. Eggroll(0) - $1
6. Cup of Coffee(20) - $1.5
7. Coffee Mug(0) - $10
8. Wireless Mouse(0) - $15
9. Folding Chair(0) - $20
10. Headphones(1) - $10
Enter the number located before the name of the object you wish to purchase. Enter "0" to checkout.
4
How many would you like to add to your cart?
2
Item(s) successfully added. Would you like to purchase anything else?
ITEM NAME(#IN STOCK) - PRICE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Potato(72) - $0.5
2. Sick Kicks(3) - $500
3. Mac and Cheese(0) - $0.4
4. Lamp(0) - $27
5. Eggroll(0) - $1
6. Cup of Coffee(20) - $1.5
7. Coffee Mug(0) - $10
8. Wireless Mouse(0) - $15
9. Folding Chair(0) - $20
10. Headphones(1) - $10
Enter the number located before the name of the object you wish to purchase. Enter "0" to checkout.
10
How many would you like to add to your cart?
1
Item(s) successfully added. Would you like to purchase anything else?
ITEM NAME(#IN STOCK) - PRICE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1. Potato(72) - $0.5
2. Sick Kicks(3) - $500
3. Mac and Cheese(0) - $0.4
4. Lamp(0) - $27
5. Eggroll(0) - $1
6. Cup of Coffee(20) - $1.5
7. Coffee Mug(0) - $10
8. Wireless Mouse(0) - $15
9. Folding Chair(0) - $20
10. Headphones(0) - $10
Enter the number located before the name of the object you wish to purchase. Enter "0" to checkout.
0
YOUR CART:
Mac and Cheese ~ $0.4(5)
Coffee Mug ~ $10(2)
Coffee Mug ~ $10(2)
Folding Chair ~ $20(7)
Eggroll ~ $1(10)
Wireless Mouse ~ $15(19)
Lamp ~ $27(2)
Headphones ~ $10(1)
Cart total: $541
*/




