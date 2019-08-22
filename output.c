#include <stdio.h>
#include <stdlib.h>

void generate_output(int binary_array[], int tap_pos[], int r_len, int b_len)
{
    int count = 0;
    int rec_counter = 0;
    int v = 0;

    //counts the taps to form the array
    for (int c=0; c<r_len; c++)
    {
        if (tap_pos[c] == 1)
        {
            count++;
        }
    }

    int rec[count];

    //save the positions of the taps
    for (int i=0; i<r_len; i++)
    {
        if (tap_pos[i] == 1)
        {
            rec[rec_counter] = i;
            rec_counter++;
        }
    }

    //XOR every bit at the tap positions for every bit in the designated string sequence
    for(int b=r_len; b<b_len; b++)
    {
        int XOR = binary_array[rec[0]+v];

        for (int j=1; j<count; j++)
        {
            XOR = XOR ^ binary_array[rec[j]+v];
        }
        v++;
        binary_array[b] = XOR;
    }
}