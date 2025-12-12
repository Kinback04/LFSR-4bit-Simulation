#include <stdio.h>
#include <stdint.h>

void printBinary4(unsigned int num) {
    for (int i = 3; i >= 0; i--) {
        unsigned int bit = (num >> i) & 1;
        printf("%d", bit);
    }
}

int main() {
    unsigned int lfsr = 0b0110; 

    printf("MO PHONG LFSR 4-BIT\n");
    printf("Buoc(t)\tNhi Phan\tThap Phan\n");

    for (int t = 0; t <= 16; t++) {
        printf("%d\t", t);
        printBinary4(lfsr);
        printf("\t\t%d\n", lfsr);

        unsigned int bit_x1 = (lfsr >> 0) & 1;
        unsigned int bit_x4 = (lfsr >> 3) & 1;

        unsigned int feedback = bit_x1 ^ bit_x4;

        lfsr = lfsr >> 1;
        lfsr = lfsr | (feedback << 3);
        lfsr = lfsr & 0xF; 
    }

    return 0;
}
