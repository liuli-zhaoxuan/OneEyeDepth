#include "test.h"
#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QDir>

test::test(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::test)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

test::~test()
{
    delete ui;
}

void test::on_selectPathButton_clicked()
{
    selectedPath = QFileDialog::getExistingDirectory(this, tr("选择图片目录"), "");
    if (selectedPath.isEmpty()) {
        QMessageBox::warning(this, "提示", "未选择任何目录");
    } else {
        ui->label_path->setText(selectedPath);
        ui->label_filename->setText("文件: （未选择）");
    }
}

void test::on_openImageButton_clicked()
{
    if (selectedPath.isEmpty()) {
        QMessageBox::warning(this, "错误", "请先选择图片路径");
        return;
    }

    QString fileName = QFileDialog::getOpenFileName(this, tr("打开图像"), selectedPath, tr("Image Files (*.png *.jpg *.bmp *.tif *.jpeg)"));
    if (!fileName.isEmpty()) {
        QPixmap pixmap(fileName);
        if (!pixmap.isNull()) {
            scene->clear();
            scene->addPixmap(pixmap);
            ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
            ui->label_filename->setText(QFileInfo(fileName).fileName());
        } else {
            QMessageBox::critical(this, "错误", "加载图像失败");
        }
    }
}

void test::on_loadIntrinsicsButton_clicked()
{
    //opencv需要重新编译
}

void test::on_undistortButton_clicked()
{
    
}