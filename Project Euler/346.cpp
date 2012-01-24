#include <iostream>
#include <set>

using namespace std;

int main(){
    const long long MAX_VAL = 1000000000000LL;
    
    set<long long> S;
    S.insert(1);
    
    for(long long b = 2;;++b){
        long long aux = b*b + b + 1;
        if(aux >= MAX_VAL) break;
        
        while(aux < MAX_VAL){
            S.insert(aux);
            aux = aux * b + 1;
        }
    }
    
    long long ans = 0;
    
    for(set<long long> :: iterator it = S.begin();it != S.end();++it)
        ans += *it;
    
    cout << ans << '\n';
    
    return 0;
}
