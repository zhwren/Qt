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
*    >  File Name   : ProgressBar.cc
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-03 14:24                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#include "ProgressBar.hh"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QProgressBar>
#include <QProgressDialog>

ProgressBar::ProgressBar(QWidget* parent)
  :QDialog(parent)
{
  setWindowTitle("进度条");
  label1 = new QLabel("文件数目");
  label2 = new QLabel("显示类型");
  lineEdit = new QLineEdit();
  comboBox = new QComboBox();
  comboBox->addItem("progress bar");
  comboBox->addItem("progress dialog");
  button = new QPushButton("开始");
  bar = new QProgressBar();

  QGridLayout *layout = new QGridLayout(this);
  layout->addWidget(label1, 0, 0);
  layout->addWidget(lineEdit, 0, 1);
  layout->addWidget(label2, 1, 0);
  layout->addWidget(comboBox, 1, 1);
  layout->addWidget(bar, 2, 0, 1, 2);
  layout->addWidget(button, 3, 1);

  connect(button, SIGNAL(clicked()), this, SLOT(startProgressBar()));
}

ProgressBar::~ProgressBar()
{}

void ProgressBar::startProgressBar()
{
  QString text = lineEdit->text();
  int totalEvent = text.toInt();
  if( comboBox->currentIndex()==0 )
  {
    bar->setRange(0, totalEvent);
    for(int i=0; i<totalEvent+1; i++)
      bar->setValue(i);
  }
  else if(comboBox->currentIndex()==1)
  {
    QProgressDialog* pdialog = new QProgressDialog(this);
    pdialog->setWindowModality(Qt::WindowModal);
    pdialog->setWindowTitle("请稍等");
    pdialog->setLabelText("正在复制");
    pdialog->setCancelButtonText("取消");
    pdialog->setRange(0, totalEvent);
    for(int i=0; i<totalEvent+1; i++)
    {
      pdialog->setValue(i);
      if(pdialog->wasCanceled()) return;
      pdialog->show();
    }
  }
}
