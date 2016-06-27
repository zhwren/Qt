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
*    >  File Name   : imgProcessor.hh
*    >  Author      : zhuhaiwen                            *
*    >  mail        : zhwren0211@whu.edu.cn                *
*    >  Created Time: 2016-06-21 11:08                     *
*    >  PhoneNumber : 18625272373                          *
***********************************************************/
#ifndef imgProcessor_h
#define imgProcessor_h 1

#include <QMainWindow>

class QImage;
class QLabel;
class QMenu;
class QMenuBar;
class QAction;
class QComboBox;
class QSpinBox;
class QFontComboBox;
class QTextCharFormat;
class ShowWidget;

class ImgProcessor : public QMainWindow
{
  Q_OBJECT
  public:
    ImgProcessor(QWidget* parent=0);
    ~ImgProcessor();

    void createActions();
    void createMenus();

  private:
    ShowWidget* showWidget;
    QAction* openFileAction;
    QAction* newFileAction;
    QMenu* fileMenu;
};
#endif
