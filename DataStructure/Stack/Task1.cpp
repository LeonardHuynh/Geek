#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
using namespace std;

// chức năng cho biết thứ tự ưu tiên của phép toán
int prec(char ch)
{
    if(ch == '^')
        return 3;
    else if(ch == '/' || ch == '*')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}


// The main function to convert infix expression
//to postfix expression

void infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for(int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            result += c;
        // nếu gặp dấu '('
        else if(c == '(')
            st.push('(');
        else if(c == ')')
        {
            while(st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty())
    {
        result += st.top();
        st.pop();
    }
    cout << result << endl;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}
