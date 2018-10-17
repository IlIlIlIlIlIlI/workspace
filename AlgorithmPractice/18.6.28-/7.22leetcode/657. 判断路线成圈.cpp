bool judgeCircle(char* moves) {
    int Unum = 0;
    int Dnum = 0;
    int Lnum = 0;
    int Rnum = 0;

    int length = strlen(moves);

    for(int i = 0; i < length; i++){
        if(moves[i] == 'U') Unum++;
        else if(moves[i] == 'D') Dnum++;
        else if(moves[i] == 'L') Lnum++;
        else if(moves[i] == 'R') Rnum++;
    }

    if(Unum == Dnum && Lnum == Rnum) return true;
    else return false;
}



bool judgeCircle(char* moves) {
    char *p = moves;
    int i = 0,j = 0;
    while(*p)
    {
        switch(*p)
        {
        case 'R':
            {
                i++;
                p++;
                break;
            }
        case 'L':
            {
                i--;
                p++;
                break;
            }
        case 'U':
            {
                j++;
                p++;
                break;
            }
        case 'D':
            {
                j--;
                p++;
                break;
            }
        }
    }
    if(i == 0 && j == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
