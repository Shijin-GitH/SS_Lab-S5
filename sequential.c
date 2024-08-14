#include <stdio.h>

struct file
{
    int sb, length, blocks[100], allocated;
};

void main()
{
    int n, num, j;
    printf("Enter number of files: ");
    scanf("%d", &n);
    struct file file[n];
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        file[i].allocated = 1;
        printf("Enter starting block of file %d: ", i + 1);
        scanf("%d", &file[i].sb);
        temp = file[i].sb;
        printf("Enter length of file %d: ", i + 1);
        scanf("%d", &file[i].length);
        for (j = 0; j < file[i].length; j++)
            file[i].blocks[j] = temp++;

        for (j = 0; j < i; j++)
        {
            if (!file[j].allocated)
                continue;
            for (int k = 0; k < file[j].length; k++)
                for (int m = 0; m < file[i].length; m++)
                    if (file[i].blocks[m] == file[j].blocks[k])
                    {
                        file[i].allocated = 0;
                        break;
                    }
            if (!file[i].allocated)
                break;
        }
        if (!file[i].allocated)
            printf("This file was not allocated.\n");
    }

    printf("\nFiles:\nFile No.\tStarting Block\tLength\n");
    for (int i = 0; i < n; i++)
    {
        if (!file[i].allocated)
            continue;
        printf("%d\t\t%d\t\t%d\n", i + 1, file[i].sb, file[i].length);
    }

    printf("Enter file number to display: ");
    scanf("%d", &num);
    if (file[num - 1].allocated)
    {
        printf("Blocks Allocated: ");
        for (int i = 0; i < file[num - 1].length; i++)
            printf("%d ", file[num - 1].blocks[i]);
    }
    else
        printf("This block is not allocated.");
    printf("\n");
}
