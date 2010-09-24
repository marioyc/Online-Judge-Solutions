#include<cstdio>
#include<set>

using namespace std;

int main(){    
    bool p[10000];
    fill(p,p+10000,true);
    
    set<int> S;    
    int sum=0;
    int a[1230];
    a[0]=0;
    int P[1229];
    
    for(int i=2,j=0;i<10000;i++)
        if(p[i]){
            sum+=i;
            S.insert(sum);
            P[j]=i;
            a[++j]=sum;
            
            for(int j=i*i;j<10000;j+=i) p[j]=false;
        }
    
    int n,cont;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        cont=0;
        
        for(int i=0;P[i]<=n && i<1229;i++)
            if(S.find(n+a[i])!=S.end()) cont++;
        
        printf("%d\n",cont);
    }    
    
    return 0;
}
