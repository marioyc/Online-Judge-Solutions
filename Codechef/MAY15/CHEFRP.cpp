#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100000

int main(){
    int T,N,a[MAXN];

    scanf("%d",&T);

    while(T--){
        scanf("%d",&N);

        bool ok = true;

        for(int i = 0;i < N;++i){
            scanf("%d",&a[i]);
            if(a[i] < 2) ok = false;
        }

        if(!ok) printf("-1\n");
        else{
            sort(a,a + N);

            int ans = 0;

            for(int i = N - 1;i > 0;--i)
                ans += a[i];
            
            ans += min(a[0],2);

            printf("%d\n",ans);
        }
    }

    return 0;
}