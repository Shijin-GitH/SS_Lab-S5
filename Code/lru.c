#include <stdio.h>

void main()
{
    int i, j, page_fault = 0, num_pages, num_frames, currenttime = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);
    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);
    int pages[num_pages], frames[num_frames], time[num_frames];
    printf("Enter page reference string: ");
    for (i = 0; i < num_pages; i++)
        scanf("%d", &pages[i]);
    for (i = 0; i < num_frames; i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("LRU Page Replacement Algorithm\n\n");
    for (i = 0; i < num_pages; i++)
    {
        int found = 0;
        for (j = 0; j < num_frames; j++)
        {
            if (pages[i] == frames[j])
            {
                found = 1;
                printf("Page Hit: Page: %d\n", pages[i]);
                time[j] = currenttime++;
                break;
            }
        }
        if (!found)
        {
            int lru = 0;
            for (j = 0; j < num_frames; j++)
            {
                if (frames[j] == -1)
                {
                    lru = j;
                    break;
                }
                if (time[j] < time[lru])
                    lru = j;
            }
            printf("Page Fault: Page: %d\n", pages[i]);
            page_fault++;
            frames[lru] = pages[i];
            time[lru] = currenttime++;
        }
        printf("Frames: \n");
        for (j = 0; j < num_frames; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }
    printf("Total page faults: %d\n", page_fault);
    printf("Total page hits: %d", num_pages - page_fault);
}