#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX (10000)

void radixSort(int* arr, int n) {
    int res[MAX];   // 결과 배열
    int maxValue = 0;
    int exp = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    while (maxValue / exp > 0) 
    {
        int bucket[10] = { 0 };
        for (int i = 0; i < n; i++) {
            bucket[arr[i] / exp % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            bucket[i] += bucket[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            res[--bucket[a[i] / exp % 10]] = a[i];
        }

        for (int i = 0; i < n; i++) {
            arr[i] = res[i];
        }

        exp *= 10;
    }
}

int main(void) {
    int arr[MAX];
    int i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    radixSort(a, n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}