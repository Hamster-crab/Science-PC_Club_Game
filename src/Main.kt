package src

import java.awt.*
import java.awt.event.ActionEvent
import java.awt.event.ActionListener
import java.awt.event.KeyEvent
import java.awt.event.KeyListener
import javax.swing.*

object Main {
    private var partnSato = ""
    private var playerName = ""
    private var gender = ""
    private var imageTree = ""
    private const val imageNormalHouse = "resources/Textures/NomalHouse.png"
    private const val imageNormalTree = "resources/Textures/NomalTree.png"
    private const val imageWaterEmpty = "resources/Textures/Water-Empty.png"
    private const val imageWaterHalf = "resources/Textures/Water-Half.png"
    private const val imageWaterFull = "resources/Textures/Water-Full.png"
    private const val imageICCard = "resources/Textures/ICCard.png"
    private const val imageCoin = "resources/Textures/Coin.png"
    // private const val blockDirt = "resources/Textures/block_Dirt.jpg"
    private const val blockgrassone = "resources/Textures/maptile_grasslands_one.jpg"
    private const val blockgrasstwo = "resources/Textures/maptile_grasslands_two.jpg"
    private const val playerHeart = "resources/Textures/player_heart.jpg"
    private const val cow = "resources/Textures/CowLanguage.jpg"
    private const val beef = "resources/Textures/Beef.jpg"
    private const val boiledEgg = "resources/Textures/boiled_egg.jpg"
    private const val BossesT = "resources/Textures/Explosiveturbo_T.jpg"
    private const val MiddleFinger = "resources/Textures/FuckYou_Senpai_BB.jpg"
    private const val BossesS = "resources/Textures/Ikegai_senpai_BB.jpg"
    private const val FuckYouSenpai = "resources/Textures/Kiwi_Senpai(notBB).jpg"
    private const val BossesK = "resources/Textures/MiddleFingerMessengerAppears.jpg"
    private const val PlayerArm = "resources/Textures/player_arm_bot.png"

    private const val BackGroundImageOverWorld = ""

    private var language = "JP"

    @JvmStatic
    fun main(args: Array<String>) {
        SwingUtilities.invokeLater { createAndShowGUI() }
    }

    private fun createAndShowGUI() {
        val frame = JFrame(getText("title"))
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

        val title = JLabel(getText("mainTitle"))
        title.font = Font("Serif", Font.BOLD, 60)
        title.foreground = Color.PINK
        title.horizontalAlignment = SwingConstants.CENTER
        gbc.gridy = 0
        panel.add(title, gbc)

        val start = JButton(getText("start"))
        start.font = Font("Serif", Font.BOLD, 19)
        gbc.gridy = 1
        panel.add(start, gbc)

        val setting = JButton(getText("settings"))
        setting.font = Font("Serif", Font.BOLD, 19)
        gbc.gridy = 2
        panel.add(setting, gbc)

        val end = JButton(getText("quit"))
        end.font = Font("Serif", Font.BOLD, 19)
        gbc.gridy = 3
        panel.add(end, gbc)

        start.addActionListener(StartButtonListener(frame))
        setting.addActionListener(SettingsButtonListener(frame, title, start, setting, end))
        end.addActionListener { System.exit(0) }

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
            val satoSelect = getText("selectSato")
            val settingsFrame = JFrame(satoSelect)
            settingsFrame.setSize(1150, 680)
            settingsFrame.setLocationRelativeTo(frame)

            val buttonPanel = JPanel()
            buttonPanel.layout = FlowLayout()

            val partnerSato = JButton(getText("gangimariSato"))
            val partnerSatoTwo = JButton(getText("satoFromAbove"))
            val partnerSatoThree = JButton(getText("thumbsUpSato"))

            buttonPanel.add(partnerSato)
            buttonPanel.add(partnerSatoTwo)
            buttonPanel.add(partnerSatoThree)

            settingsFrame.contentPane.add(buttonPanel, BorderLayout.NORTH)

            val canvas = DrawCanvas()
            settingsFrame.contentPane.add(canvas, BorderLayout.CENTER)
            val decision = getText("decide")
            val decideButton = JButton(decision)
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
                if (partnSato.isEmpty()) {
                    partnSato = "resources/YajuSenpai"
                }
                println("Selected Sato Image Path: $partnSato")
                settingsFrame.dispose()

                val enterYourName = getText("enterYourName")
                val nameFrame = JFrame(enterYourName)
                nameFrame.setSize(400, 200)
                nameFrame.setLocationRelativeTo(frame)

                val namePanel = JPanel()
                namePanel.layout = BorderLayout()

                val nameLabel = JLabel(getText("yourName"))
                nameLabel.font = Font("Serif", Font.BOLD, 24)
                nameLabel.horizontalAlignment = SwingConstants.CENTER
                namePanel.add(nameLabel, BorderLayout.NORTH)

                val nameTextField = JTextField()
                nameTextField.font = Font("Serif", Font.PLAIN, 24)
                namePanel.add(nameTextField, BorderLayout.CENTER)

                val selectButton = JButton(getText("select"))
                selectButton.font = Font("Serif", Font.BOLD, 19)
                namePanel.add(selectButton, BorderLayout.SOUTH)

                nameFrame.add(namePanel)
                nameFrame.isVisible = true
                selectButton.addActionListener {
                    playerName = nameTextField.text
                    println("Player Name: $playerName")
                    nameFrame.dispose()

                    val genderFrame = JFrame(getText("selectGender"))
                    genderFrame.setSize(600, 200)
                    genderFrame.setLocationRelativeTo(frame)

                    val genderPanel = JPanel(GridBagLayout())
                    val gbc = GridBagConstraints()
                    gbc.insets = Insets(10, 10, 10, 10)

                    val genderLabel = JLabel(getText("selectGender"))
                    genderLabel.font = Font("Serif", Font.BOLD, 24)
                    gbc.gridx = 0
                    gbc.gridy = 0
                    gbc.gridwidth = 3
                    gbc.anchor = GridBagConstraints.CENTER
                    genderPanel.add(genderLabel, gbc)

                    val femaleButton = JButton(getText("female"))
                    femaleButton.font = Font("Serif", Font.BOLD, 19)
                    gbc.gridx = 0
                    gbc.gridy = 1
                    gbc.gridwidth = 1
                    gbc.anchor = GridBagConstraints.WEST
                    genderPanel.add(femaleButton, gbc)

                    val hamsterButton = JButton(getText("hamster"))
                    hamsterButton.font = Font("Serif", Font.BOLD, 19)
                    gbc.gridx = 1
                    gbc.gridy = 1
                    gbc.anchor = GridBagConstraints.CENTER
                    genderPanel.add(hamsterButton, gbc)

                    val maleButton = JButton(getText("male"))
                    maleButton.font = Font("Serif", Font.BOLD, 19)
                    gbc.gridx = 2
                    gbc.gridy = 1
                    gbc.anchor = GridBagConstraints.EAST
                    genderPanel.add(maleButton, gbc)

                    val genderSelectionListener = ActionListener { e3: ActionEvent ->
                        gender = (e3.source as JButton).text
                        println("Gender: $gender")
                        genderFrame.dispose()

                        val gameStartFrame = JFrame(getText("gameStart"))
                        gameStartFrame.setSize(1100, 650) // Increase the window size
                        gameStartFrame.setLocationRelativeTo(frame)
                        val gamePanel = GamePanel()
                        gameStartFrame.add(gamePanel)
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
        private val title: JLabel,
        private val start: JButton,
        private val setting: JButton,
        private val end: JButton
    ) : ActionListener {
        override fun actionPerformed(e: ActionEvent) {
            val settingsFrame = JFrame(getText("settings"))
            settingsFrame.setSize(400, 200)
            settingsFrame.setLocationRelativeTo(frame)

            val settingsPanel = JPanel()
            settingsPanel.layout = GridLayout(2, 1)

            val languageLabel = JLabel(getText("languageSettings"))
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
                language = "JP"
                updateText(title, start, setting, end)
                settingsFrame.dispose()
            }

            englishButton.addActionListener {
                language = "EN"
                updateText(title, start, setting, end)
                settingsFrame.dispose()
            }
        }

        private fun updateText(title: JLabel, start: JButton, setting: JButton, end: JButton) {
            title.text = getText("mainTitle")
            start.text = getText("start")
            setting.text = getText("settings")
            end.text = getText("quit")
        }
    }

    private fun getText(key: String): String {
        val textsJP = mapOf(
            "title" to "愛を知らせに来た佐藤 alpha ver 0.11451481019194545",
            "mainTitle" to "愛を知らせに来た佐藤",
            "start" to "すたーと",
            "settings" to "せってい",
            "quit" to "おわり",
            "selectSato" to "佐藤の選択",
            "gangimariSato" to "ガンギマリ佐藤",
            "satoFromAbove" to "上から見る佐藤",
            "thumbsUpSato" to "親指を建てる佐藤",
            "decide" to "決定",
            "enterYourName" to "名前入力",
            "yourName" to "あなたの名前(英語で)",
            "select" to "選択",
            "selectGender" to "性別を選択",
            "female" to "女",
            "hamster" to "ハムスター",
            "male" to "男",
            "gameStart" to "ゲームスタート",
            "languageSettings" to "言語の設定"
        )

        val textsEN = mapOf(
            "title" to "Sato has come to tell you about love alpha ver 0.11451481019194545",
            "mainTitle" to "Sato has come to tell you about love",
            "start" to "Start",
            "settings" to "Settings",
            "quit" to "Quit",
            "selectSato" to "Select Sato",
            "gangimariSato" to "Gangimari Sato",
            "satoFromAbove" to "Sato Seen From Above",
            "thumbsUpSato" to "Thumbs Up Sato",
            "decide" to "Decide",
            "enterYourName" to "Enter Your Name",
            "yourName" to "Your Name (in English)",
            "select" to "Select",
            "selectGender" to "Select Gender",
            "female" to "Female",
            "hamster" to "Hamster",
            "male" to "Male",
            "gameStart" to "Game Start",
            "languageSettings" to "Language Settings"
        )

        return if (language == "JP") textsJP[key] ?: key else textsEN[key] ?: key
    }

// 
    internal class GamePanel : JPanel(), KeyListener {
        private var playerX = 0
        private var playerY = 0
        private var img: Image? = null
        private val backgroundMap = mutableMapOf<Pair<Int, Int>, Image>()
    
        private var viewX = 0
        private var viewY = 0
    
        private val scrollSpeed = 10
    
        // 押されているキーのセット
        private val keysPressed = mutableSetOf<Int>()
    
        init {
            img = Toolkit.getDefaultToolkit().getImage(javaClass.classLoader.getResource("resources/Textures/Beef.png"))
            val initialBackground = Toolkit.getDefaultToolkit().getImage(javaClass.classLoader.getResource("resources/Textures/OverWorld/maptile_grasslands_one.png"))
            backgroundMap[0 to 0] = initialBackground
    
            isFocusable = true
            addKeyListener(this)
    
            // 初期位置を画面の中心に設定
            SwingUtilities.invokeLater {
                playerX = (width - (img?.getWidth(this) ?: 0)) / 2
                playerY = (height - (img?.getHeight(this) ?: 0)) / 2
            }
        }
    
        override fun paintComponent(g: Graphics) {
            super.paintComponent(g)
    
            // 白い背景を描画する
            g.color = Color.WHITE
            g.fillRect(0, 0, width, height)
    
            // 背景を描画する
            val tileWidth = width
            val tileHeight = height
    
            // 描画範囲のタイルの起点を計算する
            val startX = (viewX / tileWidth) * tileWidth
            val startY = (viewY / tileHeight) * tileHeight
    
            // 描画範囲をカバーするタイルの計算
            val endX = startX + width
            val endY = startY + height
    
            var currentX = startX
            while (currentX < endX) {
                var currentY = startY
                while (currentY < endY) {
                    val tileX = currentX / tileWidth
                    val tileY = currentY / tileHeight
    
                    // 背景タイルが読み込まれていない場合は追加
                    if (backgroundMap[tileX to tileY] == null) {
                        val newBackground = Toolkit.getDefaultToolkit().getImage(javaClass.classLoader.getResource("resources/Textures/OverWorld/maptile_grasslands_one.png"))
                        backgroundMap[tileX to tileY] = newBackground
                    }
    
                    // 背景タイルを描画
                    val image = backgroundMap[tileX to tileY]
                    g.drawImage(image, currentX - viewX, currentY - viewY, tileWidth, tileHeight, this)
    
                    currentY += tileHeight
                }
                currentX += tileWidth
            }
    
            // プレイヤーを描画する
            img?.let {
                g.drawImage(it, playerX, playerY, this)
            }
        }
    
        private fun movePlayer(dx: Int, dy: Int) {
            playerX += dx
            playerY += dy
    
            // プレイヤーの位置を画面中心に固定
            if (playerX < width / 2 - scrollSpeed) {
                viewX -= scrollSpeed
                playerX = width / 2 - scrollSpeed
            } else if (playerX > width / 2 + scrollSpeed) {
                viewX += scrollSpeed
                playerX = width / 2 + scrollSpeed
            }
    
            if (playerY < height / 2 - scrollSpeed) {
                viewY -= scrollSpeed
                playerY = height / 2 - scrollSpeed
            } else if (playerY > height / 2 + scrollSpeed) {
                viewY += scrollSpeed
                playerY = height / 2 + scrollSpeed
            }
    
            // 新しい背景の生成
            val gridX = viewX / width
            val gridY = viewY / height
    
            if (backgroundMap[gridX to gridY] == null) {
                val newBackground = Toolkit.getDefaultToolkit().getImage(javaClass.classLoader.getResource("resources/Textures/OverWorld/maptile_grasslands_one.png"))
                backgroundMap[gridX to gridY] = newBackground
            }
    
            repaint()
        }
    
        override fun keyTyped(e: KeyEvent) {}
    
        override fun keyPressed(e: KeyEvent) {
            keysPressed.add(e.keyCode)
            updatePlayerMovement()
        }
    
        override fun keyReleased(e: KeyEvent) {
            keysPressed.remove(e.keyCode)
            updatePlayerMovement()
        }
    
        private fun updatePlayerMovement() {
            var dx = 0
            var dy = 0
    
            if (KeyEvent.VK_W in keysPressed) dy -= scrollSpeed
            if (KeyEvent.VK_S in keysPressed) dy += scrollSpeed
            if (KeyEvent.VK_A in keysPressed) dx -= scrollSpeed
            if (KeyEvent.VK_D in keysPressed) dx += scrollSpeed
    
            movePlayer(dx, dy)
        }
    }
// 

}
