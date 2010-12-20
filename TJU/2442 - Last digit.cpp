#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool p[1000000];
int P[78498],sz = 0;

void getPrimes(){
    memset(p,true,sizeof(p));
    
    for(int i = 2;i<1000000;++i){
        if(p[i]){
            P[sz++] = i;
            
            if(i<1000)
                for(int j = i*i;j<1000000;j += i)
                    p[j] = false;
        }
    }
}

void getExponents(int n, int *exp){
    fill(exp,exp+sz,0);
    if(n<=1) return;
    
    for(int i = 0,aux;i<sz;++i){
        aux = n;
        
        while(aux!=0){
            exp[i] += aux/P[i];
            aux /= P[i];
        }
    }
}

int pow(int a, int b){
    if(b==0) return 1;
    
    int ret = pow(a,b/2);
    ret = (ret*ret)%10;
    if(b & 1) ret = (ret*a)%10;
    
    return ret;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    
    getPrimes();
    
    int exp[3][sz];
    getExponents(n,exp[0]);
    getExponents(m,exp[1]);
    getExponents(n-m,exp[2]);
    
    for(int i = 0;i<sz;++i)
        exp[0][i] -= exp[1][i]+exp[2][i];
    
    int x = min(exp[0][0],exp[0][2]);
    exp[0][0] -= x;
    exp[0][2] -= x;
    
    int ans = 1;
    for(int i = 0;i<sz;++i) ans = (ans*pow(P[i],exp[0][i]))%10;
    
    printf("%d\n",ans);
    
    return 0;
}
