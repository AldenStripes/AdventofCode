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
    int r, c;
    while (getline(File, line)) {
        for (int i=0; i<line.size(); ++i) {
            grid[index][i] = line[i];
            if (grid[index][i]=='^') {
                r = index;
                c = i;
            }
        }
        index ++;
    }

    int dir = 0;
    while (true) {
        grid[r][c] = 'X';
        if (r==0 && dir==0) {
            break;
        }   else if (c==0 && dir==3) {
            break;
        }   else if (r==129 && dir==2) {
            break;
        }   else if (c==129 && dir==1) {
            break;
        }
        if (dir==0) {
            if (grid[r-1][c]=='#') {
                dir = 1;
                c ++;
            }   else {
                r --;
            }
        }   else if (dir==1) {
            if (grid[r][c+1]=='#') {
                dir = 2;
                r ++;
            }   else {
                c ++;
            }
        }   else if (dir==2) {
            if (grid[r+1][c]=='#') {
                dir = 3;
                c --;
            }   else {
                r ++;
            }
        }   else {
            if (grid[r][c-1]=='#') {
                dir = 0;
                r --;
            }   else {
                c --;
            }
        }
    }

    int ans = 0;
    for (int i=0; i<130; ++i) {
        for (int j=0; j<130; ++j) {
            if (grid[i][j]=='X') ans ++;
        }
    }
    cout << ans << '\n';
}