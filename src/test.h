#pragma once
#include <QMainWindow>
#include "ui_test.h"
#include <QGraphicsScene>
#include <QString>

class test : public QMainWindow {
    Q_OBJECT

public:
    explicit test(QWidget* parent = nullptr);
    ~test();

private slots:
    void on_selectPathButton_clicked();
    void on_openImageButton_clicked();
    void on_loadIntrinsicsButton_clicked();
    void on_undistortButton_clicked();

private:
    Ui::test *ui;
    QGraphicsScene *scene;
    QString selectedPath;
    //cv::Mat cameraMatrix, distCoeffs;
};