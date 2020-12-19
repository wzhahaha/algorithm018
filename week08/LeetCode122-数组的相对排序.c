/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* 此方法为哈希，当然也可以先排序然后比较 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int hash[1001] = { 0 };
    int *arr = (int*)malloc(sizeof(int) * arr1Size);
    int index = 0;
    for (int i = 0; i < arr1Size; i++) {
        hash[arr1[i]]++;
    }
    
    for (int j = 0; j < arr2Size; j++) {
        while (hash[arr2[j]] > 0) {
            arr[index++] = arr2[j];
            hash[arr2[j]]--;
        }
    }

    for (int k = 0; k < 1001; k++) {
        while (hash[k] > 0) {
            arr[index++] = k;
            hash[k]--;
        }
    }

    *returnSize = arr1Size;
    return arr;
}