static const auto _____ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];
        bool con = true;
        int resNum =0;
        while(con){
            for(int i=1;i<strs.size();i++){
                if(strs[i][resNum]!=strs[0][resNum]){
                    con = false;
                    break;
                }
            }
            ++resNum;
        }
        if(resNum == 1) return "";
        return strs[0].substr(0,resNum-1);
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
    string longestCommonPrefix(vector<string>& strs) {
        int n1 = strs.size();
        if(n1 < 1)
        {
            return "";
        }
        string s = strs[0];
        for(int i = 0; i < n1; i++)
        {
            int j = 0;
            while(s[j] && strs[i][j] && s[j] == strs[i][j])
            {
                j++;
            }
            s[j] = '\0';
        }
        return s;
    }
};