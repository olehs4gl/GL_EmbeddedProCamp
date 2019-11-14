#include <stdio.h>
#include <stdint.h>

uint16_t swap16(uint16_t a)
{
	uint16_t res;
	res = (a&0x00FF) << 8;
	res += (a&0xFF00) >> 8;
	return res;
}

int main(void)
{
    uint16_t a = 100;
    uint16_t ret;

    ret = swap16(a);

    printf(" before: 0x%04x\n after: 0x%04x\n", a,ret);

    return 0;
}
