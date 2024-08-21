#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, i, max_size, head, total_seek_time = 0, direction;
    printf("Enter disk size: ");
    scanf("%d", &max_size);
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int requests[n], sorted_requests[n + 2];
    printf("Enter %d requests: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
        if (requests[i] < 0 || requests[i] >= max_size) {
            printf("Request %d can't be served.\n", requests[i--]);
        }
    }
    printf("Initial head position: ");
    scanf("%d", &head);
    printf("Enter head movement direction (0 for down, 1 for up): ");
    scanf("%d", &direction);

    // Sort the requests
    for (i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    int index = 0;
    if (direction == 1) { // Upward direction
        for (i = 0; i < n; i++) {
            if (requests[i] >= head) {
                sorted_requests[index++] = requests[i];
            }
        }
        sorted_requests[index++] = max_size - 1; // End of the disk
        sorted_requests[index++] = 0; // Start of the disk
        for (i = 0; i < n; i++) {
            if (requests[i] < head) {
                sorted_requests[index++] = requests[i];
            }
        }
    } else { // Downward direction
        for (i = n - 1; i >= 0; i--) {
            if (requests[i] <= head) {
                sorted_requests[index++] = requests[i];
            }
        }
        sorted_requests[index++] = 0; // Start of the disk
        sorted_requests[index++] = max_size - 1; // End of the disk
        for (i = n - 1; i >= 0; i--) {
            if (requests[i] > head) {
                sorted_requests[index++] = requests[i];
            }
        }
    }

    printf("Order of requests: %d->", head);
    for (i = 0; i < index; i++) {
        total_seek_time += abs(head - sorted_requests[i]);
        head = sorted_requests[i];
        printf("%d->", head);
    }
    printf("\nTotal seek time: %d\n", total_seek_time);
}