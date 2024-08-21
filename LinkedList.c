#include<stdio.h>
#include <stdlib.h>

struct  Node{
  int data;
  struct Node* link;
};
struct Node* head = NULL;

void insertAtEnd(int data){
  if(head == NULL){
    head = (struct Node*) malloc(sizeof(struct Node));
    head -> data = data;
    head -> link = NULL;
  }else{
    struct Node* temp = head;
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode -> data = data;
    newNode -> link = NULL;

    while (temp-> link != NULL){
      temp = temp-> link;
    }
    temp-> link = newNode;   
  }
}
void printList(){
  if(head == NULL){
    printf("List is empty\n");
  }else{
    struct Node* temp = head;
    while (temp != NULL){
      printf("item:%d\n", temp->data);
      temp = temp-> link;
    } 
  }
}


int main(){
  void printList();
  void insertAtEnd(int);
  char option;
  int data;

  while (option != 'q'){
    printf("Q for quite \t I for insert \nS for show List \t\nEnter the option: ");
    scanf("%c", &option);
    switch (option){
      case 'S': printList();
      break;
      case 'I':
          printf("Enter the Number: ");
          scanf("%d", &data);
          insertAtEnd(data);
          printf("Data inserted at the end successfully!!\n");
      break;
      default:printf("Enter a valid option");
      break;
    }
    
  }
  
  return 0;
}