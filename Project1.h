#ifndef BST_included
#define BST_included

/* BST node */
typedef struct Node {
  struct Node *left;
  struct Node *right;
  char *str;
} BST;

extern int BSTDoCheck;

/* create a new binary search tree */
BST *BSTAlloc();

/* free memory associated with a binary search tree */
void BSTFree(BST *lp);

/* append a copy of str to the binary search tree */
void BSTPut(BST *lp, char *s);

/* delete all elements off of the binary search tree */
void BSTMakeEmpty(BST *lp);

/* print tree membership. Prints default message if message is NULL */
void BSTPrint(BST *lp, char *msg);

/*check bst consistency, always returns zero */
int BSTCheck(BST *lp);

#endif /* included */
