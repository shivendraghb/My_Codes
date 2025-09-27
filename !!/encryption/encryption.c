#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

char* encryption(char* s) {
    int length = strlen(s);
    char* modified = malloc((length + 1) * sizeof(char));
    int modified_index = 0;

    // Remove spaces
    for (int i = 0; i < length; i++) {
        if (s[i] != ' ') {
            modified[modified_index++] = s[i];
        }
    }
    modified[modified_index] = '\0';

    int modified_length = strlen(modified);
    int rows = (int)floor(sqrt(modified_length));
    int columns = (int)ceil(sqrt(modified_length));
    if (rows * columns < modified_length) {
        rows = columns;
    }

    int result_length = modified_length + columns;
    char* result = malloc((result_length + 1) * sizeof(char));

    int result_index = 0;
    for (int col = 0; col < columns; col++) {
        for (int row = 0; row < rows; row++) {
            int pos = row * columns + col;
            if (pos < modified_length) {
                result[result_index++] = modified[pos];
            }
        }
        if (col < columns - 1) {
            result[result_index++] = ' ';
        }
    }
    result[result_index] = '\0';
    free(modified);
    return result;
}

int main() {
    printf("Enter the string to encrypt:\n");
    char* s = readline();

    char* result = encryption(s);

    printf("Encrypted string:\n%s\n", result);

    free(s);
    free(result);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = NULL;

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = NULL;
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = NULL;
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
