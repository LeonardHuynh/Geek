#include <iostream>
#include <stack>

using namespace std;

//Kiểm tra toán tử
bool isOperator(char x)
{
    switch(x)
    {
        case '+': case '-' : case '*' : case '/':
            return true;
    }
    return false;
}

string preToInfix(string pre)
{
    int length = pre.size();
    stack<string> st;
    //duyệt các giá trị trong chuỗi từ phần tử cuối đến phần tử đầu
    for(int i = length -1 ; i >= 0; i--)
    {
        char c = pre[i];
        //Nếu c là một toán tử, ta lấy 2 giá trị đầu của stack và toán tử sẽ đặt ở giữa 2 giá trị đó
        if(isOperator(c) == true)
        {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = "(" + op1 + pre[i] + op2 + ")";
        //Đưa string temp vào stack trở lại
            st.push(temp);
        }
        else
        {
            st.push(string(1,pre[i]));  // string(1,) đối số 1 nghĩa là tạo một chuỗi rỗng mới
        }
    }

    return st.top();    // lúc này trong chuỗi chỉ còn phần tử chuỗi kết quả 
}

int main() 
{
    string pre_exp = "*-A/BC-/AKL";
    cout << "Infix : " << preToInfix(pre_exp);
    return 0;
}
