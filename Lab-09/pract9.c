#include <stdio.h>

#define SIZE 7

int main() {
    int hashTable[SIZE];
    int keys[20], n, i, index;

   
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter the keys (integers):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &keys[i]);

    for (i = 0; i < n; i++) {
        int key = keys[i];
        index = key % SIZE;  

    
        while (hashTable[index] != -1) {
            index = (index + 1) % SIZE;
        }

        hashTable[index] = key;
    }

    printf("\nFinal Hash Table (index : value):\n");
    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("%d : %d\n", i, hashTable[i]);
        else
            printf("%d : [empty]\n", i);
    }

    return 0;
}

