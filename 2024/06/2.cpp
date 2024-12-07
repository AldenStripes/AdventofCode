#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;

char grid[130][130];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream File("file.txt");

    string line;
    int index = 0;
    int ar, ac;
    while (getline(File, line)) {
        for (int i=0; i<line.size(); ++i) {
            grid[index][i] = line[i];
            if (grid[index][i]=='^') {
                ar = index;
                ac = i;
            }
        }
        index ++;
    }

    int ans = 0;
    for (int i=0; i<130; ++i) {
        for (int j=0; j<130; ++j) {
            if (grid[i][j]=='.') {
                grid[i][j] = '#';
                cout << "CHANGED grid["<<i<<"]["<<j<<"] to #\n";

                set<tuple<int, int, int>> s; // r, c, dir
                int dir = 0;
                int r = ar, c = ac;
                while (true) {
                    if (s.count({r, c, dir})==1) {
                        ans ++;
                        break;
                    }
                    s.insert({r, c, dir});
                    if (r==0 && dir==0 || c==0&&dir==3 || r==129&&dir==2 || c==129&&dir==1) {
                        break;
                    }
                    if (dir==0) {
                        if (grid[r-1][c]=='#') {
                            dir = 1;
                        }   else {
                            r --;
                        }
                    }   else if (dir==1) {
                        if (grid[r][c+1]=='#') {
                            dir = 2;
                        }   else {
                            c ++;
                        }
                    }   else if (dir==2) {
                        if (grid[r+1][c]=='#') {
                            dir = 3;
                        }   else {
                            r ++;
                        }
                    }   else {
                        if (grid[r][c-1]=='#') {
                            dir = 0;
                        }   else {
                            c --;
                        }
                    }
                }
                grid[i][j] = '.';
            }
        }
    }

    cout << ans << '\n';
}