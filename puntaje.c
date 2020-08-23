#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "invalid number of arguments");
        return 1;
    }
    int intvar;
    if (sscanf(argv[2], "%i", &intvar) != 1) {
        fprintf(stderr, "error - not an integer");
        return 1;
    }
    printf("%s: %s\n", argv[1], (intvar >= 7 ? "si" : "no"));
}
