import javax.swing.*;
import java.awt.*;
import java.io.File;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("愛を知らせに来た佐藤");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 500);
        frame.setLocationRelativeTo(null);

        // テキストを表示するラベルの作成
        JLabel label1 = new JLabel("愛を知らせに来た佐藤");
        label1.setBounds(243, 20, 350, 35);
        label1.setFont(new Font("SansSerif", Font.PLAIN, 30));
        label1.setHorizontalAlignment(SwingConstants.CENTER); // 中央寄せを追加
        panel.add(label1);

        // ボタンを作成
        JButton button1 = new JButton("すたーと");
        button1.setBounds(233, 130, 400, 50);
        panel.add(button1);

        JButton button2 = new JButton("せってい");
        button2.setBounds(233, 230, 400, 50);
        panel.add(button2);

        JButton button3 = new JButton("おわり");
        button3.setBounds(233, 340, 400, 50);
        panel.add(button3);

        frame.add(panel);
        frame.setVisible(true);
    }
}
