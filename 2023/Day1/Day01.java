package AdventOfCode2023;
import java.util.*;
import java.io.*;
public class Day01 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("Day1Input.txt"));
		long sum = 0;
		while (sc.hasNextLine()) {
			String S = sc.nextLine();
			String cur = "";
			for (int i=0; i<S.length(); ++i) {
				char c = S.charAt(i);
				if (Character.isDigit(c)) {
					cur += c;
					break;
				}
			}
			for (int i=S.length()-1; i>=0; --i) {
				char c = S.charAt(i);
				if (Character.isDigit(c)) {
					cur += c;
					break;
				}
			}
			sum += Long.parseLong(cur);
		}
		sc.close();
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
