#include<iostream>
#include<algorithm>

using namespace std;

int MAX(int n){
    int cont=0;
    
    while(n!=0){
        n/=2;
        cont++;
    }
    
    return cont;
}

int main(){    
    int n,m;
    
    cin>>n>>m;
    
    int a[n];
    
    for(int i=0;i<n;i++) cin>>a[i];
    
    int cont=0;
    
    for(int i=0;i<n;i++) if(a[i]<a[m]) cont++;
    
    cout<<(cont==n-1? MAX(cont):0)<<" "<<MAX(cont)<<endl;
    
    return 0;
}
