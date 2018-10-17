bool isValid(char* s) {
    if (s == NULL) {
        return false;
    }
    size_t n = strlen(s);
    if (n % 2 == 1) {
        return false;
    } else if (n == 0) {
        return true;
    }
    // ���һ���ض���������
    if (s[n - 1] == '(' || s[n - 1] == '[' || s[n - 1] == '{') {
        return false;
    }
    // �����������ҵ���Ӧ��������
    for (int i = 0; i < n - 1; ++i) {
        // ÿһ�������Ŷ�Ӧ�������űض���2*k+1��
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            bool state = false;
            for (int j = i + 1; j < n; j += 2) {
                switch (s[i]) {
                    case '(':
                        state = s[j] == ')';
                        break;
                    case '[':
                        state = s[j] == ']';
                        break;
                    case '{':
                        state = s[j] == '}';
                        break;
                    default:
                        break;
                }
                if (state) {
                    break;
                }
            }
            if (!state) {
                return false;
            }
        }
    }
    return true;
}


bool isValid(char* s) {
    char ch[10005];
    int top = -1;
    while(*s)
    {
        if(*s == '(' || *s == '{' || *s == '[')
        {
            ch[++top] = *s++;
        }
        else if((*s == ')' || *s == '}' || *s == ']') && top != -1)
        {
            char tmp = *s;
            if((ch[top] == '(' && tmp == ')') ||
               (ch[top] == '{' && tmp == '}') ||
               (ch[top] == '[' && tmp == ']'))
                {
                    top--;
                    s++;
                }
                else
                {
                    return false;
                }
        }
        else if((*s == ')' || *s == '}' || *s == ']') && top == -1)
        {
            return false;
        }
    }
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
