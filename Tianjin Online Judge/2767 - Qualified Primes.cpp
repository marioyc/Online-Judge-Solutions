#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

bool p[4000001];

int main(){    
    int A,B,D;
    
    scanf("%d %d %d",&A,&B,&D);
    
    fill(p,p+4000001,true);
    p[1]=false;
    
    double root=sqrt(B);
    
    for(int i=2;i<=root && i<=2000;i++)
        if(p[i]){
            for(int j=i*i;j<=B;j+=i) p[j]=false;
        }
    
    int cont=0;
    
    for(int i=A;i<=B;i++)
        if(p[i]){
            for(int x=i;x!=0;x/=10)
                if(x%10==D){
                    cont++;
                    break;
                }
        }
    
    printf("%d\n",cont);
    
    return 0;
}
