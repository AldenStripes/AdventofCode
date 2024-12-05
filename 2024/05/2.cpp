#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream File("file.txt");

    ll ans = 0;
    vector<set<int>> v(100);
    string line;
    for (int i=0; i<1176; ++i) {
        getline(File, line);
        int x, y;
        istringstream stream(line);
        char bar;
        stream >> x >> bar >> y;
        v[x].insert(y);
        cout << "inserted " << y << " in v[" << x << "].\n";
    }
    getline(File, line);
    while (getline(File, line)) {
        vector<int> cur;
        stringstream ss(line);
        string num;
        while (getline(ss, num, ',')) {
            cur.push_back(stoi(num));
        }
        for (int i=0; i<cur.size(); ++i) {
            cout << cur[i] << ' ';
        }
        cout << '\n';
        bool good = true;
        for (int i=0; i<cur.size()-1; ++i) {
            for (int j=i+1; j<cur.size(); ++j) {
                if (v[cur[j]].count(cur[i])) {
                    good = false;
                    break;
                }
            }
        }
        if (!good) {
            for (int i=0; i<cur.size(); ++i) {
                int count = 0;
                for (int j=0; j<cur.size(); ++j) {
                    if (i!=j) {
                        if (v[cur[i]].count(cur[j])) count ++;
                    }
                }
                if (count==cur.size()/2) {
                    ans += cur[i];
                }
            }
        }
    }
    cout << ans << '\n';
}