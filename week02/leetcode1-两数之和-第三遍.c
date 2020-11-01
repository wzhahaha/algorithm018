/**
 两数之和：参考网友解法--散列表
*/

#define MAX_SIZE 2048

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, hash[MAX_SIZE], *res = (int *)malloc(sizeof(int) * 2);
    memset(hash, -1, sizeof(hash));
    for (i = 0; i < numsSize; i++)
    {
        if (hash[(target - nums[i] + MAX_SIZE) % MAX_SIZE] != -1)
        {
            res[0] = hash[(target - nums[i] + MAX_SIZE) % MAX_SIZE];
            res[1] = i;
            *returnSize = 2;
            return res;
        }
        hash[(nums[i] + MAX_SIZE) % MAX_SIZE] = i;  //防止负数下标越界，循环散列
    }
    free(hash);
    *returnSize = 0;
    return res;
    
}