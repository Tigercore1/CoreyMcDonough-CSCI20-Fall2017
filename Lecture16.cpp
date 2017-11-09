#include <iostream>
using namespace std;

int main()
{
    
char mystring[20] = "my test string"; //This should copy mystring to mystring2. It does not do this.
char mystring2[20] = mystring;


char myString3[15] = "my test string"; //This should test if myString3 is equivalent to "my test string". You have to compare them one by one.
if (myString3 == "my test string")
{
   cout<<"The same"<<endl;
}

 
char myString4[20] = "my test string"; //This is supposed to count the number of spaces in the char array, but it's stuck in a loop. I made it not loop and cout.
int i = 0; 
int spaceCount = 0;
while (i < 20)
{
   if (myString4[i] == ' ')
   {
        spaceCount++;
   }
i++;
}
cout <<spaceCount;



char myString5[2] = "my test string"; //We're trying to cut the string. It doesn't work.
int i = 0;
while (myString5[i] != '\0')
{
   cout<<myString5[i];
   i++;
}




char myString6[20] = "my test string"; //This adds an exclamation mark to the 15th char in the array. It then outputs it. It works. It might not work on a different compiler.
myString6[14] = '!';
cout<<myString6<<endl;
}

//run the code
//what should each of these do?  Do they do them?