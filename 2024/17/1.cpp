#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(i) i.begin(), i.end()
const int inf = 0x3f3f3f3f;

ll A = 2024, B = 0, C = 0;
int op[] = {0,1,5,4,3,0};
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
        if (i==sizeof(op)/sizeof(op[0])-1) { // no operand
            break;
        }
        int opcode = op[i], operand = op[i+1];
        switch (opcode) {
            case 0: 
                A = trunc(A / pow(2, combo(operand)));
            case 1:
                B = B ^ operand;
            case 2:
                B = combo(operand)%8;
            case 3:
                if (A!=0) {
                    i --; // jump 1
                }
            case 4:
                B = B ^ C;
            case 5:
                ans += to_string(combo(operand)%8);
                ans += ',';
            case 6:
                B = trunc(A / pow(2, combo(operand)));
            case 7:
                C = trunc(A / pow(2, combo(operand)));
        }
    }
    
    cout << ans << '\n';
}