#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int n,m,cont[20000];
    char s[21];
    string a[20000];
    
    while(true){
        scanf("%d %d",&n,&m);
        if(n==0) break;
        
        for(int i = 0;i<n;++i){
            scanf("%s",s);
            a[i] = string(s);
        }
        
        memset(cont,0,sizeof(cont));
        sort(a,a+n);
        
        int s = 0,e;
        
        while(s<n){
            e = s+1;
            while(e<n && a[e]==a[s]) ++e;
            ++cont[e-s-1];
            s = e;
        }
        
        for(int i = 0;i<n;++i) printf("%d\n",cont[i]);
    }    
    
    return 0;
}
