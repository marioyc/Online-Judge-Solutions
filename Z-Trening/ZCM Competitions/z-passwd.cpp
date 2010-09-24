#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
    int n;
    map<string, int> M;
    
    cin>>n;
    
    string s;
    
    for(int i=0;i<n;i++){
        cin>>s;
        M[s]++;
    }
    
    int cont=0;
    
    for(int i=0;i<n;i++){
        cin>>s;
        if(M[s]>0){
            M[s]--;
            cont++;
        }
    }
    
    cout<<cont<<endl;
    
    return 0;
}
