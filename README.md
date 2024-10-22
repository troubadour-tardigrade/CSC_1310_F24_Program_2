# CSC_1310_F24_Program_2
Repository for CSC 1310 Program 2 at TN Tech 

# <u>Write up</u> 
# Group Members: 
Jonathan Salvato, Nick Romsdal
# Program Idea:
A menu planner where the user selects each item from the USDA food group plate (Fruit, Vegetable, Protein, Grain, Dairy).  

# Needed classes:
We will need to create a template food object that will store the food name, an arbitrary serving size, an arbitrary price, and the calorie count per serving of the food. 

# Needed functions:
Accessor and Mutator functions for the following attributes:
- Food Name
- Serving Size
- Price
- Calories per serving
Functions for reading from and to text files.  


# Program Flow
1. Read in data from food group text files into linked lists based on the food group (dairy text file will read into the dairy linked list, grain text file to the grain linked list, etc.)
2. Welcome Menu
3. Ask the user if they would want to create a dish or add an item to one of the food groups (Dairy, Grain, Protein, Vegetables, Fruits)

## Create a dish
1. Start one food group
2. Present a food option 
3. Ask the user if they want to select this food item for their dish, go forward to the next option, or go back to the previous option
4. Repeat steps 1-3 for all food groups (Dairy, Grain, Protein, Vegetables, Fruits)
5. Once completed with step 4, return the ingredients, as well as the total price and calories of the dish.  

## Add an item to a food group
1. Ask which food group the user wants to add to
2. Ask for the food name, price, calories per serving, and recommended serving size
3. Store all of the data gathered in step 2 in an object of the food group templated class (class Dairy, class Grain, etc.).  
4. Add the object at the end end of the list.  

# First Thoughts:
The required linked list can be implemented as a circular linked list when the user goes to select food.  

# Workflow
Throughout the production of the program, we plan to use the 'GitHub Flow' of pulling a feature branch off of the main branch to build a feature before merging back to the main branch once the feature is completed.  

# Expected Timeline
Due 1101.24 at 11:59PM  
## Due by 11/01/24
Final testing
Prettify the repository
- Deleting any unnecessary .cpp files
- Ensure all functions are well explained in the files using comments
- Finalize TEST_CASE.txt file
## Due by 10/25/24
Finalize feature to add an item to a food group LinkedList
Create a function to read food objects to a text file. 
	The file name will dictate what kind of object will be stored in the text file.  
## Due by 10/16/24 (Last day before Fall Break)
Template class file for food which contains:
- Accessor and Mutator Files
- Variables:
	- Food name (String)
	- Recommended Serving Size (Int)
	- Calories per serving size (Double)
	- Price (Double)

Create text file for sample data
Create a function to read food object variables from a text file:
- Text file title will dictate the datatype of the created object (dairy object, grain object, protein object, etc.)

