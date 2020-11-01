/**
 有效的字母异位词
*/

/* 第一遍：暴力（回头看耗时和内存都是最好的）*/
#define MAX_LEN 256
bool isAnagram(char * s, char * t){
    if (strlen(s) != strlen(t)) {
        return false;
    }
    int length = strlen(s);
    int *hashTable =  (int*)malloc(sizeof(int) * MAX_LEN);
    memset(hashTable, 0, sizeof(int) * MAX_LEN);
    int temp;
    for (int i = 0; i < length; i++) {
        temp = s[i] + '0';
        hashTable[temp]++;
    }

    for (int j = 0; j < length; j++) {
        temp = t[j] + '0';
        hashTable[temp]--;
    }

    for (int k = 0; k < length; k++) {
        temp = t[k] + '0';
        if (hashTable[temp] != 0) {
            return false;
        }
    }
    return true;
}

/* 第二遍 （三次循环，性能最差）*/
#define MAX_LEN 26
bool isAnagram(char * s, char * t){
    if (strlen(s) != strlen(t)) {
        return false;
    }
    int length = strlen(s);
    int *hashTable =  (int*)malloc(sizeof(int) * MAX_LEN);
    memset(hashTable, 0, sizeof(int) * MAX_LEN);
    int temp;
    for (int i = 0; i < length; i++) {
        temp = s[i] - 'a';
        hashTable[temp]++;
    }

    for (int j = 0; j < length; j++) {
        temp = t[j] - 'a';
        hashTable[temp]--;
    }

    for (int k = 0; k < length; k++) {
        temp = t[k] - 'a';
        if (hashTable[temp] != 0) {
            return false;
        }
    }
    return true;
}

/* 第三遍 参考网友写法，比较巧妙 */
#define MAX_LEN 26
bool isAnagram(char * s, char * t){
    if (strlen(s) != strlen(t)) {
        return false;
    }
    int length = strlen(s);
    int *hashTable =  (int*)malloc(sizeof(int) * MAX_LEN);
    memset(hashTable, 0, sizeof(int) * MAX_LEN);
    for (int i = 0; i < length; i++) {
        hashTable[s[i] - 'a']++;
        hashTable[t[i] - 'a']--;
    }

    for (int k = 0; k < MAX_LEN; k++) {
        if (hashTable[k] != 0) {
            return false;
        }
    }
    return true;
}