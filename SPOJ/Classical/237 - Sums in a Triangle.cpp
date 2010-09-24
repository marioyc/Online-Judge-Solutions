#include <iostream>
#define f(i,j) for(j=0;j<=i;++j)
#define _ std::
int T,n,i,j,M[100][100];main(){_ cin>>T;while(T--){_ cin>>n;for(i=0;i<n;++i)f(i,j)_ cin>>M[i][j];for(i=n-2;i>=0;--i)f(i,j)M[i][j]+=_ max(M[i+1][j],M[i+1][j+1]);_ cout<<M[0][0]<<'\n';}}
