#include <stdint.h>
#include <stdio.h>

typedef struct vectors
{
    uint32_t in;
    uint32_t expected;
}vec;

uint32_t bit_reverse32_bit(uint32_t x)
{
    uint32_t res = 0;
    for(uint8_t i = 0; i < 32; i++)
    {
        res <<= 1;
        res |= ((x >> i) & 1U);            
    }
    return res;
}


static const vec tests[] =
    {
        { 0x00000000u, 0x00000000u },
        { 0xFFFFFFFFu, 0xFFFFFFFFu },
        { 0x00000001u, 0x80000000u },
        { 0x80000000u, 0x00000001u },
        { 0x00000003u, 0xC0000000u },
        { 0x0000000Fu, 0xF0000000u },
        { 0xF0000000u, 0x0000000Fu },
        { 0x0000FFFFu, 0xFFFF0000u },
        { 0xFFFF0000u, 0x0000FFFFu },
        { 0x80000001u, 0x80000001u },   /* palindrome */
        { 0xAAAAAAAAu, 0x55555555u },
        { 0x55555555u, 0xAAAAAAAAu },
        { 0x00FF00FFu, 0xFF00FF00u },
        { 0x0F0F0F0Fu, 0xF0F0F0F0u },
        { 0x12345678u, 0x1E6A2C48u },
        { 0x01234567u, 0xE6A2C480u },
        { 0x89ABCDEFu, 0xF7B3D591u },
        { 0xDEADBEEFu, 0xF77DB57Bu }
    };


uint8_t reverse32_func(uint8_t size_test)
{
    uint8_t counter = 0;
    uint32_t final_val = 0;
    for(uint8_t i = 0; i < size_test; i++)
    {
        final_val = bit_reverse32_bit(tests[i].in);
        if(final_val == tests[i].expected)
            continue;
        else
        {
            counter++;
            printf("The Errors encountered are in input : 0x%08x   Expected : 0x%08x Output : 0x%08x\n", tests[i].in, tests[i].expected, final_val);
        }
    }
    if(counter)
        return 1;
    return 0;

}

int main(void)
{
    uint8_t counter = 0;
    size_t size_test = sizeof(tests)/sizeof(tests[0]);

    counter = reverse32_func(size_test);

    if(counter > 0)
        return counter;
    printf("No Errors\n");

    return 0;
}