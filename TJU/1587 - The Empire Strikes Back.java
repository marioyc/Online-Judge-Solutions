import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.math.BigInteger;

public class Main{
    public static void main(String args[]) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String num;
        BigInteger TWO = new BigInteger("2");

        while(true){
            num = in.readLine();
            if(num.equals("0")) break;

            int n = Integer.parseInt(num);
            BigInteger N = new BigInteger(num);
            BigInteger ans = BigInteger.ONE;
            BigInteger aux1 = N.multiply(TWO);
            BigInteger aux2 = BigInteger.ONE;

            for(int i=0;i<n;++i){
                ans = ans.multiply(aux1);
                ans = ans.divide(aux2);
                aux1 = aux1.subtract(BigInteger.ONE);
                aux2 = aux2.add(BigInteger.ONE);
            }

            ans = ans.multiply(TWO);
            ans = ans.divide(N.add(BigInteger.ONE));

            System.out.println(ans);
        }
    }
}
