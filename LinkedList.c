#include<stdio.h>
#include <stdlib.h>

struct  Node{
  int data;
  struct Node* link;
};
struct Node* head = NULL;
int getData(char msg[]){
  int data;
  puts(msg);
  scanf("%d", &data);
  return data;
}
void insertAtStart(int data){
  if(head == NULL){
    head = (struct Node*)malloc(sizeof(struct Node));
    head -> data = data;
    head -> link = NULL;
  }else{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> link = head;
    head = newNode;
  }
}
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
void deletNode(int data){

  if(head == NULL){
    printf("The list is empty\n");
    return;
  }else{
    struct Node* previous = head;
    struct Node* current = head-> link;

    if(current == NULL){
      if(previous-> data == data){
        free(current);
        head = NULL;
        printf("Node is deleted");
        return;
      }else{
        printf("Node with %d is not found", data);
        return;
      }
    }else{
      if(previous -> data == data){
          head = current;
          free(previous);
          printf("Node is deleted");
          return;
      }else{
        while (current != NULL)
        {
          if(current -> data == data){
            previous -> link = current -> link;
            free(current);
            printf("Node deleted");
            return;
          }
          previous = current;
          current = current -> link;
        }
        printf("Node %d is not found", data);
        return;
        
      }
    }   
  }
}
void reverList(){
  if(head == NULL) {
    printf("The List is empty\n");
    return;
  }
  struct Node* previous = NULL;
  struct Node* current = head;
  struct Node* next = current->link;

  while (next != NULL)
  {
    current-> link = previous;
    previous = current;
    current = next;
    next = current-> link;
  }
  current-> link = previous;
  head = current;
  printf("The list reversed!!\n");
}
void recursivePrint(struct Node* root){
  if(root == NULL){
    return;
  }
  printf("item: %d\n", root->data);
  recursivePrint(root -> link);
}
void recursiveReversePrint(struct Node* root){
  if(root == NULL){
    return;
  }
  recursiveReversePrint(root -> link);
  printf("Item: %d\n", root -> data);
}
int main(){
  void printList();
  void insertAtStart(int);
  void insertAtEnd(int);
  void deletNode(int);
  void reverList();
  void recursivePrint(struct Node*);
  void recursiveReversePrint(struct Node*);
  char option;
  int data;

  

  while (option != 'q'){
    printf("Q for quite \t\t\tI for insert \nS for show List \t\tD for delete \nH for insert at the head \tR for reverse the list\nP for recursive print \t\tO for recursive reverse print\nEnter the option: ");
    scanf("%c", &option);
    switch (option){
      case 'S': printList();
      break;
      case 'I':
          data = getData("Enter the number: ");
          insertAtEnd(data);
          printf("Data inserted at the end successfully!!\n");
      break;
      case 'D':
          data = getData("Enter the number: ");
          deletNode(data);
          printf("\n");
      break;
      case 'H':
          data = getData("Enter the number: ");
          insertAtStart(data);
          printf("Data inserted at the start!!\n");
      break;
      case 'R':
          reverList();
      break;
      case 'P':
          recursivePrint(head);
      break;
      case 'O':
          recursiveReversePrint(head);
      break;
      default:printf("Enter a valid option");
      break;
    }
    
  }
  
  return 0;
}