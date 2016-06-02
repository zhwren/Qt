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
#include "MessageDialog.hh"
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QFileDialog>
#include <QColorDialog>
#include <QFrame>
#include <QFontDialog>
#include <QInputDialog>

StandardDialog::StandardDialog(QWidget* parent)
  :QDialog(parent)
{
  fileButton = new QPushButton("标准文件对话框");
  fileLineEdit = new QLineEdit();
  colorButton = new QPushButton("颜色对话框");
  colorFrame = new QFrame();
  colorFrame->setFrameShape(QFrame::Box);
  colorFrame->setAutoFillBackground(true);
  fontButton = new QPushButton("字体选择");
  fontLineEdit = new QLineEdit();
  fontLineEdit->setText("欢迎来到Qt世界！");
  fontLineEdit->setReadOnly(true);
  inputButton = new QPushButton("标准输入");
  messageButton = new QPushButton("消息对话框");

  QGridLayout* mainLayout = new QGridLayout(this);
  mainLayout->addWidget(fileButton, 0, 0);
  mainLayout->addWidget(fileLineEdit, 0, 1);
  mainLayout->addWidget(colorButton, 1, 0);
  mainLayout->addWidget(colorFrame, 1, 1);
  mainLayout->addWidget(fontButton, 2, 0);
  mainLayout->addWidget(fontLineEdit, 2, 1);
  mainLayout->addWidget(inputButton, 3, 0);
  mainLayout->addWidget(messageButton, 3, 1);

  connect(fileButton, SIGNAL(clicked()), this, SLOT(showFileName()));
  connect(colorButton, SIGNAL(clicked()), this, SLOT(showColor()));
  connect(fontButton, SIGNAL(clicked()), this, SLOT(showFont()));
  connect(inputButton, SIGNAL(clicked()), this, SLOT(showInput()));
  connect(messageButton, SIGNAL(clicked()), this, SLOT(showMessage()));
}

StandardDialog::~StandardDialog()
{}

void StandardDialog::showFileName()
{
  QString ss = QFileDialog::getOpenFileName(this, "打开", "/home/zhwren/Desktop/");
  fileLineEdit->setText( ss );
}

void StandardDialog::showColor()
{
  QColor color = QColorDialog::getColor(Qt::blue, this);
  if(color.isValid() )
    colorFrame->setPalette(QPalette(color));
}

void StandardDialog::showFont()
{
  bool ok;
  QFont font = QFontDialog::getFont(&ok, this);
  if( ok ) fontLineEdit->setFont( font );
}

void StandardDialog::showInput()
{
  QString text = QInputDialog::getText(this, "input dialog", "输入你想要的文字");
  if( !text.isEmpty() ) fontLineEdit->setText( text );
}

void StandardDialog::showMessage()
{
  messageDialog = new MessageDialog(this);
  messageDialog->show();
}
