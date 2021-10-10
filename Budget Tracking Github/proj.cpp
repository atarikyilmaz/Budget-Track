/**
* Projectname	:	151220152056_ABDULLAHTARIKYILMAZ_Project3BudgetTrack
* Author		:	Abdullah Tarik Yilmaz
* Date			:	2021/01/08
* Description	:	A program to report Budget Track
*/


#include <iostream>
#include "Category.h"
#include "Transaction.h"
#include <iomanip>

using namespace std;
 
/** 
 * Friend report function is called for produce a report listing the starting balance for each category, 
 * all of the transactions for the category, and the ending balance for the category. This function includes 2 for loops.
 * The inner loop checks BudgetCategory's and TransactionCategory's id number equal or not. If it is equal, program
 * do summation for balance and writes it to the report screen. If it is not equal, id number increase one and checks
 * for another id number equation.	
 */
void report(Category &c1, Transaction &t1)
{
    for(c1.it = c1.pairs.begin(); c1.it != c1.pairs.end(); c1.it++)
   {
   		cout << setw(65) << left << c1.it->second.categoryName << endl;
		cout << "Category:\t" << setw(3) << right << c1.it->second.categoryNumber;
		cout << "  Balance:"  << setprecision(2) << fixed << setw(9) << right << c1.it->second.categoryBalance << endl;
		     
		for(t1.itTran = t1.pairsTransaction.begin(); t1.itTran != t1.pairsTransaction.end(); t1.itTran++)
   		{
   			if(c1.it->second.categoryNumber==(*t1.itTran).transactionNumber)
   			{
   				c1.it->second.categoryBalance = c1.it->second.categoryBalance + (*t1.itTran).transactionAmount;
   				cout << "\t" << setw(10) << right << (*t1.itTran).transactionDate; 
   				cout << setprecision(2) << fixed << setw(9) << right << (*t1.itTran).transactionAmount << "  ";
   				cout << setprecision(2) << fixed << setw(9) << right <<  c1.it->second.categoryBalance; 
				cout << setw(65) << left << (*t1.itTran).transactionDescription << endl;
			}
   		}
   		
   		cout <<  "Category:\t" << setw(3) << right << c1.it->second.categoryNumber;
		cout <<   "  Balance:" << setprecision(2) << fixed << setw(9) << right << c1.it->second.categoryBalance << endl << endl << endl; 
   }         
}

/** 
 * Main function has one Category class object and one Transaction class object. Main reaches the friend report function and print the report.
 *@brief Main function for program.
 */
int main(int argc, char** argv) {
	
	Category c1; // An object was created from Category class 
	Transaction t1;	 // An object was created from Transaction class 
	report(c1, t1);
	
	return 0;
}
