#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,P1,P2,P3,T1,T2;
    
    scanf("%d %d %d %d %d %d",&n,&P1,&P2,&P3,&T1,&T2);
    
    int l[n],r[n],ans = 0;
    
    for(int i = 0;i<n;++i){
        scanf("%d %d",&l[i],&r[i]);
        ans += (r[i]-l[i])*P1;
    }
    
    for(int i = 0;i+1<n;++i){
        ans += min(T1,l[i+1]-r[i])*P1;
        ans += min(T2,max(0,l[i+1]-r[i]-T1))*P2;
        ans += max(0,l[i+1]-r[i]-T1-T2)*P3;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
