#include "Transaction.h"
#include <fstream>
#include <iostream>

using namespace std;

Transaction::Transaction(int size)
			:transactionSize(size)
{
	readFromFile();
}

// readFromFile function reads values from "Transactions.txt" file and writes values inside struct arrayTran[]
void Transaction::readFromFile()
{
   	ifstream infile; 
   	infile.open("Transactions.txt");
   	for(int k=0; k<transactionSize; k++) 
   {
   		infile >> arrayTran[k].transactionNumber; // This line checks the next line if empty or not. 
   		if(infile!=NULL) 
   		{
   			infile >> arrayTran[k].transactionDate;
   			infile >> arrayTran[k].transactionAmount;
   			getline(infile,Transaction::arrayTran[k].transactionDescription);
   			sortTransaction(k); 
   		}
   }
	infile.close();	   
}

// Writes the 3 category values into the multiset
void Transaction::sortTransaction(int k)
{
   	pairsTransaction.insert((TransactionCategory{arrayTran[k].transactionNumber, arrayTran[k].transactionDate, arrayTran[k].transactionAmount ,arrayTran[k].transactionDescription}));
}
