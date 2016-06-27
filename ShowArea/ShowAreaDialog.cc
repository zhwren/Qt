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
*    >  File Name   : ShowAreaDialog.cc
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-05-19 16:14                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#include "ShowAreaDialog.hh"

#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>
ShowAreaDialog::ShowAreaDialog(QWidget* parent)
  :QDialog( parent )
{
  radiusLabel = new QLabel("半径：", this);
  areaLabel = new QLabel("面积：", this);
  radiusLineEdit = new QLineEdit();
  areaLineEdit = new QLineEdit();
  areaLineEdit->setReadOnly(true);
  okButton = new QPushButton("OK");
  cancelButton = new QPushButton("Cancel");

  QGridLayout* mainLayout = new QGridLayout(this);
  mainLayout->addWidget(radiusLabel, 0, 0);
  mainLayout->addWidget(radiusLineEdit, 0, 1);
  mainLayout->addWidget(areaLabel, 1, 0);
  mainLayout->addWidget(areaLineEdit, 1, 1);
  mainLayout->addWidget(cancelButton, 2, 0);
  mainLayout->addWidget(okButton, 2, 1);
  mainLayout->setColumnStretch(0, 1);
  mainLayout->setColumnStretch(1, 5);

  connect(okButton, SIGNAL(clicked()), this, SLOT(showArea()));
}
//......oooOO0OOooo............oooOO0OOooo......
ShowAreaDialog::~ShowAreaDialog()
{}
//......oooOO0OOooo............oooOO0OOooo......
void ShowAreaDialog::showArea()
{
  QString text = radiusLineEdit->text();
  if( text.isEmpty() ) return;
  float radius = text.toFloat();
  float area = 3.1415926*radius*radius;
  areaLineEdit->setText( text.setNum( area ) );
}
