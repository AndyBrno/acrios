#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    FILE *file;
    char line[50];

    file = fopen("../12.txt", "r");
    if (file == NULL) {
        printf("Wrong file.\n");
        return 1;
    }

    int i, iDot, length, result = 0;
    while (fgets(line, 50, file)) {
        printf("%s\n", line);

        i = 0;
        iDot = 0;
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
                number -= 1;
                if (iDot >= 0) {
                    length = i - iDot - 1;
                } else {
                    length = i;
                }
                i++;
                while (line[i] == '?' || line[i] == '#') {
                    if (line[i] == '?') {
                        length++;
                    }
                    i++;
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

