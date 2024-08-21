#include<stdio.h>
#include <stdlib.h>

struct  Node{
  int data;
  struct Node* link;
};
struct Node* head = NULL;
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

int main(){
  void printList();
  void insertAtStart(int);
  void insertAtEnd(int);
  void deletNode(int);
  char option;
  int data;

  while (option != 'q'){
    printf("Q for quite \tI for insert \nS for show List \t D for delete \nH for insert at the head \nEnter the option: ");
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
      case 'D':
          printf("Enter the node: ");
          scanf("%d", &data);
          deletNode(data);
          printf("\n");
      break;
      case 'H':
          printf("Enter the number: ");
          scanf("%d", &data);
          insertAtStart(data);
          printf("Data inserted at the start!!\n");
      break;
      default:printf("Enter a valid option");
      break;
    }
    
  }
  
  return 0;
}