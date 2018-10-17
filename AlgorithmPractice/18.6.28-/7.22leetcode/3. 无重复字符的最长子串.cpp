int lengthOfLongestSubstring(char* s) {
    int n=strlen(s);
    int flag;
    int head=0;
    int tail=0;
    int p;
    char stack[100];
    int i=0;
    int j=0;
    int ans=0;
    int ansIndex=0;
    while(i<n&&j<n)
    {
        flag=1;
        p=head;
        while(p!=tail)
        {
            if(stack[p]==s[j])
            {
                flag=0;
            }
            p=(p+1)%100;
        }
        if(flag)
        {
            stack[tail]=s[j];
            tail=(tail+1)%100;
            if((j-i+1)>ans)
            {
                ans=j-i+1;
                ansIndex=i;
            }
            j++;
        }else
        {
            head=(head+1)%100;
            i++;
        }
    }
    return ans;
}

//!/////////////////////////////////////////////////////

int lengthOfLongestSubstring(char* s) {
    int maxLen = 0,currLen = 0;
    int table[128],start = 0;
    memset(table,0,sizeof(int));
    for(int i = 0;i<strlen(s);i++)
    {
        if(table[s[i]] == 1)
        {
            if(currLen > maxLen)
            {
                maxLen = currLen;
            }
            for(int j = start;j<i;j++)
            {
                if(s[j] == s[i])
                {
                    table[s[j]] = 1;
                    start = j+1;
                    break;
                }
                else
                {
                    currLen--;
                    table[s[j]] = 0;
                }
            }
        }
        else
        {
            currLen++;
        }
    }
    if(currLen > maxLen)
    {
        maxLen = currLen;
    }
    return maxLen;
}

int lengthOfLongestSubstring(char* s) {
    int maxlen = 0,currlen = 0;
    int table[128], i, j, start = 0;
    memset(table, 0, sizeof(table));
    for (i = 0; s[i] != '\0'; i++)
    {
        table[s[i]]++;
        if( table[s[i]] == 2 )
        {
            if (currlen > maxlen)
            {
                maxlen = currlen;
            }
            for(j = start; j < i; j++)
            { //start记录重复的字符后一个位置
                if (s[j] == s[i])
                {
                    table[s[j]] = 1;
                    start = j+1;
                    break;
                }
                else
                {
                    currlen--;
                    table[s[j]] = 0;
                }
            }
        }
        else
        {
            currlen++;
        }
    }
    if (currlen > maxlen)
    {
        maxlen = currlen;
    }
    return maxlen;
}

//!/////////////////////////////////////////////////////

int lengthOfLongestSubstring(char *s){
  if(s == NULL)
    return 0;

  int len = strlen(s);
  int max_len = 0;
  int begin = 0;
  int array[128] = {0};

  for(int i = 0;i < len;i++){
    begin = array[s[i]] > begin ? array[s[i]]:begin;
    max_len = max_len > (i+1-begin) ? max_len:i+1-begin;
    array[s[i]] = i+1;
  }

  return max_len;
}



int lengthOfLongestSubstring(char* s) {
    int len=strlen(s);
    int count=0;
    int start=0;   //记录新子串的起始位置
    bool isOk=true;
    //char *tempS;
    //tempS=(char *)malloc(len);     无需额外的数组来存储

    int longLastIndex=0;
    int longLenth=0;

    for(int i=0;i<len;i++){
        isOk=true;
        for(int j=0;j<count;j++){
            if(s[j+start]==s[i]){     //改动处
                isOk=false;
                start=j+start+1;             //改动处
                break;
            }

        }
        if(isOk){
            count++;
            if(i==len-1&&longLenth<count){
                longLenth=count;
            }
        }
        else{
            if(longLenth<count){
                longLenth=count;
            }
            count=i-start+1;   //改动处

        }
    }

    return longLenth;
}



#include <cstdio>
#include <cstring>

int lengthOfLongestSubstring(char* s) {
    char ch[10005];
    int num[100];
    int ans = 0;
    int top = -1;
    memset(num,0,sizeof(int));
    while(*s)
    {
        if(num[*s] == 0)
        {

            //printf("* %c %d %d\n",*s,ans,top);
            ch[++top] = *s++;
            num[ch[top]] = 1;


        }
        else
        {
            //printf("** %c %d %d\n",*s,ans,top);
            ans = (ans >= (top+1)) ? ans : (top+1);
            top = -1;
            num[*s] = 0;
            ch[++top] = *s++;

        }
    }
    ans = (ans >= (top+1)) ? ans : (top+1);
    return ans;
}

int main()
{
    char ch[] = "yduyfg";
    printf("%d\n",lengthOfLongestSubstring(ch));
    return 0;
}
/*!
        *1
        *2
        **2
        **2
        *3
        *4
        **4

        *1
        *2
        **2
        *3
        *4
        **4
*/
