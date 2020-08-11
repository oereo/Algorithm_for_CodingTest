package algorithm.SWEA;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class SWEA_5658_보물상자비밀번호 {
	static int T, N, K;
	static List<Character> list = new ArrayList<>();
	static List<Integer> answer = new ArrayList<>();

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		T = sc.nextInt();

		for (int t = 1; t <= T; t++) {
			N = sc.nextInt();
			K = sc.nextInt();

			String str = sc.next();
			for (int i = 0; i < N; i++) {
				list.add(str.charAt(i));
			}

			calc();
			for (int i = 1; i < N / 4; i++) {
				char temp = list.remove(list.size() - 1);
				list.add(0, temp);
				calc();
			}

			Collections.sort(answer, new Comparator<Integer>() {

				@Override
				public int compare(Integer o1, Integer o2) {
					return Integer.compare(o1, o2) * -1;
				}
			});

			for (int i = 1; i < answer.size(); i++) {
				int temp = answer.get(i);
				int temp1 = answer.get(i - 1);
				if (temp == temp1) {
					answer.set(i, 0);
				}
			}

			Collections.sort(answer, new Comparator<Integer>() {

				@Override
				public int compare(Integer o1, Integer o2) {
					return Integer.compare(o1, o2) * -1;
				}
			});

			System.out.println("#" + t + " " + answer.get(K - 1));
			answer.clear();
			list.clear();

		}

	}

	static void calc() {
		int cnt = 0;
		while (true) {

			if (cnt == N) {
				break;
			}

			List<Integer> inTemp = new ArrayList<>();

			for (int i = cnt; i < cnt + (N / 4); i++) {
				char temp = list.get(i);
				if (temp == 'A') {
					inTemp.add(10);
				} else if (temp == 'B') {
					inTemp.add(11);
				} else if (temp == 'C') {
					inTemp.add(12);
				} else if (temp == 'D') {
					inTemp.add(13);
				} else if (temp == 'E') {
					inTemp.add(14);
				} else if (temp == 'F') {
					inTemp.add(15);
				} else {
					inTemp.add(temp - '0');
				}
			}

			List<Integer> tempAns = new ArrayList<>();
			int temp = 0;
			for (int i = (N / 4) - 1; i >= 0; i--) {
				tempAns.add(inTemp.get((N / 4) - 1 - i) * (int) Math.pow(16, i));
				temp += tempAns.remove(0);
			}

			answer.add(temp);

			cnt += N / 4;
		}
	}

}
