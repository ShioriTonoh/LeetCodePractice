class Solution {
public:
    bool isValid(string s) {
        for(char &c: s)
        {
            if(isLeft(c)) left.push(c);
            else
            {
                if(left.empty() || left.top() != getLeft(c)) return false;
                left.pop();
            }
        }
        return left.empty();
    }

private: 
    stack<char> left;

    char getLeft(char &c)
    {
        if(c == ')') return '(';
        if(c == ']') return '[';
        if(c == '}') return '{';
        return '\0';
    }

    inline bool isLeft(char &c)
    {
        if(c == '(' || c == '[' || c == '{') return true;
        return false;
    }
};