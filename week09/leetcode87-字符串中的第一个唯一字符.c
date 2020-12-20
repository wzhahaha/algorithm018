int firstUniqChar(char * s){
    if(s == NULL || strlen(s) == 0) return -1;
    int len = strlen(s);
    if(len == 1) return 0;
    int recode[26] = {0};
    //记录字符出现次数
    for(int i=0;i<len;i++){
        recode[s[i]-'a']++;
    }
    //找出第一个人出现一次的索引
    for(int i=0;i<len;i++){
        if(recode[s[i]-'a'] == 1){
            return i;
        }
    }
    return -1;
}

