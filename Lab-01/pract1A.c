#include<stdio.h>

int main()
{
    int n, i, oddSum=0, evenSum=0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d numbers:\n", n);
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    for(i=0; i<n; i++)
    {
        if(i%2==0)
            oddSum += arr[i];  
        else
            evenSum += arr[i]; 
    }
    
    printf("Sum of elements at odd positions: %d\n", oddSum);
    printf("Sum of elements at even positions: %d\n", evenSum);
    return 0;
}
