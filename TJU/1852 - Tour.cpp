#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define MAX_N 1000

double x[MAX_N],y[MAX_N];

double dist(int a, int b){
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

double memo[MAX_N][MAX_N];

double solve(int p1, int p2, int next){
    if(next==0) return dist(0,p1)+dist(0,p2);
    
    double &ret = memo[p1][p2];
    if(ret>-0.5) return ret;
    
    ret = fmin(dist(p1,next)+solve(next,p2,next-1),
            dist(p2,next)+solve(p1,next,next-1));
    
    return ret;
}

int main(){
    int N;
    
    while(scanf("%d",&N)==1){
        for(int i = 0;i<N;++i)
            scanf("%lf %lf",&x[i],&y[i]);
        
        memset(memo,-1,sizeof(memo));
        
        printf("%.2lf\n",solve(N-1,N-1,N-2));
    }
    
    return 0;
}
