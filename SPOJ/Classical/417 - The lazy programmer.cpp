#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct job{
    int a,b,d;
    
    job(){}
    
    bool operator < (job X)const{
        if(d != X.d) return d < X.d;
        return a > X.a;
    }
}J[100000];

double eps = 1e-10;

int main(){
    int T,n;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        for(int i = 0;i < n;++i)
            scanf("%d %d %d",&J[i].a,&J[i].b,&J[i].d);
        
        sort(J,J + n);
        
        priority_queue< pair<int, double> > Q;
        pair<int, double> P;
        
        double T = 0,ans = 0,x;
        
        for(int i = 0;i < n;++i){
            T += J[i].b;
            
            Q.push(make_pair(J[i].a,(double)J[i].b / J[i].a));
            
            while(T > J[i].d){
                P = Q.top();
                Q.pop();
                
                if(T - P.first * P.second > J[i].d){
                    T -= P.first * P.second;
                    ans += P.second;
                }else{
                    x = (T - J[i].d) / P.first;
                    T -= P.first * x;
                    ans += x;
                    Q.push(make_pair(P.first,P.second - x));
                }
            }
        }
        
        printf("%.2f\n",ans);
    }
    
    return 0;
}
