import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        String[] nm = line.split(" ");

        int N = Integer.parseInt(nm[0]);
        int M = Integer.parseInt(nm[1]);

        int[][] roads = new int[M][3];
        for (int i = 0; i < M; i++) {
            line = br.readLine();
            String[] info = line.split(" ");

            roads[i][0] = Integer.parseInt(info[0]);
            roads[i][1] = Integer.parseInt(info[1]);
            roads[i][2] = Integer.parseInt(info[2]);
        }

        Main sol = new Main();
        System.out.println(sol.solve(N, M, roads));
    }

    public int solve(int N, int M, int[][] roads) {
        int[] parent = new int[N+1];
        for (int i = 0; i < N + 1; i++) {
            parent[i] = i;
        }

        Arrays.sort(roads, Comparator.comparingInt(o -> o[2]));

        int last = 0;
        int ans = 0;
        for (int[] road : roads) {
            int from = road[0];
            int to = road[1];
            int cost = road[2];

            int fr = findRoot(parent, from);
            int tr = findRoot(parent, to);
            if (fr != tr) {
                union(parent, fr, tr);
                ans += cost;
                last = cost;
            }
        }

        return ans - last;
    }

    private void union(int[] parent, int a, int b) {
        int ar = findRoot(parent, a);
        int br = findRoot(parent, b);
        if (ar > br) {
            parent[br] = ar;
        } else {
            parent[ar] = br;
        }
    }

    private int findRoot(int[] parent, int node) {
        if (parent[node] != node) {
            parent[node] = findRoot(parent, parent[node]);
        }
        return parent[node];
    }
}