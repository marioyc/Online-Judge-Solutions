#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    vector<string> complex;
    vector<string> map;
    
    int B1,B2,D1,D2,cont;
    string s;
    bool ok;
    
    while(1){
        cin>>B1>>B2;
        if(B1==0 && B2==0) break;
        
        complex.clear();
        map.clear();
        
        for(int i=0;i<B1;i++){
            cin>>s;
            complex.push_back(s);
        }
        
        cin>>D1>>D2;
        
        for(int i=0;i<D1;i++){
            cin>>s;
            map.push_back(s);
        }
        
        cont=0;        
        
        for(int i=0;i+B1-1<D1;i++){
            for(int j=0;j+B2-1<D2;j++){
                ok=true;
                    
                for(int I=0;I<B1 && ok;I++)
                    for(int J=0;J<B2 && ok;J++)
                        if(complex[I][J]=='#' && map[I+i][J+j]=='.') ok=false;
                    
                if(ok) cont++;
            }
        }
        
        cout<<cont<<endl;
    }
    
    return 0;
}
