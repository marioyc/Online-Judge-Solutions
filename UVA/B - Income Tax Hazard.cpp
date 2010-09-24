#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int tc=1,M,mn,mx,N;
    double E;
    
    while(1){
        scanf("%d %d %d",&M,&mn,&mx);
        if(M==0 && mn==0 && mx==0) break;
        
        N=(mx-mn+1)*(mx-mn+2)/2;
        E=0;
        
        for(int s1=mx;s1>=mn;s1--){
            if(M>s1){
                E+=(2*M-s1)*(M-s1)/10.0-(M-1+s1)*(M-s1)/20.0;
                if(mx>=M) E+=(M-s1)*(mx-M+1)/10.0;
            }
        }
        
        E=E/N;
        
        printf("Case %d: %.2f\n",tc++,E);
    }
    
    return 0;
}
