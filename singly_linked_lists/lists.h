#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

/**
 * struct list_s - Singly linked list
 * @str: String (malloc'ed string)
 * @len: Length of the string
 * @next: Points to the next node
 *
 * Description: Node structure for singly linked list
 */
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;

size_t list_len(const list_t *h);

#endif /* LISTS_H */
