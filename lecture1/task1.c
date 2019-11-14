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
uint64_t swap64(uint64_t a)
{
	uint64_t res;
	res = (a&0x00000000000000FF) << 56;
	res += (a&0x000000000000FF00) << 40;
	res += (a&0x0000000000FF0000) << 24;
	res += (a&0x00000000FF000000) << 8;
	res += (a&0x000000FF00000000) >> 8;
	res += (a&0x0000FF0000000000) >> 24;
	res += (a&0x00FF000000000000) >> 40;
	res += (a&0xFF00000000000000) >> 56;
	return res;
}
uint16_t rgb888to565(uint32_t a)
{
	uint32_t res;
	res = (a&0x000000F8) >> 3;
	res += (a&0x0000FC00) >> 5;
	res += (a&0x00F80000) >> 8;
	return res;
}

int main(void)
{
    uint16_t a = 100;
    uint32_t b = 1234567800;
    uint64_t r,c = 12345678901234567;
    uint32_t ret,ret2;

    printf("   Exercise 1\n");
    ret = swap16(a);
    printf(" before: 0x%04x\n after:  0x%04x\n", a,ret);

    ret = swap32(b);
    printf(" before: 0x%08x\n after:  0x%08x\n", b,ret);

    r = swap64(c);
    ret = c >> 32;
    ret2 = c;
    printf(" before: 0x%08x%08x\n", ret,ret2);
    ret = r >> 32;
    ret2 = r;
    printf(" after:  0x%08x%08x\n", ret,ret2);

    printf("   Exercise 2\n");
    ret = rgb888to565(b);
    printf(" before: 0x%08x\n after:  0x%08x\n", b,ret);

    return 0;
}
