#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int t,n,m,a[100],b[100];
    char s[201];

    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&m);

        for(int i = 0;i < n;++i)
            scanf("%d",&a[i]);
        for(int i = 0;i < m;++i)
            scanf("%d",&b[i]);
        sort(a,a + n);
        sort(b,b + m);

        scanf("%s",s);

        int cont = 0,have = 0;

        for(int i = 0,pa = n - 1,sb = 0,eb = m - 1;i < n + m;++i){
            if(s[i] == '+'){
                have += a[pa--];
            }else{
                if(have >= b[sb]){
                    have -= b[sb];
                    ++sb;
                }else{
                    --eb;
                    ++cont;
                }
            }
        }

        printf("%d\n",cont);
    }

    return 0;
}
