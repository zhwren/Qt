/*************************************************************
**                         _ooOoo_                          **
**                        o8888888o                         **
**                        88" . "88                         **
**                        (| -_- |)                         **
**                         O\ = /O                          **
**                     ____/`---'\____                      **
**                   .   ' \\| |// `.                       **
**                    / \\||| : |||// \                     **
**                  / _||||| -:- |||||- \                   **
**                    | | \\\ - /// | |                     **
**                  | \_| ''\---/'' | |                     **
**                   \ .-\__ `-` ___/-. /                   **
**                ___`. .' /--.--\ `. . __                  **
**             ."" '< `.____<|>_/___.' >'"".                **
**            | | : `- \`.;` _ /`;.`/ - ` : | |             **
**              \ \ `-. \_ __\ /__ _/ .-` / /               **
**      ======`-.____`-.___\_____/___.-`____.-'======       **
**                         `=---='                          **
**                                                          **
**      .............................................       **
**             Buddha bless me, No bug forever              **
**                                                          **
**************************************************************
** Author       : ZhuHaiWen                                 **
** Email        : zhuhw@ihep.ac.cn/zhwren0211@whu.edu.cn    **
** Last modified: 2022-08-16 20:11:10                       **
** Filename     : interface_info.h
** Phone Number : 15756230211                               **
** Discription  :                                           **
*************************************************************/
#ifndef INTERFACE_INFO_H
#define INTERFACE_INFO_H

#include <vector>
#include <string>
#include <QDialog>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>

typedef struct {
    std::string name;
    int         width;
} FieldInfo;

typedef struct InterfaceInfoSt {
    int instNum;
    std::string name;
    std::vector<FieldInfo> fields;
    InterfaceInfoSt() {
        instNum = 0;
    }
} InterfaceInfo;

class InterfaceDialog : public QDialog
{
    Q_OBJECT
public:
    static InterfaceDialog *inst;
    static InterfaceDialog *GetInstance(QWidget *parent=nullptr);

    void ShowInterfaceInfo(InterfaceInfo &ifInfo);

private:
    InterfaceDialog(QWidget *parent=nullptr);
    ~InterfaceDialog();

private:
    QLineEdit   *ifNameEdit;
    QLineEdit   *fieldNumEdit;
    QGridLayout *mainLayout;
    QGridLayout *infoLayout;
    std::vector<QLineEdit*> fieldNameEdit;
    std::vector<QLineEdit*> fieldWidthEdit;
};

#endif
