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
** Last modified: 2022-08-16 19:04:01                       **
** Filename     : mainwindow.cpp
** Phone Number : 15756230211                               **
** Discription  :                                           **
*************************************************************/
#include "mainwindow.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    mainLayout = new QGridLayout(this);
    AddProjectInfoGroup(0, 0);
    AddInterfaceSelectionGroup(1, 0);
}

MainWindow::~MainWindow()
{
}

/*************************************************************
** Time        : 2022-08-16 19:09:00                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
void MainWindow::AddProjectInfoGroup(int row, int column)
{
    prjNameEdit  = new QLineEdit();
    QLabel *prjNameLabel = new QLabel("ProjectName:");
    moduleNameEdit = new QLineEdit();
    QLabel *moduleNameLabel = new QLabel("ModuleName:");

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(prjNameLabel, 0, 0);
    layout->addWidget(prjNameEdit,  0, 1);
    layout->addWidget(moduleNameLabel, 1, 0);
    layout->addWidget(moduleNameEdit,  1, 1);

    QGroupBox *gbox = new QGroupBox("ProjectInfo");
    gbox->setLayout(layout);
    mainLayout->addWidget(gbox, row, column);
}

/*************************************************************
** Time        : 2022-08-16 19:57:11                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
void MainWindow::AddInterfaceSelectionGroup(int row, int column)
{
    QLabel *ifSelectLabel = new QLabel("Interface:");
    ifSelectBox = new QComboBox();
    QPushButton *detailButton = new QPushButton("Detail");

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(ifSelectLabel, 0, 0);
    layout->addWidget(ifSelectBox,   0, 1);
    layout->addWidget(detailButton,  0, 2);

    QGroupBox *gbox = new QGroupBox("InterfaceInfo");
    gbox->setLayout(layout);
    mainLayout->addWidget(gbox, row, column);

    UpdateInterfaceLists();
    connect(detailButton, SIGNAL(clicked()), this, SLOT(ShowInterfaceDetail()));
}

/*************************************************************
** Time        : 2022-08-16 20:31:49                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
void MainWindow::UpdateInterfaceLists()
{
    InterfaceInfo interface;
    interface.name = "dpi_orb_sdb_data";

    FieldInfo field;
    field.name = "up_dn_vld";
    field.width = 14;
    interface.fields.push_back(field);

    field.name = "up_ecc";
    field.width = 12;
    interface.fields.push_back(field);

    field.name = "up_data";
    field.width = 1024;
    interface.fields.push_back(field);

    field.name = "down_ecc";
    field.width = 12;
    interface.fields.push_back(field);

    field.name = "down_data";
    field.width = 1024;
    interface.fields.push_back(field);

    interfaces.push_back(interface);

    for (size_t i = 0; i < interfaces.size(); i++) {
	ifSelectBox->addItem(interfaces[i].name.c_str());
    }
}

/*************************************************************
** Time        : 2022-08-16 21:17:45                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
void MainWindow::ShowInterfaceDetail()
{
    InterfaceDialog::GetInstance(this)->ShowInterfaceInfo(interfaces[0]);
    InterfaceDialog::GetInstance(this)->show();
}
