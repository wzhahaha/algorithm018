/**
 两个数组的交集：快排+较短数组长度，值依次比较
 wangzhen
 2020-10-28
*/

int cmp(const void* _a, const void* _b) {
    int *a = _a, *b = (int*)_b;
    return *a == *b ? 0 : *a > *b ? 1 : -1;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);

    int numSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int *numIndex = (int*)malloc(sizeof(int) * numSize);

    int i = 0;
    int j = 0;
    int k = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            numIndex[k++] = nums1[i];
            i++;
            j++;
        }
    }
    *returnSize = k;
    return numIndex;
    
}
