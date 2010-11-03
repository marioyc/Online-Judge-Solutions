#include <cstdio>

using namespace std;

int main(){
    int a,b,m;
    
    while(true){
        scanf("%d %d %d",&m,&a,&b);
        if(m==0) break;
        
        int ans = 0;
        
        for(int i=1;i<=1000;++i){
            int x = i*i;
            if(x>=a && x<=b) ++ans;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
