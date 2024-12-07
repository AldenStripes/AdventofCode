#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;

bool calc(ll key, vector<ll> values, ll sum, ll i) {
    if (sum>key) return false; // speed up program
    if (sum==key && i==values.size()) return true; // not putting i==values.size() cost me 12 hours of debugging time
    if (i==values.size()) return false;
    ll first = sum*values[i];
    ll second = sum+values[i];
    string s1 = to_string(sum);
    string s2 = to_string(values[i]);
    ll third = stoll(s1 + s2);
    return (calc(key, values, first, i+1) || calc(key, values, second, i+1) || calc(key, values, third, i+1));
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream File("file.txt");

    ll ans = 0;
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
        if (calc(stoll(key), values, values[0], 1)) ans += stoll(key);
    }

    cout << ans << '\n';
}