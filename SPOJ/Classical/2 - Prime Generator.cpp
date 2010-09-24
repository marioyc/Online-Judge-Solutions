#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

bool sieve[31622];
vector<int> primo;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    //si N es un número compuesto y p su menor divisor entero p<=sqrt(N)
    
    memset(sieve,true,sizeof(sieve));
    
    sieve[0]=sieve[1]=false;
    
    for(int i=2;i<31622;i++){
        if(sieve[i]){
            primo.push_back(i);
            
            for(int j=2;j*i<31622;j++) sieve[i*j]=false;
        }
    }
    
    int t,m,n;
    int sieve2[100001];
    
    scanf("%d",&t);
    
    for(int i=0;i<t;i++){
        scanf("%d %d",&m,&n);
        
        if(i!=0) printf("\n");
        
        fill(sieve2,sieve2+n-m+1,true);
        
        if(m==1) sieve2[0]=false;
        
        for(int j=0;j<primo.size();j++)
            for(int k=(m+primo[j]-1)/primo[j]*primo[j];k<=n;k+=primo[j])
                if(k!=primo[j]) sieve2[k-m]=false;
        
        for(int j=m;j<=n;j++)
            if(sieve2[j-m]) printf("%d\n",j);
    }
    
    return 0;
}
