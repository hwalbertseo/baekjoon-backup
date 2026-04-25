import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String irt = sc.nextLine();
		//System.out.println(i);
		
		// input first line
		StringTokenizer st = new StringTokenizer(irt, " ");
		int n = (int) st.nextToken().charAt(0) - 48;
		int m = (int) st.nextToken().charAt(0) - 48;
		int k = (int) st.nextToken().charAt(0) - 48;
		//System.out.println(m);
		
		//create vector
		int[] vec = new int[n];
		for(int i = 1;i <= n;i++) {
			vec[i-1] = i;
		}
		
		//input cycles		
		int[][] cyc = new int[m][2];
		for(int i = 0;i < m;i++) {
			cyc[i][0] = sc.nextInt();
			cyc[i][1] = sc.nextInt();
		}
		
		//turn cycles
		for(int j = 0;j < m;j++) {
			vec = cycles(cyc[j][0], cyc[j][1], vec);
			for(int l = 0;l < n;l++) {
				//System.out.print(vec[l]);
			}
			//System.out.println();
		}
		
		//make graph matrix
		/*
		int[][] gmat = new int[n][n];
		for(int i = 0;i < n;i++) {
			if(i != vec[i]-1) gmat[i][vec[i]-1] = 1;
		}
		*/
		/*
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < n;j++) {
				System.out.print(gmat[i][j]);
			}
			System.out.println();
		}
		*/
		
		//saving lists
		Vector<Vector<Integer>> list = new Vector<Vector<Integer>>(1);
		for(int i = 0;i < n;i++) {
			Vector<Integer> temp = new Vector<Integer>(2);
			temp.add(i);
			temp.add(vec[i] -1 );
			list.add(temp);
		}
		/*
		for(Vector<Integer> a : list) {
			for(int b : a) {
				System.out.print(b);
			}
			System.out.println();
		}
		*/
		System.out.println();
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < n;j++) {
				if(list.elementAt(j).lastElement() != list.elementAt(j).firstElement()) 
					list.elementAt(j).add(list.elementAt(list.elementAt(j).lastElement()).elementAt(1));
			}
		}
		

		//System.out.println(list);
		//for(int i : vec) System.out.println(i);
		//System.out.println();
		
		
		//create new array
		Vector<Integer> order = new Vector<Integer>(n);
		for(int i = 0;i < n;i++) {
			order.add(i);
		}
		Vector<Integer> nvec = new Vector<Integer>(n);
		for(int i = 0;i < n;i++) {
			int nk = k % (list.elementAt(i).size() - 1);
			//System.out.println(nk);
			nvec.add(order.elementAt(list.elementAt(i).elementAt(nk)) + 1);
		}
		
		for(int i : nvec) System.out.println(i);
		
		
	}
	
	//turn cycle method
	public static int[] cycles(int x, int y, int[] cvec) {
		int res = x + y - 2;
		for(int i = x-1;i <= y/2;i++) {
			//System.out.println(cvec[i] + " " + cvec[res - i]);
			int temp = 0;
			temp = cvec[i];
			cvec[i] = cvec[res - i];
			cvec[res - i] = temp;
		}
		return cvec;
	}
	
	//public static int

}
/*
class graphs {
	int a;
	public void graphs(int a) {
		this.a = a;
	}
	int[] vec = new int[this.a];
	
}
*/