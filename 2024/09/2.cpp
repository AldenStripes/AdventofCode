#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;

int main() { //incomplete
    ios::sync_with_stdio(0); cin.tie(0);
    fstream File("test.txt");

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

    // for (int i=0; i<v.size(); ++i) {
    //     cout << v[i] << ' ';
    // }
    // cout << '\n';

    // int size = 0;
    // id = v[v.size()-1];
    // for (int j=v.size()-1; j>=0; --j) {
    //     if (v[j]==id) {
    //         size ++;
    //     }   else {
    //         if (v[j]==id-1) {
    //             int count = 0;
    //             int idx = 0;
    //             for (int i=0; i<v.size(); ++i) {
    //                 if (v[i]==-1) { // count . in a row
    //                     count ++;
    //                 }
    //                 if (count==size) {
    //                     idx = i;
    //                     break;
    //                 }
    //             }
    //             for (int i=idx-(count-1); i<=idx; ++i) {
    //                 v[i] = id - 1;
    //             }
    //             id --;
    //             size = 1;
    //         }
    //     }
    //     v[j] = -1;
    // }
    for (int i=0; i<v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << '\n';

    ll ans = 0;
    for (int i=0; i<v.size(); ++i) {
        if (v[i]!=-1) {
            ans += i*v[i];
        }
    }
    cout << ans << '\n';
}