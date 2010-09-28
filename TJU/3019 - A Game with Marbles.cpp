#include<iostream>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out2.txt","w",stdout);
    
    int n;
    int m[50];
    long long tot;
    
    while(1){
        cin>>n;
        if(n==0) break;
        
        for(int i=0;i<n;i++) cin>>m[i];
        
        tot=0;
                
        for(long long i=0,j=1;i<n;i++){
            tot+=j*m[i];
            j*=2;
        }
        
        cout<<tot<<endl;
    }
    
    return 0;
}
