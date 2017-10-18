/*
 *Author: Jose M. Perez Jr.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Project1.h"

int BSTDoCheck = 1;

#define doCheck(_lp) (BSTDoCheck && BSTCheck(_lp))

/* create a new Binary Search Tree */
BST *BSTAlloc(){
  BST *lp = (BST *)malloc(sizeof(BST));
  lp->left = lp->right = 0;
  return lp;
}


/* append a copy of str to the binary search tree */
BST *BSTPut(BST *lp, char *s){
  if((lp == NULL)||(lp->str == NULL)){
    char *name = malloc(255);
    strcpy(name, s);
    lp = (BST*)malloc(255);
    lp->str = name;
    
    return lp;
  }
  else if(strcmp(s, lp->str) < 0){
    lp->left = BSTPut(lp->left, s);
  }
  else if(strcmp(s, lp->str) > 0){
    lp->right = BSTPut(lp->right, s);
  }
  return lp;

}

char *smallestNode(BST *lp){
  if(lp->left == NULL){
    return lp->str;
  }
  else{
    return smallestNode(lp->left);
  }
}

char *largestNode(BST *lp){
  if(lp->right == NULL){
    return lp->str;
  }
  else{
    return largestNode(lp->right);
  }
}


BST *Remove(BST *lp, char *name){
  if(lp == NULL){
    printf("Did not find name.");
    return lp;
  }
  else if(strcmp(lp->str, name) == 0){//found the name in the tree
    if(lp->right != NULL){//has right child, so search for 'smallest' child in right subtree.
      char *minNode = smallestNode(lp->right);
      lp->str = minNode;
      lp->right = Remove(lp->right, minNode);
    }
    else if(lp->left != NULL){//has left child, so search for 'largest' child in left subtree
      char *maxNode = largestNode(lp->left);
      lp->str = maxNode;
      lp->left = Remove(lp->left, maxNode);
    }
    else{//found the name and it is a leaf, so make it null.
      lp = NULL;
    }
      
  }
  else if(strcmp(lp->str, name) > 0){//name comes before current string (left subtree)
    lp->left = Remove(lp->left, name);
  }
  else if(strcmp(lp->str, name) < 0){ //name comes after current string (right subtree)
    lp->right = Remove(lp->right, name);
  }
  return lp;

}

void PrintInorder(BST *lp){
  if(lp==NULL ||lp->str==NULL){
    return;
  }
  PrintInorder(lp->left);
  printf("%s\n", lp->str);
  PrintInorder(lp->right);
}




int BSTCheck(BST *lp){
  BST *ip;
  ip = lp;
  if(!ip){
    assert(lp->left == 0);
    assert(lp->right == 0);
  }
  else{
    int left;
    int right;
    left = BSTCheck(lp->left);
    right = BSTCheck(lp->right);
  }
  return 0;
}

BST *PutFromFile(BST *lp, char *s){
  char c[255];
  FILE *file;
  file = fopen(s, "r");
  if(file != NULL){
    while( fgets(c, sizeof(c), file)){
      lp = BSTPut(lp, c);
    }
  }
  return lp;
      
}

void PutToFile(BST *lp, char *s){
  FILE *file;
  file = fopen(s, "w");
  if(file != NULL){
    PutToFileHelper(lp, file);
    fclose(file);
  }
  
}
void PutToFileHelper(BST *lp, FILE *file){
  if(lp==NULL || lp->str==NULL){
    return;
  }
  PutToFileHelper(lp->left, file);
  fprintf(file, "%s\n", lp->str);
  PutToFileHelper(lp->right, file);
}
