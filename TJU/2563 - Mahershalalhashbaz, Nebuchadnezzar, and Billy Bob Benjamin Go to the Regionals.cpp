#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int main(){    
    int n,k,sum,caso=0;
    char name[81];
    int a[1000];
    bool ok;
    
    while(1){
        scanf("%d %d\n",&n,&k);
        if(n==0 && k==0) break;
        
        for(int i=0;i<n;i++){
            scanf("%s",name);
            a[i]=strlen(name);
        }
        
        sort(a,a+n);
        
        ok=true;
        
        for(int i=0;i<n/k && ok;i++){
            sum=0;
            for(int j=0;j<k;j++) sum+=a[k*i+j];
            
            for(int j=0;j<k && ok;j++)
                if(abs(k*a[k*i+j]-sum)>2*k) ok=false;
        }
        
        if(caso!=0) printf("\n");
        
        caso++;
        
        if(ok) printf("Case %d: yes\n",caso);
        else printf("Case %d: no\n",caso);
    }
    
    return  0;
} 
