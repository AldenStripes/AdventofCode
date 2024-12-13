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
    map<ll, ll> m;
    while (getline(File, line)) {
        stringstream ss(line);
        ll num;
        while (ss >> num) {
            m[num] ++;
        }
    }

    int times = 75;
    while (times--) {
        map<ll, ll> temp;
        for (auto it=m.begin(); it!=m.end(); ++it) {
            ll stone = it->first;
            ll count = it->second;
            if (stone==0) {
                temp[1] += count;
            }   else {
                string s = to_string(stone);
                if (s.size()%2==0) {
                    string s1 = s.substr(0, s.size()/2); //0 1 2 3 4 5
                    string s2 = s.substr(s.size()/2);
                    ll n1 = stoll(s1);
                    ll n2 = stoll(s2);
                    temp[n1] += count; temp[n2] += count;
                }   else {
                    temp[stone*2024] += count;
                }
            }   
        }
        m = move(temp);
    }

    ll ans = 0;
    for (auto it=m.begin(); it!=m.end(); ++it) {
        ans += it->second;
    }
    cout << ans << '\n';
}
