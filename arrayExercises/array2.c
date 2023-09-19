#include <stdio.h>

int main () {
    int array[10];

    for (int i = 0; i < 10; i++) {
        printf("Input %d number: \n", i);
        scanf("%d", &array[i]);
    }

    printf("Numbers in array in reverse order is \n");
    for (int i = 9; i >= 0; i--) {
        printf("%d ", array[i]);
    }
}