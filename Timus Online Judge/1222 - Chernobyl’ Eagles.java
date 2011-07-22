import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class timus1222 {
    public static void main(String args[]) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());

        BigInteger ans = BigInteger.ONE;
        BigInteger three = new BigInteger("3");

        if(n % 3 == 1 && n > 1){
            ans = new BigInteger("4");
            n -= 4;
        }else if(n % 3 == 2){
            ans = new BigInteger("2");
            n -= 2;
        }

        for(int i = n/3 - 1;i >= 0;--i)
            ans = ans.multiply(three);

        System.out.println(ans);
    }
}
