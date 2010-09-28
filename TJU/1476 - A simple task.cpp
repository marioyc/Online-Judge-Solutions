#include <iostream>
using namespace std;

int n,i;

int main(){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    cin>>n;
    while(cin>>n){
        i=0;
        while((n&(1<<i))==0){
            i++;
        }
        cout<<(n>>i)<<" "<<i<<endl;
    }
    return 0;
}
