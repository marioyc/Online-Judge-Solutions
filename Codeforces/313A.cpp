#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    
    cin >> n;
    
    if(n >= 0) cout << n << endl;
    else{
        int aux = abs(n);
        int d1 = aux % 10;
        aux /= 10;
        int d2 = aux % 10;
        aux /= 10;
        cout << -(aux * 10 + min(d1,d2)) << endl;
    }
    
    return 0;
}
