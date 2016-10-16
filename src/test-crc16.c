//
// Created by Eliezio Oliveira on 10/13/16.
//

#include "crc16.h"

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define DIMOF(a)    (sizeof(a) / sizeof(a[0]))

static const uint8_t single_a[]     = { 'A' };
static const uint8_t one_to_nine[]  = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
static uint8_t       multi_a[256];

static struct {
    const char *    name;
    const uint8_t * data;
    size_t          data_len;
    uint16_t        expected_crc;
} cases[] = {
    { "-None-",     NULL,        0,                   0x1d0f },
    { "A",          single_a,    sizeof(single_a),    0x9479 },
    { "123456789",  one_to_nine, sizeof(one_to_nine), 0xe5cc },
    { "A x 256",    multi_a,     sizeof(multi_a),     0xe938 },
};

int main(void) {
    int i;
    int error_count = 0;

    memset(multi_a, 'A', sizeof(multi_a));

    for (i = 0; i < DIMOF(cases); i++) {
        uint16_t crc16 = crc16_calc(cases[i].data, cases[i].data_len);
        printf("%-12s: %04x -> ", cases[i].name, crc16);
        if (crc16 == cases[i].expected_crc) {
            puts("OK");
        } else {
            printf(" WRONG! Expected = %04x\n", cases[i].expected_crc);
            ++error_count;
        }
    }

    return error_count;
}

