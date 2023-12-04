package AdventOfCode2023;
import java.util.*;
import java.io.*;
public class Day04Part2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String removeStuff(String S) {
		S = S.replaceAll("Card", "");
		S = S.replaceAll(":", "");
		return S;
	}
	static int winCount(int[] winning, int[] numbers) {
		int count = 0;
		for (int j=0; j<25; ++j) {
			for (int k=0; k<10; ++k) {
				if (numbers[j]==winning[k]) {
					count ++;
				}
			}
		}
		return count;
	}
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("Day04Input.txt"));
		int totalCards = 0;
		int[] count = new int[201];
		Arrays.fill(count, 1);
		for (int i=0; i<201; ++i) {
			int[] winning = new int[10];
			int[] numbers = new int[25];
			String S = sc.nextLine();
			S = removeStuff(S);
			S = S.trim();
			String[] nums = S.split("\\s+");
			for (int j=1; j<=10; ++j) {
				winning[j-1] = Integer.parseInt(nums[j]);
			}
			for (int j=12; j<37; ++j) {
				numbers[j-12] = Integer.parseInt(nums[j]);
			}
			int curCount = winCount(winning, numbers);
			for (int j=0; j<curCount; ++j) { //when j==0, count[i+1]
				count[i+(j+1)] += count[i];
			}
			totalCards += count[i];
		}
		System.out.println("sum: "+totalCards);
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
