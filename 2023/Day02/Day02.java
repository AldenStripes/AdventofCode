package AdventOfCode2023;
import java.util.*;
import java.io.*;
public class Day02 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String S;
	static void convert() {
		S = S.replaceAll(",", "");
		S = S.replaceAll(";", "");
		S = S.replaceAll("Game", "");
		S = S.replaceAll(":", "");
	}
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("Day02Input.txt"));
		int sum = 0;
		for (int i=0; i<100; ++i) {
			S = sc.nextLine();
			convert();
			String[] a = S.split(" ");
			LinkedList<Integer> r = new LinkedList<>(); 
			LinkedList<Integer> g = new LinkedList<>(); 
			LinkedList<Integer> b = new LinkedList<>(); 
			for (int j=2; j<a.length; j+=2) {
				int cur = Integer.parseInt(a[j]);
				switch (a[j+1]) {
				case "red": r.push(cur); break;
				case "green": g.push(cur); break;
				case "blue": b.push(cur); break;
				}
			}
			int maxR = Collections.max(r);
			int maxG = Collections.max(g);
			int maxB = Collections.max(b);
			if (maxR<=12&&maxG<=13&&maxB<=14) {
				sum += (i+1);
			}
			S = "";
		}
		System.out.println("sum: "+sum);
	}

	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static long readLong() throws IOException {
		return Long.parseLong(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}

	static char readChar() throws IOException {
		return next().charAt(0);
	}
}
