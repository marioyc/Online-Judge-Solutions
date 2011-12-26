#include <cstdio>
#include <algorithm>

using namespace std;

int na,nb,nc;
int a[4000],b[4000],c[4000];

int main(){
    scanf("%d",&na);
    
    for(int i = 0;i < na;++i)
        scanf("%d",&a[i]);
    
    scanf("%d",&nb);
    
    for(int i = 0;i < nb;++i)
        scanf("%d",&b[i]);
    
    scanf("%d",&nc);
    
    for(int i = 0;i < nc;++i)
        scanf("%d",&c[i]);
    
    int ans = 0;
    
    for(int i = 0,j = 0,k = 0;i < na;++i){
        while(j < nb && b[j] < a[i]) ++j;
        while(k < nc && c[k] < a[i]) ++k;
        
        if(b[j] == a[i] && c[k] == a[i]) ++ans;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
