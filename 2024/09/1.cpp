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
    getline(File, line);
    cout << line.size() << '\n';
    vector<int> v;
    int id = 0;
    for (int i=0; i<line.size(); ++i) {
        if (i%2==0) {
            for (int j=0; j<line[i]-'0'; ++j) {
                v.push_back(id);
            }
            id ++;
        }   else {
            for (int j=0; j<line[i]-'0'; ++j) {
                v.push_back(-1);
            }
        }
    }
    for (int i=0; i<v.size(); ++i) {
        cout << v[i];
    }
    cout << '\n';

    ll ans = 0;
    for (int i=0, j=v.size()-1; i<v.size() && i!=j+1; ++i) {
        cout << "i: " << i << ", v[i]: " << v[i] << ", j: " << j << ", v[j]: " << v[j] << '\n';
        if (v[i]==-1) {
            if (v[j]==-1) {
                j --;
                i --;
                cout << "v[j] was ., decremented i and j\n";
            }   else {
                ans += i*v[j];
                cout << "v[j] was " << v[j] << ", i: " << i <<", (v[j]-'0'): " << v[j] << ", decremented j, added " << i*v[j] << "\n";
                j --;
            }
        }   else {
            ans += i*v[i];
            cout << "v[i] was " << v[i] << ", added " << i*v[i] << "\n";
        }
        cout << "i: " << i << ", ans: " << ans << '\n';
    }
    cout << ans << '\n';
}