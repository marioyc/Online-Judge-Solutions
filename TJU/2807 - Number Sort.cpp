#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int num_dig(int x){
    int ret = 0;
    
    while(x){
        x /= 10;
        ++ret;
    }
    
    return ret;
}

int get_dig(int d, int x){
    if(d == 0) return x % 10;
    return get_dig(d - 1,x / 10);
}

int main(){
    int tc = 1,N,a[1000];
    pair<int, int> P[1000];
    
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        
        for(int i = 0;i < N;++i)
            scanf("%d",&a[i]);
        
        int D = 1;
        
        for(int i = 0;i < N;++i)
            D = max(D,num_dig(a[i]));
        
        printf("Case %d:\n",tc++);
        
        for(int i = 0;i < D;++i){
            for(int j = 0;j < N;++j)
                P[j] = make_pair(get_dig(i,a[j]),a[j]);
            
            sort(P,P + N);
            
            for(int j = 0;j < N;++j){
                if(j > 0) putchar(' ');
                printf("%d",P[j].second);
            }
            
            putchar('\n');
        }
    }
    
    return 0;
}
