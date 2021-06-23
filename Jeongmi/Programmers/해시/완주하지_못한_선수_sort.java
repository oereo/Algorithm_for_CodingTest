package practice.programmers.해시;

import java.util.Arrays;
import java.util.Scanner;

public class 완주하지_못한_선수_sort {
    private static final Scanner SCANNER = new Scanner(System.in);
    private static final String DELIMITER = ", ";

    public static void main(String[] args) {
        String participant = SCANNER.nextLine();
        String completion = SCANNER.nextLine();
        solution(participant.split(DELIMITER), completion.split(DELIMITER));
    }

    public static String solution(String[] participant, String[] completion) {
        Arrays.sort(participant);
        Arrays.sort(completion);

        for (int i = 0; i < completion.length; i++) {
            if (!participant[i].equals(completion[i])) {
                return participant[i];
            }
        }
        return participant[participant.length - 1];
    }
}
