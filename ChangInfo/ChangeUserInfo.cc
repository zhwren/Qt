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
*    >  File Name   : ChangeUserInfo.cc
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-01 14:27                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#include "Detail.hh"
#include "Contact.hh"
#include "BasicInfo.hh"
#include "ChangeUserInfo.hh"
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>

ChangeUserInfo::ChangeUserInfo(QWidget* parent)
  :QFrame(parent)
{
  basicInfo = new BasicInfo();
  contact = new Contact();
  detail = new Detail();
  stack = new QStackedWidget(this);
  stack->addWidget(basicInfo);
  stack->addWidget(contact);
  stack->addWidget(detail);
  QPushButton* okButton = new QPushButton("修改");
  QPushButton* cancelBtn = new QPushButton("取消");
  QHBoxLayout* btnLayout = new QHBoxLayout();
  btnLayout->addStretch(1);
  btnLayout->addWidget(okButton);
  btnLayout->addWidget(cancelBtn);

  QVBoxLayout *mainLayout = new QVBoxLayout(this);
  mainLayout->addWidget(stack);
  mainLayout->addLayout(btnLayout);
}

ChangeUserInfo::~ChangeUserInfo()
{}
