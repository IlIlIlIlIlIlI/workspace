static const auto speedUp = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0)
        {
            int tmp = ans * 10 + x % 10;
            if(tmp / 10 != ans)
            {
                return 0;
            }
            ans = tmp;
            x /= 10;
        }
        return ans;
    }
};