import javax.swing.*;
import javax.swing.JFrame;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.util.Arrays;


public class Main {
    public static void main(String[] args) {

        java.awt.GraphicsEnvironment env = java.awt.GraphicsEnvironment.getLocalGraphicsEnvironment();
        // 変数desktopBoundsにデスクトップ領域を表すRectangleが代入される
        java.awt.Rectangle desktopBounds = env.getMaximumWindowBounds();
        System.out.println (desktopBounds);

        int desktopX = desktopBounds.x;
        int desktopY = desktopBounds.y;
        int desktopWIDTH = desktopBounds.width;
        int desktopHEIGTH = desktopBounds.height;

        JFrame frame = new JFrame("愛を知らせに来た佐藤");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 500);
        frame.setLocationRelativeTo(null);

        JPanel panel = new JPanel();
        panel.setLayout(null);

        // テキストを表示するラベルの作成
        JLabel label1 = new JLabel("愛を知らせに来た佐藤");
        label1.setBounds(70, 20, 650, 65);
        label1.setFont(new Font("SansSerif", Font.PLAIN, 60));
        label1.setHorizontalAlignment(SwingConstants.CENTER); // 中央寄せを追加
        panel.add(label1);

        // ボタンを作成
        JButton button1 = new JButton("すたーと");
        button1.setBounds(193, 130, 400, 50);
        panel.add(button1);

        JButton button2 = new JButton("せってい");
        button2.setBounds(193, 230, 400, 50);
        panel.add(button2);

        JButton button3 = new JButton("おわり");
        button3.setBounds(193, 340, 400, 50);
        panel.add(button3);

        //すたーとボタンが押されたとき
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // 新しいウィンドウを作成
                JFrame settingsFrame = new JFrame("イキスギワールド"); // タイトルは後で決める（ワールドの名前にするから）
                settingsFrame.setSize(1150, 680);
                settingsFrame.setLocationRelativeTo(frame);
                settingsFrame.setVisible(true);

                // 各佐藤選択ボタン
                JButton PartnerSato = new JButton("ガンギマリ佐藤");
                JButton PartnerSatoTWO = new JButton("上から見る佐藤");
                JButton PartnerSatoTHREE = new JButton("親指を建てる佐藤");

                // 佐藤画像
                class GameWindow extends JFrame{

                    public GameWindow(String title, int width, int height) {
                        super(title);
                        setDefaultCloseOperation(EXIT_ON_CLOSE);
                        setSize(width,height);
                        setLocationRelativeTo(null);
                        setResizable(false);
                    }
                }
                class DrawCanvas extends JPanel{
                    Image img = Toolkit.getDefaultToolkit().getImage("Sato/partner-sato/ガンギマリ佐藤.png");
                    public void paintComponent(Graphics g) {
                        super.paintComponent(g);
                        //画像の表示
                        g.drawImage(img, 0, 0, this);
                    }
                }

                JPanel p = new JPanel();
                p.add(PartnerSato);
                p.add(PartnerSatoTWO);
                p.add(PartnerSatoTHREE);

                Container contentPane = settingsFrame.getContentPane();
                contentPane.add(p, BorderLayout.CENTER);
            }
        });


        // Settings button is pressed
        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Create a new window
                JFrame settingsFrame = new JFrame("せってい"); // Changed window title to "Settings"
                settingsFrame.setSize(280, 70);
                settingsFrame.setLocationRelativeTo(frame);
                settingsFrame.setVisible(true);

                // Create a button for language switching
                JButton languageButton = new JButton("日本語");
                languageButton.setBounds(50, 50, 280, 70);
                settingsFrame.add(languageButton);

                // Action listener for the language button
                languageButton.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        String currentLabel = languageButton.getText();
                        if (currentLabel.equals("日本語")) {
                            languageButton.setText("English");
                            label1.setText("Sato who came to let us know of his love"); // Change label text
                            button1.setText("Start"); // Change button label
                            button2.setText("Settings"); // Change button label
                            button3.setText("End"); // Change button label
                        } else {
                            languageButton.setText("日本語");
                            label1.setText("愛を知らせに来た佐藤"); // Restore original label text
                            button1.setText("すたーと"); // Restore original button label
                            button2.setText("せってい"); // Restore original button label
                            button3.setText("おわり"); // Restore original button label
                        }
                    }
                });
            }
        });


        // おわりボタンが押されたとき
        button3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Component c = (Component)e.getSource();

                Window w = SwingUtilities.getWindowAncestor(c);

                w.dispose();
            }
        });


        frame.add(panel);
        frame.setVisible(true);
    }
}
