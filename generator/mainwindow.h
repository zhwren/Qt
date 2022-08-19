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
** Last modified: 2022-08-16 18:57:05                       **
** Filename     : mainwindow.h
** Phone Number : 15756230211                               **
** Discription  :                                           **
*************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "interface_info.h"
#include <QWidget>

class QLineEdit;
class QGridLayout;
class QComboBox;

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    std::vector<InterfaceInfo> interfaces;
    QLineEdit   *prjNameEdit;
    QLineEdit   *moduleNameEdit;
    QLineEdit   *workdirEdit;
    QComboBox   *ifSelectBox;
    QGridLayout *mainLayout;
    QGridLayout *leftLayout;
    QGridLayout *rightLayout;

    QLineEdit   *ifNameEdit;
    QLineEdit   *fieldNumEdit;
    QGridLayout *infoLayout;
    std::vector<QLineEdit*> fieldNameEdit;
    std::vector<QLineEdit*> fieldWidthEdit;

private:
    void AddFieldInfoGroup();
    void UpdateInterfaceLists();
    void AddFunctionalGroup(int, int);
    void AddProjectInfoGroup(int, int);
    void AddInterfaceSelectionGroup(int, int);

private slots:
    void SelectWorkdir();
    void ShowInterfaceDetail();
    void GenerateUtils();
    void GenerateEnvironment();
    void AddInterfaceProcess();
    void ChangeFieldNumber();
    void SaveFieldInfoProcess();
};
#endif
