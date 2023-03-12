#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;


int main() {
    int n;
    cin >> n;

    string s;
    list <int> l;

    while ((getline(cin, s, ' '))&&(l.size() < n)){
        l.push_back(stoi(s));
    }

    l.sort();

    l.unique();

    cout << l.size() << endl;

    return 0;
}
