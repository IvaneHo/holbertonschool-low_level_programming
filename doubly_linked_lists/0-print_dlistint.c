/*
 * File: 0-print_dlistint.c
 * Auth: Ivane
 */

 #include "lists.h"
 #include <stdio.h>
 
 /**
  * print_dlistint - Prints all the elements of a dlistint_t list.
  * @h: The head of the dlistint_t list.
  *
  * Return: The number of nodes in the list.
  */
 size_t print_dlistint(const dlistint_t *h)
 {
     size_t nodes = 0;
 
     while (h)
     {
         printf("%d\n", h->n);
         nodes++;
         h = h->next;
     }
 
     return (nodes);
 }
 