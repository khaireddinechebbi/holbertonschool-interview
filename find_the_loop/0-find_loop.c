#include "lists.h"

/**
* find_listint_loop - Detects the start of a loop in a singly linked list
* @head: Pointer to the head of the list
*
* Return: Address of the node where the loop starts, or NULL if no loop exists
*
* This function uses Floyd's Tortoise and Hare algorithm to detect a cycle.
* Once a loop is detected, it resets one pointer to the head and advances both
* pointers one step at a time until they meet at the start of the loop.
*/
listint_t *find_listint_loop(listint_t *head)
{
listint_t *slow = head, *fast = head;

while (fast && fast->next)
{
slow = slow->next;
fast = fast->next->next;

if (slow == fast)
{
slow = head;
while (slow != fast)
{
slow = slow->next;
fast = fast->next;
}
return (slow);
}
}
return (NULL);
}
