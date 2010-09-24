#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T, N, cont;
    
    int M[12]={5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625};
    
    cin>>T;
    
    for(int i=0;i<T;i++){
        cin>>N;
        
        cont=0;
        
        for(int j=0;j<12;j++) cont+=N/M[j];
        
        cout<<cont<<endl;
    }
}
