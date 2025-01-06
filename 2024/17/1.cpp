#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;

ll A = 47719761, B = 0, C = 0;
int op[] = {2,4,1,5,7,5,0,3,4,1,1,6,5,5,3,0};
string ans = "";

ll combo(int operand) {
    if (operand>=0 && operand<=3) {
        return operand;
    }
    if (operand==4) {
        return A;
    }
    if (operand==5) {
        return B;
    }
    if (operand==6) {
        return C;
    } 
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // for speed reasons not getting input from file

    for (int i=0; i<sizeof(op)/sizeof(op[0]); i+=2) {
        int opcode = op[i], operand = op[i+1];
        switch (opcode) {
            case 0: 
                A = A / pow(2, combo(operand));
                break;
            case 1:
                B = B ^ operand;
                break;
            case 2:
                B = combo(operand)%8;
                break;
            case 3:
                if (A!=0) {
                    i = operand-2; // jumps 
                }
                break;
            case 4:
                B = B ^ C;
                break;
            case 5:
                ans += to_string(combo(operand)%8);
                ans += ',';
                break;
            case 6:
                B = A / pow(2, combo(operand));
                break;
            case 7:
                C = A / pow(2, combo(operand));
                break;
        }
    }
    
    ans.pop_back();
    cout << ans << '\n';
}