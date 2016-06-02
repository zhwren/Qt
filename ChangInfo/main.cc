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
*    >  File Name   : main.cc
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-01 14:35                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#include <QApplication>
#include <QSplitter>
#include <QListWidget>
#include <QFont>
#include "ChangeUserInfo.hh"

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  QFont font("AR PL KaitiM GB", 12);
  app.setFont( font );

  QSplitter* splitterMain = new QSplitter(Qt::Horizontal);
  splitterMain->setOpaqueResize(true);
  QListWidget* list = new QListWidget(splitterMain);
  list->insertItem(0, "基本信息");
  list->insertItem(1, "联系方式");
  list->insertItem(2, "详细信息");
  ChangeUserInfo* changeInfo = new ChangeUserInfo(splitterMain);

  QObject::connect(list, SIGNAL(currentRowChanged(int)),
                   changeInfo->stack, SLOT(setCurrentIndex(int)));

  splitterMain->show();
  return app.exec();
}
