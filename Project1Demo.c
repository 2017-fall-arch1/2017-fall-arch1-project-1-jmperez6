#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Project1.h"


int gets_n(char *s, int limit){
  char*p =s;
  char c;
  char *x;
  if(fgets(s, limit, stdin)){
    while((c=*p) && c != '\n'){
      p++;
    }
    if(c == '\n'){
      *p=0;
    }
  }
  return (p-s);
}


int main(void){
  char *temp;
  BST *bst = NULL;
  char buf[100];
  int x=0;
  char name[255];
  char filename[255];
  
  while (1) { //x!=1 | x!=2 | x!=3 | x!=4 | x!=5 |x!=6){
    
    printf("Please select an option:\n");
    printf("1: Add an employee name.\n");
    printf("2: Remove an employee name.\n");
    printf("3: List all employee names.\n");
    printf("4: Add employee names to BST from a file.\n");
    printf("5: Add employee names to a file from BST.\n");
    printf("6: Quit.\n");
    printf("");
    //gets_n(buf, 100);
    scanf("%d", &x);
    //fgets(x,100,stdin);
    printf("%d\n", x);
    switch ( x ) {
    case 1:
      printf("Please enter the employee's name.\n");
      scanf("%s", name);
      bst = BSTPut(bst, name);
      continue;
    case 2:
      printf("Please enter the employee's name you wish to remove.\n");
      scanf("%s", name);
      bst = Remove(bst, name);
      continue;
    case 3:
      PrintInorder(bst);
      continue;
    case 4:
      printf("Please enter the filename\n");
      scanf("%s", filename);
      bst = PutFromFile(bst, filename);
      continue;
    case 5:
      printf("Please enter the filename\n");
      scanf("%s", filename);
      PutToFile(bst, filename);
      continue;
    case 6:
      return 0;
    }/*
    if(x == 1){
      //char *name;
      printf("Please enter the full name of the employee you want to add.",&name);
      //scanf("%s", name);
      BSTPut(bst, name);
      }
      else if(x == 2){

      }
      else if(x == 3){
	PrintInorder(bst);
      }
      else if(x == 4){

      }
      else if(x == 5){

      }*/
    }
}
    
