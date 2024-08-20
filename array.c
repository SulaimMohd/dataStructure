// Array : easy to access arranged in continous memory location. insertion order n, deletion order n fixed memory size may be waste mybe less 
#include <stdio.h>

int main() {
    int a[10];
    int n;

    // reading the limit number
    printf("Enter the limit number:");
    scanf("%d", &n);
  
    // reading the array
    for(int i = 0; i < n; i++) {
        printf("Enter the number %d: ", i+1);  // Added a colon and a space for better readability
        scanf("%d", &a[i]);
    }

    //printing the array 
    for (int i = 0; i < n; i++){
      printf("Number %d: %d\n", i+1, a[i]);
    }
    

    return 0;
}



 