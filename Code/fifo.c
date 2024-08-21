#include <stdio.h>
int main()
{
    int num_frames, num_pages, i, j, page_faults = 0, current_frame = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);
    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);
    int frames[num_frames], pages[num_pages];
    printf("Enter the page reference string: ");
    for (i = 0; i < num_pages; i++)
    {
        scanf("%d", &pages[i]);
    }
    for (i = 0; i < num_frames; i++)
    {
        frames[i] = -1;
    }
    printf("\nPage Reference String: ");
    for (i = 0; i < num_pages; i++)
    {
        printf("%d ", pages[i]);
    }
    printf("\n");
    printf("\nFIFO Page Replacement Algorithm:\n");
    for (i = 0; i < num_pages; i++)
    {
        int page_found = 0;
        for (j = 0; j < num_frames; j++)
        {
            if (frames[j] == pages[i])
            {
                page_found = 1;
                printf("\nPage hit: Page %d\n", pages[i]);
                break;
            }
        }
        if (!page_found)
        {
            printf("\nPage Fault: Page %d\n", pages[i]);
            page_faults++;
            frames[current_frame] = pages[i];
            current_frame = (current_frame + 1) % num_frames;
        }
        printf("Frames: ");
        for (j = 0; j < num_frames; j++)
        {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", num_pages - page_faults);
    return 0;
}
