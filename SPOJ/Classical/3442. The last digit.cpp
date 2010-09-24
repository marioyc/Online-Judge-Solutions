#include <cstdio>

using namespace std;

int pot(int a, int b){
    if(b==0) return 1;
    
    int aux=pot(a,b/2);
    
    if(b%2==0) return (aux*aux)%10;
    else return (a*aux*aux)%10;
}

int main(){    
    int t,a,b;
    
    scanf("%d",&t);
    
    for(int tc=1;tc<=t;tc++){
        scanf("%d %d",&a,&b);        
        a%=10;        
        printf("%d\n",pot(a,b));
    }
}
