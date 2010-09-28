#include<cstdio>

using namespace std;

int main(){    
    int T,a,b,c,d;
    
    scanf("%d",&T);
    
    for(int i=1;i<=T;i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        
        printf("Scenario #%d:\n",i);
        
        if((((a&1)+(b&1))&1)==(((c&1)+(d&1))&1)) printf("0\n\n");
        else printf("1\n\n");
    }
    
    return 0;
}
