#include "widget.h"
#include "ui_widget.h"

#include<QFile>
#include<QDebug>
#include <QTextStream>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QFileDialog>  // 用來跳出「另存新檔 / 開啟舊檔」視窗
#include <QMessageBox>  // 用來跳出提示訊息（選用）

QString mFilename = "C:/test/myfile.txt"; // 存檔路徑（請確保 C 槽有 test 資料夾）

void Write(QString Filename, QString str)
{
    QFile mFile(Filename); // 宣告 QFile 物件
    // 寫入檔案判斷
    if (!mFile.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << "could not open file for write";
        return;
    }

    QTextStream out(&mFile);
    out << str;    // 將內容輸出至 txt 檔
    mFile.flush(); // 刷新 mFile 緩衝區
    mFile.close(); // 關閉 mFile
}

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);//呼叫命名空間Ui內的My Widget物件之成員函數setupUi(自己的記憶體位址)

    QStringList ColTotle;

    ui->tableWidget->setColumnCount(4);

    ColTotle << QStringLiteral("學號")
             << QStringLiteral("班級")
             << QStringLiteral("姓名")
             << QStringLiteral("電話");

    ui->tableWidget->setHorizontalHeaderLabels(ColTotle);

    //美化
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//4欄位平均分配
    ui->tableWidget->setAlternatingRowColors(true);//交錯底色
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//點取選取整列
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}



Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QTableWidgetItem *inputRow1, *inputRow2, *inputRow3, *inputRow4;

    inputRow1 = new QTableWidgetItem(QString(ui->lineEdit->text()));
    inputRow2 = new QTableWidgetItem(QString(ui->lineEdit_3->text()));
    inputRow3 = new QTableWidgetItem(QString(ui->lineEdit_2->text()));
    inputRow4 = new QTableWidgetItem(QString(ui->lineEdit_4->text()));

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());

    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, inputRow1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, inputRow2);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, inputRow3);
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, inputRow4);

    // 新增完畢後，清除 4 個 lineEdit 輸入框的內容
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
}

// ===== 4. 「匯出」按鈕功能 =====
void Widget::on_pushButton_2_clicked()
{
    QString saveFile = ""; // 用來累積要存檔的所有文字內容

    // 外層迴圈 i：跑過每一列 (row)
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        // 內層迴圈 j：跑過該列的每一欄 (column)
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
            saveFile += ui->tableWidget->item(i, j)->text() + ",";
        }
        saveFile += "\n"; // 每一列結束後加上換行符號
    }

    Write(mFilename, saveFile); // 呼叫上方自定義的 Write 函式寫入檔案
}
void Widget::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    QStringLiteral("匯出聯絡人"),
                                                    "contacts.csv",
                                                    "CSV Files (*.csv);;Text Files (*.txt)");

    if (fileName.isEmpty()) return;

    QFile file(fileName);
    // 以「唯讀、文字模式」打開檔案
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
}
    ui->tableWidget->setRowCount(0);

    QTextStream in(&file);
    // 一行一行讀取檔案，直到檔案結束
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue; // 跳過空白行

        // 用逗號「,」把這一行拆成 4 個字串（學號、班級、姓名、電話）
        QStringList fields = line.split(",");

        // 在表格最下方新增一列
        int newRow = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(newRow);

        // 把拆出來的每個欄位塞回表格裡
        for (int col = 0; col < fields.size() && col < 4; col++) {
            ui->tableWidget->setItem(newRow, col, new QTableWidgetItem(fields[col]));
        }
    }

    file.close();
}
