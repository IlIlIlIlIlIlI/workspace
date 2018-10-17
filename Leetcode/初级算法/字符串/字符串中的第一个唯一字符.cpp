static int xx = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int temp[26]={0};
    int firstUniqChar(string s) {
        int ind=0;int n=s.size();
        for(char i : s)
            temp[i-'a']++;
        for(int i=0;i<n;++i)
            if(temp[s[i]-'a']==1) return i;
        return -1;
    }
};



static const auto speedUp = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            int f = 0, j = 0;
            for(; j < n; j++)
            {
                if(s[i] == s[j] && i != j)
                {
                    f = 1;
                    break;
                }
            }
            if(j == n && f == 0)
            {
                return i;
            }
        }
        return -1;
    }
};