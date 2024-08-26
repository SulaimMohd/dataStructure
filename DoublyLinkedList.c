#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
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
    head = (struct Node*) malloc(sizeof(struct Node));
    head -> data = data;
    head -> left = NULL;
    head -> right = NULL;
    return;
  }
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode -> data = data;
  newNode -> right = head;
  head -> left = newNode;

  head = newNode;
  printf("Node created successfully");
}

void printList(){
  if(head == NULL){
    printf("This list is empty!");
    return;
  }
  struct Node* temp = head;
  printf("List Items: ");
  while (temp != NULL){
    printf("%d, ", temp-> data);
    temp = temp-> right;
  }
}
int main(){
  int getData(char[]);
  void insertAtStart(int);
  void printList();
  char option;
  int data;
  while (option != 'q'){
    printf("\nI for insert Node \t S for showlist\nQ for quite \n");
    printf("Enter the option: ");
    scanf("%c", &option);

    switch (option)
    {
    case 'I': 
        data = getData("Enter the Data");
        insertAtStart(data);
    break;
    case 'S':
        printList();
    break;
    default:
          printf("Enter a valid Option!");
      break;
    }
  }
  

  return 0;
}