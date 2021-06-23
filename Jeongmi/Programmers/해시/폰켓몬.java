package practice.programmers.해시;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class 폰켓몬 {
    private static final Scanner SCANNER = new Scanner(System.in);
    private static final String DELIMITER = ", ";
    private static final int DEFAULT_VALUE = 0;

    public static void main(String[] args) {
        String nums = SCANNER.nextLine();
        solution(Arrays.stream(nums.split(DELIMITER))
            .mapToInt(Integer::parseInt)
            .toArray()
        );
    }

    private static int solution(int[] nums) {
        // <Integer, Integer>: <포켓몬 종류, 그 종류의 수>
        int halfOfN = nums.length / 2;
        Map<Integer, Integer> typeStatistics = new HashMap<>();
        for (int num : nums) {
            typeStatistics.put(num, typeStatistics.getOrDefault(num, DEFAULT_VALUE) + 1);
        }

        // 폰켓몬 종류가 N/2마리보다 많다면
        return Math.min(typeStatistics.size(), halfOfN);
    }
}
