#include <stdio.h>
#include <stdlib.h>
#include "output.h"

int main(void)
{
    



    printf("\nEnter Output Length: \n");
    int b_len;
    scanf("%d", &b_len);
    int binary_array[b_len];



    printf("\nEnter Size of Register: \n");
    int r_len;
    scanf("%d", &r_len);
    printf("\n");

    int tap_positions[r_len];


    for (int s=0; s<r_len; s++)
    {
        printf("Enter Initial State Value %d:\n", s+1);
        scanf("%d", &binary_array[s]);
    }
    printf("\n");

    


    for (int t=0; t<r_len; t++)
    {
        
        printf("Is there a tap on Value %d? (y/n)\n", t+1);
        char c;
        scanf(" %c", &c);
        

        if (c == 'y')
        {
            tap_positions[t] = 1;
        }
        else
        {
            tap_positions[t] = 0;
        }
    }

    //call generates a string of n length via recursive XOR
    generate_output(binary_array, tap_positions, r_len, b_len);

    //////////////////////////////////////////////////////////////////////////
    printf("\n\nLFSR OUTPUT:\n");

    for (int p=0; p<b_len; p++)
    {
        printf("%d", binary_array[p]);
    }

    printf("\n\n");
    //////////////////////////////////////////////////////////////////////////

    return 0;
}