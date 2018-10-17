char* toLowerCase(char* str) {
    int length = strlen(str);
    int i;
    for (i=0; i<length; i++) {
        if ( 'A'<=str[i] && str[i]<= 'Z') {
            str[i] += 32;
        }
    }
    return str;
}



char* toLowerCase(char* str) {
    char *p = str;
    while(*p)
    {
        if(*p >= 'A' && *p <= 'Z')
        {
            *p -= 'A' - 'a';
        }
        p++;
    }
    return str;
}
