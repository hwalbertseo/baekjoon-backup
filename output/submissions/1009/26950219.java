import java.util.*;

public class Main {
	public static int pmul(int x, int y) {
		int k = x;
		for(int j = 1;j < y;j++) {
			//System.out.println(k);
			int temp = k % 10;
			k = temp*x;
		}		
		return k;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int p,q;
		for(int i = 0;i < n;i++) {
			p = sc.nextInt(); 
			q = sc.nextInt();
			System.out.println(pmul(p, q) % 10);
		}
		
	}

}