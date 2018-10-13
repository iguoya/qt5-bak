#include "dialog.h"
#include "ui_dialog.h"

//const static double PI = 3.1415926;

//static int Mines[BlockNum][BlockNum];
static QVector<int> MinesIndexs;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("mines"));

    LeftLayout = new QGridLayout();
    LeftLayout->setSpacing(0);

    for(int i = 0; i< BlockNum; ++i) {
        for(int j = 1; j<= BlockNum; ++j) {
            int index = i*BlockNum+j;
            BlockButton[index] = new QPushButton(tr(""));
            BlockButton[index]->setMinimumWidth(80);
            BlockButton[index]->setMinimumHeight(80);

            LeftLayout->addWidget(BlockButton[index], i, j);
        }
        LeftLayout->setColumnStretch(i, 0);
    }


    FlagLabel = new QLabel(tr("flag num"));
    FlagLabelNum = new QLabel(tr("flag"));

    TimeLabel = new QLabel(tr("cost time"));
    TimeLabelNum = new QLabel(tr(""));

    PauseButton = new QPushButton(tr("pause"));
    SetDifficultyButton = new QPushButton(tr("set difficulty"));

    RightLayout = new QVBoxLayout();

    RightLayout->addWidget(FlagLabel);

    RightLayout->addWidget(TimeLabel);

    RightLayout->addWidget(FlagLabel);
    RightLayout->addWidget(TimeLabelNum);

    RightLayout->addWidget(PauseButton);

    RightLayout->addWidget(SetDifficultyButton);

    CancelButton = new QPushButton(tr("cancel"));
    ResetButton = new QPushButton(tr("reset"));
    QuitButton = new QPushButton(tr("quit"));
    connect( QuitButton, SIGNAL(clicked()), this, SLOT(close()) );
    ButtonLayout = new QHBoxLayout();
    ButtonLayout->addStretch();
    ButtonLayout->addWidget(CancelButton);

    ButtonLayout->addWidget(ResetButton);

    ButtonLayout->addWidget(QuitButton);



    QGridLayout *mainLayout = new QGridLayout(this);
//    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);

    mainLayout->addLayout(LeftLayout, 0, 0);
    mainLayout->addLayout(RightLayout, 0, 1);
    mainLayout->addLayout(ButtonLayout, 1, 0, 1, 2);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    //    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    //    QSignalMapper *signalMapper = new QSignalMapper(this);

    for(int index = 1; index <= BlockNum*BlockNum; ++index) {
        connect(BlockButton[index], &QPushButton::clicked, this, [=](){ClearMine(index);});
    }
    AssignMine();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::AssignMine() {

    int RemainMinesNum = MinesNum;
    MinesIndexs = N_RandomNum(BlockNum*BlockNum, MinesNum);
    QString MinesInfo;
    MinesInfo.sprintf("地雷总数:%d,剩余:%d", MinesNum, RemainMinesNum);
    FlagLabelNum->setText(MinesInfo);
    for(auto it = MinesIndexs.begin(); it != MinesIndexs.end(); ++it) {
        BlockButton[*it]->setStyleSheet("background-color:  rgb(170, 0, 0);");
        BlockButton[*it]->setText("雷");
    }
    QMap<int, int> MinesAroundInfo = GetMinesAroundInfo(MinesIndexs);

    for(auto it = MinesAroundInfo.begin(); it != MinesAroundInfo.end(); ++it) {
        if(MinesIndexs.contains(it.key())) continue;
        if(it.value() == 1) {
            BlockButton[it.key()]->setStyleSheet("background-color: green;");
            BlockButton[it.key()]->setText(QString::number(it.value(), 10));
        } else {
            BlockButton[it.key()]->setStyleSheet("background-color: blue;");
            BlockButton[it.key()]->setText(QString::number(it.value(), 10));
        }
    }
}


void Dialog::ClearMine(int index) {
    QString info;
    info = info.sprintf("你成功啦", index);
    FlagLabel->setText(info);

    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(this, tr("成功"), info);

}

QMap<int, int> Dialog::GetMinesAroundInfo(QVector<int> MinesIndexs) {
    QMap<int, int> MinesAroundInfo;

    for(auto it = MinesIndexs.begin(); it != MinesIndexs.end(); ++it) {
        QList<int> MineAroundBlock;
        int index = *it;
//        int row = index / BlockNum;
//        int column = index % BlockNum;

        int blockAboveLeft = index - BlockNum - 1;
        if(blockAboveLeft > 0 && (blockAboveLeft % BlockNum != 0)) {
            MineAroundBlock.append(blockAboveLeft);
        }

        int blockAbove = index - BlockNum;
        if(blockAbove > 0) {
            MineAroundBlock.append(blockAbove);
        }

        int blockAboveRight = index - BlockNum + 1;
        if(blockAboveRight > 0 && (blockAboveRight % BlockNum != 1)) {
            MineAroundBlock.append(blockAboveRight);
        }


        int blockLeft = index - 1;
        if(blockLeft % BlockNum != 0) {
            MineAroundBlock.append(blockLeft);
        }
        int blockRight = index + 1;
        if(blockRight % BlockNum != 1) {
            MineAroundBlock.append(blockRight);
        }


        int blockBelowLeft = index + BlockNum - 1;
        if(blockBelowLeft < BlockNum*BlockNum &&  (blockAboveLeft % BlockNum != 0)) {
            MineAroundBlock.append(blockBelowLeft);
        }
        int blockBelow = index + BlockNum ;
        if(blockBelow <= BlockNum*BlockNum) {
            MineAroundBlock.append(blockBelow);
        }
        int blockBelowRight = index + BlockNum + 1;
        if((blockBelowRight % BlockNum != 1) && blockBelowRight <= BlockNum*BlockNum) {
            MineAroundBlock.append(blockBelowRight);
        }

        for(auto it=MineAroundBlock.begin(); it !=MineAroundBlock.end(); ++it) {

            auto i = MinesAroundInfo.find(*it);
            if(i != MinesAroundInfo.end()) {
                i.value() += 1;
                cout<<"重叠:"<<i.key()<<", current:"<<i.value()<<endl;
            } else {
                cout<<"周边:"<<*it<<endl;
                MinesAroundInfo.insert(*it, 1);
            }
        }
    }
    return MinesAroundInfo;
}

//void Dialog::on_BlockButton_clicked(int index) {
//    QString info;
//    FlagLabel->setText(info.sprintf("你点击了%d块", index));



//}

QVector<int> Dialog::N_RandomNum(int n, int m) {
    QVector<int> randNums;
    srand((unsigned)time(NULL));
    for(int i = 0; i < m;i++ ) {
        int mine = rand()%(n+1);
        if(mine == 0) {
            --i;
            continue;
        }

        randNums.append(mine);
        cout<<"地雷坐标:"<<mine<<endl;
    }
    return randNums;
}
