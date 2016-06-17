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
*    >  File Name   : Palette.hh
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-03 15:07                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#ifndef Palette_h
#define Palette_h 1

#include <QDialog>

class QFrame;
class QLabel;
class QLineEdit;
class QTextEdit;
class QComboBox;
class QPushButton;
class QGridLayout;
class QVBoxLayout;
class Palette : public QDialog
{
  Q_OBJECT
  public:
    Palette(QWidget* parent=0);
    ~Palette();
  private:
    QLabel* windowLabel;
    QLabel* windowTextLabel;
    QLabel* buttonLabel;
    QLabel* buttonTextLabel;
    QLabel* baseLabel;
    QLabel* label1;
    QLabel* label2;
    QLineEdit* lineEdit;
    QComboBox* comboBox1;
    QTextEdit* textEdit;
    QComboBox* windowColorBox;
    QComboBox* windowTextColorBox;
    QComboBox* buttonColorBox;
    QComboBox* buttonTextColorBox;
    QComboBox* baseColorBox;
    QGridLayout* leftLayout;
    QVBoxLayout* rightLayout;
    QFrame* contentFrame;
    QFrame* ctrlFrame;

  private:
    void fillColorList(QComboBox*);
    void putLeftLayout();
    void putRightLayout();

  private slots:
    void showWindow();
    void showWindowText();
};
#endif
