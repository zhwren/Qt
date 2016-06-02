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
*    >  File Name   : BasicInfo.cc
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-01 14:21                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#include "BasicInfo.hh"
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

BasicInfo::BasicInfo(QWidget* parent)
  :QDialog(parent)
{
  QGridLayout* mainLayout = new QGridLayout(this);
  QGridLayout* leftLayout = GetLeftLayout();
  QVBoxLayout* rightLayout = GetRightLayout();
  mainLayout->addLayout(leftLayout, 0, 0);
  mainLayout->addLayout(rightLayout, 0, 1);
}

BasicInfo::~BasicInfo()
{}

QGridLayout* BasicInfo::GetLeftLayout()
{
  userNameLabel = new QLabel("用户名:");
  userNameLineEdit = new QLineEdit();
  
  nameLabel = new QLabel("姓名:");
  nameEdit = new QLineEdit();
  
  sexLabel = new QLabel("性别:");
  sexComboBox = new QComboBox();
  sexComboBox->addItem("男");
  sexComboBox->addItem("女");
  
  ageLabel = new QLabel("年龄:");
  ageLineExit = new QLineEdit();

  otherLabel = new QLabel("备注:");
  otherLineEdit = new QLineEdit();

  branchLabel = new QLabel("部门:");
  branchTextEdit = new QTextEdit();
  QGridLayout* leftLayout = new QGridLayout();
  leftLayout->addWidget(userNameLabel, 0, 0);
  leftLayout->addWidget(userNameLineEdit, 0, 1);
  leftLayout->addWidget(nameLabel, 1, 0);
  leftLayout->addWidget(nameEdit, 1, 1);
  leftLayout->addWidget(sexLabel, 2, 0);
  leftLayout->addWidget(sexComboBox, 2, 1);
  leftLayout->addWidget(ageLabel, 3, 0);
  leftLayout->addWidget(ageLineExit, 3, 1);
  leftLayout->addWidget(branchLabel, 4, 0);
  leftLayout->addWidget(branchTextEdit, 4, 1);
  leftLayout->addWidget(otherLabel, 5, 0);
  leftLayout->addWidget(otherLineEdit, 5, 1);

  return leftLayout;
}

QHBoxLayout* BasicInfo::GetTopLayout()
{
  QLabel* imgLabel = new QLabel("头像:");
  QPushButton* updateButton = new QPushButton("更新");
  QHBoxLayout* topLayout = new QHBoxLayout();
  topLayout->addWidget(imgLabel);
  topLayout->addWidget(updateButton);
  
  return topLayout;
}

QVBoxLayout* BasicInfo::GetRightLayout()
{
  QLabel* infoLabel = new QLabel("个人说明:");
  QTextEdit* infoTextEdit = new QTextEdit();
  QHBoxLayout* topLayout = GetTopLayout();
  QVBoxLayout* rightLayout = new QVBoxLayout();
  rightLayout->addLayout(topLayout);
  rightLayout->addWidget(infoLabel);
  rightLayout->addWidget(infoTextEdit);

  return rightLayout;
}
