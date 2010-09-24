#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int t,N;
    int a[20];
    
    cin>>t;
    
    for(int caso=0;caso<t;caso++){
        cin>>N;
        
        for(int i=0;i<N;i++) cin>>a[i];
        
        for(int i=0;i<N-1;i++)
            for(int j=0;j<N-i-1;j++) a[j]=a[j+1]-a[j];
        
        cout<<a[0]<<endl;
    }
    
    return 0;
}
