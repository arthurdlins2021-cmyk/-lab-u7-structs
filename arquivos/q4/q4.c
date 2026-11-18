#include <stdio.h>

union bytes {
    int i;
    unsigned char b[4];
};

int main(void) {
    union bytes dado;
    dado.i = 0x01020304;

    printf("%02X %02X %02X %02X\n", dado.b[0], dado.b[1], dado.b[2], dado.b[3]);
    return 0;
}
