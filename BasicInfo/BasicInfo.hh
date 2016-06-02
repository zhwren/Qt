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
*    >  File Name   : BasicInfo.hh
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-05-19 16:56                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#ifndef BasicInfo_h
#define BasicInfo_h 1

#include <QDialog>
class QLabel;
class QLineEdit;
class QComboBox;
class QTextEdit;
class QPushButton;
class BasicInfo : public QDialog
{
  Q_OBJECT
  public:
    BasicInfo(QWidget* parent = 0);
    ~BasicInfo();
  private:
    QLabel* userNameLabel;
    QLabel* nameLabel;
    QLabel* sexLabel;
    QLabel* departLabel;
    QLabel* ageLabel;
    QLabel* otherLabel;
    QLabel* imgLabel;
    QLabel* photoLabel;
    QLabel* personalLabel;
    QLineEdit* userNameEdit;
    QLineEdit* nameEdit;
    QComboBox* sexComboBox;
    QTextEdit* departEdit;
    QTextEdit* personalEdit;
    QLineEdit* ageEdit;
    QLineEdit* otherEdit;
    QPushButton* okButton;
    QPushButton* cancelButton;
    QPushButton* updateButton;
};

#endif
