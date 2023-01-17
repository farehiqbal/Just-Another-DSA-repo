import java.awt.Graphics;
import java.awt.Color;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class MazeSolver {
    private static final int N = 10;
    private static final int CELL_SIZE = 50;
    private static final int[][] MAZE = {{1, 1, 1, 0, 1, 1, 0, 0, 0, 1},
                                        {0, 0, 1, 1, 1, 0, 1, 1, 1, 1},
                                        {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
                                        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
                                        {1, 0, 1, 0, 0, 0, 0, 1, 1, 1},
                                        {0, 0, 0, 1, 1, 1, 0, 1, 0, 1},
                                        {0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
                                        {1, 1, 0, 0, 0, 1, 1, 0, 1, 1},
                                        {1, 0, 0, 1, 0, 0, 1, 1, 0, 0},
                                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};



    public static void main(String[] args) {

        JFrame frame = new JFrame("Maze Solver");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(N * CELL_SIZE + 1, N * CELL_SIZE + 1);
        frame.setVisible(true);

        JPanel panel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                g.setColor(Color.BLACK);
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        if (MAZE[i][j] == 1) {
                            g.fillRect(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE);
                        }
                    }
                }
            }
        };
        frame.add(panel);
    }
}
