//Problem: Write a program to check whether a given matrix is symmetric. 
//A matrix is said to be symmetric if it is a square matrix and is equal to its transpose 
//(i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).


#include <stdio.h>

int main()
{
    int n,m, isSymmetric=1;
    printf("rows and columns: ");
    scanf("%d", &n);
    scanf("%d", &m);

    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    if(m==n){
        for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] != arr[j][i]){
                isSymmetric= 0;
                break;
            }
        }
    }
    }
    else
        printf("not symmetric");

    return 0;

}