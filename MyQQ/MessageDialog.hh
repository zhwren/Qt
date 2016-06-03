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
*    >  File Name   : MessageDialog.hh
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-02 22:31                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#ifndef MessageDialog_h
#define MessageDialog_h 1

#include <QDialog>
class QPushButton;
class MessageDialog : public QDialog
{
  Q_OBJECT
  public:
    MessageDialog(QWidget* parent=0);
    ~MessageDialog();
  private:
    QPushButton* questionButton;
    QPushButton* messageButton;
    QPushButton* warningButton;
    QPushButton* aboutQtButton;
    QPushButton* aboutButton;
    QPushButton* criticalButton;
  private slots:
    void showQuestion();
    void showMessage();
    void showWarning();
    void showAbout();
    void showAboutQt();
    void showCritical();
};
#endif
