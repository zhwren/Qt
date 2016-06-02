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
*    >  File Name   : MessageDialog.cc
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-02 22:31                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#include "MessageDialog.hh"
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>

MessageDialog::MessageDialog(QWidget* parent)
  :QDialog( parent )
{
  questionButton = new QPushButton("问题对话框");
  messageButton = new QPushButton("信息消息框");
  warningButton = new QPushButton("警告消息框");
  aboutButton = new QPushButton("关于消息框");
  aboutQtButton = new QPushButton("关于Qt");
  criticalButton = new QPushButton("Crtical消息框");

  QGridLayout* mainLayout = new QGridLayout(this);
  mainLayout->addWidget(questionButton, 0, 0);
  mainLayout->addWidget(messageButton, 0, 1);
  mainLayout->addWidget(warningButton, 1, 0);
  mainLayout->addWidget(aboutButton, 1, 1);
  mainLayout->addWidget(aboutQtButton, 2, 0);
  mainLayout->addWidget(criticalButton, 2, 1);

  connect(questionButton, SIGNAL(clicked()), this, SLOT(showQuestion()));
  connect(messageButton, SIGNAL(clicked()), this, SLOT(showMessage()));
  connect(warningButton, SIGNAL(clicked()), this, SLOT(showWarning()));
  connect(aboutButton, SIGNAL(clicked()), this, SLOT(showAbout()));
  connect(aboutQtButton, SIGNAL(clicked()), this, SLOT(showAboutQt()));
  connect(criticalButton, SIGNAL(clicked()), this, SLOT(showCritical()));
}

MessageDialog::~MessageDialog()
{}

void MessageDialog::showQuestion()
{
  QMessageBox::question(this, "问题对话", "真的要结束吗？");
}

void MessageDialog::showMessage()
{
  QMessageBox::information(this, "提示", "你是猪");
}

void MessageDialog::showWarning()
{
  QMessageBox::warning(this, "严重警告", "你已违反中华人民共和国宪法");
}

void MessageDialog::showAbout()
{
  QMessageBox::about(this, "提醒一下", "壹贰叁肆伍陆柒捌玖拾佰仟萬亿");
}

void MessageDialog::showAboutQt()
{
  QMessageBox::aboutQt(this);
}

void MessageDialog::showCritical()
{
  QMessageBox::critical(this, "错误", "内存分配错误");
}
