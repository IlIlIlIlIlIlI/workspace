char* reverseWords(char* s) {
    char *begin, *end, *tmp_p;
    for (begin = end = s;; ++end) {
        if (*end == ' ' || *end == '\0') {
            // 一个单词
            for (tmp_p = end - 1; begin < tmp_p; begin++, tmp_p--) {
                *begin = *begin^*tmp_p;
                *tmp_p = *begin^*tmp_p;
                *begin = *begin^*tmp_p;
            }
            begin = end + 1;
        }
        if (*end == '\0')
            break;
    }
    return s;

}

char* reverseWords(char* s) {
    char *begin, *end, *tmp_p, tmp;
    for (begin = end = s;; ++end) {
        if (*end == ' ' || *end == '\0') {
            // 一个单词
            for (tmp_p = end - 1; begin < tmp_p; begin++, tmp_p--) {
                tmp = *begin;
                *begin = *tmp_p;
                *tmp_p = tmp;
            }
            begin = end + 1;
        }
        if (*end == '\0')
            break;
    }
    return s;

}

char* reverseWords(char* s) {
    char *str = s;
    char ch[20000];
    int top = -1,start = 0;
    if(strcmp(s,"") == 0)
    {
        return "";
    }
    while(*s)
    {
        if(*s != ' ')
        {
            ch[++top] = *s++;
        }
        else
        {
            int tmp = top;
            for(int i = start;i<=(start+tmp);i++)
            {
                str[i] = ch[top--];
            }
            start += tmp;
            s++;
            start += 2;
        }
    }
    int tmp = top;
    for(int i = start;i<=(start+tmp);i++)
    {
        str[i] = ch[top--];
    }
    return str;
}
