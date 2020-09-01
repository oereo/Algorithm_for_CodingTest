package algo.Programmers;

public class PG_2020KakaoInt_키패드누르기 {
    static int[] numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    static String hand = "right";

    public static void main(String[] args) {
        solution(numbers, hand);
    }

    public static String solution(int[] numbers, String hand) {
        StringBuilder answer = new StringBuilder();

        lPosition lp = new lPosition(3, 0);
        rPosition rp = new rPosition(3, 2);
        numPosition np = new numPosition(0, 0);

        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
                answer.append("L");
                if (numbers[i] == 1) {
                    lp.r = 0;
                    lp.c = 0;
                } else if (numbers[i] == 4) {
                    lp.r = 1;
                    lp.c = 0;
                } else if (numbers[i] == 7) {
                    lp.r = 2;
                    lp.c = 0;
                }
            } else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
                answer.append("R");
                if (numbers[i] == 3) {
                    rp.r = 0;
                    rp.c = 2;
                } else if (numbers[i] == 6) {
                    rp.r = 1;
                    rp.c = 2;
                } else if (numbers[i] == 9) {
                    rp.r = 2;
                    rp.c = 2;
                }
            } else {
                if (numbers[i] == 0) {
                    np.r = 3;
                    np.c = 1;
                } else if (numbers[i] == 2) {
                    np.r = 0;
                    np.c = 1;
                } else if (numbers[i] == 5) {
                    np.r = 1;
                    np.c = 1;
                } else if (numbers[i] == 8) {
                    np.r = 2;
                    np.c = 1;
                }

                if (Math.abs(np.r - lp.r) + Math.abs(np.c - lp.c) > Math.abs(np.r - rp.r)
                        + Math.abs(np.c - rp.c)) {
                    answer.append("R");
                    rp.r = np.r;
                    rp.c = np.c;
                } else if (Math.abs(np.r - lp.r) + Math.abs(np.c - lp.c) < Math.abs(np.r - rp.r)
                        + Math.abs(np.c - rp.c)) {
                    answer.append("L");
                    lp.r = np.r;
                    lp.c = np.c;
                } else if ((Math.abs(np.r - lp.r) + Math.abs(np.c - lp.c)) == (Math.abs(np.r - rp.r)
                        + Math.abs(np.c - rp.c))) {
                    if (hand == "right") {
                        answer.append("R");
                        rp.r = np.r;
                        rp.c = np.c;
                    } else {
                        answer.append("L");
                        lp.r = np.r;
                        lp.c = np.c;
                    }
                }
            }
        }
        System.out.println(answer.toString());
        return answer.toString();
    }

    static class lPosition {
        int r, c;

        public lPosition(int r, int c) {
            this.r = r;
            this.c = c;
        }

    }

    static class rPosition {
        int r, c;

        public rPosition(int r, int c) {
            this.r = r;
            this.c = c;
        }

    }

    static class numPosition {
        int r, c;

        public numPosition(int r, int c) {
            this.r = r;
            this.c = c;
        }

    }
}
