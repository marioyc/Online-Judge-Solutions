#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    int A[N],B[N];
    for(int i = 0;i<N;++i) scanf("%d %d",&A[i],&B[i]);
    
    int ans[6];
    
    for(int g = 1;g<=5;++g){
        ans[g] = 0;
        
        for(int i = 0,cont = 0;i<N;++i){
            if(A[i]==g || B[i]==g) ++cont;
            else cont = 0;
            ans[g] = max(ans[g],cont);
        }
    }
    
    int best = -1,G = -1;
    
    for(int g = 1;g<=5;++g){
        if(ans[g]>best){
            best = ans[g];
            G = g;
        }
    }
    
    printf("%d %d\n",best,G);
    
    return 0;
}
