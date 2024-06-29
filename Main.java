import javax.swing.*;
import javax.swing.JFrame;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.util.Arrays;


public class Main {
    public static void main(String[] args) {

        // GraphicsEnvironmentからデスクトップ領域を取得
        GraphicsEnvironment env = GraphicsEnvironment.getLocalGraphicsEnvironment();
        Rectangle desktopBounds = env.getMaximumWindowBounds();

        JFrame frame = new JFrame("愛を知らせに来た佐藤");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 500);
        frame.setLocationRelativeTo(null);

        // 背景画像のパス
        String backgroundImage = "./Sato/Title/TitleSato.png";

        // 背景画像を描画するパネルを作成
        ImagePanel panel = new ImagePanel(backgroundImage);
        panel.setLayout(null); // レイアウトマネージャーをnullに設定する

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

        // すたーとボタンが押されたときの処理
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // 新しいウィンドウを作成
                JFrame settingsFrame = new JFrame("イキスギワールド");
                settingsFrame.setSize(1150, 680);
                settingsFrame.setLocationRelativeTo(frame);
                settingsFrame.setVisible(true);

                // 各佐藤選択ボタン
                JButton PartnerSato = new JButton("ガンギマリ佐藤");
                JButton PartnerSatoTWO = new JButton("上から見る佐藤");
                JButton PartnerSatoTHREE = new JButton("親指を建てる佐藤");

                JPanel p = new JPanel();
                p.add(PartnerSato);
                p.add(PartnerSatoTWO);
                p.add(PartnerSatoTHREE);

                Container contentPane = settingsFrame.getContentPane();
                contentPane.add(p, BorderLayout.CENTER);
            }
        });

        // せっていボタンが押されたときの処理
        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // 設定ウィンドウを作成
                JFrame settingsFrame = new JFrame("せってい");
                settingsFrame.setSize(280, 70);
                settingsFrame.setLocationRelativeTo(frame);
                settingsFrame.setVisible(true);

                // 言語切り替えボタン
                JButton languageButton = new JButton("日本語");
                languageButton.setBounds(50, 50, 280, 70);
                settingsFrame.add(languageButton);

                // 言語切り替えボタンのアクションリスナー
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

        // おわりボタンが押されたときの処理
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
