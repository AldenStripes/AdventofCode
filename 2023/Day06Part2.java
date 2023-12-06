package AdventOfCode2023;
import java.util.*;
import java.io.*;
public class Day06Part2 {
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
		String[] times = new String[4];
		for (int i=0; i<4; ++i) {
			times[i] = sc.next();
		}
		sc.next();
		String[] distances = new String[4];
		for (int i=0; i<4; ++i) {
			distances[i] = sc.next();
		}
		String temp = times[0]+""+times[1]+""+times[2]+""+times[3];
		String temp2 = distances[0]+""+distances[1]+""+distances[2]+""+distances[3];
		long timeAlloted = Long.parseLong(temp);
		long distanceRecord = Long.parseLong(temp2);
		System.out.println(timeAlloted);
		System.out.println(distanceRecord);
		int num = 0;
		for (long j=1; j<timeAlloted; ++j) { //hold for j miliseconds
			long cur = j*(timeAlloted-j);
			if (cur>distanceRecord) {
				num ++;
			}
		}
		System.out.println("num: "+num);
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
