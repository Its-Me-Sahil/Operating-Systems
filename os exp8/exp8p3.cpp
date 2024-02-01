//Page Replacement using optimal
#include <stdio.h>
#include <limits.h>

int findOptimalPage(int pages[], int frame[], int start, int end, int fs)
{
    int result = -1, farthest = -1;
    for (int i = 0; i < fs; ++i)
    {
        int j;
        for (j = start; j < end; ++j)
        {
            if (frame[i] == pages[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    result = i;
                }
                break;
            }
        }
        if (j == end)
        {
            return i; // Page not found in future references
        }
    }
    return (result == -1) ? 0 : result;
}

int main()
{
    int pages[20], frame[3], i, j, k, available, n, fs, count = 0;

    printf("\nPage Replacement using optimal\n");
    printf("\nEnter the total number of referenced strings: ");
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
        frame[i] = 0; // Initialize frame to -1 to indicate an empty frame
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
            }
        }

        if (available == 0)
        {
            int index = findOptimalPage(pages, frame, i + 1, n, fs);
            frame[index] = pages[i];
            count++;
        }

        for (k = 0; k < fs; k++)
        {
            printf("%d ", frame[k]);
        }
        printf("\n");
    }
    printf("Total number of page faults are %d", count);
    return 0;
}
