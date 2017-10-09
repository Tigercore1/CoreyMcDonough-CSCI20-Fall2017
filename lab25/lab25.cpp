//Created By: Corey McDonough
//Created On: 10/3/2017
//

#include <iostream>
#include <string>
using namespace std;

class Book{
    public:
        void SetTitle(string title){
            title_ = title;
        }
        void SetAuthor(string author){
            author_ = author;
        }
        void SetYear(int year){
            year_ = year;
        }
        
        string GetTitle() const{
            return title_;
        }
        string GetAuthor() const{
            return author_;
        }
        int GetYear() const{
            return year_;
        }
        
        void Print(){
            cout << "Book: " << title_ << endl;
            cout << "Author: " << author_ << endl;
            cout << "Copyright Year: " << year_ << endl << endl;
        }

    
    private:
        string title_;
        string author_;
        int year_;
    
};

main(){
    Book book1;
    Book book2;
    Book book3;
    Book book4;
    Book book5;
    
    string tit;
    string aut;
    int yea = 0;
    
    cout << "BOOK 1" << endl << "---------------------" << endl; 
    cout << "Enter book title: ";
    cin >> tit;
    book1.SetTitle(tit);
    cout << "Enter book author: ";
    cin >> aut;
    book1.SetAuthor(aut);
    cout << "Enter copyright year: ";
    cin >> yea;
    book1.SetYear(yea);
    cout << endl;
    
    cout << "BOOK 2" << endl << "---------------------" << endl;
    cout << "Enter book title: ";
    cin >> tit;
    book2.SetTitle(tit);
    cout << "Enter book author: ";
    cin >> aut;
    book2.SetAuthor(aut);
    cout << "Enter copyright year: ";
    cin >> yea;
    book2.SetYear(yea);
    cout << endl;
    
    cout << "BOOK 3" << endl << "---------------------" << endl;
    cout << "Enter book title: ";
    cin >> tit;
    book3.SetTitle(tit);
    cout << "Enter book author: ";
    cin >> aut;
    book3.SetAuthor(aut);
    cout << "Enter copyright year: ";
    cin >> yea;
    book3.SetYear(yea);
    cout << endl;
    
    cout << "BOOK 4" << endl << "---------------------" << endl;
    cout << "Enter book title: ";
    cin >> tit;
    book4.SetTitle(tit);
    cout << "Enter book author: ";
    cin >> aut;
    book4.SetAuthor(aut);
    cout << "Enter copyright year: ";
    cin >> yea;
    book4.SetYear(yea);
    cout << endl;
    
    cout << "BOOK 5" << endl << "---------------------" << endl;
    cout << "Enter book title: ";
    cin >> tit;
    book5.SetTitle(tit);
    cout << "Enter book author: ";
    cin >> aut;
    book5.SetAuthor(aut);
    cout << "Enter copyright year: ";
    cin >> yea;
    book5.SetYear(yea);
    cout << endl;
    
    cout << "ALL BOOKS" << endl << "---------------------" << endl;
    book1.Print();
    book2.Print();
    book3.Print();
    book4.Print();
    book5.Print();    
    
}