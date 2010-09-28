#include <iostream>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int N,M,i,j,cont;
    cin>>N;
    string s;
    for(i=1;i<=N;i++){
        cin>>M;
        cont=0;
        for(j=0;j<M;j++){
            cin>>s;
            if(s=="sheep") cont++;
        }
        cout<<"Case "<<i<<": This list contains "<<cont<<" sheep."<<endl;
        if(i!=N) cout<<endl;
    }

    return 0;
}
