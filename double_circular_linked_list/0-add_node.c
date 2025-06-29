#include "list.h"
#include <stdio.h>

/**
* add_node_end - Adds a node to the end of a circular doubly linked list
* @list: pointer to the head of the list
* @str: string to duplicate and store in the new node
* Return: pointer to the new node, or NULL on failure
*/
List *add_node_end(List **list, char *str)
{
List *new_node;
List *last;

new_node = malloc(sizeof(List));
if (!new_node)
return (NULL);

new_node->str = strdup(str);
if (!new_node->str)
{
free(new_node);
return (NULL);
}

if (!*list)
{
new_node->next = new_node;
new_node->prev = new_node;
*list = new_node;
return (new_node);
}

last = (*list)->prev;
new_node->next = *list;
new_node->prev = last;
last->next = new_node;
(*list)->prev = new_node;

return (new_node);
}

/**
* add_node_begin - Adds a node to the beginning of a circular doubly linked
* @list: pointer to the head of the list
* @str: string to duplicate and store in the new node
* Return: pointer to the new node, or NULL on failure
*/
List *add_node_begin(List **list, char *str)
{
List *new_node;

new_node = add_node_end(list, str);
if (new_node)
*list = new_node;
return (new_node);
}
