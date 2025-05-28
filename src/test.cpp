#include "test.h"

test::test(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::test)
{
    ui->setupUi(this);
}

test::~test()
{
    delete ui;
}