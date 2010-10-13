#include <cstdio>
#include <algorithm>

using namespace std;

int L1,L2,S1[180],S2[180];

int solve(){
    int ans = 0;
    
    for(int i = 0;i<L1;++i){
        for(int j = 0;j<L2;++j){
            int aux = 0;
            
            for(int k = 0;i+k<L1 && j+k<L2;++k){
                if(S1[i+k]!=S2[j+k]) break;
                ++aux;
            }
            
            ans = max(ans,aux);
        }
    }
    
    return ans;
}

int main(){
    scanf("%d %d",&L1,&L2);
    
    for(int i = 0;i<L1;++i) scanf("%d",&S1[i]);
    for(int i = 0;i<L2;++i) scanf("%d",&S2[i]);
    
    printf("%d\n",solve());
    
    return 0;
}
