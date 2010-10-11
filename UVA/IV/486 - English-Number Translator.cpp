#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const string names1[] = {"zero","one","two","three","four","five","six","seven",
                    "eight","nine","ten","eleven","twelve","thirteen","fourteen",
                    "fifteen","sixteen","seventeen","eighteen","nineteen"};

const string names2[] = {"","","twenty","thirty","forty","fifty","sixty","seventy",
                    "eighty","ninety"};

int convert(vector<string> &v){
    int N1 = 0,N2 = 0,n = v.size(),s = 0;
    
    if(v[0]=="hundred"){
        N1 = 1;
        s = 1;
    }
    
    if(n>=2 && v[1]=="hundred"){
        for(int i = 1;i<10;++i)
            if(v[0]==names1[i])
                N1 = i;
        
        s = 2;
    }
    
    if(n-s>0){
        if(n==s+1){
            for(int i = 1;i<20;++i)
                if(v[s]==names1[i])
                    N2 = i;
            
            for(int i = 2;i<10;++i)
                if(v[s]==names2[i])
                    N2 = i*10;
        }else{
            int N3 = 0,N4 = 0;
            
            for(int i = 2;i<10;++i)
                if(v[s]==names2[i])
                    N3 = i;
            
            for(int i = 1;i<10;++i)
                if(v[s+1]==names1[i])
                    N4 = i;
            
            N2 = 10*N3+N4;
        }
    }
    
    return N1*100+N2;
}

int main(){
    string s,aux;
    vector<string> v;
    int sign,A,B,C,ans;
    
    while(getline(cin,s)){
        sign = 1;
        
        if(s=="zero") ans = 0;
        else{
            istringstream is(s);
            
            if(s.find("negative")!=string::npos){
                sign = -1;
                is>>aux;
            }
            
            A = B = C = 0;
            
            if(s.find("million")!=string::npos){
                v.clear();
                
                while(true){
                    is>>aux;
                    if(aux=="million") break;
                    v.push_back(aux);
                }
                
                if(!v.empty()) A = convert(v);
                else A = 1;
            }
            
            if(s.find("thousand")!=string::npos){
                v.clear();
                
                while(true){
                    is>>aux;
                    if(aux=="thousand") break;
                    v.push_back(aux);
                }
                
                if(!v.empty()) B = convert(v);
                else B = 1;
            }
            
            v.clear();
            while(is>>aux) v.push_back(aux);
            if(!v.empty()) C = convert(v);
            
            ans = A;
            ans = ans*1000+B;
            ans = ans*1000+C;
            
            
        }
        
        if(sign==-1) cout<<"-";
        cout<<ans<<endl;
    }
    
    return 0;
}
