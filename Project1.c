/*
 *Author: Jose M. Perez Jr.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Project1.h"

int BSTDoCheck = 1;

#define doCheck(_lp) (BSTDoCheck && BSTCheck(_lp))

/* create a new Binary Search Tree */
BST *BSTAlloc(){
  BST *lp = (BST *)malloc(sizeof(BST));
  lp->first = lp->last = 0;
  doCheck(lp);
  return lp;
}

/* recycle a binary search tree, discarding all items it contains */
void BSTFree(BST *lp){
  doCheck(lp);
  BSTMakeEmpty(lp);
  free(lp);
}

/* Delete all elements off of the list */
void BSTMakeEmpty(BST *lp){

}

/* append a copy of str to the binary search tree */
void BSTPut(BST *lp, char *s){
}
