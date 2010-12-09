#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int L;
    char skew[60];
    
    while(true){
        scanf("%s",skew);
        L = strlen(skew);
        if(L==1 && skew[0]=='0') break;
        
        long long ans = 0;
        
        for(int i = 0;i<L;++i)
            if(skew[i]!='0')
                ans += (skew[i]-'0')*((1LL<<(L-i))-1);
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
