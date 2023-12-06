package AdventOfCode2023;
import java.util.*;
import java.io.*;
public class Day05Part2 { //THIS TOOK 3 WHOLE HOURS TO RUN I HAD TO USE A FAN TO COOL MY COMPUTER
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static Map<Long, long[]> seedToSoil = new HashMap<>();
	static Map<Long, long[]> soilToFert = new HashMap<>();
	static Map<Long, long[]> fertToWater = new HashMap<>();
	static Map<Long, long[]> waterToLight = new HashMap<>();
	static Map<Long, long[]> lightToTemp = new HashMap<>();
	static Map<Long, long[]> tempToHumid= new HashMap<>();
	static Map<Long, long[]> humidToLoc = new HashMap<>();
	static Scanner sc;
	static long[] convertToArray(String S) {
		String[] cur = S.split("\\s+");
		long[] a = new long[3];
		for (int j=0; j<3; ++j) {
			a[j] = Long.parseLong(cur[j]);
		}
		return a;
	}
	static void fillHashMaps() {
		sc.nextLine(); sc.nextLine(); //seed-to-soil map:
		for (int i=0; i<(50-4+1); ++i) {
			String S = sc.nextLine();
			System.out.println(S);
			long[] a = convertToArray(S);
			long source = a[1];
			long[] destination = {a[0], a[2]};
			seedToSoil.put(source, destination);
		}
		sc.nextLine(); sc.nextLine(); //soil-to-fertillizer map:
		for (int i=0; i<(70-53+1); ++i) {
			String S = sc.nextLine();
			System.out.println(S);
			long[] a = convertToArray(S);
			long source = a[1];
			long[] destination = {a[0], a[2]};
			soilToFert.put(source, destination);
		}
		sc.nextLine(); sc.nextLine(); //fertillizer-to-water map:
		for (int i=0; i<(84-73+1); ++i) {
			String S = sc.nextLine();
			System.out.println(S);
			long[] a = convertToArray(S);
			long source = a[1];
			long[] destination = {a[0], a[2]};
			fertToWater.put(source, destination);
		}
		sc.nextLine(); sc.nextLine(); //water-to-light map:
		for (int i=0; i<(135-87+1); ++i) {
			String S = sc.nextLine();
			System.out.println(S);
			long[] a = convertToArray(S);
			long source = a[1];
			long[] destination = {a[0], a[2]};
			waterToLight.put(source, destination);
		}
		sc.nextLine(); sc.nextLine(); //light-to-temperature map:
		for (int i=0; i<(167-138+1); ++i) {
			String S = sc.nextLine();
			System.out.println(S);
			long[] a = convertToArray(S);
			long source = a[1];
			long[] destination = {a[0], a[2]};
			lightToTemp.put(source, destination);
		}
		sc.nextLine(); sc.nextLine(); //temperature-to-humidity map:
		for (int i=0; i<(192-170+1); ++i) {
			String S = sc.nextLine();
			System.out.println(S);
			long[] a = convertToArray(S);
			long source = a[1];
			long[] destination = {a[0], a[2]};
			tempToHumid.put(source, destination);
		}
		sc.nextLine(); sc.nextLine(); //humidity-tos-location map:
		for (int i=0; i<(237-195+1); ++i) {
			String S = sc.nextLine();
			System.out.println(S);
			long[] a = convertToArray(S);
			long source = a[1];
			long[] destination = {a[0], a[2]};
			humidToLoc.put(source, destination);
		}
	}
	static long convertSeedToSoil(long l) {
		long curSoil = 0;
		boolean thereIs = false;
		for (long key: seedToSoil.keySet()) {
			long soil = seedToSoil.get(key)[0];
			long rangeLength = seedToSoil.get(key)[1];
			if (l>=key&&l<=key+rangeLength) {
				long added = l - key;
				curSoil = soil+added;
				thereIs = true;
				break;
			}
		}
		if (thereIs) {
			return curSoil;
		}	else {
			return l;
		}
	}
	static long convertSoilToFert(long l) {
		long curFert = 0;
		boolean thereIs = false;
		for (long key: soilToFert.keySet()) {
			long fert = soilToFert.get(key)[0];
			long rangeLength = soilToFert.get(key)[1];
			if (l>=key&&l<=key+rangeLength) {
				long added = l - key;
				curFert = fert+added;
				thereIs = true;
				break;
			}
		}
		if (thereIs) {
			return curFert;
		}	else {
			return l;
		}
	}
	static long convertFertToWater(long l) {
		long curFert = 0;
		boolean thereIs = false;
		for (long key: fertToWater.keySet()) {
			long fert = fertToWater.get(key)[0];
			long rangeLength = fertToWater.get(key)[1];
			if (l>=key&&l<=key+rangeLength) {
				long added = l - key;
				curFert = fert+added;
				thereIs = true;
				break;
			}
		}
		if (thereIs) {
			return curFert;
		}	else {
			return l;
		}
	}
	static long convertWaterToLight(long l) {
		long curFert = 0;
		boolean thereIs = false;
		for (long key: waterToLight.keySet()) {
			long fert = waterToLight.get(key)[0];
			long rangeLength = waterToLight.get(key)[1];
			if (l>=key&&l<=key+rangeLength) {
				long added = l - key;
				curFert = fert+added;
				thereIs = true;
				break;
			}
		}
		if (thereIs) {
			return curFert;
		}	else {
			return l;
		}
	}
	static long convertLightToTemp(long l) {
		long curFert = 0;
		boolean thereIs = false;
		for (long key: lightToTemp.keySet()) {
			long fert = lightToTemp.get(key)[0];
			long rangeLength = lightToTemp.get(key)[1];
			if (l>=key&&l<=key+rangeLength) {
				long added = l - key;
				curFert = fert+added;
				thereIs = true;
				break;
			}
		}
		if (thereIs) {
			return curFert;
		}	else {
			return l;
		}
	}
	static long convertTempToHumid(long l) {
		long curFert = 0;
		boolean thereIs = false;
		for (long key: tempToHumid.keySet()) {
			long fert = tempToHumid.get(key)[0];
			long rangeLength = tempToHumid.get(key)[1];
			if (l>=key&&l<=key+rangeLength) {
				long added = l - key;
				curFert = fert+added;
				thereIs = true;
				break;
			}
		}
		if (thereIs) {
			return curFert;
		}	else {
			return l;
		}
	}
	static long convertHumidToLoc(long l) {
		long curFert = 0;
		boolean thereIs = false;
		for (long key: humidToLoc.keySet()) {
			long fert = humidToLoc.get(key)[0];
			long rangeLength = humidToLoc.get(key)[1];
			if (l>=key&&l<=key+rangeLength) {
				long added = l - key;
				curFert = fert+added;
				thereIs = true;
				break;
			}
		}
		if (thereIs) {
			return curFert;
		}	else {
			return l;
		}
	}
	static long seedToLocation(long l) {
		long curSoil = convertSeedToSoil(l);
		long curFert = convertSoilToFert(curSoil);
		long curWater = convertFertToWater(curFert);
		long curLight = convertWaterToLight(curWater);
		long curTemp = convertLightToTemp(curLight);
		long curHumid = convertTempToHumid(curTemp);
		long curLocation = convertHumidToLoc(curHumid);
		return curLocation;
	}
	public static void main(String[] args) throws IOException {
		sc = new Scanner(new File("Day05Input.txt"));
		String seeds = sc.nextLine();
		seeds = seeds.replaceAll("seeds: ", "");
		String[] temp = seeds.split("\\s+");
		long[] seed = new long[temp.length];
		for (int i=0; i<temp.length; ++i) {
			seed[i] = Long.parseLong(temp[i]);
		}
		//fill hashmaps
		fillHashMaps();
		//get location from original seeds
		long minLocation = Long.MAX_VALUE;
		System.out.println("start of the deadly loop");
		for (int i=0; i<seed.length; i+=2) {
			for (long j=0; j<seed[i+1]; ++j) {
				long cur = seedToLocation(seed[i]+j);
				minLocation = Math.min(cur, minLocation);
			}
		}
		System.out.println("minLocation: "+minLocation); //dont even bother running this
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
