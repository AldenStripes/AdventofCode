#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;

unordered_map<ll, vector<ll>> m;

bool calc(ll key, vector<ll> values, ll sum, int i) {
    if (sum==key) return true;
    if (i==values.size()) return false;
    return (calc(key, values, sum*values[i], i+1) || calc(key, values, sum+values[i], i+1));
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream File("file.txt");

    string line;
    while (getline(File, line)) {
        istringstream lineStream(line);
        string key;
        vector<ll> values;
        ll value;
        getline(lineStream, key, ':');
        key.erase(remove(key.begin(), key.end(), ' '), key.end());
        while (lineStream >> value) {
            values.push_back(value);
        }
        m[stoll(key)] = values;
    }

    ll ans = 0;
    for (auto it=m.begin(); it!=m.end(); ++it) {
        ll key = it->first;
        const vector<ll>& values = it->second;
    // }
    // for (const auto& [key, values]: m) {
        ll cur = values[0];
        if (calc(key, values, values[0], 1)) ans += key;
    }
    cout << ans << '\n';
}