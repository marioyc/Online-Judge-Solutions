#include <cstdio>
#include <algorithm>

using namespace std;

int cont[1000001],ans[1000001];

int main(){
    int N;
    scanf("%d",&N);
    
    int a[N],M=1;
    fill(cont,cont+1000001,0);
    
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
        cont[a[i]]++;
        M>?=a[i];
    }
    
    fill(ans,ans+M+1,0);
    
    for(int i=1;i<=M;i++){
        if(cont[i]==0) continue;
        ans[i]+=cont[i]-1;
        for(int j=2*i;j<=M;j+=i) ans[j]+=cont[i];
    }
    
    for(int i=0;i<N;i++) printf("%d\n",ans[a[i]]);
    
    return 0;
}
