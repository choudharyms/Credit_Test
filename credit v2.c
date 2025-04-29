#include <stdio.h>
#include <stdbool.h> // Include for the bool type

int know_len(long l);
bool check_sum(long n);
void check_startn(long s);

int main(void)
{
    long cardn;

    // Get Card Number From User without cs50.h
    printf("Enter Card Number: ");
    if (scanf("%ld", &cardn) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    if (cardn < 1) {
        printf("Invalid input\n");
        return 1;
    }

    // Get Card length and check if length is valid
    int k = know_len(cardn);
    if (k != 13 && k != 15 && k != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Checksum Function Integration Based on Luhn's Algorithm
    if (check_sum(cardn)) // Check if checksum is valid
    {
        // Check For Starting Numbers only if checksum passes
        check_startn(cardn);
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

void check_startn(long s)
{
    long n = s;
    while (s > 100)
    {
        s = s / 10;
    }
    // Checking starting digits for the card type
    if ((s / 10 == 5) && (0 < s % 10 && s % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((s / 10 == 3) && (s % 10 == 4 || s % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (s / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int know_len(long l)
{
    int i = 0;
    while (l > 0)
    {
        l = l / 10;
        i++;
    }
    return i;
}

bool check_sum(long n)
{
    int sum1 = 0;
    int sum2 = 0;
    long x = n;
    int d1;
    int d2;
    int mod1;
    int mod2;
    do
    {
        // Remove last digit
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;
        // Remove second last digit
        mod2 = x % 10;
        x = x / 10;
        // 2 times second last digit and add digits to sum2
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (x > 0);
    int total = sum1 + sum2;
    // Checking Luhn Algorithm
    if (total % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    return 0;
}
// The code is a C program that checks the validity of credit card numbers using the Luhn algorithm.