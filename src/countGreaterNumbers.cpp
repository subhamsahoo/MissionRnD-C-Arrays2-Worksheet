/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
//time complexity is O(n),space complexity is O(1)
int myAtoi(char *str)
{
	int result = 0;
	for (int i = 0; str[i] != '\0'; ++i)
		result = result * 10 + str[i] - '0';
	return result;
}
int date_function(char *date)
{
	char *date1 = (char*)malloc(5);
	int c = 0;
	for (int i = 6; date[i] != '\0'; i++)
	{
		date1[c++] = date[i];
	}
	date1[c] = '\0';
	int date2 = myAtoi(date1);
	return date2;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (Arr == NULL)
		return NULL;
	int year, year1, count = 0;
	year1 = date_function(date);
	for (int i = 0; i<len; i++)
	{
		year = date_function(Arr[i].date);
		if (year>year1)
			count++;
	}
	return count;
}
