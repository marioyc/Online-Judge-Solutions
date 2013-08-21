#include <cstdio>

using namespace std;

int main(){
    int n,m,c;
    long long ax = 0,bx = 0,cx = 0,ay = 0,by = 0,cy = 0;
    
    scanf("%d %d",&n,&m);
    
    for(int i = 0;i < n;++i){
        for(int j = 0;j < m;++j){
            scanf("%d",&c);
            
            ax += c;
            bx += (4 * i + 2) * c;
            cx += (long long)(4 * i + 2) * (4 * i + 2) * c;
            
            ay += c;
            by += (4 * j + 2) * c;
            cy += (long long)(4 * j + 2) * (4 * j + 2) * c;
        }
    }
    
    ax *= 16; bx *= -8;
    ay *= 16; by *= -8;
    
    long long bestx = cx,besty = cy;
    int X = 0,Y = 0;
    
    for(int i = 1;i <= n;++i){
        long long aux = ax * i * i + bx * i + cx;
        if(aux < bestx){
            bestx = aux;
            X = i;
        }
    }
    
    for(int i = 1;i <= m;++i){
        long long aux = ay * i * i + by * i + cy;
        if(aux < besty){
            besty = aux;
            Y = i;
        }
    }
    
    printf("%I64d\n%d %d\n",bestx + besty,X,Y);
    
    return 0;
}
