package practice.programmers.탐욕법;

public class 체육복_추가 {
    public static void main(String[] args) {
        int n = 5;
        int[] lost = {2, 4};
        int[] reserve = {1, 3, 5};
        System.out.println(solution(n, lost, reserve));
    }

    private static int solution(int n, int[] lostStudents, int[] reserveStudents) {
        int[] clothesStatus = initiateClothesStatus(n, lostStudents, reserveStudents);
        clothesStatus = borrowClothes(clothesStatus);
        int maxAttendants = calculateMaxAttendants(clothesStatus, n);

        return maxAttendants;
    }

    private static int[] initiateClothesStatus(int n, int[] lostStudents, int[] reserveStudents) {
        int[] clothesStatus = new int[n + 2];   // n명의 학생 + 0과 (n+1) 패딩

        for (int lostStudent : lostStudents) {
            clothesStatus[lostStudent]--;
        }
        for (int reserveStudent : reserveStudents) {
            clothesStatus[reserveStudent]++;
        }

        return clothesStatus;
    }

    private static int[] borrowClothes(int[] clothesStatus) {
        for (int i = 1; i < clothesStatus.length - 1; i++) {    // 1번부터 n번 학생까지
            if (clothesStatus[i] == -1) {
                if (clothesStatus[i - 1] == 1) {
                    clothesStatus[i - 1]--;
                    clothesStatus[i]++;
                } else if (clothesStatus[i + 1] == 1) {
                    clothesStatus[i + 1]--;
                    clothesStatus[i]++;
                }
            }
        }

        return clothesStatus;
    }

    private static int calculateMaxAttendants(int[] clothesStatus, int n) {
        int maxAttendants = n;
        for (int i = 1; i < clothesStatus.length - 1; i++) {
            if (clothesStatus[i] == -1) {
                maxAttendants--;
            }
        }
        return maxAttendants;
    }
}
