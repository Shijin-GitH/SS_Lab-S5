#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, i, max_size;
    printf("Enter disk size: ");
    scanf("%d", &max_size);
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int requests[n + 1], head, total_seek_time = 0;
    printf("Enter %d requests: ", n);
    for (i = 1; i < n + 1; i++)
    {
        scanf("%d", &requests[i]);
        if (requests[i] < 0 || requests[i] >= max_size)
            printf("Request %d can't be served.\n", requests[i--]);
    }
    printf("Initial head position: ");
    scanf("%d", &requests[0]);
    printf("Order of requests: %d->", requests[0]);
    for (i = 0; i < n; i++)
    {
        total_seek_time += abs(requests[i] - requests[i + 1]);
        printf("%d->", requests[i]);
    }
    printf("%d\n", requests[i]);
    printf("Total seek time: %d\n", total_seek_time);
}
