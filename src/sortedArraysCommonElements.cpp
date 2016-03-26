/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int check(char *date1, char *date2)
{
	int result = 1;
	for (int i = 0; date1[i] != '\0'&&date2 != '\0'; i++)
	{
		if (date1[i] != date2[i])
		{
			result = 0;
			break;
		}
	}
	return result;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	int create = 0;
	struct transaction *result1 = (struct transaction*)malloc(((ALen>BLen) ? ALen : BLen)*sizeof(struct transaction));
	for (int i = 0; i<ALen; i++)
	{
		for (int j = 0; j<BLen; j++)
		{
			if ((check(A[i].date, B[j].date)) == 1)
			{
				result1[create++] = A[i];
			}
		}
	}
	if (create != 0)
		return result1;
	else
		return NULL;
}