import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main{
    static boolean isPalindrome(String s){
        int n=s.length();

        for(int i=n/2-1;i>=0;i--)
            if(s.charAt(i)!=s.charAt(n-1-i)) return false;

        return true;
    }

    public static void main(String args[]) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String s,s2;
        int n,L,cont;

        while(true){
            s = in.readLine();
            if(s.isEmpty()) break;

            n=s.length();
            L=1; cont=n;

            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    s2=s.substring(i,j+1);
                    if(s2.length()>=L && isPalindrome(s2)){
                        if(s2.length()==L) cont++;
                        else{
                            L=s2.length();
                            cont=1;
                        }
                    }
                }
            }

            System.out.println(L + " " + cont);
        }
    }
}

