#include "search.h"

/**
* linear_skip - searches for a value in a sorted skip list
* @list: pointer to the head of the skip list
* @value: value to search for
* Return: pointer to the first node where value is located, or NULL
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *node, *jump;

if (list == NULL)
return (NULL);

node = list;
jump = list->express;

while (jump != NULL)
{
printf("Value checked at index [%lu] = [%d]\n", jump->index, jump->n);
if (jump->n >= value)
break;
node = jump;
jump = jump->express;
}

if (jump == NULL)
{
/* No more express lanes, go to the end of the list */
jump = node;
while (jump->next)
jump = jump->next;
}

printf(
"Value found between indexes [%lu] and [%lu]\n", node->index, jump->index
);

while (node && node->index <= jump->index)
{
printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
if (node->n == value)
return (node);
node = node->next;
}

return (NULL);
}
