#include<cstdio>
#include<numeric>

using namespace std;

int main(){
    int N;
    
    scanf("%d",&N);
    
    int a[N];
    int p[N];
    
    for(int i=0;i<N;i++) scanf("%d %d",&a[i],&p[i]);
    
    printf("%.2f\n",inner_product(a,a+N,p,0)*1.0/accumulate(a,a+N,0));
    
    return 0;
}
