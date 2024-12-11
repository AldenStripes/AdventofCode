#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream File("file.txt");

    string line;
    vector<ll> v;
    while (getline(File, line)) {
        stringstream ss(line);
        ll num;
        while (ss >> num) {
            v.push_back(num);
        }
    }

    int times = 25;
    while (times--) {
        vector<ll> temp;
        for (int i=0; i<v.size(); ++i) {
            if (v[i]==0) {
                temp.push_back(1);
            }   else {
                string s = to_string(v[i]);
                if (s.size()%2==0) {
                    string s1 = s.substr(0, s.size()/2); //0 1 2 3 4 5
                    string s2 = s.substr(s.size()/2);
                    ll n1 = stoll(s1);
                    ll n2 = stoll(s2);
                    temp.push_back(n1); temp.push_back(n2);
                }   else {
                    temp.push_back(v[i]*2024);
                }
            }   
        }
        v = temp;
    }
    cout << v.size() << '\n';
}