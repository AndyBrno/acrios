#include "12.h"

int twelve() {
    FILE *file;
    char line[50];

    file = fopen("../12.txt", "r");
    if (file == NULL) {
        printf("Wrong file.\n");
        return 1;
    }

    int i, j, iDot, length, result = 0;
    while (fgets(line, 50, file)) {
        printf("%s\n", line);

        i = 0;
        iDot = -1;
        length = 0;
        result = 0;
        bool hashtag = false;
        int number = atoi(&line[14]);

        while (line[i] != ' ') {
            if (line[i] == '.') {
                iDot = i;
                if (length - number + 1 > 0) {
                    result = result + length - number + 1;
                }
                length = 0;
            } else if (line[i] == '#') {
                hashtag = true;
                number--;
                if (iDot >= 0) {
                    length = i - iDot - 1;
                } else {
                    if (i > number) {
                        length = number;
                    } else {
                        length = i;
                    }
                }
                i++;
                j = i;
                while ((line[j] == '?' || line[j] == '#') && j-i < number) {
                    if (line[j] == '?') {
                        length++;
                    } else {
                        number--;
                        length = j-i;
                    }
                    j++;
                }
                result = length - number + 1;
                break;
            }  else {
                length++;
            }

            i++;
        }
        if (!hashtag && length - number + 1 > 0) {
            result = result + length - number + 1;
        }

        printf("result: %d\n", result);
        printf("length: %d\n", length);
    }

    fclose(file);
    return 0;
}

