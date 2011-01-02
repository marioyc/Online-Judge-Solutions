#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool isNumber(string s){
    int pos = 0,L = s.size();
    
    if(s[0]=='+' || s[0]=='-') ++pos;
    
    while(pos<L){
        if(!(s[pos]>='0' && s[pos]<='9')) return false;
        ++pos;
    }
    
    return true;
}

bool comp(string s1, string s2){
    for(int i = s1.size()-1;i>=0;--i)
        if(s1[i]>='A' && s1[i]<='Z')
            s1[i] += 'a'-'A';
    
    for(int i = s2.size()-1;i>=0;--i)
        if(s2[i]>='A' && s2[i]<='Z')
            s2[i] += 'a'-'A';
    
    return s1<s2;
}

int main(){
    string line,s;
    vector<int> v1;
    vector<string> v2;
    int sz1,sz2;
    bool number[100000];
    
    while(getline(cin,line)){
        for(int i = line.size()-1;i>=0;--i)
            if(line[i]==',' || line[i]=='.')
                line[i] = ' ';
        
        istringstream is(line);
        sz1 = sz2 = 0;
        memset(number,false,sizeof(number));
        v1.clear(); v2.clear();
        
        while(is>>s){
            if(!isNumber(s)){
                v2.push_back(s);
                ++sz2;
            }else{
                int num;
                sscanf(s.c_str(),"%d",&num);
                v1.push_back(num);
                number[sz1+sz2] = true;
                ++sz1;
            }
        }
        
        if(sz1+sz2==0) break;
        
        if(sz1>0) sort(v1.begin(),v1.end());
        if(sz2>0) sort(v2.begin(),v2.end(),comp);
        
        for(int i = 0,j = 0,k = 0;i<sz1+sz2;++i){
            if(i>0) putchar(' ');
            
            if(number[i]) printf("%d",v1[j++]);
            else printf("%s",v2[k++].c_str());
            
            if(i+1<sz1+sz2) putchar(',');
        }
        
        puts(".");
    }
    
    return 0;
}
