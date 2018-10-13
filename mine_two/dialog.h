#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QDateTime>
#include <QSignalMapper>
#include <QSignalBlocker>
#include <QVector>
#include <vector>
#include <QMessageBox>
#include <QMap>

#include <ctime>
#include <cstdlib>


#include <QTimer>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    const static int BlockNum = 10;
    const static int MinesNum = 5;

    ~Dialog();

private:
    QVector<int> N_RandomNum(int n, int m);
    QMap<int, int> GetMinesAroundInfo(QVector<int> );
    void AssignMine();
    void Rank();


    Ui::Dialog *ui;


    //left
//    QLabel *PauseLabel;
//    QLabel *OtherPauseLabel;
    QPushButton *BlockButton[BlockNum*BlockNum+1];
    QGridLayout *LeftLayout;

    //right
    QLabel *FlagLabel;
    QLabel *FlagLabelNum;

    QTimer * timer;      //定时器 每秒更新时间
    QTime * TimeRecord;  //记录时间
    bool isStart;        //记录是否已经开始计时


    QLabel *TimeLabel;
    QLabel *TimeLabelNum;

    QPushButton *SetDifficultyButton;
    QPushButton *PauseButton;



    QVBoxLayout *RightLayout;

    //botton
    QPushButton *CancelButton;
    QPushButton *ResetButton;
    QPushButton *QuitButton;
    QHBoxLayout *ButtonLayout;


//    connect( QuitButton, SIGNAL(clicked()), &this, SLOT(quit()) );


private slots:
//    void on_BlockButton_clicked(int index);
//    void Demining(int);
    void ClearMine(int );

};

#endif // DIALOG_H
