#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to the head of the list
 * @number: the number to insert into the list
 * Return: address of the new node, or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node, *current;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL); /* Memory allocation failed */

    new_node->n = number;
    new_node->next = NULL;

    /* Case 1: If the list is empty, the new node becomes the head */
    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    /* Case 2: If the new number is smaller than the head node */
    if (number < (*head)->n)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    /* Case 3: Traverse the list and insert the new node in the correct position */
    current = *head;
    while (current->next != NULL && current->next->n < number)
    {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    return (new_node);
}
