#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,r,e,c;
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&r,&e,&c);        
        
        e-=c;
        
        if(e<r) cout<<"do not advertise"<<endl;
        else if(e>r) cout<<"advertise"<<endl;
        else cout<<"does not matter"<<endl;
    }

    return 0;
}
