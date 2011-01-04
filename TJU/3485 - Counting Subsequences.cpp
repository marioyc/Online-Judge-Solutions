#include <cstdio>
#include <map>

using namespace std;

int a[1000001];

int main(){
    int T,N;
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        a[0] = 0;
        for(int i = 1;i<=N;++i) scanf("%d",&a[i]);
        for(int i = 1;i<=N;++i) a[i] += a[i-1];
        
        map<long long,int> cont;
        cont[0] = 1;
        
        int ans = 0;
        
        for(int i = 1;i<=N;++i){
            ans += cont[a[i]-47];
            ++cont[a[i]];
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
