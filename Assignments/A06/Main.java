import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		final Scanner scan = new Scanner(System.in);
		final int numberOfRuns = scan.nextInt();
		scan.useDelimiter("\n\n");
		final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		final LinkedHashMap<String, Integer> sortedTreeMap = new LinkedHashMap<>();
		for(int i = 0; i < numberOfRuns; i++) {
			final String input = scan.next();
			final String[] treeArray = input.split("\n");
			final List<String> treeList = Arrays.asList(treeArray);
			Collections.sort(treeList);
			treeList.stream().forEach(e -> {
				sortedTreeMap.put(e, sortedTreeMap.getOrDefault(e, 0) + 1);
			});
			for(String e : sortedTreeMap.keySet()) {
				final double percentage = (double) Math.round((sortedTreeMap.get(e) / (treeList.size() + 0.0)) * 100 * 10000d) / 10000d;
				if(e.length() > 1) {
					if(percentage*1000 == Math.floor(percentage*1000) || percentage < 0.001) {
						out.write((e + " " + String.format("%.4f", percentage) + "\n"));
					} else {
						out.write((e + " " + percentage + "\n"));
					}
				}
			}
			out.flush();
			if(i != numberOfRuns-1)
				System.out.println();
		}
		System.exit(0);
	}

}
