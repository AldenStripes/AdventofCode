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

    ll ans = 0;
    for (int i=0, j=v.size()-1; i<v.size() && i!=j+1; ++i) {
        if (v[i]==-1) {
            if (v[j]==-1) {
                j --;
                i --;
            }   else {
                ans += i*v[j];
                j --;
            }
        }   else {
            ans += i*v[i];
        }
    }
    cout << ans << '\n';
}