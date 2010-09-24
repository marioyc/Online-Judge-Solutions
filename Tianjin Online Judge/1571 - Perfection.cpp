#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,sum,raiz;
    
    cout<<"PERFECTION OUTPUT"<<endl;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        sum=0;
        for(int i=1;i<sqrt(n);i++)
            if(n%i==0) sum+=i+n/i;
            
        sum-=n;
            
        raiz=round(sqrt(n));
        
        if(raiz*raiz==n) sum+=raiz;
        
        cout<<setw(5)<<n;
        
        if(sum==n) cout<<"  PERFECT"<<endl;
        else if(sum<n) cout<<"  DEFICIENT"<<endl;
        else cout<<"  ABUNDANT"<<endl;
    }

    cout<<"END OF OUTPUT"<<endl;

    return 0;
}
