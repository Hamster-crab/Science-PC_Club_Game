package src

import java.awt.*
import java.awt.event.ActionEvent
import java.awt.event.ActionListener
import javax.swing.*

object Main {
    private var PartnSato = ""
    private var PlayerName = ""
    private var gender = ""
    private var Image_Nomal_House = "resources/Textures/NomalHouse.png"
    private var Image_Tree =""
    private var Image_Normal_Tree = "resources/Textures/NomalTree.png"
    private var Image_Water_Empty = "resources/Textures/Water-Empty.png"
    private var Image_Water_Half = "resources/Textures/Water-Half.png"
    private var Image_Water_Full = "resources/Textures/Water-Full.png"
    private var Image_ICCard = "resources/Textures/ICCard.png"
    private var Image_Coin = "resources/Textures/Coin.png"

    @JvmStatic
    fun main(args: Array<String>) {
        SwingUtilities.invokeLater { createAndShowGUI() }
    }

    private fun createAndShowGUI() {
        val frame = JFrame("愛を知らせに来た佐藤 alpha ver 0.114514")
        frame.defaultCloseOperation = JFrame.EXIT_ON_CLOSE
        frame.setSize(800, 500)
        frame.setLocationRelativeTo(null)

        val panel = BackgroundPanel("resources/Sato/Title/TitleSato.ico")
        panel.layout = GridBagLayout()

        val gbc = GridBagConstraints()
        gbc.insets = Insets(10, 10, 10, 10)
        gbc.gridx = 0
        gbc.gridy = 0
        gbc.gridwidth = 1
        gbc.gridheight = 1
        gbc.anchor = GridBagConstraints.CENTER

        val label1 = JLabel("愛を知らせに来た佐藤")
        label1.font = Font("Serif", Font.BOLD, 60)
        label1.foreground = Color.PINK
        label1.horizontalAlignment = SwingConstants.CENTER
        gbc.gridy = 0
        panel.add(label1, gbc)

        val button1 = JButton("すたーと")
        button1.font = Font("Serif", Font.BOLD, 19)
        gbc.gridy = 1
        panel.add(button1, gbc)

        val button2 = JButton("せってい")
        button2.font = Font("Serif", Font.BOLD, 19)
        gbc.gridy = 2
        panel.add(button2, gbc)

        val button3 = JButton("おわり")
        button3.font = Font("Serif", Font.BOLD, 19)
        gbc.gridy = 3
        panel.add(button3, gbc)

        button1.addActionListener(StartButtonListener(frame))
        button2.addActionListener(SettingsButtonListener(frame, label1, button1, button2, button3))
        button3.addActionListener { e: ActionEvent? -> System.exit(0) }

        frame.add(panel)
        frame.isVisible = true
    }

    internal class BackgroundPanel(fileName: String?) : JPanel() {
        private val backgroundImage: Image? = Toolkit.getDefaultToolkit().createImage(fileName)

        override fun paintComponent(g: Graphics) {
            super.paintComponent(g)
            if (backgroundImage != null) {
                g.drawImage(backgroundImage, 0, 0, width, height, this)
            }
        }
    }

    internal class StartButtonListener(private val frame: JFrame) : ActionListener {
        override fun actionPerformed(e: ActionEvent) {
            val settingsFrame = JFrame("佐藤の選択")
            settingsFrame.setSize(1150, 680)
            settingsFrame.setLocationRelativeTo(frame)

            val buttonPanel = JPanel()
            buttonPanel.layout = FlowLayout()

            val partnerSato = JButton("ガンギマリ佐藤")
            val partnerSatoTwo = JButton("上から見る佐藤")
            val partnerSatoThree = JButton("親指を建てる佐藤")

            buttonPanel.add(partnerSato)
            buttonPanel.add(partnerSatoTwo)
            buttonPanel.add(partnerSatoThree)

            settingsFrame.contentPane.add(buttonPanel, BorderLayout.NORTH)

            val canvas = DrawCanvas()
            settingsFrame.contentPane.add(canvas, BorderLayout.CENTER)

            val decideButton = JButton("決定")
            decideButton.font = Font("Serif", Font.BOLD, 19)
            settingsFrame.contentPane.add(decideButton, BorderLayout.SOUTH)

            partnerSato.addActionListener { e1: ActionEvent? ->
                PartnSato = "resources/Sato/Partner-Sato/GanGimariSato.jpg"
                canvas.setImage(PartnSato)
            }

            partnerSatoTwo.addActionListener { e1: ActionEvent? ->
                PartnSato = "resources/Sato/Partner-Sato/SatoSeenFromAbove.jpg"
                canvas.setImage(PartnSato)
            }

            partnerSatoThree.addActionListener { e1: ActionEvent? ->
                PartnSato = "resources/Sato/Partner-Sato/ThumbsUpSato.jpg"
                canvas.setImage(PartnSato)
            }

            decideButton.addActionListener { e1: ActionEvent? ->
                println("Selected Sato Image Path: " + PartnSato)
                settingsFrame.dispose()

                val nameFrame = JFrame("名前入力")
                nameFrame.setSize(400, 200)
                nameFrame.setLocationRelativeTo(frame)

                val namePanel = JPanel()
                namePanel.layout = BorderLayout()

                val nameLabel = JLabel("あなたの名前(英語で)")
                nameLabel.font = Font("Serif", Font.BOLD, 24)
                nameLabel.horizontalAlignment = SwingConstants.CENTER
                namePanel.add(nameLabel, BorderLayout.NORTH)

                val nameTextField = JTextField()
                nameTextField.font = Font("Serif", Font.PLAIN, 24)
                namePanel.add(nameTextField, BorderLayout.CENTER)

                val selectButton = JButton("選択")
                selectButton.font = Font("Serif", Font.BOLD, 19)
                namePanel.add(selectButton, BorderLayout.SOUTH)

                nameFrame.add(namePanel)
                nameFrame.isVisible = true
                selectButton.addActionListener { e2: ActionEvent? ->
                    PlayerName = nameTextField.text
                    println("Player Name: " + PlayerName)
                    nameFrame.dispose()

                    val genderFrame = JFrame("性別を選択")
                    genderFrame.setSize(600, 200)
                    genderFrame.setLocationRelativeTo(frame)

                    val genderPanel = JPanel(GridBagLayout())
                    val gbc = GridBagConstraints()
                    gbc.insets = Insets(10, 10, 10, 10)

                    val genderLabel = JLabel("性別を選択")
                    genderLabel.font = Font("Serif", Font.BOLD, 24)
                    gbc.gridx = 0
                    gbc.gridy = 0
                    gbc.gridwidth = 3
                    gbc.anchor = GridBagConstraints.CENTER
                    genderPanel.add(genderLabel, gbc)

                    val femaleButton = JButton("女")
                    femaleButton.font = Font("Serif", Font.BOLD, 19)
                    gbc.gridx = 0
                    gbc.gridy = 1
                    gbc.gridwidth = 1
                    gbc.anchor = GridBagConstraints.WEST
                    genderPanel.add(femaleButton, gbc)

                    val hamsterButton = JButton("ハムスター")
                    hamsterButton.font = Font("Serif", Font.BOLD, 19)
                    gbc.gridx = 1
                    gbc.gridy = 1
                    gbc.anchor = GridBagConstraints.CENTER
                    genderPanel.add(hamsterButton, gbc)

                    val maleButton = JButton("男")
                    maleButton.font = Font("Serif", Font.BOLD, 19)
                    gbc.gridx = 2
                    gbc.gridy = 1
                    gbc.anchor = GridBagConstraints.EAST
                    genderPanel.add(maleButton, gbc)

                    val genderSelectionListener = ActionListener { e3: ActionEvent ->
                        gender = (e3.source as JButton).text
                        println("Gender: " + gender)
                        genderFrame.dispose()

                        val gameStartFrame = JFrame("ゲームスタート")
                        gameStartFrame.setSize(1100, 650) // Increase the window size
                        gameStartFrame.setLocationRelativeTo(frame)
                        gameStartFrame.isVisible = true
                    }

                    femaleButton.addActionListener(genderSelectionListener)
                    hamsterButton.addActionListener(genderSelectionListener)
                    maleButton.addActionListener(genderSelectionListener)

                    genderFrame.add(genderPanel)
                    genderFrame.isVisible = true
                }
            }

            settingsFrame.isVisible = true
        }
    }

    internal class DrawCanvas : JPanel() {
        private var imgIcon: ImageIcon? = null

        fun setImage(fileName: String) {
            val imgURL = javaClass.classLoader.getResource(fileName)
            if (imgURL != null) {
                imgIcon = ImageIcon(imgURL)
            } else {
                println("Error loading image: $fileName")
                imgIcon = null
            }
            repaint()
        }

        override fun paintComponent(g: Graphics) {
            super.paintComponent(g)
            if (imgIcon != null) {
                val width = imgIcon!!.iconWidth / 2
                val height = imgIcon!!.iconHeight / 2
                val x = (getWidth() - width) / 2
                val y = (getHeight() - height) / 2
                imgIcon!!.paintIcon(this, g, x, y)
            }
        }
    }

    internal class SettingsButtonListener(
        private val frame: JFrame,
        private val label1: JLabel,
        private val button1: JButton,
        private val button2: JButton,
        private val button3: JButton
    ) : ActionListener {
        override fun actionPerformed(e: ActionEvent) {
            val settingsFrame = JFrame("設定")
            settingsFrame.setSize(400, 200)
            settingsFrame.setLocationRelativeTo(frame)

            val settingsPanel = JPanel()
            settingsPanel.layout = GridLayout(2, 1)

            val languageLabel = JLabel("言語の設定")
            languageLabel.font = Font("Serif", Font.BOLD, 24)
            languageLabel.horizontalAlignment = SwingConstants.CENTER
            settingsPanel.add(languageLabel)

            val languagePanel = JPanel()
            languagePanel.layout = FlowLayout()

            val japaneseButton = JButton("日本語")
            val englishButton = JButton("English")

            languagePanel.add(japaneseButton)
            languagePanel.add(englishButton)

            settingsPanel.add(languagePanel)

            settingsFrame.add(settingsPanel)
            settingsFrame.isVisible = true

            japaneseButton.addActionListener { e1: ActionEvent? ->
                label1.text = "愛を知らせに来た佐藤"
                button1.text = "すたーと"
                button2.text = "せってい"
                button3.text = "おわり"
                settingsFrame.dispose()
            }

            englishButton.addActionListener { e1: ActionEvent? ->
                label1.text = "Sato has come to tell you about love"
                button1.text = "Start"
                button2.text = "Settings"
                button3.text = "Quit"
                settingsFrame.dispose()
            }
        }
    }
}
