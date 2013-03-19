#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utf8.h"

#define BOM 1  // set to 1 to include utf8 BOM

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("You must supply a filename\n");
        return -1;
    }

    FILE *latin1file;

    if ((latin1file = fopen(argv[1], "r")) == NULL) {
        printf("Unable to open file %s\n", argv[1]);
    } else {
        char line[4096];

        #if BOM == 1
            printf("%c", 0xEF);
            printf("%c", 0xBB);
            printf("%c", 0xBF);
        # endif

        while (!feof(latin1file)) {
            if (fgets(line, 4096, latin1file) != NULL) {
                int i;
                for (i = 0; i < strlen(line); i++) {
                    unsigned char current = line[i];
                    int *bytes = code_point_to_utf8(current);

                    char byte_chars[5] = {'\0', '\0', '\0', '\0', '\0'};

                    int q;
                    for (q = 0; q < 4; q++) {
                        if (bytes[q] != -1) {
                            byte_chars[q] = bytes[q];
                        }
                    }

                    printf("%s", byte_chars);
                }
            }
        }
    }
}