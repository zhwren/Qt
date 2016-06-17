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
*    >  File Name   : digiclock.cc
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-15 14:07                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#include "digiclock.hh"

#include <QTime>
#include <QTimer>
#include <QMouseEvent>

DigiClock::DigiClock(QWidget* parent)
  :QLCDNumber(parent)
{
  QPalette p = palette();
  p.setColor(QPalette::Window, Qt::red);
  setPalette(p);

  setWindowFlags(Qt::FramelessWindowHint);
//  setWindowOpacity(0.5);

  QTimer* timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
  timer->start(1000);
  showTime();
  resize(150,150);
  showColon=true;
}

DigiClock::~DigiClock()
{}

void DigiClock::showTime()
{
  QTime time = QTime::currentTime();
  QString text = time.toString("hh:mm");
  if( showColon )
  {
    text[2] = ':';
    showColon = false;
  }
  else
  {
    text[2] = ' ';
    showColon = true;
  }
  display(text);
}

void DigiClock::mousePressEvent(QMouseEvent* event)
{
  if(event->button()==Qt::LeftButton)
  {
    dragPosition = event->globalPos()-frameGeometry().topLeft();
    event->accept();
  }
  if(event->button()==Qt::RightButton)
  {
    close();
  }
}

void DigiClock::mouseMoveEvent(QMouseEvent* event)
{
  if(event->buttons()&Qt::LeftButton)
  {
    move(event->globalPos()-dragPosition);
    event->accept();
  }
}
