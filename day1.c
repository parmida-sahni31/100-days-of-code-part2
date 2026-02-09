/* Write a C program to insert an element x at a given 1-based position pos in an array of n integers. 
Shift existing elements to the right to make space. */

#include <stdio.h>

int main()
{
    int n, pos, element;

    scanf("%d", &n);

    int arr[n + 1];  

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &pos);      // position (1-based)
    scanf("%d", &element);  

    // shift elements to the right
    for(int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    // insert element
    arr[pos - 1] = element;

    n++; 

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
