
#include "stack"
#include "iostream"
#include "string"

using namespace std;

int CheckUuTien(char op ){
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}
string  Post_Fix ( string InFix){
    string postfix;
    stack<char> st;
    for(char pf : InFix){
        if (isnumber(pf)){
            postfix += pf;
        }
        else if (pf == '('){
            st.push(pf);
        }
        else if (pf == ')'){
            while(st.top()!='('){
                postfix += ' ';
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else{

            while(!st.empty() && (CheckUuTien(st.top())>= CheckUuTien(pf))){
                postfix += ' ';
                postfix += st.top();
                st.pop();
            }
            postfix += ' ';
            st.push(pf);
        }
    }
    if (!st.empty()){
        postfix += ' ';
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

double Calculator(double num1, double num2, char op)
{
    double res = 0;
    switch (op)
    {
        case '+':
            res += num2 + num1;
            break;
        case '-':
            res += num2 - num1;
            break;
        case '*':
            res += num2 * num1;
            break;
        case '/':
            res += num2 / num1;
            break;
    }
    return res;
}
bool isop (char op){
    switch (op) {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        default:
            return false;
    }
}

double PostfixCalculator(string op) {
    stack<double> res;
    for (char pf : op) {
        int operand = INT_MIN;
        if(isnumber(pf)){
            operand = operand * 10 + (pf - '0');
            continue;
        }
        if (operand > INT_MIN) {
            res.push(operand);
        }
        if (pf ==' '){
            continue;
        }
        if (isop(pf)){
            double num1 = res.top();
            res.pop();
            double num2 = res.top();
            res.pop();
            res.push(Calculator(num1, num2, pf));
        }
    }
    return res.top();
}

int main()
{
    string test;
    cin>> test;
    cout<<Post_Fix(test);
    cout<<PostfixCalculator(Post_Fix(test));
}