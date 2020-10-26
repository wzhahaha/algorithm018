/*
 func: 加一
 users: wangzhen
 time: 2020-10-20
*/

int* plusOne(int* digits, int digitsSize, int* returnSize){

    for (int i = digitsSize - 1; i >= 0; i--) {
       if (digits[i] == 9) {
            digits[i] = 0;
        } else {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
    }
    
    int *digits_new = (int*)malloc(sizeof(int) * (digitsSize + 1));
    memset(digits_new, 0, (digitsSize + 1) * sizeof(int));
    digits_new[0] = 1;
    *returnSize = digitsSize + 1;
    return digits_new;
}