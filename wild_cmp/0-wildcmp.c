#include "holberton.h"

/**
* wildcmp - compares two strings and returns 1 if they can be
* considered identical, otherwise returns 0.
* @s1: the first string
* @s2: the second string, may contain the special character '*'
*
* Return: 1 if identical, 0 otherwise
*/
int wildcmp(char *s1, char *s2)
{
if (*s1 == '\0' && *s2 == '\0')
return (1);

if (*s2 == '*')
{
if (wildcmp(s1, s2 + 1))  // try treating '*' as matching 0 characters
return (1);
if (*s1 != '\0' && wildcmp(s1 + 1, s2))  // try matching '*' with one or more characters
return (1);
}
else if (*s1 == *s2)
{
return (wildcmp(s1 + 1, s2 + 1));
}

return (0);
}
