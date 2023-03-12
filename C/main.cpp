#include<iostream>
#include<deque>
#include <sstream>


using namespace std;

template <typename T>
void print_deque (deque<T>& v){
    auto i = v.begin();

    while(i != v.end()){
        cout << *i << " ";
        i++;
    }

    cout << "\n";
}


int main(){
    deque<int> d1, d2;
    string s1, s2;
    string str;

    getline(cin, str);
    istringstream iss1(str);

    while(getline(iss1, s1, ' ')){
        d1.push_back(stoi(s1));
    }

    str.clear();

    getline(cin, str);
    istringstream iss2(str);

    while(getline(iss2, s2, ' ')){
        d2.push_back(stoi(s2));
    }


    int n = 0;

    
    while(!(d1.empty()) || !(d2.empty())){
        if (n > 1000000){
            cout << "botva";
            break;
        }else{
            if(d1.empty()){
                cout<<"second "<< n;
                break;
            }else if(d2.empty()){
                cout<<"first "<< n;
                break;
            }else{
                if (d1[0] == 0 && d2[0] == 9){
                    d1.push_back(d1.front());
                    d1.push_back(d2.front());
                    d1.pop_front();
                    d2.pop_front();
                    ++n;
                }
                else if (d1[0] == 9 && d2[0] == 0){
                    d2.push_back(d1.front());
                    d2.push_back(d2.front());
                    d1.pop_front();
                    d2.pop_front();
                    ++n;
                }
                else if (d1[0] > d2[0]){
                    d1.push_back(d1.front());
                    d1.push_back(d2.front());
                    d1.pop_front();
                    d2.pop_front();
                    ++n;
                }
                else{
                    d2.push_back(d1.front());
                    d2.push_back(d2.front());
                    d1.pop_front();
                    d2.pop_front();
                    ++n;
                }

            }
        }
    }


    return 0;
}