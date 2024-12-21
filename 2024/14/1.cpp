#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream File("file.txt");

    int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
    string line;
    while (getline(File, line)) {
        stringstream ss(line);
        string str1, str2;
        char ch;
        int r, c, vr, vc;
        ss >> ch >> ch >> c >> ch >> r >> ch >> ch >> vc >> ch >> vr;
        cout << "r: " << r << ", c: " << c << ", vr: " << vr << ", vc: " << vc << '\n';
        int width = 101, height = 103; // 101, 103
        r = ((r+vr*100)%height+height)%height;
        c = ((c+vc*100)%width+width)%width;
        cout << r << " " << c << "\n";
        if (r<(height-1)/2 && c>(width-1)/2) {
            q1++;
            cout << "added to q1\n";
        }
        if (r<(height-1)/2 && c<(width-1)/2) {
            q2++;
            cout << "added to q2\n";
        }
        if (r>(height-1)/2 && c<(width-1)/2) {
            q3++;
            cout << "added to q3\n";
        }
        if (r>(height-1)/2 && c>(width-1)/2) {
            q4++;
            cout << "added to q4\n";
        }
    }
    cout << q1 << ' ' << q2 << ' ' << q3 << ' ' << q4 << '\n';
    cout << q1*q2*q3*q4 << '\n';
}