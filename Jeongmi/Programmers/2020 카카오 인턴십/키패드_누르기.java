package practice.programmers.kakao_2020_intership;

import java.util.Arrays;
import java.util.Scanner;

public class 키패드_누르기 {
    private static final Scanner SCANNER = new Scanner(System.in);
    private static final String DELIMITER = ", ";
    private static final char LEFT = 'L';
    private static final char RIGHT = 'R';
    private static final String LEFT_HAND = "left";
    private static final String RIGHT_HAND = "right";
    private static int[] leftThumbPosition = {3, 0}; // *로 초기화.
    private static int[] rightThumbPosition = {3, 2}; // #로 초기화.
    private static StringBuilder BUILDER = new StringBuilder();

    // 몫 = (number - 1) / 3, 나머지 = (number - 1) % 3, 키패드 0을 11로 치환.
    // (0, 0) (0, 1) (0, 2)
    // (1, 0) (1, 1) (1, 2)
    // (2, 0) (2, 1) (2, 2)
    //   (x)  (3, 1)   (x)

    public static void main(String[] args) {
        String numbers = SCANNER.nextLine();
        String hand = SCANNER.nextLine();
        solution(convertStringNumbersIntoInts(numbers), hand);
    }

    private static int[] convertStringNumbersIntoInts(String numbers) {
        String[] splitNumbers = numbers.split(DELIMITER);
        return Arrays.stream(splitNumbers)
            .mapToInt(Integer::parseInt)
            .toArray();
    }

    private static void solution(int[] numbers, String hand) {
        for (int number : numbers) {
            if (number == 0) {
                number += 11;
            }
            if ((number - 1) % 3 == 0) {  // 왼쪽 열
                moveLeftThumbPosition(number);
            } else if ((number - 1) % 3 == 2) {   // 오른쪽 열
                moveRightThumbPosition(number);
            } else if ((number - 1) % 3 == 1) {    // number가 가운데 열의 숫자일 경우: 2, 5, 8, 0
                compareDistance(number, hand);
            }
        }

        System.out.println(BUILDER.toString());
    }

    private static void compareDistance(int number, String hand) {
        int leftDistance = calculateDistance(number, leftThumbPosition);
        int rightDistance = calculateDistance(number, rightThumbPosition);

        if (leftDistance < rightDistance || (leftDistance == rightDistance && hand.equals(LEFT_HAND))) {
            moveLeftThumbPosition(number);
        } else if (leftDistance > rightDistance || (leftDistance == rightDistance && hand.equals(RIGHT_HAND))) {
            moveRightThumbPosition(number);
        }
    }

    private static int calculateDistance(int number, int[] thumbPosition) {
        int numberX = (number - 1) / 3;
        int numberY = 1;
        int thumbPositionX = thumbPosition[0];
        int thumbPositionY = thumbPosition[1];

        return Math.abs(numberX - thumbPositionX) + Math.abs(numberY - thumbPositionY);
    }

    private static void moveLeftThumbPosition(int number) {
        leftThumbPosition[0] = (number - 1) / 3;
        leftThumbPosition[1] = (number - 1) % 3;
        BUILDER.append(LEFT);
    }

    private static void moveRightThumbPosition(int number) {
        rightThumbPosition[0] = (number - 1) / 3;
        rightThumbPosition[1] = (number - 1) % 3;
        BUILDER.append(RIGHT);
    }
}
