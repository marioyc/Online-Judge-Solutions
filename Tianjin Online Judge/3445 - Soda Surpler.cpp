#include <cstdio>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int e,f,c,n;
    scanf("%d %d %d",&e,&f,&c);
    
    n=e+f;
    
    int ans=0,m;
    
    while(n>=c){
        m=n/c;
        n%=c;
        n+=m;
        
        ans+=m;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
