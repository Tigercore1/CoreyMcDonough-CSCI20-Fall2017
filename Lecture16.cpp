//Created By: April Browne
//Revised By: Corey McDonough
 //Revised on: 9/11/2017
 
 #include <iostream>
 using namespace std;
 
 struct monster{
  string head;
  string eyes;
  string ears;
  string mouth;
  string nose;
 };
 
 int main()
 {
   monster monsterA;
   monsterA.head = "Zombus";
   monsterA.eyes = "Vegitas";
   monsterA.ears = "Wackus";
   monsterA.nose = "Vegitas";
   monsterA.mouth = "Wackus";
   
   monster monsterB;
   monsterB.head = "Happy";
   monsterB.eyes = "Wackus";
   monsterB.ears = "Vegitas";
   monsterB.nose = "Vegitas";
   monsterB.mouth = "Spritem";
   
   cout<<"Monster A~" << endl;
   cout<<"Head:"<<monsterA.head<<endl;
   cout<<"Eyes:"<<monsterA.eyes<<endl;
   cout<<"Ears:"<<monsterA.ears<<endl;
   cout<<"Nose:"<<monsterA.nose<<endl;
   cout<<"Mouth:"<<monsterA.mouth<<endl;
   
   cout<< "Monster B~" << endl;
   cout<<"Head:"<<monsterB.head<<endl;
   cout<<"Eyes:"<<monsterB.eyes<<endl;
   cout<<"Ears:"<<monsterB.ears<<endl;
   cout<<"Nose:"<<monsterB.nose<<endl;
   cout<<"Mouth:"<<monsterB.mouth<<endl;
     
 }
 
 /* 
 Important:
 2) A struct is not a variable or an object.
 1) Structs must have a ";" after the final "}"
 
 Questions:
 1) Can we use structs to do calculations?
 2) What happens if we make an input into a struct, but one of the attributes is left blank and then latter that blank is outputted?
 */ 