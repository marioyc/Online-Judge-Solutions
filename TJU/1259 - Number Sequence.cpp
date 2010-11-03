#include <cstdio>

using namespace std;

int digits(int n){
    int res = 0;
    
    while(n>0){
        n/=10;
        ++res;
    }
    
    return res;
}

int solve(int P){
    for(int n=0,i=1;;++i){
        int d = digits(i);
        if(n+d>=P){
            int last = n+d,aux = i;
            while(last!=P){
                --last;
                aux /= 10;
            }
            return aux%10;
        }else n += d;
    }
    
    return -1;
}

int main(){
    int T,P;
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d",&P);
        
        int D = 0;
        
        for(int i=1;;++i){
            int d = digits(i);
            if(D+d<P) P -= D+d;
            else break;
            D += d;
        }
        
        printf("%d\n",solve(P));
    }
    
    return 0;
}
