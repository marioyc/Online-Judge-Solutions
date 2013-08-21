#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int n,m;
    int M1[100][100],M2[100][100];
    long long flip1,flip2;
    pair<long long, long long> c1[100],c2[100],c3[100];
    
    while(true){
        scanf("%d %d",&n,&m);
        if(n < 0 || m < 0) break;
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j < m;++j)
                scanf("%d",&M1[i][j]);
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j < m;++j)
                scanf("%d",&M2[i][j]);
        
        for(int j = 0;j < m;++j){
            long long cj1 = 0,cj2 = 0;
            
            for(int i = 0;i < n;++i){
                if(M1[i][j]){
                    if(i < 50) cj1 |= (1LL << i);
                    else cj2 |= (1LL << (i - 50));
                }
            }
            
            c1[j].first = cj1; c1[j].second = cj2;
        }
        
        for(int j = 0;j < m;++j){
            long long cj1 = 0,cj2 = 0;
            
            for(int i = 0;i < n;++i){
                if(M2[i][j]){
                    if(i < 50) cj1 |= (1LL << i);
                    else cj2 |= (1LL << (i - 50));
                }
            }
            
            c2[j].first = cj1; c2[j].second = cj2;
        }
        
        sort(c2,c2 + m);
        bool found = false;
        
        for(int i = 0;i < m && !found;++i){
            flip1 = flip2 = 0;
            
            for(int j = 0;j < n;++j){
                if(M1[j][0] != M2[j][i]){
                    if(j < 50) flip1 |= (1LL << j);
                    else flip2 |= (1LL << (j - 50));
                }
            }
            
            for(int j = 0;j < m;++j){
                c3[j].first = (c1[j].first ^ flip1);
                c3[j].second = (c1[j].second ^ flip2);
            }
            
            sort(c3,c3 + m);
            
            found = true;
            
            for(int j = 0;j < m;++j)
                if(c2[j] != c3[j]) found = false;
        }
        
        printf("%s\n",found? "Yes" : "No");
    }
    
    return 0;
}
