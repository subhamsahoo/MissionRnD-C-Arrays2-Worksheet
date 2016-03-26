/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int myAtoi2(char *str)//Time complexity O(n) and space complexity O(n)
{
	int result = 0;
	for (int i = 0; str[i] != '\0'; ++i)
		result = result * 10 + str[i] - '0';
	return result;
}
int date_function2(char *date)
{
	char *date1 = (char*)malloc(5);
	int c = 0;
	for (int i = 6; date[i] != '\0'; i++)
	{
		date1[c++] = date[i];
	}
	date1[c] = '\0';
	int date2 = myAtoi2(date1);
	return date2;
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==NULL||B==NULL)
	return NULL;
	struct transaction *result = (struct transaction*)malloc((ALen + BLen)*sizeof(struct transaction));
	int i = 0, j = 0, size = 0;
	while (i<ALen&&j<BLen)
	{
		if ((date_function2(A[i].date)) <= (date_function2(B[j].date)))
		{
			result[size++] = A[i];
			printf("%d\n", result[size - 1].amount);
			i++;
		}
		else if ((date_function2(A[i].date))>(date_function2(B[j].date)))
		{
			result[size++] = B[j];
			printf("%d\n", result[size - 1].amount);
			j++;
		}


	}
	if (i != ALen && j == BLen)
	{
		while (i<ALen)
		{
			result[size++] = A[i];
			printf("%d\n", result[size - 1].amount);
			i++;
		}
	}
	else if (j != BLen && i == ALen)
	{
		while (j<BLen)
		{
			result[size++] = B[j];
			printf("%d\n", result[size - 1].amount);
			j++;
		}
	}
	return result;

}