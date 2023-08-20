#include<stdio.h>

/*
Using adjacency matrix 
    ->find adjacency node - O(v)...where v = |V|
    ->find if two nodes are connected - O(1)
    ->space-O(v^2)
    ->add a new edge or delete just use the vertices associated with it and change the record
*/

/*
Using a double pointer (also known as a pointer to a pointer) is a common approach to create and work 
with a dynamic 2D array in C or C++. Essentially, it involves creating an array of pointers where each 
pointer points to an array of elements. This allows you to allocate memory for each row independently, 
giving you flexibility in managing your 2D array.

Here's how you can use a double pointer to work with a 2D array:
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3;
    int cols = 4;

    // Step 1: Allocate memory for the array of pointers (rows)
    int **matrix = (int **)malloc(rows * sizeof(int *));

    // Step 2: Allocate memory for each row
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Step 3: Initialize values
    int count = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = count;
            count++;
        }  
    }

    // Step 4: Access and print values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Step 5: Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
 
*/

int main(){
     
}