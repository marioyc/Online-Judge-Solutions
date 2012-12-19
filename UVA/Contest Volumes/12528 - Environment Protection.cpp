#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXK 8
#define PARTS 4900

int W,D,A,K;
double p1[MAXK + 1],q1[MAXK + 1];
double p2[MAXK + 1],q2[MAXK + 1];
double P1,Q1,P2,Q2;
double f1[2 * PARTS + 1],f2[2 * PARTS + 1];

inline double calc(int pos, double mi){
    return max(f1[pos],-mi) - max(f2[pos],-mi);
}

int main(){
    while(scanf("%d %d %d %d",&W,&D,&A,&K) == 4){
        for(int i = 0;i <= K;++i) scanf("%lf",&p1[i]);
        for(int i = 0;i <= K;++i) scanf("%lf",&q1[i]);
        for(int i = 0;i <= K;++i) scanf("%lf",&p2[i]);
        for(int i = 0;i <= K;++i) scanf("%lf",&q2[i]);
        double dx = (double)W / 2 / PARTS,curx = 0,P1;
        
        for(int i = 2 * PARTS,pos = 0;i >= 0;--i, curx += dx, ++pos){
            P1 = Q1 = P2 = Q2 = 0;
            
            for(int i = K;i >= 0;--i){
                P1 = P1 * curx + p1[i];
                Q1 = Q1 * curx + q1[i];
                P2 = P2 * curx + p2[i];
                Q2 = Q2 * curx + q2[i];
            }
            
            f1[pos] = P1 / Q1;
            f2[pos] = P2 / Q2;
        }
        
        double lo = 0,hi = D,mi;
        
        for(int it = 0;it < 29;++it){
            mi = (lo + hi) / 2.0;
            
            double sum0 = calc(0,mi) + calc(2 * PARTS,mi),sum1 = 0,sum2 = 0;
            
            for(int i = 1,pos = 2;i < PARTS;++i,pos += 2)
                sum1 += calc(pos,mi);
            
            for(int i = 0,pos = 1;i < PARTS;++i,pos += 2)
                sum2 += calc(pos,mi);
            
            if((sum0 + 2 * sum1 + 4 * sum2) * dx / 3 > A) hi = mi;
            else lo = mi;
        }
        
        printf("%.5f\n",lo);
    }
    
    return 0;
}
