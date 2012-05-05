#include <cstdio>
#include <vector>

using namespace std;

int LIS(vector<int> X){
    int n = X.size(),L = 0,M[n+1],P[n]; 
    int lo,hi,mi;
    
    L = 0;
    M[0] = 0;
    
    for(int i=0,j;i<n;i++){
        lo = 0; hi = L;
        
        while(lo!=hi){
            mi = (lo+hi+1)/2;
            
            if(X[M[mi]]<X[i]) lo = mi;
            else hi = mi-1;
        }
        
        j = lo;
        
        P[i] = M[j];
        
        if(j==L || X[i]<X[M[j+1]]){
            M[j+1] = i;
            L = max(L,j+1);
        }
    }
    
    return L;
}

int main(){
    int T,n;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        vector<int> v;
        
        for(int i = 0,x;i < n;++i){
            scanf("%d",&x);
            v.push_back(x);
        }
        
        printf("%d\n",LIS(v));
    }
    
    return 0;
}
