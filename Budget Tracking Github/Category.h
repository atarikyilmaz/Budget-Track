#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <map>

using namespace std;

/** 
 * BudgetCategory includes 3 variables to save "Budget.txt" category values.
 *@brief A struct which is holding variables from "Budget.txt" file
 */
struct BudgetCategory
		{
			int categoryNumber; //!< variable 1 to hold categoryNumber
			float categoryBalance; //!< variable 2 to hold categoryBalance
			string categoryName; //!< variable 3 to hold categoryName
		};

class Transaction;

/** 
 * Category class.
 * Includes functions and variables to get values from .txt file and write them to a multimap container
 *@brief A class which includes functions and variables.
 */
class Category
{
	public:
		/** 
 		 *@brief A constructor.
 		 *@param size is an integer number which is equal to 50. This was made for limit the BudgetCategory array. 
 		 */
		Category(int size=50);
		/** 
 		 * A function to read values from .txt file.
 		 */
		void readFromFile(); 
		/** 
 		 * A function taking an integer and returning void.
 		 * This function sort and insert the values to a multimap container.
 		 */
		void sortBudget(int);
		/** 
 		 * A friend function taking two class objects and returns void.
 		 * This function for write data to screen.
 		 */
		friend void report(Category &, Transaction &);
		
		// array of BudgetCategory
		/** 
 		 * An array of TransactionCategory to hold 50 category.
 		 */
		BudgetCategory array[50]; 
		
		
	private:
		 // const int BudgetSize is made for limit the BudgetCategory array
		const int budgetSize;  //!< const int BudgetSize is made for limit the BudgetCategory array
		/** 
 		 * A multimap container definition.
 		 * This container taking one integer and one struct. Sort them ascending order automaticly.
 		 */
		multimap <int, BudgetCategory, less<int> > pairs; // A multimap container definition. This container taking one integer and one struct. Sort them ascending order automaticly.
		/** 
 		 * A multimap container iterator definition.
 		 * This container iterator taking one integer and one struct. Used to reach container's variebles.
 		 */
		multimap <int, BudgetCategory >::iterator it; // A multimap container iterator definition. This container iterator taking one integer and one struct. Used to reach container's variebles.
		
};

#endif
