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
*    >  File Name   : BasicInfo.hh
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-01 14:21                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#ifndef BasicInfo_h
#define BasicInfo_h 1

#include <QDialog>

class QLabel;
class QLineEdit;
class QTextEdit;
class QComboBox;
class QGridLayout;
class QHBoxLayout;
class QVBoxLayout;
class BasicInfo : public QDialog
{
  Q_OBJECT
  public:
    BasicInfo(QWidget* parent = 0);
    ~BasicInfo();

  private:
    QLabel* userNameLabel;
    QLineEdit* userNameLineEdit;
    QLabel* nameLabel;
    QLineEdit* nameEdit;
    QLabel* sexLabel;
    QComboBox* sexComboBox;
    QLabel* ageLabel;
    QLineEdit* ageLineExit;
    QLabel* branchLabel;
    QTextEdit* branchTextEdit;
    QLabel* otherLabel;
    QLineEdit* otherLineEdit;

  private:
    QGridLayout* GetLeftLayout();
    QHBoxLayout* GetTopLayout();
    QVBoxLayout* GetRightLayout();
};
#endif
