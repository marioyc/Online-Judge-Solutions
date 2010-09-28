#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

struct segment{
    double x1,x2;
    
    segment(){
    }
    
    bool operator < (segment X) const{
        if(x1 != X.x1) return x1<X.x1;
        return x2<X.x2;
    }
};

int main(){    
    int n,bx,by,cx,cy,r,d;
    double a,b,x1,x2;
    segment M[500];
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        scanf("%d %d",&bx,&by);
        
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&cx,&cy,&r);
            d=(bx-cx)*(bx-cx)+(by-cy)*(by-cy);
            
            a=(bx-cx)*1.0/(by-cy);
            b=sqrt(d-r*r)/r;
            
            x1=bx-by*(1+b*a)/(b-a);
            x2=bx-by*(b*a-1)/(b+a);
            
            M[i].x1=x1;
            M[i].x2=x2;
        }
        
        sort(M,M+n);
        
        x1=M[0].x1;
        x2=M[0].x2;
        
        for(int i=1;i<n;i++){
            if(M[i].x1>x2){
                printf("%.2f %.2f\n",x1,x2);
                x1=M[i].x1;
                x2=M[i].x2;
            }else if(M[i].x1<=x2 && M[i].x2>x2) x2=M[i].x2;
        }
        
        printf("%.2f %.2f\n\n",x1,x2);
    }
    
    return 0;
}
