#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* getRemovableIndices(char* str1, char* str2, int* result_count) {
    int n = strlen(str1);
    int m = strlen(str2);
printf("\n n = %d", n);
printf("\n m = %d\n", m);

    // Allocate maximum possible size (n)
    int *result = (int*)malloc(sizeof(int) * n);
    *result_count = 0;

    // Length condition check
    if (n != m + 1) {
        result[0] = -1;
        *result_count = 1;
        return result;
    }

    // Try removing each index
    for (int i = 0; i < n; i++) {
        int j = 0, k = 0;

        while (j < n) {
            if (j == i) {
                j++;
                continue;
            }

            if (str1[j] != str2[k]) {
                break;
            }

            j++;
            k++;
        }

        // If full match found
        if (k == m) {
            result[*result_count] = i;
            (*result_count)++;
        }
    }

    // If no valid indices found
    if (*result_count == 0) {
        result[0] = -1;
        *result_count = 1;
    }

    return result;
}


int main() {
    char str1[] = "abdgggda";
    char str2[] = "abdggda";

    int count;
    int* indices = getRemovableIndices(str1, str2, &count);

    printf("[");
    for (int i = 0; i < count; i++) {
        printf("%d", indices[i]);
        if (i < count - 1) printf(", ");
    }
    printf("]\n");

    free(indices);
    return 0;
}