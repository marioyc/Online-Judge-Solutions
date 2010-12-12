#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int b;
    char num[100001];
    
    while(true){
        scanf("%d",&b);
        if(b==0) break;
        
        scanf("%s",num);
        
        int s = 0,mod = 0,L = strlen(num);
        
        for(int i = 0;i<L;++i) s += num[i]-'0';
        for(int i = 0;i<L;++i) mod = (mod*b+num[i]-'0')%s;
        
        if(mod==0) puts("yes");
        else puts("no");
    }
    
    return 0;
}
