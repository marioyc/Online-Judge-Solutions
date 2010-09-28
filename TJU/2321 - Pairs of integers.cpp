#include <cstdio>
#include <set>

using namespace std;

int d[9],cont,M,x;

set<int> S;

void search(int n){
    if(n%11<10){
        x=10*(n/11)+(n%11);
        
        for(int i=cont-1;i>=0;i--) x=10*x+d[i];
        
        S.insert(x);
    }
    
    if(n%2==0 && n>0){
        int d1=(n%10)/2;
        int d2=d1+5;
        
        cont++;
        
        if(n>2*d1){
            d[cont-1]=d1;
            search((n-d1)/10);
        }
        
        if(n>2*d2){
            d[cont-1]=d2;
            search((n-d2)/10);
        }
        
        cont--;
    }
}

int dig(int n){
    if(n==0) return 1;
    
    cont=0;
    
    while(n!=0){
        n/=10;
        cont++;
    }
    
    return cont;
}

int main(){
    int N;
    
    scanf("%d",&N);
    
    cont=0;
    search(N);
    
    int sz=S.size(),aux;
    set<int> :: iterator it;
    
    printf("%d\n",sz);
    for(it=S.begin();it!=S.end();it++){
        aux=(*it);
        
        printf("%d + ",aux);
        for(int j=dig(aux)-dig(N-aux)-1;j>0;j--) printf("0");
        printf("%d = %d\n",N-aux,N);
    }
    
    return 0;
}
