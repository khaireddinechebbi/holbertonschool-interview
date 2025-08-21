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
int word_len, total_len, s_len, *indices, *found, *count;
int i, j, k, idx, valid;

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

/* allocate helper arrays */
count = malloc(sizeof(int) * nb_words);
found = malloc(sizeof(int) * nb_words);
if (!count || !found)
{
free(indices);
free(count);
free(found);
return NULL;
}

for (i = 0; i <= s_len - total_len; i++)
{
/* reset found counts */
for (j = 0; j < nb_words; j++)
found[j] = 0;

valid = 1;
for (j = 0; j < nb_words; j++)
{
const char *sub = s + i + j * word_len;
/* try to match this substring with a word */
idx = -1;
for (k = 0; k < nb_words; k++)
{
if (strncmp(sub, words[k], word_len) == 0)
{
idx = k;
break;
}
}
if (idx == -1 || found[idx] >= 1)
{
valid = 0;
break;
}
found[idx]++;
}
if (valid)
indices[(*n)++] = i;
}

free(count);
free(found);

if (*n == 0)
{
free(indices);
return NULL;
}
return indices;
}
