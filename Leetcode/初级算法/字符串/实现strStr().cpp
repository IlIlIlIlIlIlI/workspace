class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="")
            return 0;
        int size=haystack.length();
        int sin=needle.length();
        int p=(size-sin+1);
        for(int i=0;i<size;i++)
        {
            if(i==p)
                break;
            //cout<<"haystack:"<<haystack[i]<<endl;
            for(int p=0;p<sin;p++)
            {
                if(haystack[p+i]!=needle[p])
                {
                    break;
                }
                if(p==(sin-1))
                    return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

static const auto speedUp = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if(m < 1)
        {
            return 0;
        }
        for(int i = 0; i < n; i++)
        {
            int f = 0, j = 0;
            for(; j < m && i+j < n; j++)
            {
                if(needle[j] != haystack[i+j])
                {
                    f = 1;
                    break;
                }
            }
            if(!f && j == m)
            {
                return i;
            }
        }
        return -1;
    }
};