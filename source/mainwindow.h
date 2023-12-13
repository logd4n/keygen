/*  # # #   # # #  # # #  # # # #       # # # #     #       #        # # #   # # # #
  #     # #     # #    # #             #    # #   #        #       # * * #  #
 #       #     # #    # # # # #       # # #   # #         #       #  *  #  #  # # #
#     # #     # #    # #             #    #   #          #       # * * #  #      #
# # #   # # #  # # #  # # # #       # # #    #          # # # #  # # #    # # # # */

//MainWindow.h ver 1.0.0

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QRandomGenerator>

#include <QtMultimedia>
#include <QMediaPlayer>
#include <QSoundEffect>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void generateLowLetters(char key[]);
    void generateHighLetters(char key[]);
    void generateNumbers(char letters[]);
    void deleteSymbol(char array[], int position, int arrayLenght);
    void deleteSymbol(int numbers[], int &size, int position);
    void printKey(char key[], int numbers[]);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    //QMediaPlayer *m_player;
};
#endif // MAINWINDOW_H
