#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int M,N;
    cin>>M>>N;
    
    map<int,int> F;
    vector<string> v;
    string s;
    
    for(int i=0;i<M;i++){
        cin>>s;
        v.push_back(s);
    }
    
    int cont;

    for(int i=0;i<N;i++){
        cont=0;
        for(int j=0;j<M;j++){
            if(v[j][i]=='0') cont++;
            if(v[j][i]=='1'){
                if(cont!=0) F[cont]++;
                cont=0;
            }
        }
        if(cont!=0) F[cont]++;
    }

    map<int,int> :: iterator it;
    for(it=F.begin();it!=F.end();it++) cout<<(*it).first<<" "<<(*it).second<<endl;

    return 0;
}
