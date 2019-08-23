//A fast C program to invert actual bits of a number.
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
//---------------------------------------------------------------------------------------------------------------------

#define TO_BASE_N (sizeof(unsigned)*CHAR_BIT + 1)
#define TO_BASE(x, b, p) my_to_base((char [TO_BASE_N]){""}, (x), (b), (p))
//---------------------------------------------------------------------------------------------------------------------

char *my_to_base(char *buf, unsigned i, int base, bool padZero) {
    char *s = &buf[TO_BASE_N - 1];
    *s = '\0';
    do {
        s--;
        *s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i % base];
        i /= base;
    } while (i);
    
    if(padZero)
    {
        if(s != buf)
        {
            do
            {
                s--;
                *s = '0';
            }
            while(s != buf);
        }
    }

    return s;
}
//---------------------------------------------------------------------------------------------------------------------

bool isPowerOfTwo(int v)
{
    return v && !(v & (v - 1));
}
//---------------------------------------------------------------------------------------------------------------------

//Round up to the next highest power of 2
int roundUpNextPowerOfTwo(int v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    
    return v;
}
//---------------------------------------------------------------------------------------------------------------------

int invertBits(int num)
{
    if((num == 0) || (isPowerOfTwo(num)))
    {
        return num - 1;
    }
    else
    {
        int mask = roundUpNextPowerOfTwo(num) - 1;
        return ((~num) & mask);
    }
}
//---------------------------------------------------------------------------------------------------------------------

int main()
{
	int testArray[] = {0, 34, 64, 127, 9, 288, 365, 56356, -2};
	int numElem = sizeof(testArray)/sizeof(testArray[0]);
	
	for(int i = 0; i < numElem; i++)
	{
	    int newNum = testArray[i];
	    int invNum = invertBits(newNum);
	    printf("%d\t %s\t %s\n", newNum, TO_BASE(newNum, 2, true), TO_BASE(invNum, 2, true));
	}
	
	return 0;
}
//---------------------------------------------------------------------------------------------------------------------