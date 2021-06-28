package practice.programmers.dev_matching_2021;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class 로또의_최고_순위와_최저_순위 {
    private static final Scanner SCANNER = new Scanner(System.in);
    private static final String DELIMITER = ", ";

    public static void main(String[] args) {
        String lottosInput = SCANNER.nextLine();
        String winNumsInput = SCANNER.nextLine();

        int[] lottos = Arrays.stream(lottosInput.split(DELIMITER))
            .mapToInt(Integer::parseInt)
            .toArray();
        int[] winNums = Arrays.stream(winNumsInput.split(DELIMITER))
            .mapToInt(Integer::parseInt)
            .toArray();
        solution(lottos, winNums);
    }

    private static int[] solution(int[] lottos, int[] winNums) {
        int unknownCounts = 0; // 알아볼 수 없는 번호의 개수
        int matchingCounts = 0; // 당첨 번호와 일치한 구매번호 개수
        List<Integer> rank = new ArrayList<>();

        Arrays.sort(lottos);
        for (int lotto : lottos) {
            if (lotto == 0) {
                unknownCounts += 1;
            } else {
                break;
            }
        }

        List<Integer> winNumsInts = new ArrayList<>();
        for (int winNumber : winNums) {
            winNumsInts.add(winNumber);
        }

        matchingCounts = (int)Arrays.stream(lottos)
            .filter(winNumsInts::contains)
            .count();

        // 당첨이 가능한 최고 순위: 알아볼 수 있는 번호 + 알아볼 수 있는 번호 모두 당첨 번호와 일치한 경우
        rank.add(getRankFromMatchingCounts(matchingCounts + unknownCounts));
        // 당첨이 가능한 최저 순위: 알아볼 수 있는 번호만 당첨 번호와 일치한 경우
        rank.add(getRankFromMatchingCounts(matchingCounts));

        return convertIntegers(rank);
    }

    private static int getRankFromMatchingCounts(int matchingCounts) {
        if (matchingCounts == 6) {
            return 1;
        } else if (matchingCounts == 5) {
            return 2;
        } else if (matchingCounts == 4) {
            return 3;
        } else if (matchingCounts == 3) {
            return 4;
        } else if (matchingCounts == 2) {
            return 5;
        } else {
            return 6;
        }
    }

    private static int[] convertIntegers(List<Integer> integers) {
        int[] result = new int[integers.size()];
        for (int i = 0; i < result.length; i++) {
            result[i] = integers.get(i);
        }
        return result;
    }
}
