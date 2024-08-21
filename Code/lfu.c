#include <stdio.h>

void main()
{
    int i, j, num_pages, num_frames, page_fault = 0;
    printf("Enter number of frames: ");
    scanf("%d", &num_frames);
    printf("Enter number of pages: ");
    scanf("%d", &num_pages);
    int pages[num_pages], frames[num_frames], freq[num_frames], time[num_frames];
    printf("Enter page reference string: ");
    for (i = 0; i < num_pages; i++)
        scanf("%d", &pages[i]);
    for (i = 0; i < num_frames; i++)
    {
        frames[i] = -1;
        freq[i] = 0;
        time[i] = 0;
    }

    printf("\nLFU Page replacement algorithm\n\n");
    for (i = 0; i < num_pages; i++)
    {
        int found = 0;
        for (j = 0; j < num_frames; j++)
        {
            if (pages[i] == frames[j])
            {
                found = 1;
                printf("Page Hit: Page: %d\n", pages[i]);
                freq[j]++;
                break;
            }
        }
        if (!found)
        {
            int lfu = 0;
            for (j = 0; j < num_frames; j++)
            {
                if (frames[j] == -1)
                {
                    lfu = j;
                    break;
                }
                if (freq[j] < freq[lfu] || (freq[lfu] == freq[j] && time[j] < time[lfu]))
                    lfu = j;
            }
            printf("Page Fault: Page: %d\n", pages[i]);
            page_fault++;
            frames[lfu] = pages[i];
            freq[lfu] = 1;
            time[lfu] = i;
        }
        printf("Frames: \n");
        for (j = 0; j < num_frames; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }
    printf("Total page faults: %d\n", page_fault);
    printf("Total page hits: %d", num_pages - page_fault);
}