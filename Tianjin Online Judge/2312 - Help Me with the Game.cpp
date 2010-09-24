#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct piece{
    int r,c;
    char sym;
    
    piece(int _r, int _c, char _sym){
        r=_r;
        c=_c;
        sym=_sym;
    }
};

int main(){    
    string s,aux;
    int ind;
    
    for(int i=0;i<17;i++){
        getline(cin,aux);
        s+=aux;
    }
    
    vector<piece> v;
    
    ind=s.find("K");
    if(ind != -1) v.push_back(piece(8-(ind/33)/2,(ind%33)/4+1,'K'));
    ind=s.find("Q");
    if(ind != -1) v.push_back(piece(8-(ind/33)/2,(ind%33)/4+1,'Q'));    
    ind=s.find("R");
    while(ind != -1){
        v.push_back(piece(8-(ind/33)/2,(ind%33)/4+1,'R'));
        ind=s.find("R",ind+1);
    }    
    ind=s.find("B");
    while(ind != -1){
        v.push_back(piece(8-(ind/33)/2,(ind%33)/4+1,'B'));
        ind=s.find("B",ind+1);
    }
    ind=s.find("N");
    while(ind != -1){
        v.push_back(piece(8-(ind/33)/2,(ind%33)/4+1,'N'));
        ind=s.find("N",ind+1);
    }    
    ind=s.find("P");
    while(ind != -1){
        v.push_back(piece(8-(ind/33)/2,(ind%33)/4+1,'P'));
        ind=s.find("P",ind+1);
    }
    
    for(int i=0;i<v.size();i++)
        if(v[i].sym=='P'){
            for(int j=i;j<v.size();j++)
                for(int k=j+1;k<v.size();k++)
                    if(v[j].r>v[k].r || (v[j].r==v[k].r && v[j].c>v[k].c))swap(v[j],v[k]);
            break;
        }else if(i+1<v.size() && v[i].sym==v[i+1].sym && (v[i].r>v[i+1].r || (v[i].r==v[i+1].r && v[i].c>v[i+1].c))) swap(v[i],v[i+1]);
    
    cout<<"White: ";
    
    for(int i=0;i<v.size();i++){
        if(i!=0) cout<<",";
        if(v[i].sym!='P') cout<<v[i].sym;
        cout<<(char)(v[i].c+'a'-1)<<v[i].r;
    }
    
    cout<<endl;
    
    v.clear();
    
    ind=s.find("k");
    if(ind != -1) v.push_back(piece(8-(ind/33)/2,(ind%33)/4+1,'K'));
    ind=s.find("q");
    if(ind != -1) v.push_back(piece(8-(ind/33)/2,(ind%33)/4+1,'Q'));   
    ind=s.find("r");
    while(ind != -1){
        v.push_back(piece(8-(ind/33)/2,(ind%33)/4+1,'R'));
        ind=s.find("r",ind+1);
    }    
    ind=s.find("b");
    while(ind != -1){
        v.push_back(piece(8-(ind/33)/2,(ind%33)/4+1,'B'));
        ind=s.find("b",ind+1);
    }
    ind=s.find("n");
    while(ind != -1){
        v.push_back(piece(8-(ind/33)/2,(ind%33)/4+1,'N'));
        ind=s.find("n",ind+1);
    }    
    ind=s.find("p");
    while(ind != -1){
        v.push_back(piece(8-(ind/33)/2,(ind%33)/4+1,'P'));
        ind=s.find("p",ind+1);
    }
    
    for(int i=0;i<v.size();i++)
        if(v[i].sym=='P'){
            for(int j=i;j<v.size();j++)
                for(int k=j+1;k<v.size();k++)
                    if(v[j].r<v[k].r || (v[j].r==v[k].r && v[j].c>v[k].c))swap(v[j],v[k]);
            break;
        }else if(i+1<v.size() && v[i].sym==v[i+1].sym && (v[i].r<v[i+1].r || (v[i].r==v[i+1].r && v[i].c>v[i+1].c))) swap(v[i],v[i+1]);
    
    cout<<"Black: ";
    
    for(int i=0;i<v.size();i++){
        if(i!=0) cout<<",";
        if(v[i].sym!='P') cout<<v[i].sym;
        cout<<(char)(v[i].c+'a'-1)<<v[i].r;
    }
    
    cout<<endl;
    
    return 0;
}
