int lengthOfLIS(int* nums, int numsSize){
    int *dp = malloc(sizeof(int) * numsSize);
    int count = 1;

    if (numsSize == 0) {
        return 0;
    }

    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        count = max(count, dp[i]);
    }
    return count;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}