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
*    >  File Name   : ProgressBar.hh
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-03 14:23                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#ifndef ProgressBar_h
#define ProgressBar_h 1

#include <QDialog>
class QLabel;
class QLineEdit;
class QComboBox;
class QPushButton;
class QProgressBar;
class ProgressBar : public QDialog
{
  Q_OBJECT
  public:
    ProgressBar(QWidget* parent=0);
    ~ProgressBar();
  private:
    QLabel* label1;
    QLabel* label2;
    QLineEdit* lineEdit;
    QComboBox* comboBox;
    QPushButton* button;
    QProgressBar* bar;
  private slots:
    void startProgressBar();
};
#endif
