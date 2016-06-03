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
*    >  File Name   : Drawer.hh
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-03 09:46                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#ifndef Drawer_h
#define Drawer_h 1

#include <QToolBox>

class QToolButton;
class MessageDialog;
class Drawer : public QToolBox
{
  Q_OBJECT
  public:
    Drawer(QWidget* parent=0, Qt::WindowFlags f=0);
    ~Drawer();

  private:
    QToolButton* toolBtn1_1;
    QToolButton* toolBtn1_2;
    QToolButton* toolBtn1_3;
    QToolButton* toolBtn1_4;
    QToolButton* toolBtn2_1;
    QToolButton* toolBtn2_2;
    QToolButton* toolBtn2_3;
    QToolButton* toolBtn2_4;
    MessageDialog* message;
  private slots:
    void showMessage();
};
#endif
