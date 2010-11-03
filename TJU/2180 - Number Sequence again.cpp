#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,a,b,a0;
    scanf("%d",&N);
    
    for(int tc=1;tc<=N;++tc){
        scanf("%d/%d",&a,&b);
        
        if(a%b==0) a0 = a/b-1;
        else if(a<0) a0 = -(-a+b-1)/b;
        else a0 = a/b;
        
        printf("case %d: [%d",tc,a0);
        a -= a0*b;
        
        if(a==b) printf(",1");
        else if(a!=0){
            while(b%a!=0){
                printf(",%d",b/a);
                swap(a,b);
                a -= a/b*b;
            }
            
            printf(",%d,1",b/a-1);
        }
        
        printf("]\n");
    }
    
    return 0;
}
