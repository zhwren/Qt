/***********************************************************
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
*      .............................................       *
*             Buddha bless me, No bug forever              *
************************************************************
*    >  CopyRight   :                                      *
*    >  File Name   : BasicInfo.cc
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-05-19 16:57                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#include "BasicInfo.hh"
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QComboBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

BasicInfo::BasicInfo(QWidget* parent)
  :QDialog( parent )
{
  userNameLabel = new QLabel(tr("用户名："));
  nameLabel = new QLabel(tr("姓名："));
  sexLabel = new QLabel(tr("性别："));
  departLabel = new QLabel(tr("部门："));
  ageLabel = new QLabel(tr("年龄："));
  otherLabel = new QLabel(tr("备注："));
  userNameEdit = new QLineEdit();
  nameEdit = new QLineEdit();
  sexComboBox = new QComboBox();
  sexComboBox->addItem(tr("男"), 0);
  sexComboBox->addItem(tr("女"), 1);
  departEdit = new QTextEdit();
  ageEdit = new QLineEdit();
  otherEdit = new QLineEdit();

  QGridLayout* leftLayout = new QGridLayout();
  leftLayout->addWidget(userNameLabel, 0, 0);
  leftLayout->addWidget(userNameEdit, 0, 1);
  leftLayout->addWidget(nameLabel, 1, 0);
  leftLayout->addWidget(nameEdit, 1, 1);
  leftLayout->addWidget(sexLabel, 2, 0);
  leftLayout->addWidget(sexComboBox, 2, 1);
  leftLayout->addWidget(departLabel, 3, 0);
  leftLayout->addWidget(departEdit, 3, 1);
  leftLayout->addWidget(ageLabel, 4, 0);
  leftLayout->addWidget(ageEdit, 4, 1);
  leftLayout->addWidget(otherLabel, 5, 0);
  leftLayout->addWidget(otherEdit, 5, 1);

  imgLabel = new QLabel(tr("头像："));
  photoLabel = new QLabel;
  QPixmap icon("123.png");
  photoLabel->setPixmap(icon);
  photoLabel->resize(icon.width(), icon.height());
  personalLabel = new QLabel(tr("个人说明："));
  okButton = new QPushButton(tr("确定"));
  cancelButton = new QPushButton(tr("取消"));
  updateButton = new QPushButton(tr("更新"));
  personalEdit = new QTextEdit();
  QHBoxLayout* toprightLayour = new QHBoxLayout();
  toprightLayour->addWidget(imgLabel);
  toprightLayour->addWidget(photoLabel);
  toprightLayour->addWidget(updateButton);
  QVBoxLayout* rightLayout = new QVBoxLayout();
  rightLayout->addLayout(toprightLayour);
  rightLayout->addWidget(personalLabel);
  rightLayout->addWidget(personalEdit);

  QHBoxLayout* bottomLayout = new QHBoxLayout();
  bottomLayout->addWidget(cancelButton);
  bottomLayout->addWidget(okButton);

  QGridLayout* mainLayout = new QGridLayout(this);
  mainLayout->addLayout(leftLayout, 0, 0);
  mainLayout->addLayout(rightLayout, 0, 1);
  mainLayout->addLayout(bottomLayout, 1, 0, 1, 2);
}

BasicInfo::~BasicInfo()
{
  delete userNameLabel;
  delete userNameEdit;
  delete sexLabel;
  delete sexComboBox;
  delete departLabel;
  delete departEdit;
  delete ageEdit;
  delete ageLabel;
  delete otherEdit;
  delete otherLabel;
  delete imgLabel;
  delete photoLabel;
  delete personalEdit;
  delete personalLabel;
  delete okButton;
  delete cancelButton;
  delete updateButton;
  delete nameEdit;
  delete nameLabel;
}
