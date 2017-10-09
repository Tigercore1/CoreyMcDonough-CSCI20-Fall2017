//Created By: Corey McDonough
//Created On: 9/12/2017
//This program will take inputs regarding people's health and calculate the number of calories they must consume in a day and their BMI. It will also calculate how many snickers bars they have to eat in a day and output all this information.

//inputs
Create a struct for people. Each person is a different object. The variables for it are the person's height, weight, age.
Have an input for the person's first and last name 
Have an input for age in months, weight in pounds, and height in feet and inches 

//conversions
change age in months to years (months / 12)
change weight in pounds to kg (pounds * 0.453592) //keep original weight in lbs
change height in feet to just inches (feet * 12 +inches)
change height in inches to cm (inches * 2.54)// keep original height in inches

//calculations
Use the Mifflin st Jeor equation. 
If male, (10 * weight + 6.25 * height - 5 * age + 5)

Use the Harris Benedict Formula.
If male, (66.5 + (13.75 * weight) + (5.003 * height) - (6.775 * age))

Calculate BMI (703*(Weight.lb / (Height.in*Height.in)))

calculate how many snickers bars you have to eat in a day (Mifflin equation ans / 250)

//outputs
Output persons first and last name on same line.
Output age in years, height, weight, BMI, Mifflin St Jeor calories, Harris-Benedict calories, and how many snickers bars they have to eat.
