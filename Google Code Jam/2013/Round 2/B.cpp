#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    
    int T;
    
    cin >> T;
    
    int N;
    long long P;
    
    for(int tc = 1;tc <= T;++tc){
        cin >> N >> P;
        
        long long lo = 0,hi = (1LL << N) - 1,mi;
        
        while(lo < hi){
            mi = (lo + hi + 1) >> 1 ;
            
            long long aux = (1LL << N) - mi;
            long long pos = 0;
            
            for(int i = 0;i < N;++i){
                if(aux >= 2) pos *= 2;
                else pos = 2 * pos + 1;
                aux /= 2;
            }
            
            if(pos >= P) hi = mi - 1;
            else lo = mi;
        }
        
        long long lo2 = 0,hi2 = (1LL << N) - 1,mi2;
        
        while(lo2 < hi2){
            mi2 = (lo2 + hi2 + 1) >> 1;
            
            long long aux = mi2 + 1;
            long long pos = 0;
            
            for(int i = 0;i < N;++i){
                if(aux >= 2) pos = 2 * pos + 1;
                else pos *= 2;
                aux /= 2;
            }
            
            if(pos >= P) hi2 = mi2 - 1;
            else lo2 = mi2;
        }
        
        cout << "Case #" << tc << ": " << lo2<< " " << lo << endl;
    }
    
    return 0;
}
