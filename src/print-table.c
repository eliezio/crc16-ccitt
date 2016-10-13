//
// Created by Eliezio Oliveira on 10/13/16.
//

#include <stdio.h>
#include <stdint.h>

int main(void) {
    int i = 0;

    putchar('\n');
    while (i < 256) {
        uint8_t x = (uint8_t) i;
        x ^= (x >> 4);

        printf("0x%04x", ((unsigned short) (x << 12)) ^ ((unsigned short) (x << 5)) ^ ((unsigned short) x));
        if ((++i % 8) == 0) {
            putchar('\n');
        } else {
            fputs(", ", stdout);
        }
    }

    return 0;
}