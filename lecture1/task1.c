#include <stdio.h>
#include <stdint.h>

uint16_t swap16(uint16_t a)
{
	uint16_t res;
	res = (a&0x00FF) << 8;
	res += (a&0xFF00) >> 8;
	return res;
}
uint32_t swap32(uint32_t a)
{
	uint32_t res;
	res = (a&0x000000FF) << 24;
	res += (a&0x0000FF00) << 8;
	res += (a&0x00FF0000) >> 8;
	res += (a&0xFF000000) >> 24;
	return res;
}

int main(void)
{
    uint16_t a = 100;
    uint32_t b = 1234567800;
    uint32_t ret;

    ret = swap16(a);
    printf(" before: 0x%04x\n after: 0x%04x\n", a,ret);

    ret = swap32(b);
    printf(" before: 0x%04x\n after: 0x%04x\n", b,ret);

    return 0;
}
