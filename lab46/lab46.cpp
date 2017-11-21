/*Created By: Corey McDonough
* Created On: 11/20/2017
* This program takes an input.txt file for people's name, number of classes, number of credit hours per class, and the grade. With this information it calculates the person's GPA and 
* outputs it as an HTML file. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
    //Declare variables
    string first_name;
    string last_name;
    int num_classes = 0;
    ifstream fin;
    ofstream fout;
    int total_credits = 0;
    int total_grade_points = 0;
    double grade_point_average = 0;
    int heading_count = 1;
    
    fin.open("input.txt");
    fout.open("output.html");
    
    fout << "<!DOCTYPE html>" << endl; //fout for HTML start
    fout << "<html>" << endl;
    fout << "<body>" << endl << endl;
    
    
    while(!fin.eof()){ //loop runs until file ends
        num_classes = 0; //Initialize variables
        total_credits = 0;
        total_grade_points = 0;
        grade_point_average = 0;
        
        fin >> first_name >> last_name; 
        if (fin.eof()){ //I know the loop doesn't work properly. For some reason the !fin.eof loop would execute one extra time even if the document was finished. I couldn't get around it.
            break;
        }
        fout << "<h" << heading_count << ">"; //Name is a heading in HTML
        fout << first_name << " " << last_name;
        fout << "</h" << heading_count << ">" << endl;
        
        heading_count ++; //heading count for HTML
        fin >> num_classes; //input for num_classes
        //cout << num_classes << endl; (TEST)
        
        vector<int> credit_hours(num_classes); //I learned how to use vectors because the size of array will change per person.
        vector<char> grade(num_classes);
        vector<int> grade_points(num_classes);
    
        for (int i = 0; i < num_classes; i++){ //Input for credit hours and grade
            fin >> credit_hours[i];
            fin >> grade[i];
        }
        //for (int i = 0; i < num_classes; i++){ // (TEST)
        //    cout << credit_hours[i] << " " << grade[i] << endl;
        //}
        for (int i = 0; i < num_classes; i++){ //converts grades to credit points (grade point * credit hour = credit points)
            switch(grade[i]){
                case 'A':
                    grade_points[i] = 4 * credit_hours[i];
                    break;
                case 'B':
                    grade_points[i] = 3 * credit_hours[i];
                    break;
                case 'C':
                    grade_points[i] = 2 * credit_hours[i];
                    break;
                case 'D':
                    grade_points[i] = 1 * credit_hours[i];
                    break;
                case 'F':
                    grade_points[i] = 0 * credit_hours[i];
                    break;
                default: //if an invalid grade is inputted
                    grade_points[i] =9999;
                    break;
            }
        }
    
    
        for (int i = 0; i < num_classes; i++){ //calculation for total credits and total grade points
            total_credits = total_credits + credit_hours[i];
            total_grade_points = total_grade_points + grade_points[i];
        }
        
        grade_point_average = (double)total_grade_points / (double)total_credits; //casts int to double for division (GPA = grad points / total credits)
        
        fout << "<p>"; //output for total credits in HTML
        fout << "Total credits: " << total_credits;
        fout << "</p>" << endl;
        //cout << "Total grade points: " << total_grade_points << endl; (TEST)
        fout << "<p>"; //output for GPA in HTML
        fout << "GPA: " << grade_point_average;
        fout << "</p>" << endl << endl;
    }
    
    fout << "</body>" << endl; //end of HTML
    fout << "</html>";
    
    
    fin.close(); //file close
    fout.close();
    
}