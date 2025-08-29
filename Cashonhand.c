#include <stdio.h>

int main() {
    int cash, thousands, five_hundreds, hundreds, fifties, twenties, tens, fives, ones;

    // Input the cash amount
    printf("Cash on hand: ");
    scanf("%d", &cash);

    // Calculate the number of each denomination
    thousands = cash / 1000;
    cash %= 1000;
    
    five_hundreds = cash / 500;
    cash %= 500;

    hundreds = cash / 100;
    cash %= 100;

    fifties = cash / 50;
    cash %= 50;

    twenties = cash / 20;
    cash %= 20;

    tens = cash / 10;
    cash %= 10;

    fives = cash / 5;
    cash %= 5;

    ones = cash;

    // Output the results
    printf("\nDenominations:\n");
    printf("1000 - %d\n", thousands);
    printf("500  - %d\n", five_hundreds);
    printf("100  - %d\n", hundreds);
    printf("50   - %d\n", fifties);
    printf("20   - %d\n", twenties);
    printf("10   - %d\n", tens);
    printf("5    - %d\n", fives);
    printf("1    - %d\n", ones);

    return 0;
}

