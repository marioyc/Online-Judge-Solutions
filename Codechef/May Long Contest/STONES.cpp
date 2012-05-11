#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int T;
    char j[101],s[101];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%s %s",j,s);
        
        int Lj = strlen(j),Ls = strlen(s),ans = 0;
        
        for(int i = 0;i < Ls;++i)
            ans += min(1,count(j,j + Lj,s[i]));
        
        printf("%d\n",ans);
    }
    
    return 0;
}
