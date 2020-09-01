package algo.Programmers;

public class PG_2020KakaoInt_키패드누르기 {
    static int[] numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    static String hand = "right";

    public static void main(String[] args) {
        solution(numbers, hand);
    }

    public static String solution(int[] numbers, String hand) {
        StringBuilder answer = new StringBuilder();

        int l = 10;
        int r = 12;

        for (int number : numbers) {
            if (number == 1 || number == 4 || number == 7) {
                answer.append("L");
                l = number;
            } else if (number == 3 || number == 6 || number == 9) {
                answer.append("R");
                r = number;
            } else {
                int distanceL = getDist(l, number);
                int distanceR = getDist(r, number);

                if (distanceL > distanceR) {
                    answer.append("R");
                    r = number;
                } else if (distanceL < distanceR) {
                    answer.append("L");
                    l = number;
                } else {
                    if (hand.equals("right")) {
                        answer.append("R");
                        r = number;
                    } else {
                        answer.append("L");
                        l = number;
                    }
                }

            }
        }

        return answer.toString();
    }

    private static int getDist(int location, int number) {
        if (number == 0) {
            number = 11;
        }

        if (location == 0) {
            location = 11;
        }

        int locationX = (location - 1) / 3;
        int locationY = (location - 1) % 3;

        int numberX = (number - 1) / 3;
        int numberY = (number - 1) % 3;

        return Math.abs(locationX - numberX) + Math.abs(locationY - numberY);
    }


}
