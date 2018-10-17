int numJewelsInStones(char* J, char* S) {
    int length_J = strlen(J);
    int length_S = strlen(S);
    int i = 0;
    int j = 0;
    int num = 0;
    for(i = 0; i < length_J; i++){
        for(j = 0; j < length_S; j++){
            if(S[j] == J[i])
                num++;
        }
    }
    return num;
}

#include <cstdio>
#include <cstdlib>
int numJewelsInStones(char* J, char* S) {
    int ans = 0;
    while(*J)
    {
        char *tmp = S;
        while(*tmp)
        {
            if(*tmp == *J)
            {
                ans++;
            }
            tmp++;
        }
        J++;
    }
    return ans;
}

int main()
{
    char *j = (char*)malloc(sizeof(char)*55);
    char *s = (char*)malloc(sizeof(char)*55);
    j = "aA";
    s = "aAAbbbb";
    printf("%d\n",numJewelsInStones(j,s));
}
