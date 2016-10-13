//
// Created by Eliezio Oliveira on 10/13/16.
//

#include "crc16.h"

#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(void) {
    uint8_t as[256];
    memset(as, 'A', sizeof(as));

    printf("-None-     : %04x\n", crc16_calc(NULL, 0));

    printf("'A'        : %04x\n", crc16_calc((const uint8_t *) "A", 1));

    printf("'123456789': %04x\n", crc16_calc((const uint8_t *) "123456789", 9));

    printf("'A' x 256  : %04x\n", crc16_calc(as, sizeof(as)));

    return 0;
}

