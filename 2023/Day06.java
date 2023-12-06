package AdventOfCode2023;
import java.util.*;
import java.io.*;
public class Day06 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String extract(String S) {
		S = S.replaceAll("Time:", "");
		S = S.replaceAll("Distance:", "");
		S = S.trim();
		return S;
	}
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("Day06Input.txt"));
		sc.next();
		int[] times = new int[4];
		for (int i=0; i<4; ++i) {
			times[i] = sc.nextInt();
		}
		sc.next();
		int[] distances = new int[4];
		for (int i=0; i<4; ++i) {
			distances[i] = sc.nextInt();
		}
		int total = 1;
		for (int i=0; i<4; ++i) {
			int timeAlloted = times[i];
			int distanceRecord = distances[i];
			int numberOfWays = 0;
			for (int j=1; j<timeAlloted; ++j) { //hold for j miliseconds
				int cur = j*(timeAlloted-j);
				if (cur>distanceRecord) {
					numberOfWays ++;
				}
			}
			total *= numberOfWays;
		}
		System.out.println("total: "+total);
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
