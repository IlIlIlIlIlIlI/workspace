char* lower(char *s)
{
    int len = strlen(s);
    char *ch = (char*)malloc(sizeof(char)*len);
    int top = -1;
    char *tmp = s;
    int num = 0;
    while(*tmp)
    {
        if((*tmp >='0' && *tmp <= '9') || (*tmp >='a' && *tmp <= 'z') || (*tmp >= 'A' && *tmp <= 'Z'))
        {
            if(*tmp >= 'A' && *tmp <= 'Z')
            {
                *tmp += 32;
            }
            ch[++top] = *tmp++;
        }
        else
        {
            num++;
            tmp++;
        }
    }
    if(len == num)
    {
        return "a";
    }
    /*if(num)
    {
        ch = (char*)realloc(ch,sizeof(char)*(len-num));
    }*/
    return ch;
}

bool isPalindrome(char* s) {
    if(*s == NULL || !(*(s+1)) || *s == ' ' )
    {
        return true;
    }
    s = lower(s);
    //printf("%s\n",s);
    int len = strlen(s);
    int mid = len/2,i,j;
    for(i = 0,j = len-1;i<mid,i<j;i++,j--)
    {
        if(s[i] == s[j])
        {
            continue;
        }
        else
        {
            break;
        }
    }
    if(i<mid && i<j)
    {
        return false;
    }
    else
    {
        return true;
    }
}
