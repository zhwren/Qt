/***********************************************************
*                                                          *
*                                                          *
*                         _ooOoo_                          *
*                        o8888888o                         *
*                        88" . "88                         *
*                        (| -_- |)                         *
*                         O\ = /O                          *
*                     ____/`---'\____                      *
*                   .   ' \\| |// `.                       *
*                    / \\||| : |||// \                     *
*                  / _||||| -:- |||||- \                   *
*                    | | \\\ - /// | |                     *
*                  | \_| ''\---/'' | |                     *
*                   \ .-\__ `-` ___/-. /                   *
*                ___`. .' /--.--\ `. . __                  *
*             ."" '< `.____<|>_/___.' >'"".                *
*            | | : `- \`.;` _ /`;.`/ - ` : | |             *
*              \ \ `-. \_ __\ /__ _/ .-` / /               *
*      ======`-.____`-.___\_____/___.-`____.-'======       *
*                         `=---='                          *
*                                                          *
*                                                          *
*      .............................................       *
*             Buddha bless me, No bug forever              *
************************************************************
*    >  CopyRight   :                                      *
*    >  File Name   : StandardDialog.cc
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-02 17:11                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#include "StandardDialog.hh"
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QFileDialog>
#include <QColorDialog>
#include <QFrame>

StandardDialog::StandardDialog(QWidget* parent)
  :QDialog(parent)
{
  fileButton = new QPushButton("标准文件对话框");
  fileLineEdit = new QLineEdit();
  colorButton = new QPushButton("颜色对话框");
  colorFrame = new QFrame();
  colorFrame->setFrameShape(QFrame::Box);
  colorFrame->setAutoFillBackground(true);

  QGridLayout* mainLayout = new QGridLayout(this);
  mainLayout->addWidget(fileButton, 0, 0);
  mainLayout->addWidget(fileLineEdit, 0, 1);
  mainLayout->addWidget(colorButton, 1, 0);
  mainLayout->addWidget(colorFrame, 1, 1);

  connect(fileButton, SIGNAL(clicked()), this, SLOT(showFileName()));
  connect(colorButton, SIGNAL(clicked()), this, SLOT(showColor()));
}

StandardDialog::~StandardDialog()
{}

void StandardDialog::showFileName()
{
  QString ss = QFileDialog::getOpenFileName(this, "open file", "/home/zhwren/Desktop/");
  fileLineEdit->setText( ss );
}

void StandardDialog::showColor()
{
  QColor color = QColorDialog::getColor(Qt::blue, this);
  if(color.isValid() ) colorFrame->setPalette(QPalette(color));
}
