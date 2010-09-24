/*
ID:zion_ba1
LANG:C++
TASK:evenodd
*/

#include <iostream>

using namespace std;

int main(){
    freopen("evenodd.in","r",stdin);
    freopen("evenodd.out","w",stdout);
    
    int N,x;
    cin>>N;
    
    for(int i=0;i<N;i++){
        cin>>x;
        if(x&1) cout<<"odd"<<endl;
        else cout<<"even"<<endl;
    }
    
    return 0;
}
