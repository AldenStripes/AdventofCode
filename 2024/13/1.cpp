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
    ll ans = 0;
    int idx = 0;
    while (getline(File, line)) {
        pair<ll, ll> A, B, prize;
        istringstream lineStream(line);
        string dummy;
        char plus;
        lineStream >> dummy >> dummy >> plus >> A.first >> dummy >> plus >> A.second;
        getline(File, line);
        lineStream.clear();
        lineStream.str(line);
        lineStream >> dummy >> dummy >> plus >> B.first >> dummy >> plus >> B.second;
        getline(File, line);
        lineStream.clear();
        lineStream.str(line);
        lineStream >> dummy >> plus >> plus >> prize.first >> dummy >> plus >> plus >> prize.second;
        prize.first += 10000000000000;
        prize.second += 10000000000000;
        getline(File, line);
        lineStream.clear();

        // cout << A.first << " " << A.second << ' ' << B.first << ' ' << B.second << " " << prize.first << ' ' << prize.second << '\n';
        ll maxB = max((prize.first/B.first)+1, (prize.second/B.second)+1);

        for (ll i=0; i<maxB; ++i) { // how many times u press B
            for (ll j=0; j<1000; ++j) {
                if (i*B.first+j*A.first == prize.first && i*B.second+j*A.second == prize.second) {
                    ans += i+j*3;
                    break;
                }
            }
        }
        cout << "line " << idx << '\n';
        idx ++;
    }

    cout << ans << "\n";

}