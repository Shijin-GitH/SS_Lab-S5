#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n, seekTime = 0, diff;
    printf("Enter the size of Queue: ");
    scanf("%d", &n);
    int queue[n + 1];
    printf("Enter the Queue: ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &queue[i]);
    printf("Enter the initial head position: ");
    scanf("%d", &queue[0]); /* head element */
    printf("\nMovement of Cylinders\n");
    for (int i = 0; i < n; i++)
    {
        diff = abs(queue[i + 1] - queue[i]);
        seekTime += diff;
        printf("%d -> ", queue[i]);
    }
    printf("%d", queue[n]);
    printf("\nTotal Seek Time: %d", seekTime);
    printf("\nAverage Seek Time = %f", (float)seekTime / n);
}