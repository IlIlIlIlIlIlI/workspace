bool isNumber(char* s) {
    if(*s < '0' || *s > '9')
    {
        s++;
        return false;
    }
    while(*s)
    {
        if(*s == 'e' || *s == '.' || (*s >= '0' && *s <= '9'))
        {
            s++;
        }
        else
        {
            return false;
        }
    }
    return true;
}
