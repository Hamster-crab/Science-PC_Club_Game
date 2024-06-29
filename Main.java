import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main {
    public static void main(String[] args) {
        // デスクトップ領域の取得
        GraphicsEnvironment env = GraphicsEnvironment.getLocalGraphicsEnvironment();
        Rectangle desktopBounds = env.getMaximumWindowBounds();
        System.out.println(desktopBounds);

        // メインウィンドウの設定
        JFrame frame = new JFrame("愛を知らせに来た佐藤");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 500);
        frame.setLocationRelativeTo(null);

        // 背景画像を描画するカスタムJPanelクラス
        class BackgroundPanel extends JPanel {
            private Image backgroundImage;

            // コンストラクタで背景画像のファイル名を受け取る
            public BackgroundPanel(String fileName) {
                backgroundImage = Toolkit.getDefaultToolkit().createImage(fileName);
            }

            // 背景画像を描画
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                if (backgroundImage != null) {
                    g.drawImage(backgroundImage, 0, 0, getWidth(), getHeight(), this);
                }
            }
        }

        // カスタムJPanelをメインパネルとして使用
        BackgroundPanel panel = new BackgroundPanel("Sato/Title/TitleSato.png");
        panel.setLayout(null);

        // タイトルラベルの設定（ピンク色で見やすいフォント）
        JLabel label1 = new JLabel("愛を知らせに来た佐藤");
        label1.setBounds(70, 20, 650, 65);
        label1.setFont(new Font("Serif", Font.BOLD, 60)); // 見やすいフォントに設定
        label1.setForeground(Color.PINK); // ピンク色に設定
        label1.setHorizontalAlignment(SwingConstants.CENTER);
        panel.add(label1);

        // ボタンの設定
        JButton button1 = new JButton("すたーと");
        button1.setBounds(193, 130, 400, 50);
        button1.setFont(new Font("Serif", Font.BOLD, 24)); // フォントを小さく設定
        panel.add(button1);

        JButton button2 = new JButton("せってい");
        button2.setBounds(193, 230, 400, 50);
        button2.setFont(new Font("Serif", Font.BOLD, 24)); // フォントを小さく設定
        panel.add(button2);

        JButton button3 = new JButton("おわり");
        button3.setBounds(193, 340, 400, 50);
        button3.setFont(new Font("Serif", Font.BOLD, 24)); // フォントを小さく設定
        panel.add(button3);

        // 「すたーと」ボタンが押されたときのアクションリスナー
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // 新しいウィンドウの作成
                JFrame settingsFrame = new JFrame("イキスギワールド");
                settingsFrame.setSize(1150, 680);
                settingsFrame.setLocationRelativeTo(frame);
                settingsFrame.setVisible(true);

                // 佐藤選択ボタンの設定
                JPanel buttonPanel = new JPanel();
                JButton partnerSato = new JButton("ガンギマリ佐藤");
                JButton partnerSatoTwo = new JButton("上から見る佐藤");
                JButton partnerSatoThree = new JButton("親指を建てる佐藤");

                buttonPanel.add(partnerSato);
                buttonPanel.add(partnerSatoTwo);
                buttonPanel.add(partnerSatoThree);

                settingsFrame.getContentPane().add(buttonPanel, BorderLayout.CENTER);

                // 画像描画用のカスタムJPanelクラス
                class DrawCanvas extends JPanel {
                    final Image img = Toolkit.getDefaultToolkit().getImage("Sato/partner-sato/ガンギマリ佐藤.png");

                    @Override
                    protected void paintComponent(Graphics g) {
                        super.paintComponent(g);
                        g.drawImage(img, 0, 0, this);
                    }
                }

                settingsFrame.getContentPane().add(new DrawCanvas(), BorderLayout.CENTER);
            }
        });

        // 「せってい」ボタンが押されたときのアクションリスナー
        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // 新しいウィンドウの作成
                JFrame settingsFrame = new JFrame("せってい");
                settingsFrame.setSize(280, 70);
                settingsFrame.setLocationRelativeTo(frame);
                settingsFrame.setVisible(true);

                // 言語切替ボタンの設定
                JButton languageButton = new JButton("日本語");
                languageButton.setBounds(50, 50, 280, 70);
                languageButton.setFont(new Font("Serif", Font.BOLD, 24)); // フォントを小さく設定
                settingsFrame.add(languageButton);

                // 言語切替ボタンのアクションリスナー
                languageButton.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        String currentLabel = languageButton.getText();
                        if (currentLabel.equals("日本語")) {
                            languageButton.setText("English");
                            label1.setText("Sato who came to let us know of his love");
                            button1.setText("Start");
                            button2.setText("Settings");
                            button3.setText("End");
                        } else {
                            languageButton.setText("日本語");
                            label1.setText("愛を知らせに来た佐藤");
                            button1.setText("すたーと");
                            button2.setText("せってい");
                            button3.setText("おわり");
                        }
                    }
                });
            }
        });

        // 「おわり」ボタンが押されたときのアクションリスナー
        button3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Component c = (Component) e.getSource();
                Window w = SwingUtilities.getWindowAncestor(c);
                w.dispose();
            }
        });

        // メインウィンドウにパネルを追加
        frame.add(panel);
        frame.setVisible(true);
    }
}
