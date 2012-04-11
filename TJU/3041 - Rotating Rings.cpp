#include <cstdio>

using namespace std;

int M[1000][1000],M2[1000][1000];
int a[4000],b[4000],m;

int main(){
    int tc = 1,n;
    
    while(true){
        scanf("%d",&n);
        if(n == 0) break;
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j < n;++j)
                scanf("%d",&M[i][j]);
        
        for(int i = 0,cont = 0;i < n;++i)
            for(int j = 0;j < n;++j)
                M2[i][j] = ++cont;
        
        bool ok = true;
        
        for(int l = n,it = 0;l > 0 && ok;l -= 2,++it){
            if(l == 1){
                a[0] = M[it][it];
                b[0] = M2[it][it];
                m = 1;
            }else{
                m = 0;
                
                for(int i = 0;i < l;++i){
                    a[m] = M[it][it + i];
                    b[m] = M2[it][it + i];
                    ++m;
                }
                
                for(int i = 1;i + 1 < l;++i){
                    a[m] = M[it + i][it + l - 1];
                    b[m] = M2[it + i][it + l - 1];
                    ++m;
                }
                
                for(int i = 0;i < l;++i){
                    a[m] = M[n - 1 - it][it + l - 1 - i];
                    b[m] = M2[n - 1 - it][it + l - 1 - i];
                    ++m;
                }
                
                for(int i = l - 2;i >= 1;--i){
                    a[m] = M[it + i][it];
                    b[m] = M2[it + i][it];
                    ++m;
                }
            }
            
            int s = -1;
            
            for(int i = 0;i < m;++i){
                if(a[i] == b[0]){
                    s = i;
                    break;
                }
            }
            
            if(s == -1) ok = false;
            else{
                for(int i = 0;i < m;++i)
                    if(b[i] != a[(s + i) % m])
                        ok = false;
            }
        }
        
        printf("%d. %s\n",tc++,ok? "YES" : "NO");
    }
    
    return 0;
}
