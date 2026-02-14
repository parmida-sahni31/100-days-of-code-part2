//Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

#include <stdio.h>

int main(){
    int n, temp, i;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i< n; i++){
        scanf("%d", &arr[i]);
    }

   
    int *first= &arr[0];
    int *last= &arr[n-1];

    while(first< last){
        temp = *first;
        *first = *last;
        *last= temp;

        first++;
        last--;
    }

    for(int i=0; i< n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}