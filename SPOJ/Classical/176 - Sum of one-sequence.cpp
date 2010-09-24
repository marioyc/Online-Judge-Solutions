#include <cstdio>
#define abs(x) x<0? -x:x

using namespace std;

void solve(int &n, int &S){
    if((abs(S))%2 != (n*(n-1)/2)%2 || S > n*(n-1)/2 || S < -n*(n-1)/2){
        printf("No\n");
        return;
    }
    
    printf("0\n");
    int a=0;
    
    for(int i=n-1;i>0;i--){
        if(S+i <= i*(i-1)/2){
            a--;
            S+=i;
        }else{
            a++;
            S-=i;
        }
        
        printf("%d\n",a);
    }
}

int main(){    
    int t,n,S;
    
    scanf("%d",&t);
    
    for(int tc=1;tc<=t;tc++){
        scanf("%d %d",&n,&S);
        solve(n,S);
    }
    
    return 0;
}
