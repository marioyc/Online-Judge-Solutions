#include<cstdio>
#include<numeric>

using namespace std;

int main(){    
    int N,Q,sum,s,e;
    int H[500];
    
    scanf("%d %d",&N,&Q);
    
    for(int i=0;i<N;i++) scanf("%d",&H[i]);
    
    for(int i=0;i<Q;i++){
        scanf("%d %d",&s,&e);
        s--; e--;
        
        sum=accumulate(H+s,H+e+1,0);
        
        printf("%d\n",sum);
    }
    
    return 0;
}
