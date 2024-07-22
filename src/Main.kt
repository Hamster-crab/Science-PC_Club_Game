package src

import java.awt.*
import java.awt.event.ActionEvent
import java.awt.event.ActionListener
import javax.swing.*

object Main {
    // ImageID
    private var partnSato = ""
    private var playerName = ""
    private var gender = ""
    private const val imageNormalHouse = "resources/Textures/NomalHouse.png"
    private var imageTree = ""
    private const val imageNormalTree = "resources/Textures/NomalTree.png"
    private const val imageWaterEmpty = "resources/Textures/Water-Empty.png"
    private const val imageWaterHalf = "resources/Textures/Water-Half.png"
    private const val imageWaterFull = "resources/Textures/Water-Full.png"
    private const val imageICCard = "resources/Textures/ICCard.png"
    private const val imageCoin = "resources/Textures/Coin.png"

    @JvmStatic
    fun main(args: Array<String>) {
        SwingUtilities.invokeLater { createAndShowGUI() }
    }

    private fun createAndShowGUI() {
        val frame = JFrame("愛を知らせに来た佐藤 alpha ver 0.11451481019194545")
        frame.defaultCloseOperation = JFrame.EXIT_ON_CLOSE
        frame.setSize(800, 500)
        frame.setLocationRelativeTo(null)

        val panel = BackgroundPanel("resources/Satos/Title/TitleSato.ico")
        panel.layout = GridBagLayout()

        val gbc = GridBagConstraints()
        gbc.insets = Insets(10, 10, 10, 10)
        gbc.gridx = 0
        gbc.gridy = 0
        gbc.gridwidth = 1
        gbc.gridheight = 1
        gbc.anchor = GridBagConstraints.CENTER

        val Title = JLabel("愛を知らせに来た佐藤")
        Title.font = Font("Serif", Font.BOLD, 60)
        Titile.foreground = Color.PINK
        Title.horizontalAlignment = SwingConstants.CENTER
        gbc.gridy = 0
        panel.add(label1, gbc)

        val Start = JButton("すたーと")
        Start.font = Font("Serif", Font.BOLD, 19)
        gbc.gridy = 1
        panel.add(button1, gbc)

        val Setting = JButton("せってい")
        Setting.font = Font("Serif", Font.BOLD, 19)
        gbc.gridy = 2
        panel.add(button2, gbc)

        val EnD = JButton("おわり")
        EnD.font = Font("Serif", Font.BOLD, 19)
        gbc.gridy = 3
        panel.add(button3, gbc)

        Start.addActionListener(StartButtonListener(frame))
        Setting.addActionListener(SettingsButtonListener(frame, label1, button1, button2, button3))
        EnD.addActionListener { System.exit(0) }

        frame.add(panel)
        frame.isVisible = true
    }

    internal class BackgroundPanel(fileName: String?) : JPanel() {
        private val backgroundImage: Image? = Toolkit.getDefaultToolkit().getImage(javaClass.classLoader.getResource(fileName))

        override fun paintComponent(g: Graphics) {
            super.paintComponent(g)
            backgroundImage?.let {
                g.drawImage(it, 0, 0, width, height, this)
            }
        }
    }

    internal class StartButtonListener(private val frame: JFrame) : ActionListener {
        override fun actionPerformed(e: ActionEvent) {
            val SatoSelect = "佐藤の選択"
            val settingsFrame = JFrame(SatoSelect)
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
            val Decision = "決定"
            val decideButton = JButton(Decision)
            decideButton.font = Font("Serif", Font.BOLD, 19)
            settingsFrame.contentPane.add(decideButton, BorderLayout.SOUTH)

            partnerSato.addActionListener {
                partnSato = "resources/Satos/Partner-Sato/GanGimariSato.jpg"
                canvas.setImage(partnSato)
            }

            partnerSatoTwo.addActionListener {
                partnSato = "resources/Satos/Partner-Sato/SatoSeenFromAbove.jpg"
                canvas.setImage(partnSato)
            }

            partnerSatoThree.addActionListener {
                partnSato = "resources/Satos/Partner-Sato/ThumbsUpSato.jpg"
                canvas.setImage(partnSato)
            }

            decideButton.addActionListener {
                println("Selected Sato Image Path: $partnSato")
                settingsFrame.dispose()

                val EnterYourName = "名前入力"
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
                selectButton.addActionListener {
                    playerName = nameTextField.text
                    println("Player Name: $playerName")
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
                        println("Gender: $gender")
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
            imgIcon?.let {
                val width = it.iconWidth / 2
                val height = it.iconHeight / 2
                val x = (width - width) / 2
                val y = (height - height) / 2
                it.paintIcon(this, g, x, y)
            }
        }
    }

    internal class SettingsButtonListener(
        private val frame: JFrame,
        private val Title: JLabel,
        private val Start: JButton,
        private val Setting: JButton,
        private val EnD: JButton
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

            japaneseButton.addActionListener {
                Title.text = "愛を知らせに来た佐藤"
                Start.text = "すたーと"
                Setting.text = "せってい"
                EnD.text = "おわり"
                SatoSelect.text = "佐藤の選択"
                EnterYourName.text = "名前入力"
                femaleButton.text ="女"
                hamsterButton.text = "ハムスター"
                maleButton.text = "男"
                gameStartFrame.text = "ゲームスタート"
                settingsFrame.text = "設定"
                settingsFrame.dispose()

            }

            englishButton.addActionListener {
                Title.text = "Sato has come to tell you about love"
                Start.text = "Start"
                Setting.text = "Settings"
                EnD.text = "Quit"
                SatoSelect.text = "Sato's Choice"
                EnterYourName.text = "Enter Your Name"
                femaleButton.text ="Female"
                hamsterButton.text = "Hamster"
                maleButton.text = "Man"
                gameStartFrame.text = "Game Start"
                settingsFrame.text = "Settings"
                settingsFrame.dispose()

            }
        }
    }
}
