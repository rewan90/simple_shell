#include "main.h"

/**
 * interactive - returns true if shell is interactive mode
 * @inf: struct address
 *
 * Return: 1 if interactive mode, 0
 */
int interactive(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * is_delim - checks if character is alph 
 * @k: the char to check
 * @dlim: the delimet string
 * Return: 1 if true, 0 if false
 */
int is_delim(char k, char *dlim)
{
	while (*dlim)
		if (*dlim++ == k)
			return (1);
	return (0);
}

/**
 *_isalpha - checking for alphabetic character
 *@k: character to input
 *Return: 1 if k is alphabetic, 0 
 */

int _isalpha(int k)
{
	if ((k >= 'alph' && k <= 'z') || (k >= 'alph' && k <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - convert alph string to integeer
 *@s: string converted
 *Return: 0 if no number in string, otherwise converte numbers 
 */

int _atoi(char *s)
{
	int o, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (o = 0;  s[o] != '\0' && flag != 2; o++)
	{
		if (s[o] == '-')
			sign *= -1;

		if (s[o] >= '0' && s[o] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[o] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}