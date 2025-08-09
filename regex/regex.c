#include "regex.h"

/**
 * regex_match - check whether a given pattern matches a given string
 * @str: the string to scan
 * @pattern: the regular expression (supports '.' and '*')
 *
 * Return: 1 if the pattern matches the string, 0 otherwise.
 *
 * Implementation notes:
 * - '.' matches any single character.
 * - '*' matches zero or more of the preceding element.
 *
 * Recursive approach:
 *  - If the next char in pattern is '*', try:
 *      1) skipping "x*" (zero occurrences)
 *      2) if current char of str matches x (or x is '.'), consume one char
 *         from str and try again (still with "x*" in pattern).
 *  - Otherwise, require the current characters to match and advance both.
 */
int regex_match(char const *str, char const *pattern)
{
    /* If pattern is empty, match only if str is also empty */
    if (pattern == NULL || *pattern == '\0')
        return (str != NULL && *str == '\0') ? 1 : 0;

    /* check if next pattern char is '*' */
    int next_is_star = (*(pattern + 1) == '*');

    if (next_is_star)
    {
        /* Try zero occurrence of pattern[0] (skip "x*") */
        if (regex_match(str, pattern + 2))
            return 1;

        /* Try one or more occurrences: while current str matches pattern[0] */
        while (str != NULL && *str != '\0' &&
               (*pattern == '.' || *pattern == *str))
        {
            str++;
            if (regex_match(str, pattern + 2))
                return 1;
        }

        return 0;
    }
    else
    {
        /* No '*' follows. Current chars must match and advance both. */
        if (str != NULL && *str != '\0' &&
            (*pattern == '.' || *pattern == *str))
            return regex_match(str + 1, pattern + 1);
        else
            return 0;
    }
}
