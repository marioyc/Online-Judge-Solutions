#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main(){
    string s;
    getline(cin,s);
    
    int L = s.size();
    pair<int, int> A[20000],B[20000];
    int szA = 1,szB;
    
    A[0] = make_pair(0,L-1);
    
    bool found = true;
    
    while(found){
        found = false;
        
        szB = 0;
        
        for(int i = 0;i<szA;++i){
            if(A[i].second!=A[i].first){
                found = true;
                int s = A[i].first, e = A[i].second;
                
                if(e==s+1){
                    B[szB] = make_pair(s,s);
                    ++szB;
                    
                    B[szB] = make_pair(s+1,s+1);
                    ++szB;
                }else{
                    B[szB] = make_pair(s+1,(s+e)/2);
                    ++szB;
                    
                    B[szB] = make_pair(s,s);
                    ++szB;
                    
                    B[szB] = make_pair((s+e)/2+1,e);
                    ++szB;
                }
            }else{
                B[szB] = A[i];
                ++szB;
            }
        }
        
        for(int i = 0;i<szB;++i) A[i] = B[i];
        szA = szB;
    }
    
    for(int i = 0;i<L;++i) putchar(s[A[i].first]);
    putchar('\n');
    
    return 0;
}
