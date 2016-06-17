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
*    >  File Name   : extensiondlg.hh
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-15 14:39                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#ifndef extensiondlg_h
#define extensiondlg_h 1

#include <QDialog>

class ExtensionDlg : public QDialog
{
  Q_OBJECT
  public:
    ExtensionDlg(QWidget* parent=0);
    ~ExtensionDlg();

  private:
    QWidget* basicWidget;
    QWidget* detailWidget;
    void createBasic();
    void createDetail();

  private slots:
    void showMoreDialog();
};
#endif
