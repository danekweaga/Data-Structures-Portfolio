#include "TNode.h"
#include "BST.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
   bst* node = makeBST();
   insert("ohio",node);
   insert("North Carolina",node);
   insert("South Carolina",node);
   insert("Virgina",node);
   insert("Texas",node);
   insert("Utah",node);
   insert("wyoming",node);
   printf("\n");
   printTNodeAll(node);
   printf("\n");
   printTNodeAll(node->root->left);
   printf("\n");
   printTNodeAll(node->root->right);
   return 0;
}
