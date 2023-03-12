#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;


class student {
    public:
        student (int g, string n){
            grade = g;
            name = n;
        }
        void set_grade (int g){
            if (g >= 9 && g <= 11)
                grade = g;
        }
        void set_name (string n){
            name = n;
        }
        int get_grade(){
            return grade;
        }
        string get_name(){
            return name;
        }

    private:
        int grade;
        string name;
};



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

    vector<student> v;

    student a(9, "name");

    int n;
    cin >> n;

    string str;
    string s;
    vector<string> vv;


    for (int i = 0; i < n; i++){
        getline(cin, str);
        istringstream iss2(str);
        while (getline(iss2, s, ' ')){
            vv.push_back(s);
            print_vector(vv);
            /*
            a.set_grade(stoi(vv.front()));
            a.set_name(vv.back());
            v.push_back(a);*/
        }
    }

    for (int i = 0; i < n; i++){
        cout << v[i].get_grade() << " " << v[i].get_name() << "\n";
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j].get_grade() > v[j + 1].get_grade()) {
                swap(v[j], v[j + 1]);

            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << v[i].get_grade() << " " << v[i].get_name() << "\n";
    }

    return 0;
}
