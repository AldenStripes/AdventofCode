#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;

vector<int> a, b;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream File("file.txt");

    string line;
    while (getline(File, line)) {
        int x, y;
        istringstream stream(line);
        stream >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    sort(all(a));
    sort(all(b));
    ll ans = 0;
    for (int i=0; i<a.size(); ++i) {
        ans += abs(a[i]-b[i]);
    }
    cout << ans << '\n';
}