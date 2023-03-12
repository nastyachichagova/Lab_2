#include<iostream>
#include<vector>
#include <sstream>
using namespace std;

template <typename T>
void print_vector (vector<T>& v){
    auto i = v.begin();

    while(i != v.end()){
        cout << *i << " ";
        i++;
    }

    cout << "\n";
}

int main() {
    string s;

    getline(cin, s);

    vector<char> v(s.begin(), s.end());
    vector<char> v1;

    vector<char>::iterator it;

    string error = "yes";

    for (it = v.begin(); it != v.end(); ++it){
        if ((*it == '[') || (*it == '(') || ((*it) == '{')){
            v1.push_back(*it);
        }else if (!(v1.empty())){
            if (*it == ']' && v1.back() == '[')
                v1.pop_back();
            else if (*it == ')' && v1.back() == '(')
                v1.pop_back();
            else if (*it == '}' && v1.back() == '{')
                v1.pop_back();
            else
                error = "no";
        }else
            error = "no";
    }

    if (!v1.empty())
        error = "no";

    cout << error;
    return 0;
}
