int calPoints(char** ops, int opsSize) {
    int top = -1;
    int sum[2005];
    int ans = 0;
    for(int i = 0;i<opsSize;i++)
    {
        if(ops[i][0] != '+' && ops[i][0] != 'D' && ops[i][0] != 'C')
        {
            int num;
            if(ops[i][0] == '-')
            {
                if(ops[i][2] != '\0')
                {
                    num = -((ops[i][1]-'0')*10 + (ops[i][2]-'0'));
                    sum[++top] = num;
                }
                else
                {
                    sum[++top] = (-(ops[i][1] - '0'));
                }
            }
            else
            {
                if(ops[i][1])
                {
                    num = ((ops[i][0]-'0')*10 + (ops[i][1]-'0'));
                    sum[++top] = num;
                }
                else
                {
                    sum[++top] = (ops[i][0] - '0');
                }
            }
            ans += sum[top];
        }
        else
        {
            if(ops[i][0] == '+')
            {
                if(top >= 1)
                {
                    int tmp = sum[top-1]+sum[top];
                    ans += tmp;
                    sum[++top] = tmp;
                }
                else
                {
                    int tmp = 2*sum[top];
                    ans += tmp;
                    sum[++top] = tmp;
                }
            }
            if(ops[i][0] == 'D')
            {
                int tmp = 2*sum[top];
                ans += tmp;
                sum[++top] = tmp;
            }
            if(ops[i][0] == 'C')
            {
                if(sum[top] >= 0)
                {
                    ans -= sum[top--];
                }
                else
                {
                    ans += (-sum[top--]);
                }
            }
        }
    }
    return ans;
}
/*["4","D","D","C","D"]*/
