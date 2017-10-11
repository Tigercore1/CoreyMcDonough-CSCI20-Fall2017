//Created By: Corey McDonough
//Created On: 10/10/2017
//This program takes inputs of smart phones, dumb phones, tablets, and data usage. It then runs lots of if/else statemetns that calculates the price of each of the plans given the inputs.
//The calculations are then displayed in an outputput. If an input does not work with a plan, "NA" will be displayed instead of the price.

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){
    //INITIALIZE
    int num_smart = 0;
    int num_dumb = 0;
    int num_tablet = 0;
    int num_gig = 0;
    int num_phones = 0;
    
    int price_unlimited_plus = 0;
    bool price_unlimited_plus_check = 0; //Each plan has a bool check. If the plan for some reason does not work with their request, an if/else statement will change the value to 1.
    int price_unlimited_choice = 0;
    bool price_unlimited_choice_check = 0;
    int price_family_plan = 0;
    bool price_family_plan_check = 0;
    int price_verizon_unlimited = 0;
    bool price_verizon_unlimited_check = 0;
    int price_sprint_unlimited = 0;
    bool price_sprint_unlimited_check = 0;
    int price_sprint_2gig = 0;
    bool price_sprint_2gig_check = 0;
    
    
    //INPUTS
    cout << "Enter the number of smart phones, dumb phones, and tablets you wish to have on the plan. Seperate each number by a space." << endl;
    cin >> num_smart >> num_dumb >> num_tablet;
    cout << "Enter number of GB needed: ";
    cin >> num_gig;
    
    num_phones = num_dumb + num_smart; //Smart phones and dumb phones are seen as the same in the plans provided.
    
    //IF AND ELSE STATEMENTS FOR PLAN PRICE CALCULATIONS
    //ATT UNLIMITED PLUS PLAN
    if (num_phones == 0){
        price_unlimited_plus = 0;
    }
    else if (num_phones == 1){
        price_unlimited_plus = 90; 
    }
    else if (num_phones == 2){ 
        price_unlimited_plus = 145;
    }
    else if ((num_phones > 2) && (num_phones <= 10 )){
        price_unlimited_plus = 145 + (20 * (num_phones-2));
    }
    else {
        price_unlimited_plus_check = 1;
    }
    price_unlimited_plus = price_unlimited_plus + (10 * num_tablet);
    
    //ATT UNLIMITED CHOICE PLAN
    if (num_phones == 0){
        price_unlimited_choice = 0;
    }
    else if (num_phones == 1){
        price_unlimited_choice = 60; 
    }
    else if (num_phones == 2){ 
        price_unlimited_choice = 115;
    }
    else if ((num_phones > 2) && (num_phones <= 10 )){
        price_unlimited_choice = 115 + (20 * (num_phones - 2));
    }
    else {
        price_unlimited_choice_check = 1;
    }
    price_unlimited_choice = price_unlimited_choice + (10 * num_tablet);
    
    //ATT FAMILY PLANS
    if (num_gig == 0){
        price_family_plan = 0;
    }
    else if ((num_gig > 0) && (num_gig <= 1)){
        price_family_plan = 30;
    }
    else if ((num_gig > 1) && (num_gig <= 3)){
        price_family_plan = 40;
    }
    else if ((num_gig > 3) && (num_gig <= 6)){
        price_family_plan = 60;
    }
    else if ((num_gig > 6) && (num_gig <= 10)){
        price_family_plan = 80;
    }
    else if ((num_gig > 10) && (num_gig <= 16)){
        price_family_plan = 90;
    }
    else if ((num_gig > 16) && (num_gig <= 25)){
        price_family_plan = 110;
    }
    else {
        price_family_plan_check = 1;
    }
    price_family_plan = price_family_plan + ((20 * num_phones) + (10 * num_tablet));
    
    //VERIZON UNLIMITED
    if (num_phones == 0){
        price_verizon_unlimited = 0;
    }
    else if (num_phones == 1){
        price_verizon_unlimited = 80;
    }
    else if (num_phones >= 2){
        price_verizon_unlimited = 110 + ((num_phones - 1) * 20);
    }
    else{
        price_verizon_unlimited_check = 1;
    }
    price_verizon_unlimited = price_verizon_unlimited + (10 * num_tablet);
    
    //SPRINT UNLIMITED
    if (num_tablet != 0){ //sprint plans don't work with tablets
        price_sprint_unlimited_check = 1;
    }
    else if (num_phones == 1){
        price_sprint_unlimited = 60;
    }
    else if (num_phones == 2){
        price_sprint_unlimited = 100;
    }
    else if (num_phones > 2){
        price_sprint_unlimited = 100 + ((num_phones - 2) * 30);
    }
    else {
        price_sprint_unlimited_check = 1;
    }
    
    //SPRINT 2GB PLAN
    if (num_tablet != 0){ //sprint plans don't work with tablets
        price_sprint_2gig_check = 1;
    }
    else if (num_gig <= 2){
        price_sprint_2gig = (40 * num_phones);
    }
    else {
        price_sprint_2gig_check = 1; //the 2GB plan wont work with any request over 2GB.
    }
    
    
    //OUTPUTS
    cout << "--------------------------------------------------" << endl;
    cout << "The price for each plan in dollars..." << endl;
    
    cout << "ATT Unlimited Plus Plan: "; //each plan output has an if/else statement. If the check reads "0", the price is displayed.
    if (price_unlimited_plus_check == 0){
        cout << price_unlimited_plus << endl;
    }
    else {
        cout << "NA" << endl;
    }
    
    
    cout << "ATT Unlimited Choice Plan: ";
    if (price_unlimited_choice_check == 0){
        cout << price_unlimited_choice << endl;
    }
    else {
        cout << "NA" << endl;
    }
    
    
    cout << "ATT Family Plan: ";
    if (price_family_plan_check == 0){
        cout << price_family_plan << endl;
    }
    else {
        cout << "NA" << endl;
    }
    
    
    cout << "Verizon Unlimited: ";
    if (price_verizon_unlimited_check == 0){
        cout << price_verizon_unlimited << endl;
    }
    else {
        cout << "NA" << endl;
    }
    
    
    cout << "Sprint Unlimited: ";
    if (price_sprint_unlimited_check == 0){
        cout << price_sprint_unlimited << endl;
    }
    else {
        cout << "NA" << endl;
    }
    
    
    cout << "Sprint 2GB Plan: ";
    if (price_sprint_2gig_check == 0){
        cout << price_sprint_2gig << endl;
    }
    else {
        cout << "NA" << endl;
    }
    
    
}



/* TESTS:

Enter the number of smart phones, dumb phones, and tablets you wish to have on the plan. Seperate each number by a space.
2 0 0 
Enter number of GB needed: 5
--------------------------------------------------
The price for each plan in dollars...
ATT Unlimited Plus Plan: 145
ATT Unlimited Choice Plan: 115
ATT Family Plan: 100
Verizon Unlimited: 130
Sprint Unlimited: 100
Sprint 2GB Plan: NA


Enter the number of smart phones, dumb phones, and tablets you wish to have on the plan. Seperate each number by a space.
2 1 1
Enter number of GB needed: 15
--------------------------------------------------
The price for each plan in dollars...
ATT Unlimited Plus Plan: 175
ATT Unlimited Choice Plan: 145
ATT Family Plan: 160
Verizon Unlimited: 160
Sprint Unlimited: NA
Sprint 2GB Plan: NA


Enter the number of smart phones, dumb phones, and tablets you wish to have on the plan. Seperate each number by a space.
0 1 0
Enter number of GB needed: 0
--------------------------------------------------
The price for each plan in dollars...
ATT Unlimited Plus Plan: 90
ATT Unlimited Choice Plan: 60
ATT Family Plan: 20
Verizon Unlimited: 80
Sprint Unlimited: 60
Sprint 2GB Plan: 40
*/