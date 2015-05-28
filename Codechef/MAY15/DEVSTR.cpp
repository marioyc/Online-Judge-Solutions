#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100000

char s[MAXN + 1];

int main(){
    int T,n,k;

    scanf("%d",&T);

    while(T--){
        scanf("%d %d %s",&n,&k,s);

        if(k == 1){
            int cont1 = 0,cont2 = 0,ans;

            for(int i = 0,x1 = 0,x2 = 1;i < n;++i,x1 ^= 1,x2 ^= 1){
                if(s[i] - '0' != x1) ++cont1;
                if(s[i] - '0' != x2) ++cont2;
            }

            int x;

            if(cont1 < cont2) x = 0;
            else x = 1;
            ans = min(cont1,cont2);

            for(int i = 0;i < n;++i,x ^= 1)
                s[i] = '0' + x;

            printf("%d\n%s\n",ans,s);
        }else{
            int ans = 0;

            for(int i = 0;i < n;){
                int e = i;

                while(e < n && s[e] == s[i]) ++e;

                int pos = i + k;

                if((e - i) % (k + 1) == 0)
                    pos = i + k - 1;

                char x = (s[i] == '0'? '1' : '0');

                while(pos < e){
                    s[pos] = x;
                    pos += k + 1;
                }

                ans += (e - i) / (k + 1);
                i = e;
            }

            printf("%d\n%s\n",ans,s);
        }
    }

    return 0;
}