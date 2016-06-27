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
*    >  File Name   : imgProcessor.cc
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-21 11:11                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#include <QImage>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QComboBox>
#include <QSpinBox>
#include <QFontComboBox>
#include <QTextCharFormat>

#include "showWidget.hh"
#include "imgProcessor.hh"

ImgProcessor::ImgProcessor(QWidget* parent)
  :QMainWindow(parent)
{
  setWindowTitle("Easy Word");
  showWidget = new ShowWidget(this);
  setCentralWidget(showWidget);
  createActions();
  createMenus();
}

ImgProcessor::~ImgProcessor()
{}

void ImgProcessor::createActions()
{
  openFileAction = new QAction(QIcon("Open.png"),tr("打开"), this);
  openFileAction->setShortcut(tr("Ctrl+O"));
  openFileAction->setStatusTip("打开一个文件");

  newFileAction = new QAction(QIcon("New.png"),tr("新建"), this);
  newFileAction->setShortcut(tr("Ctrl+N"));
  newFileAction->setStatusTip("新建一个文件");
}

void ImgProcessor::createMenus()
{
  fileMenu = menuBar()->addMenu("文件");
  fileMenu->addAction(openFileAction);
  fileMenu->addAction(newFileAction);
}
