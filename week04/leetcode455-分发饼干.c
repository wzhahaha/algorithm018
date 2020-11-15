/*
  快排+贪心
  贪心主要在于尽量省着分配饼干给小孩子，使得刚好满足即可；此处排序后依次对比是否满足即可
*/

int compare(const void *a, const void *b) {
    return (*(int*)a- *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    if (s == NULL || g == NULL) {
        return 0;
    }
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);
    int i = 0;
    int j = 0;
    while (i < gSize && j < sSize){
        if (g[i] <= s[j]) {
            i++;
        }
        j++;
    }
    return i;
}