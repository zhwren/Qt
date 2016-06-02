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
*    >  File Name   : Contact.cc
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-01 16:00                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#include "Contact.hh"
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QCheckBox>

Contact::Contact(QWidget* parent)
  :QDialog(parent)
{
  QLabel* emailLabel = new QLabel("电子邮件:");
  QLabel* addressLabel = new QLabel("联系地址:");
  QLabel* postLabel = new QLabel("邮政编码:");
  QLabel* phoneLabel = new QLabel("移动电话:");
  QLabel* officeLabel = new QLabel("办公电话:");
  QLineEdit* emailEdit = new QLineEdit();
  QLineEdit* addressEdit = new QLineEdit();
  QLineEdit* postEdit = new QLineEdit();
  QLineEdit* phoneEdit = new QLineEdit();
  QLineEdit* officeEdit = new QLineEdit();
  QCheckBox* phoneCheckBox = new QCheckBox("接收留言");
  
  QGridLayout *mainLayout = new QGridLayout(this);
  mainLayout->addWidget(emailLabel, 0, 0);
  mainLayout->addWidget(emailEdit, 0, 1);
  mainLayout->addWidget(addressLabel, 1, 0);
  mainLayout->addWidget(addressEdit, 1, 1);
  mainLayout->addWidget(postLabel, 2, 0);
  mainLayout->addWidget(postEdit, 2, 1);
  mainLayout->addWidget(phoneLabel, 3, 0);
  mainLayout->addWidget(phoneEdit, 3, 1);
  mainLayout->addWidget(phoneCheckBox, 3, 2);
  mainLayout->addWidget(officeLabel, 4, 0);
  mainLayout->addWidget(officeEdit, 4, 1);
}
Contact::~Contact()
{}
