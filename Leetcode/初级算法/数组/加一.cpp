class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
		if (digits[i] <= 8) {
			digits[i] += 1;
			return digits;
		}
		else {
			if (i != 0)digits[i] = 0;
			else {
				digits[i] = 1;
				digits.push_back(0);
				return digits;
			}
		}
	}
    }
};



class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        digits[0] += 1;
        for(int i = 0; i < digits.size(); i++)
        {
            if(digits[i] >= 10)
            {
                digits[i] %= 10;
                if(i+1 == digits.size())
                {
                    digits.push_back(1);
                }
                else
                {
                    digits[i+1] += 1;
                }
            }
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};