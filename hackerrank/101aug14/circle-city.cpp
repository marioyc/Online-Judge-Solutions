#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int T,r,k;
    
    cin >> T;
    
    while(T--){
        cin >> r >> k;
        
        int x = 0,cont = 0;
        
        while(x * x < r){
            int y = r - x * x;
            int ry = (int)sqrt(y);
            
            if(y == ry * ry) ++cont;
            ++x;
        }
        
        if(k >= 4 * cont) cout << "possible\n";
        else cout << "impossible\n";
    }
    
    return 0;
}
