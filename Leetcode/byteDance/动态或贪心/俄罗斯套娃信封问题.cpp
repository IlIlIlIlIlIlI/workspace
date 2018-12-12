static const auto speedUp = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int ans = 0;
        for(int i = 0; i < envelopes.size(); i++)
        {
            int tmp = 0;
            for(int j = 0; j < i; j ++)
            {
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
                {
                    tmp++;
                }
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};