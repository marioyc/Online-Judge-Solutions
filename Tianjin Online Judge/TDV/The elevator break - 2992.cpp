#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n;
    long long min_discontent,a,b;
    int C[5000];
    int U[5000];
    int D[5000];
    int S1[5000];
    int S2[5000];
    
    scanf("%d",&n);
    
    for(int i=0;i<n;i++) scanf("%d",&C[i]);
    
    for(int i=0;i<n;i++){
        cin>>a>>b;
        U[i]=a*C[i];
        D[i]=b*C[i];
    }
    
    S1[0]=S2[n-1]=0;    
    for(int i=1;i<n;i++){
        S1[i]=S1[i-1]+U[i-1];
        S2[n-i-1]=S2[n-i]+D[n-i];
    }
        
    a=0; // costo de subir    
    
    b=0; //costo de bajar
    for(int i=1;i<n;i++) b+=i*D[i];
    
    min_discontent=a+b;
        
    for(int i=1;i<n;i++){
        a+=S1[i];
        b-=S2[i-1];
        
        if(a+b<min_discontent) min_discontent=a+b;
    }
    
    cout<<min_discontent<<endl;
    
    return 0;
}
