#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N,R,Q,aux,x,pos,caso;
    vector<int> I;
    vector<int> J;
    
    caso=1;
    
    while(1){
        cin>>N;
        if(N==0) break;
        
        cin>>R;
        
        I.clear();
        J.clear();
        
        for(int i=0;i<R;i++){
            cin>>aux;
            I.push_back(aux);
            
            cin>>aux;
            J.push_back(aux);
        }
        
        cin>>Q;
        
        cout<<"Genome "<<caso<<endl;
        caso++;
        
        for(int i=0;i<Q;i++){
            cin>>x;
            
            for(int j=0;j<R;j++)
                if(I[j]<=x && x<=J[j]) x=I[j]+J[j]-x;
            
            cout<<x<<endl;
        }
    }
    
    return 0;
}
