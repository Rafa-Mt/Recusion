#include <stdio.h> 
#include <stdlib.h>

int combinations = 0;

void getCombinations(int array[], int data[], int start, int end, int index, int range) {
    if (index == range) {
        printf("{ ");
        for (int i=0; i<range; i++)
            printf("%d ", data[i]);
        printf("}\n");
        combinations++;
        return;
    }
    for (int i=start; i<=end && end-i+1 >= range-index; i++) {
        data[index] = array[i];
        getCombinations(array, data, i+1, end, index+1, range);
    }
}

void printCombination(int array[], int size, int range) {
    int data[range];
    getCombinations(array, data, 0, size-1, 0, range);
}

int getRange(int size) {
    int range;
    printf("Ingrese rango de las combinaciones: ");
    scanf("%d", &range);
    if (range > size || range < 1) {
        printf("Rango invalido \n");
        return size;
    }
    return range;
}

void printArray(int array[], int size) {
    printf("Para el array [ ");
    for (int i=0; i<size; i++) 
        printf("%d, ", array[i]);
    printf("] las combinaciones son: \n");
}

int main() {
    int array[] = {1,2,3,4,5};
    int range = getRange(sizeof(array)/sizeof(array[0]));
    printArray(array, sizeof(array)/sizeof(array[0]));
    printCombination(array, sizeof(array)/sizeof(array[0]), range);
    printf("Numero total de combinaciones: %d\n", combinations);
}