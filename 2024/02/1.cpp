#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fstream File("file.txt");

    int ans = 0;
    string line;
    while (getline(File, line)) {
        vector<int> a;
        stringstream ss(line);
        int num;
        while (ss >> num) {
            a.push_back(num);
        }
        for (int i=0; i<a.size(); ++i) {
            int temp = a[i];   
            a.erase(a.begin()+i);
            bool works = true;
            for (int i=0; i<a.size()-1; ++i) {
                if (a[0]>a[1]) { // should be decreasing
                    int dif = a[i]-a[i+1];
                    if (!(1<=dif && dif<=3)) {
                        works = false;
                        break; 
                    }
                }   else {
                    int dif = a[i+1]-a[i];
                    if (!(1<=dif && dif<=3)) {
                        works = false;
                        break;
                    }
                }
            }
            if (works) {
                ans ++;
                break;
            }
            a.insert(a.begin()+i, temp);
        }
    }
    cout << ans << '\n';
}