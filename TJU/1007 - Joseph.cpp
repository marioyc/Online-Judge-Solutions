#include<iostream>

using namespace std;

int m[]={2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n;
    
    while(1){
        cin>>n;
        
        if(n==0) break;
        
        cout<<m[n-1]<<endl;
    }
}

/*int n,i;

bool f(int a){
    i=0;
    
    for(int j=0;j<n;j++){
        i=(i+a-1)%(2*n-j);
        if(i<n) return false;
    }
    
    return true;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    while(1){
        cin>>n;
        
        if(n==0) break;
        
        for(int m=n+1;;m++){
            if(f(m)){
                cout<<m<<",";
                break;
            }
        }
    }
        
    return 0;
}*/
