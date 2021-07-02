package practice.programmers.탐욕법;

import java.util.Arrays;
import java.util.Scanner;

public class 체육복 {
    private static final Scanner SCANNER = new Scanner(System.in);
    private static final String DELIMITER = ", ";

    public static void main(String[] args) {
        int n = SCANNER.nextInt();
        String lostInput = SCANNER.nextLine();
        String reverseInput = SCANNER.nextLine();

        int[] lost = Arrays.stream(lostInput.split(DELIMITER))
            .mapToInt(Integer::parseInt)
            .toArray();
        int[] reserve = Arrays.stream(reverseInput.split(DELIMITER))
            .mapToInt(Integer::parseInt)
            .toArray();

        solution(n, lost, reserve);
    }

    private static int solution(int n, int[] lostStudents, int[] reserveStudents) {
        int maxAttendants = n - lostStudents.length;
        Arrays.sort(lostStudents);
        Arrays.sort(reserveStudents);

        // 여벌 체육복을 가져온 학생이 체육복을 도난당했을 경우
        for (int i = 0; i < reserveStudents.length; i++) {
            for (int j = 0; j < lostStudents.length; j++) {
                if (reserveStudents[i] == lostStudents[j]) {
                    reserveStudents[i] = -1;
                    lostStudents[j] = -1;
                    maxAttendants += 1;
                    break;
                }
            }
        }

        // 여벌 체육복을 가져온 학생들이 체육복을 도난당한 학생들에게 체육복을 빌려준다.
        for (int i = 0; i < reserveStudents.length; i++) {
            if (reserveStudents[i] == -1) {
                continue;
            }

            for (int j = 0; j < lostStudents.length; j++) {
                if (lostStudents[j] == -1) {
                    continue;
                }

                if (Math.abs(lostStudents[j] - reserveStudents[j]) == 1) {
                    reserveStudents[j] = -1;
                    // lostStudents[j] = -1;
                    maxAttendants += 1;
                    break;
                }
            }
        }

        return maxAttendants;
    }
}
