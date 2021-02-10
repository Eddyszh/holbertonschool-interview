#include "palindrome.h"
/**
 * is_palindrome - checks whether or not a given
 * unsigned integer is a palindrome
 * @n: the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	static unsigned long num, rev;

	if (n != 0)
	{
		num = n % 10;
		rev = rev * 10 + num;
		is_palindrome(n / 10);
	}
	if (n == rev)
		return (1);
	return (0);

}
