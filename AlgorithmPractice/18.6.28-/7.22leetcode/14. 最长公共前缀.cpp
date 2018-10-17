char* longestCommonPrefix(char** strs, int strsSize) {
    char *p = strs[0];
    if(strsSize == 0)
    {
        return "";
    }
    for(int i = 0;i<strsSize;i++)
    {
        int j = 0;
        while(p[j] && strs[i][j] && p[j] == strs[i][j])
        {
            j++;
        }
        p[j] = '\0';
    }
    return p;
}
