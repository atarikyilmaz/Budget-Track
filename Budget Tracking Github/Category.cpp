#include "Category.h"
#include <fstream>
#include <iostream>

Category::Category(int size)
		:budgetSize(size)
{
	readFromFile(); 
}

// readFromFile function reads values from "Budget.txt" file and writes values inside struct array[]
void Category::readFromFile()
{
   	ifstream infile; 
   	infile.open("Budget.txt");
   	for(int k=0; k<budgetSize; k++) 
   {   
   		infile >> Category::array[k].categoryNumber; // This line checks the next line if empty or not. 
   		if(infile!=NULL) 
   		{
   			infile >> Category::array[k].categoryBalance;
   			getline(infile,Category::array[k].categoryName);
   			sortBudget(k); 
   		}
   }
	infile.close();	   
}

// Writes the 3 category values into the multimap
void Category::sortBudget(int k)
{
	pairs.insert(pair<int, BudgetCategory>(array[k].categoryNumber, array[k]));  
}
