/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include "invert_bits.h"

/***********************************************************************************************************************
Defines/macros
***********************************************************************************************************************/
#define TO_BASE_N (sizeof(unsigned)*CHAR_BIT + 1)
#define TO_BASE(x, b, p) my_to_base((char [TO_BASE_N]){""}, (x), (b), (p))

/***********************************************************************************************************************
Internal functions
***********************************************************************************************************************/

static char *my_to_base(char *buf, unsigned i, int base, bool padZero) {
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

/***********************************************************************************************************************
Main function
***********************************************************************************************************************/
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