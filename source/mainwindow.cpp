/*  # # #   # # #  # # #  # # # #       # # # #     #       #        # # #   # # # #
  #     # #     # #    # #             #    # #   #        #       # * * #  #
 #       #     # #    # # # # #       # # #   # #         #       #  *  #  #  # # #
#     # #     # #    # #             #    #   #          #       # * * #  #      #
# # #   # # #  # # #  # # # #       # # #    #          # # # #  # # #    # # # # */

//MainWindow.cpp

#include "mainwindow.h"
#include "./ui_mainwindow.h"

#define NUMBER_CONST 48 //Константа для перевода из INT в CHAR

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("keygen by LOG");
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

    //QDesktopServices::openUrl(QUrl("https://vk.com/logd4n")); //OPEN VK

    /*
    //QMediaPlayer *m_player = new QMediaPlayer;
    QSoundEffect *soundfx = new QSoundEffect;

    QUrl url("qrc:/music/music/test.mp3");
    QUrl newurl("C:/Users/LOG/Desktop/keygen/keygen_song.mp3");

    soundfx->setSource(url);

    soundfx->setVolume(1);

    soundfx->play();

    qDebug() << "Playing?: " << soundfx->isPlaying();
    //m_player->setSource(newurl);

    //m_player->play();
    //m_player->stop();

    //qDebug() << "Source: " << m_player->source();
    //qDebug() << "\nPlaying?: " << m_player->isPlaying();
    */
}

MainWindow::~MainWindow()
{
    delete ui;

    //m_player->stop();
    //delete m_player;
}

void MainWindow::printKey(char key[], int numbers[])
{
    int numberPlace = 0;

    char result[13];

    result[0] = key[0]; //Позиция 1

    numberPlace = QRandomGenerator::global()->bounded(1, 3);

    if (numberPlace == 1) //Позиции 2 и 3
    {
        result[1] = numbers[0] + NUMBER_CONST;
        result[2] = key[2];
    }
    else
    {
        result[1] = key[1];
        result[2] = numbers[0] + NUMBER_CONST;
    }

    for (std::size_t i = 3; i < 7; i++) //Позиции 4-7
    {
        result[i] = key[i];
    }

    numberPlace = QRandomGenerator::global()->bounded(7, 9);

    if (numberPlace == 7) //Позиции 8 и 9
    {
        result[7] = numbers[1] + NUMBER_CONST;
        result[8] = key[7]; //Ошибка в основном алгоритме (нужно исправить)
    }
    else
    {
        result[7] = key[6];
        result[8] = numbers[1] + NUMBER_CONST;
    }

    result[9] = numbers[2] + NUMBER_CONST; //Позиция 10
    result[10] = key[8]; //Позиция 11
    result[11] = numbers[3] + NUMBER_CONST; //Позиция 12

    result[12] = '\0';

    //ui->label->setText(result); //FOR TESTING

    ui->lineEdit->setText(result);
}

void MainWindow::generateLowLetters(char key[])
{
    char lowLetters[27] = {"qwertyuiopasdfghjklzxcvbnm"};

    for (std::size_t i = 0; i < 12; i++)
    {
        key[i] = lowLetters[QRandomGenerator::global()->bounded(0, 26)];
    }

    key[12] = '\0';
}

void MainWindow::deleteSymbol(char array[], int position, int arrayLenght)
{
    position--;

    for (std::size_t i = position; i < arrayLenght - 1; i++)
    {
        array[i] = array[i + 1];
    }
}

void MainWindow::deleteSymbol(int numbers[], int &size, int position)
{
    for (std::size_t i = position; i < size - 1; i++)
    {
        numbers[i] = numbers[i + 1];
    }

    size--;

    numbers[size] = '\0';
}

void MainWindow::generateHighLetters(char key[])
{
    int randomLetterPosition = 0, size = 26;

    char highLetters[27] = {"QWERTYUIOPASDFGHJKLZXCVBNM"};

    randomLetterPosition = QRandomGenerator::global()->bounded(0, size);

    key[0] = highLetters[randomLetterPosition]; //Позиция 1

    deleteSymbol(highLetters, randomLetterPosition, size);
    size--;

    if (std::isalpha(key[1])) //Позиция 2 или 3
    {
        randomLetterPosition = QRandomGenerator::global()->bounded(0, size);
        key[1] = highLetters[randomLetterPosition];
    }
    else
    {
        randomLetterPosition = QRandomGenerator::global()->bounded(0, size);
        key[2] = highLetters[randomLetterPosition];
    }

    deleteSymbol(highLetters, randomLetterPosition, size);
    size--;

    key[5] = highLetters[randomLetterPosition]; //Позиция 6

    deleteSymbol(highLetters, randomLetterPosition, size);

    if (std::isalpha(key[7])) //Позиция 8 или 9
    {
        randomLetterPosition = QRandomGenerator::global()->bounded(0, size);
        key[7] = highLetters[randomLetterPosition];
    }
    else
    {
        randomLetterPosition = QRandomGenerator::global()->bounded(0, size);
        key[8] = highLetters[randomLetterPosition];
    }

    deleteSymbol(highLetters, randomLetterPosition, size);

    randomLetterPosition = QRandomGenerator::global()->bounded(0, size);
    key[10] = highLetters[randomLetterPosition]; //Позиция 11

    deleteSymbol(highLetters, randomLetterPosition, size);
}

void MainWindow::generateNumbers(char letters[])
{
    int sum = 0, numberSize = 9, result[5],
        numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    char key[13];

    for (std::size_t i = 0; i < 13; i++)
    {
        key[i] = letters[i];
    }

    result[0] = 7;

    deleteSymbol(numbers, numberSize, 6);

    //char test1[3]; test1[2] = '\0';

    for (std::size_t i = 1; i < 3; i++)
    {
        int randomNumberPosition = QRandomGenerator::global()->bounded(1, numberSize);

        result[i] = numbers[randomNumberPosition];

        //test1[i - 1] = randomNumberPosition + NUMBER_CONST; //FOR TESTING

        deleteSymbol(numbers, numberSize, randomNumberPosition);
    }

    //ui->label_2->setText(test1); //FOR TESTING

    for (std::size_t i = 0; i < 3; i++)
    {
        sum += result[i];
    }

    result[3] = std::abs(17 - sum);

    result[4] = '\0';

    //FOR TESTING
    /*
    char test[5]; test[4] = '\0';

    for (std::size_t i = 0; i < 4; i++)
    {
        test[i] = result[i] + NUMBER_CONST;
    }

    ui->label_3->setText(test);
    */

    printKey(key, result);
}

void MainWindow::on_pushButton_clicked()
{
    //m_player->play();
    //qDebug() << "\nPlaying?: " << m_player->isPlaying();

    char key[13];

    generateLowLetters(key);

    generateHighLetters(key);

    //ui->label_2->setText(key); //FOR TESTING

    generateNumbers(key);

    //ui->label->setText(key);

    ui->statusbar->showMessage("Key size: " + QString::number(sizeof(key)));
}


void MainWindow::on_pushButton_2_clicked()
{
    QGuiApplication::clipboard()->setText(ui->lineEdit->text());

    ui->statusbar->showMessage("Copy is OK!");
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox aboutProgram (QMessageBox::Information, "About keygen...", "Version 1.0.1\n<Code by LOG>", QMessageBox::NoButton);
    aboutProgram.exec();
}
