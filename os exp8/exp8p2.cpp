//Page Replacement using LRU
#include <stdio.h>

int main()
{
    int pages[25], frame[3], i, j = 0, k, available, n, fs, count = 0, lastused[25], min, index;
    printf("\nPage Replacement using LRU\n");

    printf("\nEnter the number of referenced strings: ");
    scanf("%d", &n);

    printf("\n\nEnter the referenced pages\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("\nEnter the frame size: ");
    scanf("%d", &fs);

    for (i = 0; i < fs; i++)
    {
        frame[i] = 0;
        lastused[i] = 0;
    }

    printf("\n\nPages\tframe\n");
    for (i = 0; i < n; i++)
    {
        available = 0;
        printf("%d\t", pages[i]);
        for (k = 0; k < fs; k++)
        {
            if (frame[k] == pages[i])
            {
                available = 1;
                lastused[k] = i + 1;
            }
        }
        if (available == 0)
        {
            min = lastused[0];
            index = 0;

            for (k = 1; k < fs; k++)
            {
                if (lastused[k] < min)
                {
                    min = lastused[k];
                    index = k;
                }
            }

            frame[index] = pages[i];
            lastused[index] = i + 1;
            count++;
        }

        for (k = 0; k < fs; k++)
        {
            printf("%d ", frame[k]);
        }
        printf("\n");
    }
    printf("\nTotal number of page faults are %d", count);
    return 0;
}
