#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int N,n,ax;
    cin>>N;
    
    for(int i=0;i<N;i++){
        cin>>n;
        ax=((n*n+n)/2)*((n*n+5*n+6)/2)/2;
        cout<<i+1<<" "<<n<<" "<<ax<<endl;
    }

    return 0;
}
