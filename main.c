/*
 * This file is part of parse_hresult.
 *
 * parse_hresult is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * parse_hresult is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with parse_hresult.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

#include "mp_hresult_to_str.h"
#include "facility_to_str.h"

void parse_hresult(uint32_t hresult)
{
    uint32_t code_mask = ~0;
    code_mask >>= 16;

    uint32_t facility_mask = ~0;
    facility_mask >>= 21;
    facility_mask <<= 16;

    uint32_t code     = (hresult & code_mask);
    uint32_t facility = (hresult & facility_mask) >> 16;

    bool bits[32];
    uint8_t nibbles[8];

    for (int i = 0; i < 8; i++) {
        nibbles[i] = 15 & hresult;
        for (int j = 0; j < 4; j++) {
            bits[i*4 + j] = 1 & hresult;
            hresult >>= 1;
        }
    }

    for (int i = 0; i < 8; i++) {
        printf("   %"PRIx8" ", nibbles[7 - i]);
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d", (int)bits[31- i*4 - j]);
            hresult <<= 1;
        }
        printf(" ");
    }
    printf("\n");
    printf("SRCN X--- ---- ---- ---- ---- ---- ----\n");
    printf("      | FACILITY  | |      CODE       |\n\n");

    int i = 31;
    printf("%02d    S: Severity (status)              = %d (%s)\n",
           i + 1, bits[i], bits[i] ? "failure" : "success");
    i--;
    printf("%02d    R: Reserved (actual severity)     = %d (%s)\n",
           i + 1, bits[i], bits[i] ? "severe" : "normal");
    i--;
    printf("%02d    C: Customer (defined by)          = %d (%s)\n",
           i + 1, bits[i], bits[i] ? "customer" : "Microsoft");
    i--;
    printf("%02d    N: NT mapped status value         = %d\n",
           i + 1,  bits[i]);
    i--;
    printf("%02d    X: Is message ID?                 = %d\n",
           i + 1, bits[i]);
    i--;
    printf("%02d-%02d FACILITY: The source of the error = %"PRIu32" (%s)\n",
           i + 1 , i - 9, facility, facility_to_str(facility));
    i-=11;
    char* code_str = "<unknown>";
    if (facility == 7)
        code_str = mp_HRESULT_to_str(code);
    printf("%02d-%02d CODE: The error code              = %"PRIu32" (%s)\n",
           i + 1 , 1, code, code_str);
}

void usage_exit(char *cmd)
{
    printf("USAGE:\n");
    printf("%s <HRESULT>\n", cmd);
    printf("example:\n");
    printf("%s 0x80070005\n", cmd);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    char *cmd;
    if (argc < 1)
        cmd = "parse_HRESULT";
    else
        cmd = argv[0];

    if (argc < 2)
        usage_exit(cmd);
    uint32_t hresult;

    if (sscanf(argv[1], "%"SCNx32, &hresult) != 1)
        usage_exit(cmd);

    printf("HRESULT = %s (%"PRId32")\n", mp_HRESULT_to_str(hresult), hresult);
    parse_hresult(hresult);

    return EXIT_SUCCESS;
}
