#include<cstdio>
#include<algorithm>

using namespace std;

bool p[1000000];

int main(){
    fill(p,p+1000000,true);
    p[0]=p[1]=false;
    
    for(long long i=2;i<1000000;i++)
        if(p[i])
            for(long long j=i*i;j<1000000;j+=i) p[j]=false;
    
    int a,d,n,x;
    
    while(1){
        scanf("%d %d %d",&a,&d,&n);
        if(a==0 && d==0 && n==0) break;
        
        x=a;
        
        for(int i=0;i<n;x+=d){
            if(p[x]) i++;
        }
        
        printf("%d\n",x-d);
    }
    
    return 0;
}
