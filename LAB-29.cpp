
#include <stdio.h>

int main()
{
    int blockSize = 1024;
    int laneSize = 64;
    int totalLanes = 25;

    int rateLanes = blockSize / laneSize;
    int capacityLanes = totalLanes - rateLanes;

    int blocks = 0;
    int nonzero = 0;

    printf("SHA-3 BLOCK ANALYSIS\n");
    printf("Block Size: %d bits\n", blockSize);
    printf("Rate Lanes: %d\n", rateLanes);
    printf("Capacity Lanes: %d\n", capacityLanes);

    while(nonzero < capacityLanes)
    {
        blocks++;
        nonzero++;

        printf("After block %d: %d capacity lanes filled\n",
               blocks, nonzero);
    }

    printf("\nTotal blocks required: %d", blocks);

    return 0;
}

