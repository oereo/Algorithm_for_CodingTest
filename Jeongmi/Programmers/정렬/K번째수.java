package practice.programmers.정렬;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class K번째수 {
    private static final Scanner SCANNER = new Scanner(System.in);
    private static final String DELIMITER = ", ";

    public static void main(String[] args) {
        int[] array = {1, 5, 2, 6, 3, 7, 4};
        int[][] commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
        solution(array, commands);
    }

    private static int[] solution(int[] array, int[][] commands) {
        List<Integer> answer = new ArrayList<>();

        for (int[] command : commands) {
            int[] partOfArray = Arrays.copyOfRange(array, command[0] - 1, command[1]);
            Arrays.sort(partOfArray);
            answer.add(partOfArray[command[2] - 1]);
        }

        System.out.println(answer);
        return convertIntegers(answer);
    }

    private static int[] convertIntegers(List<Integer> integers) {
        int[] result = new int[integers.size()];
        for (int i = 0; i < result.length; i++) {
            result[i] = integers.get(i);
        }
        return result;
    }
}
