#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;

int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
int grid[103][101];
vector<array<int, 4>> v;
int height = 103, width = 101; // 101, 103
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream File("file.txt");

    string line;
    while (getline(File, line)) {
        stringstream ss(line);
        string str1, str2;
        char ch;
        int r, c, vr, vc;
        ss >> ch >> ch >> c >> ch >> r >> ch >> ch >> vc >> ch >> vr;
        grid[r][c] ++;
        v.push_back({r, c, vr, vc});
    }

    for (int i=0; i<v.size(); ++i) {
        int r = v[i][0], c = v[i][1], vr = v[i][2], vc = v[i][3];
        r = ((r+vr*20000)%height+height)%height;
        c = ((c+vc*20000)%width+width)%width;
    }
    for (int idx=0; idx<50000; ++idx) {
        cout << idx << '\n';
        for (int i=0; i<v.size(); ++i) {
            int r = v[i][0], c = v[i][1], vr = v[i][2], vc = v[i][3];
            grid[r][c] --;
            r = (r+vr+height)%height;
            c = (c+vc+width)%width;
            grid[r][c] ++;
            bool foundforthis = false;
            for (int i=0; i<103; ++i) {
                for (int j=0; j<101; ++j) {
                    bool found = true;
                    for (int k=0; k<4; ++k) {
                        if (grid[i][j+k]==0) {
                            found = false;
                            break;
                        } 
                    }
                    if (found) {
                        foundforthis = true;
                        break;
                    }
                }
                if (foundforthis) {
                    break;
                }
            }
            if (foundforthis) {
                for (int i=0; i<103; ++i) {
                    for (int j=0; j<101; ++j) {
                        if (grid[i][j]==0) cout << '.';
                        else cout << grid[i][j];
                    }
                    cout << '\n';
                }
                cout << "\n\n";
                return 0;
            }
        }
    }
    // cout << q1 << ' ' << q2 << ' ' << q3 << ' ' << q4 << '\n';
    cout << q1*q2*q3*q4 << '\n';
}