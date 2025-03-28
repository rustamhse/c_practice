// Создать функцию для поиска положения (индекса) первого положительного элемента произвольного массива целых чисел. 
// Тестовая программа:
// 1.  Создать и инициализировать 2 массива A[N1], B[N2]
// 2.  Найти положение положительного элемента массива. Полученный индекс разделяет массив на 2 части.
// 3.  Определить количество элементов в первой и второй частях массива
// 4.  Пункты 2 и 3 выполнить для массивов A и B

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int searchIndexOfFirstPositiveElement(int* array, int arr_size){
    int i = 0;
    int index = -1;
    while (i < arr_size){
        if (array[i] > 0) {
            index = i;
            break;
        }
        i++;
    }
    return index;
}

int main(){

    int N1, N2;
    printf("Введите размерности массивов N1 и N2 через пробел:\n");
    scanf("%d %d", &N1, &N2);

    int *a = (int*)malloc(N1 * sizeof(int));
    int *b = (int*)malloc(N2 * sizeof(int));

    if (a == NULL || b == NULL) {
        printf("ALLOCATION FAILED!\n");
        return -1;
    }

    srand(time(0));

    printf("Массив A:\n");
    
    for(int i = 0; i < N1; i++){
        a[i] = rand() % 21 - 10;
        printf("%d ", a[i]);
    }

    printf("\n");

    printf("Массив B:\n");

    for(int i = 0; i < N2; i++){
        b[i] = rand() % 21 - 10;
        printf("%d ", b[i]);
    }

    printf("\n");

    int a_index = searchIndexOfFirstPositiveElement(a, N1);
    int b_index = searchIndexOfFirstPositiveElement(b, N2);

    if(a_index != -1 && b_index != -1){

        int countFirstHalfOfA = 0;
        int countFirstHalfOfB = 0;
        int countSecondHalfOfA = 0;
        int countSecondHalfOfB = 0;

        for(int i = 0; i < a_index; i++){
            countFirstHalfOfA+=1;
        }

        for(int i = a_index; i < N1; i++){
            countSecondHalfOfA+=1;
        }

        for(int i = 0; i < b_index; i++){
            countFirstHalfOfB+=1;
        }

        for(int i = b_index; i < N2; i++){
            countSecondHalfOfB+=1;
        }

        printf("Кол-во элементов первой половины массива A = %d\n", countFirstHalfOfA);
        printf("Кол-во элементов второй половины массива A = %d\n", countSecondHalfOfA);
        printf("Кол-во элементов первой половины массива B = %d\n", countFirstHalfOfB);
        printf("Кол-во элементов второй половины массива B = %d\n", countSecondHalfOfB);
    }
    else printf("В одном из массивов не оказалось положительного числа!");

    free(a);
    free(b);
}