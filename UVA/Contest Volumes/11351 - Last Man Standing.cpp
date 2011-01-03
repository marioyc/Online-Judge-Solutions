#include <cstdio>

using namespace std;

int survivor(const int &n, const int &m){
   int i, s;
   
   for (s = 0, i = 1; i <= n; i++) s = (s + m) % i;

   return (s + 1);
}


int main(){
    int T,n,k;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&n,&k);
        
        printf("Case %d: %d\n",tc,survivor(n,k));
    }
    
    return 0;
}
