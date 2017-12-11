/*Created By: Corey McDonough
* Created On: 11/29/17
* This program is an experience tool for Old School Runescrape. It is primarily used to determine the estimated time to reach a certain level. It includes all combat stats. It stores
* training methods and the xp rates for those training methods in seperate folders. All information is fout to "output.txt".
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*Class skill holds all necessary information and functions for skills.
* It has fins that store information for action xp and actions per hour. It also has an fin for the xp required to reach each level in osrs.
* It can calculate xp per hour and remaining xp. Lastly, the program has a print function that fouts each skill name, required xp, action xp, required actions, and estimated time.
*/
class Skill{
    private:
        //variables inputted
        string name_;
        int current_level_;
        int desired_level_;
        int xp_per_hour_;
        
        //variables calculated/set
        int remaining_xp_;
        int xp_per_action_;
        int action_per_hour_;
        int remaining_actions_;
        
        //fin arrays
        int xp_[99];
        int level_[99];
        int combat_action_[4];
        int hitpoints_action_[4];
        int magic_action_[4];
        int prayer_action_[5];
        int magic_action_per_hour_[4];
        int prayer_action_per_hour_[5];
        
        //files
        ifstream xp;
        ifstream actionxp;
        ifstream actionperhour;
        ofstream fout;
        
    public:
        Skill(){ //default constructor
            name_ = "NA";
            current_level_ = 0;
            desired_level_ = 0;
            xp_per_hour_ = 0;
            remaining_xp_ = 0;
            xp_per_action_ = 0;
            action_per_hour_ = 0;
            remaining_actions_ = 0;
        }
        
        
        void Print(){
            fout << "~" << name_ << "~" << endl;
            fout << current_level_ << " to " << desired_level_ << endl;
            fout << "Required xp: " << remaining_xp_ << endl;
            fout << "Xp per action: " << xp_per_action_ << endl;
            fout << (remaining_xp_ / xp_per_action_) << " actions required." << endl;
            fout << "Estimated time: " << (remaining_xp_/(double)xp_per_hour_)  << " hours." << endl << endl;
        }
        
        
        void SetSkill(string in_name, int in_current_level, int in_desired_level){ //Sets basic skill data
            name_ = in_name;
            current_level_ = in_current_level;
            desired_level_ = in_desired_level;
        }
        
        void SetAction(int skill, int method){ //sets action xp value. User directs which action xp value should be used. This is gotten from files.
            if ((skill == 1) || (skill == 2) || (skill == 3) || (skill == 4)){ 
                xp_per_action_ = combat_action_[method - 1];
            }
            else if (skill == 5){
                xp_per_action_ = prayer_action_[method - 1];
            }
            else if (skill == 6){
                xp_per_action_ = magic_action_[method - 1];
            }
            else if (skill == 7){
                xp_per_action_ = hitpoints_action_[method - 1];
            }
            else{
                cout << "FIXME";
            }
        }
        
        void SetActionPerHour(int skill, int method){ //Sets actions per hour for certain methods. User input directs which data is used.
            if (skill == 5){
                action_per_hour_ = prayer_action_per_hour_[method - 1];
            }
            else if (skill == 6){
                action_per_hour_ = prayer_action_per_hour_[method - 1];
            }
            else{
                cout << "FIXME";
            }
        }
        
        void SetXpPerHour(int in_xp_per_hour){ //for skills with flunctuating xp per hour. User can input xp per hour.
            xp_per_hour_ = in_xp_per_hour;
        }
        
        
        void CalcRemainingXp(){ //calculates remaining xp based on levels inputted
            remaining_xp_ = xp_[desired_level_ - 1] - xp_[current_level_ - 1];
        }
        
        
        void CalcXpPerHour(){ //calculates xp per hour from xp_per_action and actions_per_hour. This is for methods with non-changing xp per hour.
            xp_per_hour_ = xp_per_action_ * action_per_hour_;
        }
        
        
        
        void FinXp(){ //read in data for experience and levels
            xp.open("xp.txt");
            for (int i = 0; i < 99; i++){
                xp >> level_[i];
                xp >> xp_[i];
            }
            xp.close();
        }
        
        void FinActionXp(){ //reads in data for xp per action
            actionxp.open("actionxp.txt");
            
            for (int i = 0; i < 4; i++){
                actionxp >> combat_action_[i];
            }
            
            for (int i = 0; i < 4; i++){
                actionxp >> magic_action_[i];
            }
            
            for (int i = 0; i < 5; i++){
                actionxp >> prayer_action_[i];
            }
            for (int i = 0; i < 4; i ++){
                actionxp >> hitpoints_action_[i];
            }
            actionxp.close();
        }
        
        void FinActionPerHour(){ //reads in data for actions per hour
            actionperhour.open("actionperhour.txt");
            
            for (int i = 0; i < 5; i ++){
                actionperhour >> prayer_action_per_hour_[i];
            }
            for (int i = 0; i < 4; i++){
                actionperhour >> magic_action_per_hour_[i];
            }
            actionperhour.close();
        }
        
        
        
        void FileOpen(){ //opens output
            fout.open("output.txt");
        }
        
        void FileClose(){ //closes output
            fout.close();
        }
        
};


int CheckValidNum(int low, int high){ //simple function to make sure responses are within bounds
    int response = 0;
    cin >> response;
    while ((low > response) || (high < response) ){
        cout << "Please enter a valid number." << endl;
        cin >> response;
    }
    return response;
}


int main(){
    
    Skill skill; //declare and read in files
    skill.FileOpen();
    skill.FinXp();
    skill.FinActionXp();
    skill.FinActionPerHour();
    
    
    int response =99; //initialize temp variables
    string name = "NA";
    int current_level;
    int desired_level;
    int method;
    int xp_per_hour;
    
    
    while (response != 0){ //program will repeat until 0 is entered at main screen. Object Skill is re-used for every skill selected.
    response = 99; //resets temp variables
    method = 0;
    current_level = 0;
    desired_level = 0;
    xp_per_hour = 0;
    
    cout << "Which skill do you wish to train?" << endl; //main screen
    cout << "1. Attack" << endl;
    cout << "2. Strength" << endl;
    cout << "3. Defence" << endl;
    cout << "4. Ranged" << endl;
    cout << "5. Prayer" << endl;
    cout << "6. Magic" << endl;
    cout << "7. Hitpoints" << endl;
    cout << "0. End Program" << endl;
    
    response = CheckValidNum(0, 7);
    
    switch(response) {
        case 1: cout << "ATTACK~" << endl; //attack prompts
                name = "Attack";
                cout << "Current level: " << endl;
                current_level = CheckValidNum(1, 99);
                cout << "Desired level: " << endl;
                desired_level = CheckValidNum(1,99);
                cout << "ATTACK TRAINING METHOD:" << endl;
                cout << "1. Cows" << endl;
                cout << "2. Rock Crabs" << endl;
                cout << "3. Experiments" << endl;
                cout << "4. Yaks" << endl;
                method = CheckValidNum(1, 4);
                cout << "Current XP per hour?" << endl;
                xp_per_hour = CheckValidNum(1,999999999);
                skill.SetSkill(name, current_level, desired_level);
                skill.SetXpPerHour(xp_per_hour);
                skill.SetAction(1,method);
                skill.CalcRemainingXp();
                skill.Print();
                break;
                
        case 2: cout << "STRENGTH~" << endl; //strength prompts
                name = "Strength";
                cout << "Current level: " << endl;
                current_level = CheckValidNum(1, 99);
                cout << "Desired level: " << endl;
                desired_level = CheckValidNum(1,99);
                cout << "STRENGTH TRAINING METHOD:" << endl;
                cout << "1. Cows" << endl;
                cout << "2. Rock Crabs" << endl;
                cout << "3. Experiments" << endl;
                cout << "4. Yaks" << endl;
                method = CheckValidNum(1, 4);
                cout << "Current XP per hour?" << endl;
                xp_per_hour = CheckValidNum(1,999999999);
                skill.SetSkill(name, current_level, desired_level);
                skill.SetXpPerHour(xp_per_hour);
                skill.SetAction(2,method);
                skill.CalcRemainingXp();
                skill.Print();
                break;
        
        case 3: cout << "DEFENCE~" << endl; //defence prompts
                name = "Defence";
                cout << "Current level: " << endl;
                current_level = CheckValidNum(1, 99);
                cout << "Desired level: " << endl;
                desired_level = CheckValidNum(1,99);
                cout << "DEFENCE TRAINING METHOD:" << endl;
                cout << "1. Cows" << endl;
                cout << "2. Rock Crabs" << endl;
                cout << "3. Experiments" << endl;
                cout << "4. Yaks" << endl;
                method = CheckValidNum(1, 4);
                cout << "Current XP per hour?" << endl;
                xp_per_hour = CheckValidNum(1,999999999);
                skill.SetSkill(name, current_level, desired_level);
                skill.SetXpPerHour(xp_per_hour);
                skill.SetAction(3,method);
                skill.CalcRemainingXp();
                skill.Print();
                break;
        
        case 4: cout << "RANGED~" << endl; //ranged prompts
                name = "Ranged";
                cout << "Current level: " << endl;
                current_level = CheckValidNum(1, 99);
                cout << "Desired level: " << endl;
                desired_level = CheckValidNum(1,99);
                cout << "RANGED TRAINING METHOD:" << endl;
                cout << "1. Cows" << endl;
                cout << "2. Rock Crabs" << endl;
                cout << "3. Experiments" << endl;
                cout << "4. Yaks" << endl;
                method = CheckValidNum(1, 4);
                cout << "Current XP per hour?" << endl;
                xp_per_hour = CheckValidNum(1,999999999);
                skill.SetSkill(name, current_level, desired_level);
                skill.SetXpPerHour(xp_per_hour);
                skill.SetAction(4,method);
                skill.CalcRemainingXp();
                skill.Print();
                break;
        
        case 5: cout << "PRAYER~" << endl; //prayer prompts. Xp per hour is not asked. Uses file data based on response.
                name = "Prayer";
                cout << "Current level: " << endl;
                current_level = CheckValidNum(1, 99);
                cout << "Desired level: " << endl;
                desired_level = CheckValidNum(1,99);
                cout << "PRAYER TRAINING METHOD:" << endl;
                cout << "1. Bones" << endl;
                cout << "2. Giant Bones" << endl;
                cout << "3. Dragon Bones" << endl;
                cout << "4. Dragon Bones Gilded Altar" << endl;
                cout << "5. Dragon Bones Ectofuntus" << endl;
                method = CheckValidNum(1, 5);
                skill.SetSkill(name, current_level, desired_level);
                skill.CalcRemainingXp();
                skill.SetAction(5, method);
                skill.SetActionPerHour(5, method);
                skill.CalcXpPerHour();
                skill.Print();
                break;
        
        case 6: cout << "MAGIC~" << endl; //magic prompts. Xp per hour is not asked. Uses file data based on response.
                name = "Magic";
                cout << "Current level: " << endl;
                current_level = CheckValidNum(1, 99);
                cout << "Desired level: " << endl;
                desired_level = CheckValidNum(1,99);
                cout << "MAGIC TRAINING METHOD:" << endl;
                cout << "1. Splash Fire Strike" << endl;
                cout << "2. Splash Curse" << endl;
                cout << "3. Camelot Teleport" << endl;
                cout << "4. High Level Alchemy" << endl;
                method = CheckValidNum(1, 4);
                skill.SetSkill(name, current_level, desired_level);
                skill.CalcRemainingXp();
                skill.SetAction(6, method);
                skill.SetActionPerHour(6, method);
                skill.CalcXpPerHour();
                skill.Print();
                break;
                
        case 7: cout << "HITPOINTS~" << endl; //hitpoints prompt
                name = "Hitpoints";
                cout << "Current level: " << endl;
                current_level = CheckValidNum(1, 99);
                cout << "Desired level: " << endl;
                desired_level = CheckValidNum(1,99);
                cout << "HITPOINTS TRAINING METHOD:" << endl;
                cout << "1. Cows" << endl;
                cout << "2. Rock Crabs" << endl;
                cout << "3. Experiments" << endl;
                cout << "4. Yaks" << endl;
                method = CheckValidNum(1, 4);
                cout << "Current XP per hour?" << endl;
                xp_per_hour = CheckValidNum(1,999999999);
                skill.SetSkill(name, current_level, desired_level);
                skill.SetXpPerHour(xp_per_hour);
                skill.SetAction(7,method);
                skill.CalcRemainingXp();
                skill.Print();
                break;
        
        case 0: cout << "Ending Program.";
                break;
    }

    
    } 
    
    skill.FileClose();
}


/* TEST:
Which skill do you wish to train?
1. Attack
2. Strength
3. Defence
4. Ranged
5. Prayer
6. Magic
7. Hitpoints
0. End Program
1
ATTACK~
Current level: 
1
Desired level: 
20
ATTACK TRAINING METHOD:
1. Cows
2. Rock Crabs
3. Experiments
4. Yaks
1
Current XP per hour?
10000
Which skill do you wish to train?
1. Attack
2. Strength
3. Defence
4. Ranged
5. Prayer
6. Magic
7. Hitpoints
0. End Program
1
ATTACK~
Current level: 
20
Desired level: 
60
ATTACK TRAINING METHOD:
1. Cows
2. Rock Crabs
3. Experiments
4. Yaks
2
Current XP per hour?
40000
Which skill do you wish to train?
1. Attack
2. Strength
3. Defence
4. Ranged
5. Prayer
6. Magic
7. Hitpoints
0. End Program
5
PRAYER~
Current level: 
1
Desired level: 
99
PRAYER TRAINING METHOD:
1. Bones
2. Giant Bones
3. Dragon Bones
4. Dragon Bones Gilded Altar
5. Dragon Bones Ectofuntus
4
Which skill do you wish to train?
1. Attack
2. Strength
3. Defence
4. Ranged
5. Prayer
6. Magic
7. Hitpoints
0. End Program
6
MAGIC~
Current level: 
0
Please enter a valid number.
1
Desired level: 
40
MAGIC TRAINING METHOD:
1. Splash Fire Strike
2. Splash Curse
3. Camelot Teleport
4. High Level Alchemy
1
Which skill do you wish to train?
1. Attack
2. Strength
3. Defence
4. Ranged
5. Prayer
6. Magic
7. Hitpoints
0. End Program
0
Ending Program.


OUTPUT.TXT:
~Attack~
1 to 20
Required xp: 4470
Xp per action: 32
139 actions required.
Estimated time: 0.447 hours.

~Attack~
20 to 60
Required xp: 269272
Xp per action: 200
1346 actions required.
Estimated time: 6.7318 hours.

~Prayer~
1 to 99
Required xp: 13034431
Xp per action: 180
72413 actions required.
Estimated time: 47.8925 hours.

~Magic~
1 to 40
Required xp: 37224
Xp per action: 12
3102 actions required.
Estimated time: 1.06966 hours.
*/