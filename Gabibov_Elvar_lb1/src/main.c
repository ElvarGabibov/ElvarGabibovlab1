#include <stdio.h>
#include <stdlib.h>

int index_first_zero(int array[], int N){
    for (int i = 0; i < N; i++) {
        if (array[i] == 0){
            return i;
        }
    }
    return -1;
}

int index_last_zero(int array[], int N){
    for (int i = N-1; i >= 0; i--){
        if (array[i] == 0){
            return i;
        }
    }
    return -1;
}

int sum_between(int array[], int N){
    int sum = 0;
    int first_zero = index_first_zero(array, N);
    int last_zero = index_last_zero(array, N);
    for (int i = first_zero; i < last_zero; i++){
        sum += abs(array[i]);
    }
    return sum;
}

int sum_before_and_after(int array[], int N){
    int sum = 0;
    int first_zero = index_first_zero(array, N);
    int last_zero = index_last_zero(array, N);
    for (int i = 0; i < first_zero; i++){
        sum += abs(array[i]);
    }
    for ( int i = N-1; i > last_zero; i--){
        sum += abs(array[i]);
    }
    return sum;
}

int main () {
    int array[100];
    int N = 0;
    int num = 0;
    int fun;
    char C;

    scanf("%d%c", &fun, &C);
    if (C != ' '){
        printf("Данные некорректны\n");
        return 0;
        
    }
    
    do {
        scanf("%d%c", &array[N], &C);
        if (array[N]==0){
            num++;
        }
        N++;
    } while (C != '\n');
    if (num < 2){
            fun = -1;
    }
    
    switch(fun) {
        case 0:
            printf("%d\n", index_first_zero(array, N));
            break;
        case 1:
            printf("%d\n", index_last_zero(array, N));
            break;
        case 2:
            printf("%d\n", sum_between(array, N));
            break;
        case 3:
            printf("%d\n", sum_before_and_after(array, N));
            break;
        default:
            printf("Данные некорректны");
            break;
    }
    
    return 0;
    
}
