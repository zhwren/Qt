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
*    >  File Name   : extensiondlg.cc
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-15 14:42                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#include "extensiondlg.hh"

#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTextEdit>

ExtensionDlg::ExtensionDlg(QWidget* parent)
  :QDialog(parent)
{
  createBasic();
  createDetail();
  QVBoxLayout* mainLayout = new QVBoxLayout(this);
  mainLayout->addWidget(basicWidget);
  mainLayout->addWidget(detailWidget);
  mainLayout->setSizeConstraint(QLayout::SetFixedSize);
}

ExtensionDlg::~ExtensionDlg()
{}

void ExtensionDlg::createBasic()
{
  basicWidget = new QWidget();
  QLabel* nameLabel = new QLabel("姓名：");
  QLabel* sexLabel  = new QLabel("性别：");
  QLineEdit* nameEdit = new QLineEdit();
  QComboBox* sexComboBox = new QComboBox();
  sexComboBox->insertItem(0, "女");
  sexComboBox->insertItem(1, "男");
  QPushButton* okbtn = new QPushButton("确定");
  QPushButton* moreb = new QPushButton("详细");

  connect(moreb, SIGNAL(clicked()), this, SLOT(showMoreDialog()));

  QGridLayout* mainLayout = new QGridLayout(basicWidget);
  mainLayout->addWidget(nameLabel, 0, 0);
  mainLayout->addWidget(nameEdit, 0, 1);
  mainLayout->addWidget(okbtn, 0, 2);
  mainLayout->addWidget(sexLabel, 1, 0);
  mainLayout->addWidget(sexComboBox, 1, 1);
  mainLayout->addWidget(moreb, 1, 2);
}

void ExtensionDlg::createDetail()
{
  detailWidget = new QWidget();
  QTextEdit* text = new QTextEdit();
  QVBoxLayout* mainLayout = new QVBoxLayout(detailWidget);
  mainLayout->addWidget(text);
  detailWidget->hide();
}

void ExtensionDlg::showMoreDialog()
{
  if( detailWidget->isHidden() ) detailWidget->show();
  else detailWidget->hide();
}
