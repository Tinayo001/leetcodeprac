#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int* indices = (int*)malloc(2 * sizeof(int));

	int* numIndices = (int*)malloc(100000 * sizeof(int));

	for (int i = 0; i < 100000; i++)
	{
		numIndices[i] = -1;
	}
	for (int i = 0; i < numsSize; i++)
	{
		int complement = target - nums[i];

		if (numIndices[complement] != -1 && numIndices[complement] != i)
		{
			indices[0] = numIndices[complement];
			indices[1] = i;
			*returnSize = 2;
			free(numIndices);
			return indices;
		}
		numIndices[nums[i]] = i;
	}
	returnSize = 0;
	free(numIndices);
	return NULL;
}
int main()
{
        int nums[] = {2, 7, 11, 15};
        int target = 9;
        int numsSize = sizeof(nums) / sizeof(nums[0]);
        int returnSize;
        int* result = twoSum(nums, numsSize, target, &returnSize);

        if (result != NULL)
        {
                printf("[%d, %d]\n", result[0], result[1]); // Output: [0, 1] (indices of numbers 2 and 7)
                free(result);
        }
        else
        {
                printf("No solution found.\n");
        }
        return 0;
}

