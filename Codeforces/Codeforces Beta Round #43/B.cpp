#include <iostream>
#include <string>

using namespace std;

int getShirtId(string s){
    if(s=="S") return 0;
    if(s=="M") return 1;
    if(s=="L") return 2;
    if(s=="XL") return 3;
    return 4;
}

string getShirtString(int id){
    if(id==0) return "S";
    if(id==1) return "M";
    if(id==2) return "L";
    if(id==3) return "XL";
    return "XXL";
}

int main(){
    int N,cont[5];
    string s;
    
    for(int i = 0;i<5;++i)
        cin>>cont[i];
    
    cin>>N;
    
    for(int i = 0;i<N;++i){
        cin>>s;
        int id = getShirtId(s);
        int takes = -1;
        
        for(int i = 0;i<=4;++i){
            if(id+i<5 && cont[id+i]>0){
                --cont[id+i];
                takes = id+i;
                break;
            }
            
            if(id-i>=0 && cont[id-i]>0){
                --cont[id-i];
                takes = id-i;
                break;
            }
        }
        
        cout<<getShirtString(takes)<<endl;
    }
    
    return 0;
}
