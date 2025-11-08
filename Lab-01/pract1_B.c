#include<stdio.h>

int binarySearch(int arr[], int n, int key)
{
    if(arr==NULL || n==0)
        return -1;
    int start=0, end=n-1;
    while(start <= end)
    {
        int mid = start + (end-start)/2;
        printf("Mid value at index %d: %d\n", mid, arr[mid]);
        if(arr[mid]==key)
            return mid;
        else if(key > arr[mid])
        {
            start = mid + 1;
            printf("Adjusting start to index %d\n", start);
        }
        else
        {
            end = mid - 1;
            printf("Adjusting end to index %d\n", end);
        }
    }
    return -1;
}

int main()
{
    int n, i, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if(n<=0) { printf("Array empty\n"); return 0; }
    int arr[n];
    printf("Enter elements in sorted order:\n");
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);
    printf("Enter element to search: ");
    scanf("%d",&key);
    int result = binarySearch(arr, n, key);
    if(result != -1)
        printf("Found at index %d\n", result);
    else
        printf("NULL\n");
    return 0;
}

