#include <cstdio>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T,N,A,B;
    double sum;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&N);
        
        sum=0.0;
        
        for(int i=0;i<N;i++){
            scanf("%d %d",&A,&B);
            sum+=(double)A/B;
        }
        
        if(sum>=1.0) printf("No\n");
        else printf("Yes\n");
    }
    
    return 0;
}
