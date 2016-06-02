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
*    >  File Name   : ShowAreaDialog.hh
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-05-19 16:13                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#ifndef ShowAreaDialog_h
#define ShowAreaDialog_h 1

#include <QDialog>
class QLabel;
class QLineEdit;
class QPushButton;
class ShowAreaDialog : public QDialog
{
  Q_OBJECT
  public:
    ShowAreaDialog(QWidget* parent = 0);
    ~ShowAreaDialog();
  private:
    QLabel* radiusLabel;
    QLabel* areaLabel;
    QPushButton* okButton;
    QPushButton* cancelButton;
    QLineEdit* radiusLineEdit;
    QLineEdit* areaLineEdit;
  private slots:
    void showArea();
};

#endif
