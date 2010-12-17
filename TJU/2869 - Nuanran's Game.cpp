#include <cstdio>
#include <algorithm>

using namespace std;

struct EuclidReturn{
    int u,v,d;
	
    EuclidReturn(int _u, int _v, int _d){
        u = _u; v = _v; d = _d;
    }
};
    
EuclidReturn Extended_Euclid(int a, int b){
    if(b==0) return EuclidReturn(1,0,a);
    EuclidReturn aux = Extended_Euclid(b,a%b);
    int v = aux.u-(a/b)*aux.v;
    return EuclidReturn(aux.v,v,aux.d);
}

int main(){
    int x,y,z,n;
    
    while(scanf("%d %d %d %d",&x,&y,&z,&n)==4){
        int g2 = __gcd(y,z);
        EuclidReturn ret1 = Extended_Euclid(x,g2);
        
        if(n%ret1.d==0){
            // a0*x + b*gcd(y,z) = gcd(x,y,z), a0>=0
            int a0 = (ret1.u%(g2/ret1.d)+(g2/ret1.d))%(g2/ret1.d);
            int b = (ret1.d-a0*x)/g2;
            
            // a0*x + b*gcd(y,z) = n
            a0 *= n/ret1.d;
            b *= n/ret1.d;
            
            // a1*y + a2*z = gcd(y,z)
            EuclidReturn ret2 = Extended_Euclid(y,z);
            int a1,a2;
            
            if(b==0){
                a1 = a2 = 0;
            }else if(b>0){
                a2 = (ret2.v%(y/ret2.d)+(y/ret2.d))%(y/ret2.d);
                if(a2>0) a2 -= y/ret2.d;
                a1 = (g2-a2*z)/y;
                
                // a1*y + a2*z = b*gcd(y,z)
                a1 *= b;
                a2 *= b;
            }else{
                a1 = (ret2.u%(z/ret2.d)+(z/ret2.d))%(z/ret2.d);
                if(a1>0) a1 -= z/ret2.d;
                a2 = (g2-a1*y)/z;
                
                // a1*y + a2*z = b*gcd(y,z)
                a1 *= b;
                a2 *= b;
            }
            
            printf("%d %d %d\n",a0,a1,-a2);
        }else{
            printf("-1\n");
        }
    }
    
    return 0;
}
