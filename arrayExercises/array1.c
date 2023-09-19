#include <stdio.h>

int main () {
    int array[10];

    for (int i = 0; i < 10; i++) {
        printf("Input %d number: \n", i);
        scanf("%d", &array[i]);
    }

    printf("The numbers in the array: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
}