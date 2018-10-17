char* reverseString(char* s) {
    int len=strlen(s);
    int mid=len/2;
    for(int i=0,j=len-1;i<mid,i<j;i++,j--){
        char tmp;
        tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }
    return s;
}



char* reverseString(char* s) {
    char *tmp = s;
    char ch[100005];
    int top = -1;
    while(*tmp)
    {
        ch[++top] = *tmp++;
    }
    tmp = s;
    int a = top;
    for(int i = 0;i<=a;i++)
    {
        s[i] = ch[top--];
    }
    return s;
}
