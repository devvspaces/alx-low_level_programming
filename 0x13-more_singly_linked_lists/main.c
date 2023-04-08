#include <stdio.h>
#include <stdlib.h>

char *print_bin(unsigned int value)
{
    char *s = malloc(sizeof(int) * 7);

    for (int i = sizeof(int) * 7; i >= 0; i--)
        s[(sizeof(int) * 7) - i] = ((value & (1 << i)) >> i) + '0';
    return (s);
}

int bin_dec(char *value)
{
    char s[2];
    int sum = 0;

    for (size_t i = 0; i <= sizeof(int) * 7; i++)
    {
        sprintf((char *)s, "%c", value[i]);
        sum += (atoi(s) * pow(2, ((sizeof(int) * 7) - i)));
    }
    
    return (sum);
}

int main()
{

    int n = 98;
    printf("Binary of %d: %s\n", 89, print_bin(0x89));
    printf("Decimal of %s: %d\n", print_bin(89), bin_dec(print_bin(0x89)));
    printf("Decimal of %x\n", 0x89 >> 3);

    return 0;
}
