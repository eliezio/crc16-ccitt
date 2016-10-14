//
// Created by Eliezio Oliveira on 10/13/16.
//

#include <stdio.h>
#include <stdint.h>

static uint16_t crc16_table[256];

static void build_table(void) {
    int i = 0;

    for (i = 0; i < 256; i++) {
        uint8_t x = (uint8_t) i;
        x ^= (x >> 4);
        crc16_table[i] = (uint16_t) (((unsigned short) (x << 12)) ^ ((unsigned short) (x << 5)) ^ ((unsigned short) x));
    }
}

int main(void) {
    int i = 0;

    build_table();

    putchar('\n');
    while (i < 256) {
        printf("0x%04x", crc16_table[i]);
        if ((++i % 8) == 0) {
            putchar('\n');
        } else {
            fputs(", ", stdout);
        }
    }

    return 0;
}
