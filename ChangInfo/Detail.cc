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
*    >  File Name   : Detail.cc
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-01 16:39                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#include "Detail.hh"
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QGridLayout>

Detail::Detail(QWidget* parent)
  :QDialog(parent)
{
  QLabel* contryLabel = new QLabel("国家:");
  QComboBox* contryCombo = new QComboBox();
  contryCombo->addItem("中国");
  QLabel* provenceLabel = new QLabel("省份:");
  QComboBox* provenceCombo = new QComboBox();
  provenceCombo->addItem("江苏省");
  provenceCombo->addItem("四川省");
  provenceCombo->addItem("陕西省");
  provenceCombo->addItem("湖北省");
  provenceCombo->addItem("湖南省");
  provenceCombo->addItem("湖北省");
  provenceCombo->addItem("北京市");
  QLabel* cityLabel = new QLabel("城市");
  QLineEdit *cityEdit = new QLineEdit();
  QLabel* infoLabel = new QLabel("个人说明:");
  QTextEdit *infoEdit = new QTextEdit();

  QGridLayout* mainLayout = new QGridLayout(this);
  mainLayout->addWidget(contryLabel, 0, 0);
  mainLayout->addWidget(contryCombo, 0, 1);
  mainLayout->addWidget(provenceLabel, 1, 0);
  mainLayout->addWidget(provenceCombo, 1, 1);
  mainLayout->addWidget(cityLabel, 2, 0);
  mainLayout->addWidget(cityEdit, 2, 1);
  mainLayout->addWidget(infoLabel, 3, 0);
  mainLayout->addWidget(infoEdit, 3, 1);
}

Detail::~Detail()
{}
