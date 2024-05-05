#include <stdio.h>

int getSize(int *line, int *row) {
    FILE *file;

    file = fopen("../3.txt", "r");
    if (file == NULL) {
        printf("Wrong file.\n");
        return 1;
    }

    int c = fgetc(file);
    while (c != EOF) {
        if (c == '\n') {
            *line = *line + 1;
        } else {
            *row = *row + 1;
        }
        c = fgetc(file);
    }
    fclose(file);

    *line = *line + 1;
    *row = *row / *line;

    return 0;
}

int main(void) {
    int line = 0, row = 0;

    getSize(&line, &row);
    char scheme[line][row];

    FILE *file;
    file = fopen("../3.txt", "r");
    if (file == NULL) {
        printf("Wrong file.\n");
        return 1;
    }

    int c = getc(file), number = 0, result = 0, multiplier = 1, i = 0, j = 0;
    while (c != EOF) {
        scheme[i][j] = c;
        if (c == '\n') {
            i++;
            j = 0;
        } else {
            j++;
        }

        c = fgetc(file);
    }
    fclose(file);

    int numSize = 0, begin;

    for (int k = 0; k < row; ++k) {
        if (scheme[0][k] <= '9' && scheme[0][k] >= '0') {
            number = number * multiplier + (scheme[0][k] - 48);
            multiplier = 10;
            numSize++;
        } else {
            if (multiplier != 1) {
                if (scheme[0][k] != '.') {
                    result += number;
                } else {
                    if (k == numSize) {
                        begin = 0;
                    } else {
                        begin = k - numSize - 1;
                    }
                    while (scheme[1][begin] == '.' && begin <= k) {
                        begin++;
                    }
                    if (begin <= k) {
                        result += number;
                    }
                }
                multiplier = 1;
                number = 0;
                numSize = 0;
            }
        }
    }

    for (int k = 1; k < line - 1; ++k) {
        for (int l = 0; l < row; ++l) {
            if (scheme[k][l] <= '9' && scheme[k][l] >= '0') {
                number = number * multiplier + (scheme[k][l] - 48);
                multiplier = 10;
                numSize++;
            } else {
                if (multiplier != 1) {
                    if (scheme[k][l] != '.') {
                        result += number;
                    } else {
                        if (l == numSize) {
                            begin = 0;
                        } else {
                            begin = l - numSize - 1;
                        }
                        while ((scheme[k - 1][begin] == '.' && scheme[k + 1][begin] == '.') && begin <= l) {
                            begin++;
                        }
                        if (begin <= l) {
                            result += number;
                        }
                    }
                    multiplier = 1;
                    number = 0;
                    numSize = 0;
                }
            }

        }
    }

    for (int k = 0; k < row; ++k) {
        if (scheme[line - 1][k] <= '9' && scheme[line - 1][k] >= '0') {
            number = number * multiplier + (scheme[line - 1][k] - 48);
            multiplier = 10;
            numSize++;
        } else {
            if (multiplier != 1) {
                if (scheme[line - 1][k] != '.') {
                    result += number;
                } else {
                    if (k == numSize) {
                        begin = 0;
                    } else {
                        begin = k - numSize - 1;
                    }
                    while (scheme[line - 1][begin] == '.' && begin <= k) {
                        begin++;
                    }
                    if (begin <= k) {
                        result += number;
                    }
                }
                multiplier = 1;
                number = 0;
                numSize = 0;
            }
        }
    }

    printf("sucet cisel dielov: %d\n", result);
    return 0;
}