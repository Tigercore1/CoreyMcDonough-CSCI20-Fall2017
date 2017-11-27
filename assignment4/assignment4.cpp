/*Created By: Corey McDonough
* Created On: 11/15/17
* This program grades student's tests. It accepts a file input for a key as well as student's answers. It then grades each of their tests and displays which questions they missed in another
* txt file. It also displays their grade on the test.
*/

#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
using namespace std;

/* Class Test stores all information for a test. All input for this class comes from file input, all get functions return data to the main. 
*  Private: Class test stores student name, multiple choice answers, and response answers.
*  Public: Class Test has a constructor, a set function that gets information from file input, a get function for multiple choice answers, and get functions for response answers.
*          Test also has file open/close funcitons and a function that checks if the input file has reached an end.
*/         
class Test{
    private:
    ifstream student; //declare input stream
    string first_name_;
    string last_name_;
    char multiple_choice_[18];
    string question19_;
    string question20_;
    string question21_;
    
    public:
    Test(){ //constructor
        string first_name_ = "NA";
        string last_name_ = "NA";
        for (int i = 0; i < 18; i++){
            multiple_choice_[i] = '-';
        }
        question19_ = "NA";
        question20_ = "NA";
        question21_ = "NA";
    }
    
    void OpenFile(){
        student.open("studentanswers.txt");
    }
    
    void CloseFile(){
        student.close();
    }
    
    bool CheckEof() const{ //checks if file has ended. returns true if it has.
        return student.eof();
    }
    
    void SetStudent(){ //function sets variables using input from "studentanswers.txt"
        student >> first_name_ >> last_name_;
        for (int i = 0; i < 18; i++){
            student >> multiple_choice_[i];
        }
        student >> question19_ >> question20_ >> question21_;
    }
    
    string GetFirstName() const{
        return first_name_;
    }
    
    string GetLastName() const{
        return last_name_;
    }
    
    char GetQuestion(int question_number) const{
        return multiple_choice_[question_number];
    }
    
    string GetQuestion19() const{
        return question19_;
    }
    
    string GetQuestion20() const{
        return question20_;
    }
    
    string GetQuestion21() const{
        return question21_;
    }
};


int main(){
    ifstream key; //stream decleration
    ofstream fout;
    
    char multiple_choice_key[18]; //variable decleration
    string key_19;
    string key_20;
    string key_21;
    double student_score;
    bool eof = false; //bool check for eof
    
    Test student; //creating student object of class Test. This will be used for every student.
    
    key.open("answerkey.txt"); //file opening
    fout.open("output.txt");
    student.OpenFile();
    
    
    //KEY STORING
    for (int i = 0; i < 18; i++){
        key >> multiple_choice_key[i];
    }
    key >> key_19 >> key_20 >> key_21;
    

    while (eof == false){ //loop runs until eof variable is set to true
    
    student_score = 0; //reset student grade for new student
    student.SetStudent(); //Sets all the information for a student
    
    //OUTPUTS
    fout << student.GetFirstName() << " " << student.GetLastName() << endl;
    fout << "Missed questions: ";
    
    for (int i = 0; i < 18; i++){ //if student doesn't answer
        if (student.GetQuestion(i) == '?'){
            fout << i + 1 << " ";
        }
        else if (multiple_choice_key[i] == student.GetQuestion(i)){ //else if student gets correct
            student_score = student_score + 1;
        }
        else{ //else student gets incorrect
            fout << i + 1 << " ";
            student_score = student_score - .25;
        }
    }
    
    
    //QUESTION 19
    if (student.GetQuestion19() == "?"){ //same format as the multiple choice
        fout << 19 << " ";
    }
    else if (student.GetQuestion19() == key_19){
        student_score = student_score + 1;
    }
    else{
        fout << 19 << " ";
        student_score = student_score - .25;
    }
    //QUESTION 20
    if (student.GetQuestion20() == "?"){
        fout << 20 << " ";
    }
    else if (student.GetQuestion20() == key_20){
        student_score = student_score + 1;
    }
    else{
        fout << 20 << " ";
        student_score = student_score - .25;
    }
    //QUESETION 21
    if (student.GetQuestion21() == "?"){
        fout << 21 << " ";
    }
    else if (student.GetQuestion21() == key_21){
        student_score = student_score + 1;
    }
    else{
        fout << 21 << " ";
        student_score = student_score - .25;
    }
    
    
    fout << endl << "Grade: " << (student_score/21) * 100 << "%" << endl << endl; //grade output
    
    eof = student.CheckEof(); //function call to see if file end
}
    
    student.CloseFile(); //file close
    key.close();
    fout.close();
}

