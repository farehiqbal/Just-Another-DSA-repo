import java.util.Random;

public class MazeGenerator {
    private static final int N = 10;
    private static final int[][] MAZE = new int[N][N];
    private static final Random RANDOM = new Random();
    private static final int[] dx = {1, 0, -1, 0};
    private static final int[] dy = {0, 1, 0, -1};

    private static boolean isValidMove(int x, int y) {
        
        return x >= 0 && x < N && y >= 0 && y < N && MAZE[x][y] == 0;
    }

    private static void generateMaze(int x, int y) {
        MAZE[x][y] = 1;
        while (true) {
            int[] permutation = RANDOM.ints(0, 4).distinct().limit(4).toArray();
            boolean moved = false;
            for (int d : permutation) {
                int newX = x + dx[d];
                int newY = y + dy[d];
                if (isValidMove(newX, newY)) {
                    generateMaze(newX, newY);
                    moved = true;
                    break;
                }
            }
            if (!moved) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        generateMaze(0, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(MAZE[i][j] == 1 ? "  " : "##");
            }
            System.out.println();
        }
    }
}
