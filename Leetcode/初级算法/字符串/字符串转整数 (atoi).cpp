class Solution {
public:
    int myAtoi(string str) {
        if(str.size()==0)
        {
            return 0;
        }
        int startindex=-1;
        int flag=1;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==' ')
            {
                continue;
            }
            if(str[i]=='+'||str[i]=='-')
            {
                startindex=i+1;
                if(str[i]=='-')
                {
                    flag=-1;
                }
                break;
            }
            if(str[i]>'9'||str[i]<'0')
            {
                return 0;  
            }
            else
            {
                startindex=i;
                break;
            }
            
        }
        long int res=0;
        for(int i=startindex;i<str.size();i++)
        {
            if(str[i]>'9'||str[i]<'0')
            {
                break;
            }
            
            res=res*10+str[i]-'0';
            
            if(res*flag<INT_MIN)
            {
                return INT_MIN;
            }
            if(res*flag>INT_MAX)
            {
                return INT_MAX;
            }
            
        }
       
       
        return res*flag;
        
        
    }
};



static const auto speedUp = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int myAtoi(string str) {
        int i = 0, f = 0, space = 0;
        vector<int> vec;
        while(i < str.size() && str[i] == ' ')
        {
            space = 1;
            i++;
        }
        if(isInvalid(str[i]) || (i == str.size()-1 && space == 1) || str.empty())
        {
            return 0;
        }
        if(str[i] == '-')
        {
            f = 1;
            i++;
        }
        else if(str[i] == '+')
        {
            i++;
        }
        while(i < str.size() && isNum(str[i]))
        {
            vec.push_back(str[i++]-'0');
        }
        int ans = 0;
        for(int i = 0; i < vec.size(); i++)
        {
            int tmp = ans * 10 + vec[i];
            if(tmp / 10 != ans)
            {
                if(f == 0)
                {
                    return INT_MAX;
                }
                else
                {
                    return INT_MIN;
                }
            }
            ans = tmp;
        }
        if(f == 0)
        {
            return ans;
        }
        else if(f == 1)
        {
            return -ans;
        }
    }
    private:
    bool isNum(char c)
    {
        return c >= '0' && c <= '9';
    }
    bool isInvalid(char c)
    {
        return !isNum(c) && (c != '-' && c != '+');
    }
};