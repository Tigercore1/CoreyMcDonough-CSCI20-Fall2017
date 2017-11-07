/*Created By: Corey McDonough
* Created On: 11/3/2017
* This program is for an array tools class. It will contain a class which stores an array with its size. It will also have function to print the numbers, find the min and max, find the sum,
* count the number of evens and odds, search a certain number, and check if its sorted in ascending order.
*/

#include <iostream>
#include <math.h>
using namespace std;
/*class ArrayTools stores an array and its size. It has a constructor and several functions to analyze its area. These functions include print, find min, find max, sum, 
* num even, num odd, search, and a check for if the numbers are in ascending order. 
*/
class ArrayTools {
    private:
        int size_;
        int array_[];
        
        
        
    public:
    ArrayTools(int in_array[], int in_size){ //constructor
        size_ = in_size;
        for (int i = 0; i < in_size; i++){
            array_[i] = in_array[i];
        }
    }
    
    
    void Print(){
        for (int i=0; i < size_; i++){
            cout << array_[i] << " ";
        }
        cout << endl;
    }
    
    
    int Find_min(int in_low, int in_high){ //returns lowest number in the array given a range for the array.
        in_low--; //changes the number to the proper array amount
        in_high--;
        int min = array_[in_low]; //current min
        
        for (int i = in_low; i <= in_high; i++){ 
            if (array_[i] < min){ //changes the current min
                min = array_[i];
            }
        }
        return min;
    }
    
    
    int Find_max(int in_low, int in_high){ //returns highest number in the array given a range for the array.
        in_low--; //changes the number to the proper array amount
        in_high--;
        int max = array_[in_low];
        
        for (int i = in_low; i <= in_high; i++){
            if (array_[i] > max){
                max = array_[i];
            }
        }
        return max;
    }
    
    
    int Find_sum(){ //returns a sum of all the numbers in the array
        int sum = 0;
        for (int i = 0; i < size_; i++){
            sum = sum + array_[i];
        }
        return sum;
    }
    
    
    int Num_even(){ //counts the unmber of even numbers in the array and outputs the number counted
        int cnt_even = 0;
        for (int i = 0; i < size_; i++){
            if ((array_[i] % 2) == 0){ //Check for even (num%2 == 0)
                cnt_even++;
            }
        }
        return cnt_even;
    }
    
    
    int Num_odd(){ //counts the unmber of odd numbers in the array and outputs the number counted
        int cnt_odd = 0;
        for (int i = 0; i < size_; i++){
            if ((array_[i] % 2) == 1){ //Check for odd (num%2 == 1)
                cnt_odd++;
            }
        }
        return cnt_odd;
    }
    
    
    int Search(int in_value){ //searches for a number in the array and returns the number's location.
        int value = -1;
        for (int i = 0; i < size_; i++){
            if (in_value == array_[i]){ //if numbers match, return array value
                value = i;
            }
        }
        return value;
    }
    
    
    bool Is_sorted (){ //Checks to see if the numbers are ascending, if yes, it returns true (1).
        bool sorted = true;
        for (int i = 0; i < (size_-1); i++){
            if (array_[i] > array_[i+1]){ //if array value is greater than the next array value, it's not sorted. Check for all array values.
                sorted = false;
            }
        }
        return sorted;
    }
};
int main()
{
    const int SIZE = 10;
    int myArray[SIZE];
    
    for(int i = 0; i<SIZE;i++){
        cin>>myArray[i];
    }
    ArrayTools a(myArray,SIZE);
    
    a.Print();
    cout<<"Min: "<<a.Find_min(0, 4)<<endl;
    cout<<"Max: "<<a.Find_max(5, 10)<<endl;
    cout<<"Sum = "<<a.Find_sum()<<endl;
    cout<<"Search 10: "<<a.Search(10)<<endl;
    cout<<"Sorted? "<<a.Is_sorted()<<endl;
    
    return 0;
}

/* TESTS:
1 
2
3
4
5
6
7
8
9
10
1 2 3 4 5 6 7 8 9 10 
Min: 1
Max: 10
Sum = 55
Search 10: 9
Sorted? 1


3
4
7
8
9
12
-99
10
17
67
3 4 7 8 9 12 -99 10 17 67 
Min: 3
Max: 67
Sum = 38
Search 10: 7
Sorted? 0


2
4
6
8
10
12
14
16
18
20
2 4 6 8 10 12 14 16 18 20 
Min: 2
Max: 20
Sum = 110
Search 10: 4
Sorted? 1
*/
