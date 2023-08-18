#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool bracecheck(string &str) {
    if (str.size() == 0) {
        return true;
    }

    char ch[str.size()];
    for (int i = 0; i < str.size(); i++) {
        ch[i] = str[i];
    }

    stack<char> st;
    for (int i = 0; i < str.size(); ++i) {
        if (ch[i] == '(' || ch[i] == '[' || ch[i] == '{') {
            st.push(ch[i]);
        } else if (ch[i] == ')' || ch[i] == ']' || ch[i] == '}') {
            if (st.empty()) {
                return false;
            }
            if (ch[i] == ')' && st.top() != '(' ||
                ch[i] == ']' && st.top() != '[' ||
                ch[i] == '}' && st.top() != '{') {
                return false;
            }
            st.pop();
        }
    }
    if (st.empty()) {
        return true;
    }else {
        return false;
    }
}
int main() {
    cout << "Please enter a string (must is '(',')','[',']','{','}') : ";
    string str;
    cin >> str;
    bool flag;
    flag = bracecheck(str);
    cout << "MATCH true or false :";
    if (flag == true){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
    
}