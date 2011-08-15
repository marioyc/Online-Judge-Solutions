#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string A,B;
    
    while(true){
        cin >> A >> B;
        if(A == "*") break;
        
        int L1 = A.size(),L2 = B.size();
        int L = max(L1,L2);
        
        if(L1 < L) A = string(L - L1, '0') + A;
        if(L2 < L) B = string(L - L2, '0') + B;
        
        if(A == B) cout << "=" << endl;
        else if(A < B) cout << "<" << endl;
        else cout << ">" << endl;
    }
    
    return 0;
}
