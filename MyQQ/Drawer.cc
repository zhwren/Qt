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
*    >  File Name   : Drawer.cc
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-03 09:48                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#include "Drawer.hh"
#include "MessageDialog.hh"
#include <QToolButton>
#include <QGroupBox>
#include <QVBoxLayout>

Drawer::Drawer(QWidget *parent, Qt::WindowFlags f)
  :QToolBox(parent, f)
{
  setWindowTitle("我的QQ");
  toolBtn1_1 = new QToolButton();
  toolBtn1_1->setText("张三");
  toolBtn1_1->setIcon(QPixmap("zhangsan.jpg"));
  toolBtn1_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  connect(toolBtn1_1, SIGNAL(clicked()), this, SLOT(showMessage()));

  toolBtn1_2 = new QToolButton();
  toolBtn1_2->setText("李四");
  toolBtn1_2->setIcon(QPixmap("lisi.jpg"));
  toolBtn1_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

  toolBtn1_3 = new QToolButton();
  toolBtn1_3->setText("王五");
  toolBtn1_3->setIcon(QPixmap("wangwu.jpg"));
  toolBtn1_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

  toolBtn1_4 = new QToolButton();
  toolBtn1_4->setText("赵六");
  toolBtn1_4->setIcon(QPixmap("zhaoliu.jpg"));
  toolBtn1_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

  QGroupBox* groupBox1 = new QGroupBox();
  QVBoxLayout* layout1 = new QVBoxLayout(groupBox1);
  layout1->setMargin(10);
  layout1->addWidget(toolBtn1_1);
  layout1->addWidget(toolBtn1_2);
  layout1->addWidget(toolBtn1_3);
  layout1->addWidget(toolBtn1_4);
  layout1->addStretch();

  toolBtn2_1 = new QToolButton();
  toolBtn2_1->setText("小明");
  toolBtn2_1->setIcon(QPixmap("xiaoming.jpg"));
  toolBtn2_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

  toolBtn2_2 = new QToolButton();
  toolBtn2_2->setText("小敏");
  toolBtn2_2->setIcon(QPixmap("xiaomin.jpg"));
  toolBtn2_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

  toolBtn2_3 = new QToolButton();
  toolBtn2_3->setText("小黄");
  toolBtn2_3->setIcon(QPixmap("xiaohuang.jpg"));
  toolBtn2_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

  toolBtn2_4 = new QToolButton();
  toolBtn2_4->setText("小红");
  toolBtn2_4->setIcon(QPixmap("xiaohong.jpg"));
  toolBtn2_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

  QGroupBox* groupBox2 = new QGroupBox();
  QVBoxLayout* layout2 = new QVBoxLayout(groupBox2);
  layout2->setMargin(10);
  layout2->addWidget(toolBtn2_1);
  layout2->addWidget(toolBtn2_2);
  layout2->addWidget(toolBtn2_3);
  layout2->addWidget(toolBtn2_4);

  this->addItem((QWidget*)groupBox1, tr("我的好友"));
  this->addItem((QWidget*)groupBox2, tr("高中同学"));
}
Drawer::~Drawer()
{}

void Drawer::showMessage()
{
  message = new MessageDialog(this);
  message->show();
}
