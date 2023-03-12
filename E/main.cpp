#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

int sum(int a, int b){
    return a + b;
}

int ded(int a, int b){
    return a - b;
}

int mul(int a, int b){
    return a * b;
}

void Calc (string& res, int a, int b, int (*operation)(int, int)){
    stringstream ss;
    ss << operation(a, b);
    res = ss.str();
}
/*
template <typename T>
void print_vector (vector<T>& v){
    auto i = v.begin();

    while(i != v.end()){
        cout << *i << " ";
        i++;
    }

    cout << "\n";
}
*/
int main() {
    deque<string> d;
    string s;
    string str;

    getline(cin, str);

    istringstream iss2(str);

    while(getline(iss2, s, ' ')){
        d.push_back(s);
    }

    auto i = d.begin() + 2;

    while (!d.empty()){
        if (d.size() == 1){
            cout << *(d.begin());
            break;
        }else{
            if(*i == "+"){
                Calc(*i, stoi(*(i - 2)), stoi(*(i - 1)), sum);
                d.erase(i - 2, i);
                --i;
            }else if ( *i == "-"){
                Calc(*i, stoi(*(i - 2)), stoi(*(i - 1)), ded);
                d.erase(i - 2, i);
                --i;
            }else if (*i == "*"){
                Calc(*i, stoi(*(i - 2)), stoi(*(i - 1)), mul);
                d.erase(i - 2, i);
                --i;
            }else
                ++i;
        }
    }


    return 0;
}
