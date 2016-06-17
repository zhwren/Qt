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
*    >  File Name   : Palette.cc
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-03 15:08                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#include "Palette.hh"
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QGridLayout>
#include <QComboBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPixmap>
#include <QColor>

Palette::Palette(QWidget* parent)
  :QDialog(parent)
{
  putLeftLayout();
  putRightLayout();
  QHBoxLayout* mainLayout = new QHBoxLayout(this);
  mainLayout->addWidget(ctrlFrame);
  mainLayout->addWidget(contentFrame);
}

Palette::~Palette()
{}

void Palette::putLeftLayout()
{
  ctrlFrame = new QFrame;

  windowLabel = new QLabel("QPalette::Window");
  windowTextLabel = new QLabel("QPalette::WindowText");
  buttonLabel = new QLabel("QPalette::Button");
  buttonTextLabel = new QLabel("QPalette::ButtonText");
  baseLabel = new QLabel("QPalette::Base");
  windowColorBox = new QComboBox();
  windowTextColorBox = new QComboBox();
  buttonColorBox = new QComboBox();
  buttonTextColorBox = new QComboBox();
  baseColorBox = new QComboBox();
  fillColorList(windowColorBox);
  fillColorList(windowTextColorBox);
  fillColorList(buttonColorBox);
  fillColorList(buttonTextColorBox);
  fillColorList(baseColorBox);

  connect(windowColorBox, SIGNAL(activated(int)), this, SLOT(showWindow()));
  connect(windowTextColorBox, SIGNAL(activated(int)), this, SLOT(showWindowText()));

  leftLayout = new QGridLayout(ctrlFrame);
  leftLayout->addWidget(windowLabel, 0, 0);
  leftLayout->addWidget(windowColorBox, 0, 1);
  leftLayout->addWidget(windowTextLabel, 1, 0);
  leftLayout->addWidget(windowTextColorBox, 1, 1);
  leftLayout->addWidget(buttonLabel, 2, 0);
  leftLayout->addWidget(buttonColorBox, 2, 1);
  leftLayout->addWidget(buttonTextLabel, 3, 0);
  leftLayout->addWidget(buttonTextColorBox, 3, 1);
  leftLayout->addWidget(baseLabel, 4, 0);
  leftLayout->addWidget(baseColorBox, 4, 1);
}

void Palette::fillColorList(QComboBox* comboBox)
{
  QStringList colorList = QColor::colorNames();
  QString color;
  foreach(color, colorList)
  {
    QPixmap pix(QSize(70, 20));
    pix.fill(QColor(color));
    comboBox->addItem(QIcon(pix),NULL);
    comboBox->setIconSize(QSize(70, 20));
    comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
  }
}

void Palette::putRightLayout()
{
  contentFrame = new QFrame();

  label1 = new QLabel("选择一个值");
  comboBox1 = new QComboBox();

  label2 = new QLabel("输入字符串");
  lineEdit = new QLineEdit;
  textEdit = new QTextEdit;

  QGridLayout* topLayout = new QGridLayout();
  topLayout->addWidget(label1, 0, 0);
  topLayout->addWidget(comboBox1, 0, 1);
  topLayout->addWidget(label2, 1, 0);
  topLayout->addWidget(lineEdit, 1, 1);

  QPushButton* okbtn = new QPushButton("OK");
  QPushButton* cancel= new QPushButton("cancel");

  QHBoxLayout* bomLayout = new QHBoxLayout();
  bomLayout->addWidget(okbtn);
  bomLayout->addWidget(cancel);

  rightLayout = new QVBoxLayout(contentFrame);
  rightLayout->addLayout(topLayout);
  rightLayout->addWidget(textEdit);
  rightLayout->addLayout(bomLayout);
}

void Palette::showWindow()
{
  QStringList colorList = QColor::colorNames();
  QColor color = QColor(colorList[windowColorBox->currentIndex()]);

  QPalette p = contentFrame->palette();
  p.setColor(QPalette::Window, color);

  contentFrame->setPalette(p);
  contentFrame->update();
}

void Palette::showWindowText()
{
  QStringList colorList = QColor::colorNames();
  QColor color = colorList[windowTextColorBox->currentIndex()];

  QPalette p = contentFrame->palette();
  p.setColor(QPalette::WindowText, color);

  contentFrame->setPalette(p);
}
