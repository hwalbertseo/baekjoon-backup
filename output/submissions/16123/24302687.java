import java.util.Scanner;

public class Main {
	//public int cnt = 0;
	
	public static int find_Div(int x, int y, int z) {
		int min1 = (x < y) ? x:y;
		int min = (min1 > z) ? z:min1;
		for(int Div = min;Div >= 1;Div--) {
			//System.out.println(Div);
			if(x % Div == 0 && y % Div == 0 && z % Div == 0) {
				return Div;
			}
			else continue;
			
		}
		return 0;
	}
	
	public static void main(String[] args) {
		int cnt = 0;
		Scanner sc = new Scanner(System.in);
		int L = sc.nextInt();
		for(int i = 1;i <= L;i++) {
			for(int j = 1;j < i;j++) {
				int a = i*i - j*j;
				int b = 2*i*j;
				int c = i*i - j*j;
				if(find_Div(a, b, c) == 1) cnt++;
			}
		}
		System.out.println(cnt);
	}
}
