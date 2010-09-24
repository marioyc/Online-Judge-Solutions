#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int N,L;
    
    cin>>N;
    
    int sum,ax;
    
    for(int i=0;i<N;i++){
        
        sum=1;
        cin>>L;
        
        for(int j=0;j<L;j++){
            cin>>ax;
            sum+=ax;
        }
        
        sum-=L;
        
        cout<<sum<<endl;
    }

    return 0;
}
