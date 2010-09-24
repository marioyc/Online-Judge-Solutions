#include<cstdio>

using namespace std;

int main(){
    int n,k,cont,res;
    
    while(scanf("%d %d",&n,&k)==2){
        cont=0;
        res=0;
        
        while(n>0){
            cont+=n;
            res+=n;
            n=res/k;
            res%=k;
        }
        
        printf("%d\n",cont);
    }
    
    return 0;
}
