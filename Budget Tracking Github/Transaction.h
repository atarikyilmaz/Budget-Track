#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <set>

using namespace std;

/** 
 * TransactionCategory includes 3 variables to save "Transactions.txt" category values.
 *@brief A struct which is holding variables from "Transactions.txt" file
 */
struct TransactionCategory 
{
	int transactionNumber; //!< variable 1 to hold transactionNumber
	string transactionDate; //!< variable 2 to hold transactionDate
	float transactionAmount; //!< variable 3 to hold transactionAmount
	string transactionDescription; //!< variable 4 to hold transactionDescription
	
	/** 
 	 * A bool < operator function returns true if previous id number and date is smaller than next struct variable.
 	 * This function sorts the structure first by id number then by date.
 	 */
	bool operator<(const TransactionCategory &a) const
	{
    	return ( this->transactionNumber < a.transactionNumber || this->transactionDate < a.transactionDate );
	}
};

// To make this program work properly, a declaration of a class Category should be written here. 
// This is because class Category is referenced within the class Transaction using code: friend void report(Category &, Transaction &);.
class Category;

/** 
 * Transaction class.
 * Includes functions and variables to get values from .txt file and write them to a multiset container
 *@brief A class which includes functions and variables. 
 */
class Transaction
{
	public:
		
		// functions of Transaction class
		/** 
 		 *@brief A constructor.
 		 *@param size is an integer number which is equal to 500. This was made for limit the TransactionCategory array. 
 		 */
		Transaction(int size=500);
		/** 
 		 * A function to read values from .txt file.
 		 */
		void readFromFile();
		/** 
 		 * A function taking an integer and returning void.
 		 * This function sort and insert the values to a multiset container.
 		 */
		void sortTransaction(int);
		/** 
 		 * A friend function taking two class objects and returns void.
 		 * This function for write data to screen.
 		 */
		friend void report(Category &, Transaction &);
		
		// array of TransactionCategory
		/** 
 		 * An array of TransactionCategory to hold 500 category.
 		 */
		TransactionCategory arrayTran[500]; 
		 
	private:
		//const int transactionSize is made for limit the TransactionCategory array 
		const int transactionSize; //!< const int transactionSize is made for limit the TransactionCategory array 
		/** 
 		 * A multiset container definition.
 		 * This container taking one struct. Sort it ascending order by bool operator.
 		 */
		multiset <TransactionCategory > pairsTransaction; // A multiset container definition. This container taking one struct. Sort it ascending order by bool operator.
		/** 
 		 * A multiset container iterator definition.
 		 * This container iterator taking one struct. Used to reach container's variebles.
 		 */
		multiset <TransactionCategory >::iterator itTran; // A multiset container iterator definition. This container iterator taking one struct. Used to reach container's variebles.
		
};

#endif
