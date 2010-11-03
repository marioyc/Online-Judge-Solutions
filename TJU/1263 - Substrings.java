import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main{
    public static void main(String args[]) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        
        int T,n,ans;
        String L[] = new String[100];
        String aux,aux2;
        boolean found;

        T = Integer.parseInt(in.readLine());

        for(int tc=1;tc<=T;tc++){
            n = Integer.parseInt(in.readLine());
            
            for(int i=0;i<n;i++) L[i] = in.readLine();

            ans = 0;

            for(int i=L[0].length()-1;i>=0;i--){
                for(int j=L[0].length();j>i;j--){
                    aux = L[0].substring(i,j);
                    aux2 = "";

                    for(int k=aux.length()-1;k>=0;k--) aux2 += aux.charAt(k);

                    found = true;

                    for(int k=1;k<n && found;k++)
                        if(!L[k].contains(aux) && !L[k].contains(aux2))
                            found = false;

                    if(found) ans = Math.max(ans,j-i);
                }
            }

            System.out.println(ans);
        }
    }
}
