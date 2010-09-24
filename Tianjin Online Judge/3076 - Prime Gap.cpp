#include<cstdio>
#include<algorithm>

using namespace std;

bool p[1299710];
int P[100000];

int main(){    
    fill(p,p+1299710,true);
    
    
    for(int i=2,j=0;i<1299710;i++)
        if(p[i]){
            P[j++]=i;
            if(i<1141) for(int j=i*i;j<1299710;j+=i) p[j]=false;
        }
    
    int n,hi,lo,mi;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        lo=0; hi=99999;
        
        while(lo!=hi){
            mi=lo+(hi-lo+1)/2;
            
            if(n>P[mi]) lo=mi;
            else if(n<P[mi]) hi=mi-1;
            else lo=hi=mi;
        }
        
        if(n==P[lo]) printf("0\n");
        else printf("%d\n",P[lo+1]-P[lo]);
    }
    
    return 0;
}
