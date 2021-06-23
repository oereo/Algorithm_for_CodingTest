package practice.programmers.해시;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class 두_개_뽑아서_더하기 {
    private static final Scanner SCANNER = new Scanner(System.in);
    private static final String DELIMITER = ", ";

    public static void main(String[] args) {
        String numbers = SCANNER.nextLine();
        solution(Arrays.stream(numbers.split(DELIMITER))
            .mapToInt(Integer::parseInt)
            .toArray()
        );
    }

    private static int[] solution(int[] numbers) {
        Set<Integer> sumOfTwoNums = new HashSet<>();

        for (int i = 0; i < numbers.length - 1; i++) {
            for (int j = i + 1; j < numbers.length; j++) {
                sumOfTwoNums.add(numbers[i] + numbers[j]);
            }
        }
        int[] answer = sumOfTwoNums.stream().sorted().mapToInt(Integer::intValue).toArray();
        System.out.println(answer);
        return answer;
    }
}
