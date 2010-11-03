#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

bool solve(int N, int sums[], int ans[]){
    int M = N*(N-1)/2;
    multiset<int> S;
    multiset<int> :: iterator it;
    
    sort(sums,sums+M);
    
    for(int i = 2;i<M;++i){
        if((sums[0]+sums[1]-sums[i])%2!=0) continue;
        
        ans[0] = (sums[0]+sums[1]-sums[i])/2;
        S = multiset<int>(sums,sums+M);
        
        bool valid = true;
        
        for(int j = 1;j<N && valid;++j){
            ans[j] = (*S.begin())-ans[0];
            
            for(int k = 0;k<j && valid;++k){
                it = S.find(ans[k]+ans[j]);
                
                if(it==S.end()) valid = false;
                else S.erase(it);
            }
        }
        
        if(valid) return true;
    }
    
    return false;
}

int main(){
    int N,sums[45],ans[10];
    
    while(scanf("%d",&N)==1){
        int M = N*(N-1)/2;
        
        for(int i = 0;i<M;++i)
            scanf("%d",&sums[i]);
        
        if(!solve(N,sums,ans)) printf("Impossible\n");
        else{
            printf("%d",ans[0]);
            for(int i = 1;i<N;++i) printf(" %d",ans[i]);
            printf("\n");
        }
    }
    
    return 0;
}
