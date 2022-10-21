#include <stdio.h>
#include <stdlib.h>

struct Node {
	int       num;
	struct    Node  *next;
};

void main() {
   struct Node* first  = NULL;
   struct Node* mid  = NULL;
   struct Node* last   = NULL;
   
   first     = (struct Node*) malloc(sizeof(struct Node));
   mid       = (struct Node*) malloc(sizeof(struct Node));
   last      = (struct Node*) malloc(sizeof(struct Node));

   first->num = 1;
   first->next = mid;

   mid->num = 5;
   mid->next = last;

   last->num = 3;
   last->next = NULL;
}