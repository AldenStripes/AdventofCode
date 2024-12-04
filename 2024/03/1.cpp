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
    bool yes = true;
    // string line = "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))";
    string line;
    while (getline(File, line)) {
        // cout << line << "\n\n";
        // cout << "line size: " << line.size() << '\n';
        for (int i=0; i+3<line.size(); ++i) {
            // cout << "i: " << i << '\n';
            if (yes && line[i]=='m' && line[i+1]=='u' && line[i+2]=='l' && line[i+3]=='(') {
                int start = i+4;
                int end = 0;
                for (int j=i+4; j<=line.size(); ++j) {
                    if (line[j]==')') {
                        end = j;
                        break;
                    }
                }
                string s = line.substr(start, end-start);
                int x, y;
                stringstream ss(s);
                // cout << s << '\n';
                char comma;
                ss >> x >> comma >> y;
                if (comma!=',') continue;
                // cout << "x: " << x << ", y: " << y << '\n';
                int lenx = (x==0) ? 1: static_cast<int>(log10(x))+1;
                int leny = (y==0) ? 1: static_cast<int>(log10(y))+1;
                // cout << lenx << ' ' << leny << '\n';
                if (lenx+1+leny != s.size()) continue;
                // cout << "adding: " << x*y << '\n';
                ans += x*y;
                i = end;
            }   else if (line[i]=='d' && line[i+1]=='o' && line[i+2]=='n' && line[i+3]=='\'' && line[i+4]=='t' && line[i+5]=='(' && line[i+6]==')') {
                yes = false;
            }   else if (line[i]=='d' && line[i+1]=='o' && line[i+2]=='(' && line[i+3]==')') {
                yes = true;
            }
        }
    }
    cout << ans << '\n';
}