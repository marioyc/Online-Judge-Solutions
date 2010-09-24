#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
	
	int T,a,b;
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&a,&b);
        printf("%d\n",__gcd(a,b));
    }        

    return 0;
}

