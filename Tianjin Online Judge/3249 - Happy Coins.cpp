#include <cstdio>

using namespace std;

int main(){
    char name[4];
    
    int T,n,S;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&n);
        
        S=0;
        
        for(int i=0;i<n;i++){
            scanf("%s",name);
            if(name[0]=='l') S++;
        }
        
        if(S&1) printf("lxh\n");
        else printf("hhb\n");
    }
    
    return 0;
}
