#include <cstdio>

using namespace std;

int u[22000],v[22000],w[22000],ne;
int dist[1001];

int main(){
    int N,M,l,r,a,b;
    
    while(scanf("%d %d",&N,&M) == 2){
        ne = 0;
        
        for(int i = 0;i < M;++i){
            scanf("%d %d %d %d",&l,&r,&a,&b);
            u[ne] = l - 1; v[ne] = r; w[ne] = b; ++ne;
            u[ne] = r; v[ne] = l - 1; w[ne] = -a; ++ne;
        }
        
        for(int i = 1;i <= N;++i){
            u[ne] = i - 1; v[ne] = i; w[ne] = 10000; ++ne;
            u[ne] = i; v[ne] = i - 1; w[ne] = 10000; ++ne;
        }
        
        bool found;
        dist[0] = 0;
        
        for(int i = 1;i <= N;++i)
            dist[i] = 10000000;
        
        for(int i = 0;i <= N;++i){
            found = false;
            
            for(int j = 0;j < ne;++j){
                if(dist[ v[j] ] > dist[ u[j] ] + w[j]){
                    dist[ v[j] ] = dist[ u[j] ] + w[j];
                    found = true;
                }
            }
        }
        
        if(found) printf("The spacecraft is broken!\n");
        else{
            for(int i = 0;i < N;++i)
                printf("%d%c",dist[i + 1] - dist[i],i == N - 1? '\n':' ');
        }
    }
    
    return 0;
}
