/*
Christian Won
Wonc@purdue.edu
Section 004
Eric Matson
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

 


int* randarr(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = rand();
    }
    return arr;
}
double selection(int* data, int n) {
    clock_t start = clock();
    for(int i = 0; i < n; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(data[j] < data[min]) {
                min = j;
            }
        }
        int temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}
double  bubble(int* data, int n) {
    int temp = 0;
    clock_t start = clock();
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(data[j] > data[j + 1]) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

double  insertion(int* data, int n) {
    clock_t start = clock();
    for(int i = 0; i < n; ++i) {
        int key = data[i];
        int j = i - 1;
        while(j >=0 && data[j] > key) {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }

    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;

}

double  linear(int* data, int n, int key) {
    clock_t start = clock();
    for(int i = 0; i < n; i++) {
        if(data[i] == key) {
            clock_t end = clock();
            return (double)(end - start) / CLOCKS_PER_SEC;
        }
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
    }
}

double  binary(int* data, int n, int key) {
    int low = 0;
    int high = n - 1;
    clock_t start = clock();
    while(low < high) {
        int mid = low + (high - low) / 2;
        if(data[mid] == key) {
            clock_t end = clock();
            return (double)(end - start) / CLOCKS_PER_SEC;
        }
        if(data[mid] < key) {
            low = mid + 1;
        }
        if(data[mid] > key) {
            high = mid - 1;
        }
    }
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}


void evaluation(int size) {
    int arr[size];
    randarr(arr, size);
    double  time1 = selection(arr, size);
    randarr(arr, size);
    double  time2 = insertion(arr, size);
    randarr(arr, size);
    double  time3 = bubble(arr, size);
    double  key = arr[rand() % (size + 1)];
    double  time4 = binary(arr, size, key);
    double  time5 = linear(arr, size, key);

    printf("==========================================\n");
    printf("Size = %d\n", size);
    printf("Selection ran in %.3f seconds\n", time1);
    printf("Insertion ran in %.3f seconds\n", time2);
    printf("Bubble ran in %.3f seconds\n", time3);
    printf("Binary Search ran in %.3f seconds\n", time4);
    printf("Linear Search ran in %.3f seconds\n", time5);
    
}


int main() {
    srand(time(NULL));
    evaluation(10);
    evaluation(50);
    evaluation(100);
    evaluation(500);
    evaluation(1000);
    evaluation(5000);
    evaluation(10000);
    evaluation(25000);
    evaluation(50000);

    return 0;
}
