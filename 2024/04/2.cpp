#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;
const int MM = 141;

char a[MM][MM];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream File("file.txt");

    ll ans = 0;
    int index = 0;
    string line;
    while (getline(File, line)) {
        for (int i=0; i<MM; ++i) {
            a[index][i] = line[i];
        }
        index ++;
    }

    for (int r=0; r<MM; ++r) {
        for (int c=0; c<MM; ++c) {
            if (a[r][c]=='M') {
                if (a[r][c+2]=='M') {
                    if (a[r-2][c]=='S' && a[r-2][c+2]=='S' && a[r-1][c+1]=='A') {
                        ans ++;
                    }
                    if (a[r+2][c]=='S' && a[r+2][c+2]=='S' && a[r+1][c+1]=='A') {
                        ans ++;
                    }
                }
                if (a[r+2][c]=='M') {
                    if (a[r][c+2]=='S' && a[r+2][c+2]=='S' && a[r+1][c+1]=='A') {
                        ans ++;
                    }
                    if (a[r][c-2]=='S' && a[r+2][c-2]=='S' && a[r+1][c-1]=='A') {
                        ans ++;
                    }
                }
                if (a[r][c-2]=='M') {
                    if (a[r+2][c]=='S' && a[r+2][c-2]=='S' && a[r+1][c-1]=='A') {
                        ans ++;
                    }
                    if (a[r-2][c]=='S' && a[r-2][c-2]=='S' && a[r-1][c-1]=='A') {
                        ans ++;
                    }
                }
                if (a[r-2][c]=='M') {
                    if (a[r][c+2]=='S' && a[r-2][c+2]=='S' && a[r-1][c+1]=='A') {
                        ans ++;
                    }
                    if (a[r][c-2]=='S' && a[r-2][c-2]=='S' && a[r-1][c-1]=='A') {
                        ans ++;
                    }
                }
            }
        }
    }
    cout << ans/2 << '\n';
}