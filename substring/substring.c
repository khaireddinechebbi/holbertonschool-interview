#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
* find_substring - finds all starting indices where concatenation of words appear
* @s: the string to scan
* @words: array of words
* @nb_words: number of words
* @n: pointer to number of results
*
* Return: allocated array of indices, or NULL if none
*/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
int word_len, total_len, s_len, *indices;
int i, j;
char **unique;
int *expected, *seen, unique_count;

*n = 0;
if (!s || !words || nb_words == 0)
return NULL;

word_len = strlen(words[0]);
if (word_len == 0)
return NULL;

s_len = strlen(s);
total_len = word_len * nb_words;
if (s_len < total_len)
return NULL;

indices = malloc(sizeof(int) * s_len);
if (!indices)
return NULL;

/* --- Build unique word list with frequencies --- */
unique = malloc(sizeof(char *) * nb_words);
expected = calloc(nb_words, sizeof(int));
seen = calloc(nb_words, sizeof(int));
if (!unique || !expected || !seen)
{
free(indices);
free(unique);
free(expected);
free(seen);
return NULL;
}

unique_count = 0;
for (i = 0; i < nb_words; i++)
{
int found = -1;
for (j = 0; j < unique_count; j++)
{
if (strcmp(words[i], unique[j]) == 0)
{
found = j;
break;
}
}
if (found == -1)
{
unique[unique_count] = (char *)words[i];
expected[unique_count] = 1;
unique_count++;
}
else
{
expected[found]++;
}
}

/* --- Scan string --- */
for (i = 0; i <= s_len - total_len; i++)
{
for (j = 0; j < unique_count; j++)
seen[j] = 0;

int ok = 1;
for (j = 0; j < nb_words; j++)
{
const char *sub = s + i + j * word_len;
int k, matched = 0;

for (k = 0; k < unique_count; k++)
{
if (strncmp(sub, unique[k], word_len) == 0)
{
seen[k]++;
if (seen[k] > expected[k])
ok = 0;
matched = 1;
break;
}
}
if (!matched || !ok)
{
ok = 0;
break;
}
}
if (ok)
indices[(*n)++] = i;
}

free(unique);
free(expected);
free(seen);

if (*n == 0)
{
free(indices);
return NULL;
}
return indices;
}
