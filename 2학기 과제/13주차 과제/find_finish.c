#include <stdio.h>
#include "header.h"
extern data* insert();

data* find_finish(data* node)
{
    while (1)
    {
        if (node->next == NULL)
            return node;
        node = node->next;
    }
}