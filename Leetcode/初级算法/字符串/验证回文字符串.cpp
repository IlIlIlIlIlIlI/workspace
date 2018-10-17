static const auto speedUp = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i < j)
        {
            
            while(i < j && !isAlphaNum(s[i]))
            {
                i++;
            }
            while(i < j && !isAlphaNum(s[j]))
            {
                j--;
            }
            if(lower(s[i]) == lower(s[j]))
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
private:
    bool isAlphaNum(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    char lower(char c)
    {
        if(c >= 'A' && c <= 'Z')
        {
            return c+32;
        }
        else
        {
            return c;
        }
    }
};