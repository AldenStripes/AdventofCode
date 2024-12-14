#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;

void update(vector<int> &v, int cur, int num, int last) {
    int count = 0;
    for (int i=0; i<=last; ++i) {
        if (v[i]==-1) {
            count ++;
            if (count==num) {
                for (int j=i; j>=i-count+1; --j) {
                    v[j] = cur;
                }
                for (int j=last+count; j>=last+1; --j) {
                    v[j] = -1;
                }
                break;
            }
        }   else {
            count = 0;
        }
    }
}


int main() { //incomplete
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

    int cur = v[v.size()-1];
    int count = 0;
    for (int i=v.size()-1; i>=0; --i) {
        if (v[i]==cur) {
            count ++;
        }   else {
            update(v, cur, count, i);
            count = 1;   
            cur = v[i];
        }
    }   

    ll ans = 0;
    for (int i=0; i<v.size(); ++i) {
        if (v[i]!=-1) {
            ans += i*v[i];
        }
    }
    cout << ans << '\n';
}