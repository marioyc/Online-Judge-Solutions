#include <vector>
#include <iostream>

using namespace std;

int main(){

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int N;
    int m;
    bool ok;
    
    while(cin>>N)
    {
        if(N==0) break;
        if(N==13)
        {
            cout<<1<<endl;
            continue;
        }
        else
        {
            
            m=5;
                                                
            while(true)
            {                
                if(m==6 || m==12)
                {
                    m++;
                    continue;
                }
                
                vector<bool> aux(N,false);
                aux[0]=true;
                
                int cont1=1;
                int cont2=0;
                int i;
                
                while(true)
                {
                    
                    i=1;
                    while(i<N)
                    {
                        if(!aux[i])
                        {                            
                            cont2++;
                            if(cont2==m)
                            {
                                aux[i]=true;
                                cont2=0;
                                cont1++;
                                if(cont1==N-1) goto xx;
                            }
                        }
                        
                        i++;
                    }
                    
                }
                
                xx:
                if(!aux[12]) break;
                
                m++;
            }
            cout<<m<<endl;
        }
    }

    return 0;
}
