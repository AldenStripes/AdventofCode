#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;
const int MM = 50;

char grid[MM][MM];
void printthething() {
    cout << '\n';
    for (int i=0; i<MM; ++i) {
        for (int j=0; j<MM; ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream File("file.txt");

    string line;
    int r, c;
    for (int i=0; i<MM; ++i) {
        getline(File, line);
        for (int j=0; j<MM; ++j) {
            grid[i][j] = line[j];
            if (grid[i][j]=='@') {
                r = i; c = j;
            }
        }
    }

    getline(File, line);
    vector<char> v;
    for (int i=0; i<20; ++i) {
        getline(File, line);
        for (int j=0; j<line.size(); ++j) {
            v.push_back(line[j]);
        }
    }


    for (int i=0; i<v.size(); ++i) {
        cout << v[i] << '\n';
        if (v[i]=='^') {
            if (grid[r-1][c]=='.') {
                grid[r-1][c] = '@';
                grid[r][c] = '.';
                r --;
            }   else if (grid[r-1][c]=='O') {
                for (int i=2; i<50; ++i) {
                    if (grid[r-i][c]=='.') {
                        grid[r-i][c] = 'O';
                        grid[r-1][c] = '@';
                        grid[r][c] = '.';
                        r --;
                        break;
                    }   else if (grid[r-i][c]=='#') break;
                }
            }
        }   else if (v[i]=='>') {
            if (grid[r][c+1]=='.') {
                grid[r][c+1] = '@';
                grid[r][c] = '.';
                c ++;
            }   else if (grid[r][c+1]=='O') {
                for (int i=2; i<50; ++i) {
                    if (grid[r][c+i]=='.') {
                        grid[r][c+i] = 'O';
                        grid[r][c+1] = '@';
                        grid[r][c] = '.';
                        c ++;
                        break;
                    }   else if (grid[r][c+i]=='#') break;
                }
            }
        }   else if (v[i]=='v') {
            if (grid[r+1][c]=='.') {
                grid[r+1][c] = '@';
                grid[r][c] = '.';
                r ++;
            }   else if (grid[r+1][c]=='O') {
                for (int i=2; i<50; ++i) {
                    if (grid[r+i][c]=='.') {
                        grid[r+i][c] = 'O';
                        grid[r+1][c] = '@';
                        grid[r][c] = '.';
                        r ++;
                        break;
                    }   else if (grid[r+i][c]=='#') break;
                }
            }
        }   else {
            if (grid[r][c-1]=='.') {
                grid[r][c-1] = '@';
                grid[r][c] = '.';
                c --;
            }   else if (grid[r][c-1]=='O') {
                for (int i=2; i<50; ++i) {
                    if (grid[r][c-i]=='.') {
                        grid[r][c-i] = 'O';
                        grid[r][c-1] = '@';
                        grid[r][c] = '.';
                        c --;
                        break;
                    }   else if (grid[r][c-i]=='#') break;
                }
            }
        }
    }

    ll ans = 0;
    for (int i=0; i<MM; ++i) {
        for (int j=0; j<MM; ++j) {
            cout << grid[i][j];
            if (grid[i][j]=='O') {
                ans += 100*i + j;
            }
        }
        cout << '\n';
    }
    cout << ans << '\n';
}