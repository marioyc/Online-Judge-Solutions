#include<cstdio>
#include<algorithm>

using namespace std;

int p[100000];

int main(){    
    fill(p,p+100000,true);
    
    int cont=0;
    int P[9592];
    
    for(int i=2;i<100000;i++)
        if(p[i]){
            P[cont++]=i;
            if(i<317) for(int j=i*i;j<100000;j+=i) p[j]=false;
        }
    
    int n,k;
    
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        printf("%d\n",P[k-1]);
    }
    
    return 0;
}
