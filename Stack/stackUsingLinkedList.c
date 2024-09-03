#include<stdio.h>
#include<stdlib.h>
struct Node {
  int data;
  struct Node* link;
};
struct Node* top = NULL;

int getData(char msg[]){
  int data;
  puts(msg);
  scanf("%d", &data);

  return data;
}

void pushData(int data){
  struct Node* newNoede = (struct Node*) malloc(sizeof(struct Node*));

  newNoede -> data = data;
  newNoede -> link = top;
  top = newNoede;

  printf("Data pushed successfully! \n");
  return;
}

void popData(){
  if(top == NULL) {
    printf("The stack is underflow!!\n");
    return;
  }

  printf("Data: %d\n", top -> data);
  top = top -> link;
  return;
}

void topElement(){
  if(top == NULL){
    printf("The stack is underflow!!\n");
    return;
  }

  printf("Top element: %d\n", top -> data);
  return;
}

int main(){

  int getData(char[]);
  void pushData(int);
  void popData();
  void topElement();

  char option;
  int data;


  while (option != 'q')
  {
    printf("I for Push \t\t G for Pop \nT for the Top \t\t Q for Quite ");
    printf("\nEnter option:");
    scanf(" %c", &option);
    switch (option){
      case 'I':
          data = getData("Enter the Data:");
          pushData(data);
        break;
      case 'G':
          popData();
        break;
      
      case 'T':
          topElement();
        break;
      
      default:
          printf("Please enter a valid option!! \n");
        break;
      };
  }


  


  return 0;
}