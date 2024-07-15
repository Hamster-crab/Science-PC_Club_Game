package src;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main {
    private static String PartnSato = "";
    private static String PlayerName = "";
    private static String gender = "";

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> createAndShowGUI());
    }

    private static void createAndShowGUI() {
        JFrame frame = new JFrame("愛を知らせに来た佐藤 alpha ver 0.114514");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800, 500);
        frame.setLocationRelativeTo(null);

        BackgroundPanel panel = new BackgroundPanel("resources/Sato/Title/TitleSato.ico");
        panel.setLayout(new GridBagLayout());

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(10, 10, 10, 10);
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        gbc.anchor = GridBagConstraints.CENTER;

        JLabel label1 = new JLabel("愛を知らせに来た佐藤");
        label1.setFont(new Font("Serif", Font.BOLD, 60));
        label1.setForeground(Color.PINK);
        label1.setHorizontalAlignment(SwingConstants.CENTER);
        gbc.gridy = 0;
        panel.add(label1, gbc);

        JButton button1 = new JButton("すたーと");
        button1.setFont(new Font("Serif", Font.BOLD, 19));
        gbc.gridy = 1;
        panel.add(button1, gbc);

        JButton button2 = new JButton("せってい");
        button2.setFont(new Font("Serif", Font.BOLD, 19));
        gbc.gridy = 2;
        panel.add(button2, gbc);

        JButton button3 = new JButton("おわり");
        button3.setFont(new Font("Serif", Font.BOLD, 19));
        gbc.gridy = 3;
        panel.add(button3, gbc);

        button1.addActionListener(new StartButtonListener(frame));
        button2.addActionListener(new SettingsButtonListener(frame, label1, button1, button2, button3));
        button3.addActionListener(e -> System.exit(0));

        frame.add(panel);
        frame.setVisible(true);
    }

    static class BackgroundPanel extends JPanel {
        private final Image backgroundImage;

        public BackgroundPanel(String fileName) {
            backgroundImage = Toolkit.getDefaultToolkit().createImage(fileName);
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            if (backgroundImage != null) {
                g.drawImage(backgroundImage, 0, 0, getWidth(), getHeight(), this);
            }
        }
    }

    static class StartButtonListener implements ActionListener {
        private final JFrame frame;

        public StartButtonListener(JFrame frame) {
            this.frame = frame;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            JFrame settingsFrame = new JFrame("佐藤の選択");
            settingsFrame.setSize(1150, 680);
            settingsFrame.setLocationRelativeTo(frame);

            JPanel buttonPanel = new JPanel();
            buttonPanel.setLayout(new FlowLayout());

            JButton partnerSato = new JButton("ガンギマリ佐藤");
            JButton partnerSatoTwo = new JButton("上から見る佐藤");
            JButton partnerSatoThree = new JButton("親指を建てる佐藤");

            buttonPanel.add(partnerSato);
            buttonPanel.add(partnerSatoTwo);
            buttonPanel.add(partnerSatoThree);

            settingsFrame.getContentPane().add(buttonPanel, BorderLayout.NORTH);

            DrawCanvas canvas = new DrawCanvas();
            settingsFrame.getContentPane().add(canvas, BorderLayout.CENTER);

            JButton decideButton = new JButton("決定");
            decideButton.setFont(new Font("Serif", Font.BOLD, 19));
            settingsFrame.getContentPane().add(decideButton, BorderLayout.SOUTH);

            partnerSato.addActionListener(e1 -> {
                PartnSato = "resources/Sato/Partner-Sato/GanGimariSato.jpg";
                canvas.setImage(PartnSato);
            });

            partnerSatoTwo.addActionListener(e1 -> {
                PartnSato = "resources/Sato/Partner-Sato/SatoSeenFromAbove.jpg";
                canvas.setImage(PartnSato);
            });

            partnerSatoThree.addActionListener(e1 -> {
                PartnSato = "resources/Sato/Partner-Sato/ThumbsUpSato.jpg";
                canvas.setImage(PartnSato);
            });

            decideButton.addActionListener(e1 -> {
                System.out.println("Selected Sato Image Path: " + PartnSato);
                settingsFrame.dispose();

                JFrame nameFrame = new JFrame("名前入力");
                nameFrame.setSize(400, 200);
                nameFrame.setLocationRelativeTo(frame);

                JPanel namePanel = new JPanel();
                namePanel.setLayout(new BorderLayout());

                JLabel nameLabel = new JLabel("あなたの名前(英語で)");
                nameLabel.setFont(new Font("Serif", Font.BOLD, 24));
                nameLabel.setHorizontalAlignment(SwingConstants.CENTER);
                namePanel.add(nameLabel, BorderLayout.NORTH);

                JTextField nameTextField = new JTextField();
                nameTextField.setFont(new Font("Serif", Font.PLAIN, 24));
                namePanel.add(nameTextField, BorderLayout.CENTER);

                JButton selectButton = new JButton("選択");
                selectButton.setFont(new Font("Serif", Font.BOLD, 19));
                namePanel.add(selectButton, BorderLayout.SOUTH);

                nameFrame.add(namePanel);
                nameFrame.setVisible(true);

                selectButton.addActionListener(e2 -> {
                    PlayerName = nameTextField.getText();
                    System.out.println("Player Name: " + PlayerName);
                    nameFrame.dispose();

                    JFrame genderFrame = new JFrame("性別を選択");
                    genderFrame.setSize(600, 200);
                    genderFrame.setLocationRelativeTo(frame);

                    JPanel genderPanel = new JPanel(new GridBagLayout());
                    GridBagConstraints gbc = new GridBagConstraints();
                    gbc.insets = new Insets(10, 10, 10, 10);

                    JLabel genderLabel = new JLabel("性別を選択");
                    genderLabel.setFont(new Font("Serif", Font.BOLD, 24));
                    gbc.gridx = 0;
                    gbc.gridy = 0;
                    gbc.gridwidth = 3;
                    gbc.anchor = GridBagConstraints.CENTER;
                    genderPanel.add(genderLabel, gbc);

                    JButton femaleButton = new JButton("女");
                    femaleButton.setFont(new Font("Serif", Font.BOLD, 19));
                    gbc.gridx = 0;
                    gbc.gridy = 1;
                    gbc.gridwidth = 1;
                    gbc.anchor = GridBagConstraints.WEST;
                    genderPanel.add(femaleButton, gbc);

                    JButton hamsterButton = new JButton("ハムスター");
                    hamsterButton.setFont(new Font("Serif", Font.BOLD, 19));
                    gbc.gridx = 1;
                    gbc.gridy = 1;
                    gbc.anchor = GridBagConstraints.CENTER;
                    genderPanel.add(hamsterButton, gbc);

                    JButton maleButton = new JButton("男");
                    maleButton.setFont(new Font("Serif", Font.BOLD, 19));
                    gbc.gridx = 2;
                    gbc.gridy = 1;
                    gbc.anchor = GridBagConstraints.EAST;
                    genderPanel.add(maleButton, gbc);

                    ActionListener genderSelectionListener = e3 -> {
                        gender = ((JButton) e3.getSource()).getText();
                        System.out.println("Gender: " + gender);
                        genderFrame.dispose();

                        JFrame gameStartFrame = new JFrame("ゲームスタート");
                        gameStartFrame.setSize(1100, 650);  // Increase the window size
                        gameStartFrame.setLocationRelativeTo(frame);

                        gameStartFrame.setVisible(true);
                    };

                    femaleButton.addActionListener(genderSelectionListener);
                    hamsterButton.addActionListener(genderSelectionListener);
                    maleButton.addActionListener(genderSelectionListener);

                    genderFrame.add(genderPanel);
                    genderFrame.setVisible(true);
                });
            });

            settingsFrame.setVisible(true);
        }
    }

    static class DrawCanvas extends JPanel {
        private ImageIcon imgIcon;

        public void setImage(String fileName) {
            java.net.URL imgURL = getClass().getClassLoader().getResource(fileName);
            if (imgURL != null) {
                imgIcon = new ImageIcon(imgURL);
            } else {
                System.out.println("Error loading image: " + fileName);
                imgIcon = null;
            }
            repaint();
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            if (imgIcon != null) {
                int width = imgIcon.getIconWidth() / 2;
                int height = imgIcon.getIconHeight() / 2;
                int x = (getWidth() - width) / 2;
                int y = (getHeight() - height) / 2;
                imgIcon.paintIcon(this, g, x, y);
            }
        }
    }

    static class SettingsButtonListener implements ActionListener {
        private final JFrame frame;
        private final JLabel label1;
        private final JButton button1;
        private final JButton button2;
        private final JButton button3;

        public SettingsButtonListener(JFrame frame, JLabel label1, JButton button1, JButton button2, JButton button3) {
            this.frame = frame;
            this.label1 = label1;
            this.button1 = button1;
            this.button2 = button2;
            this.button3 = button3;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            JFrame settingsFrame = new JFrame("設定");
            settingsFrame.setSize(400, 200);
            settingsFrame.setLocationRelativeTo(frame);

            JPanel settingsPanel = new JPanel();
            settingsPanel.setLayout(new GridLayout(2, 1));

            JLabel languageLabel = new JLabel("言語の設定");
            languageLabel.setFont(new Font("Serif", Font.BOLD, 24));
            languageLabel.setHorizontalAlignment(SwingConstants.CENTER);
            settingsPanel.add(languageLabel);

            JPanel languagePanel = new JPanel();
            languagePanel.setLayout(new FlowLayout());

            JButton japaneseButton = new JButton("日本語");
            JButton englishButton = new JButton("English");

            languagePanel.add(japaneseButton);
            languagePanel.add(englishButton);

            settingsPanel.add(languagePanel);

            settingsFrame.add(settingsPanel);
            settingsFrame.setVisible(true);

            japaneseButton.addActionListener(e1 -> {
                label1.setText("愛を知らせに来た佐藤");
                button1.setText("すたーと");
                button2.setText("せってい");
                button3.setText("おわり");
                settingsFrame.dispose();
            });

            englishButton.addActionListener(e1 -> {
                label1.setText("Sato has come to tell you about love");
                button1.setText("Start");
                button2.setText("Settings");
                button3.setText("Quit");
                settingsFrame.dispose();
            });
        }
    }
}
