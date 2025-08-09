#ifndef REGEX_H
#define REGEX_H

/**
 * regex_match - checks if a string matches a pattern containing . and *
 * @str: the string to scan
 * @pattern: the regular expression pattern
 *
 * Return: 1 if pattern matches the string, 0 otherwise.
 */
int regex_match(char const *str, char const *pattern);

#endif /* REGEX_H */
