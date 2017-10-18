#ifndef BST_included
#define BST_included

/* BST node */
typedef struct Node_s {
  struct Node_s *left;
  struct Node_s *right;
  char *str;
}BST;

extern int BSTDoCheck;

/* create a new binary search tree */
BST *BSTAlloc();

/* free memory associated with a binary search tree */
BST *Remove(BST *lp, char *s);

/* append a copy of str to the binary search tree */
BST *BSTPut(BST *lp, char *s);

/*Insert names from a  text file to the binary search tree*/
BST *PutFromFile(BST *lp, char *s);

/*Insert names to a text file from the binary search tree*/
void PutToFile(BST *lp, char *s);

/*Helper method for PutToFIle*/
void PutToFileHelper(BST *lp, FILE *file);

/* print tree membership. Prints default message if message is NULL */
void PrintInorder(BST *lp);

/*check bst consistency, always returns zero */
int BSTCheck(BST *lp);

#endif /* included */
