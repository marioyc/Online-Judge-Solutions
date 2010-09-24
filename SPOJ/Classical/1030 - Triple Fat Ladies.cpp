#include <cstdio>

using  namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int T,m;
    long long k;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%lld",&k);
        
        k--;
        m=k&3;
        k/=4;
        
        
        if(k>0) printf("%lld",k);
        
        if(m==0) printf("192\n");
        else if(m==1) printf("442\n");
        else if(m==2) printf("692\n");
        else printf("942\n");
    }
    
    return 0;
}
