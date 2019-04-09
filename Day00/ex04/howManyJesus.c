#include "header.h"

int search(char *string, char *txt, int prime)
{
    int stringLen = strlen(string);
    int txtLen = strlen(txt);
    int i, j;
    int stringHash = 0;
    int txtHash = 0;
    int hash = 1;
	int count = 0;

    for (i = 0; i < stringLen-1; i++)
        hash = (hash * 256) % prime;
    for (i = 0; i < stringLen; i++)
    {
        stringHash = (256 * stringHash + string[i]) % prime;
        txtHash = (256 * txtHash + txt[i]) % prime;
    }
    for (i = 0; i <= txtLen - stringLen; i++)
    {
        if ( stringHash == txtHash )
        {
            for (j = 0; j < stringLen; j++)
            {
                if (txt[i+j] != string[j])
                    break;
            }
            if (j == stringLen) {
				count++;
			}
        }
        if ( i < txtLen-stringLen )
        {
            txtHash = (256 * (txtHash - txt[i] * hash) + txt[i + stringLen]) % prime;
            if (txtHash < 0)
            txtHash = (txtHash + prime);
        }
    }
	return count;
}




int howManyJesus(char *bible, char *jesus)
{
	return search(jesus, bible, 101);
}
