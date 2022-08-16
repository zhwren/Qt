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
** Last modified: 2022-08-16 20:45:17                       **
** Filename     : interface_info.cpp
** Phone Number : 15756230211                               **
** Discription  :                                           **
*************************************************************/
#include "interface_info.h"
#include <iostream>
#include <QGroupBox>
#include <QLabel>
#include <QString>
#include <QLineEdit>
#include <QGridLayout>
using namespace std;

InterfaceDialog* InterfaceDialog::inst = nullptr;

InterfaceDialog::InterfaceDialog(QWidget *parent)
    : QDialog(parent)
{
    QLabel *ifNameLabel = new QLabel("InterfaceName:");
    ifNameEdit = new QLineEdit();
    QLabel *fieldNumLabel = new QLabel("FieldNumber:");
    fieldNumEdit = new QLineEdit();
    
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(ifNameLabel, 0, 0);
    layout->addWidget(ifNameEdit,  0, 1);
    layout->addWidget(fieldNumLabel, 1, 0);
    layout->addWidget(fieldNumEdit,  1, 1);

    QGroupBox *gbox = new QGroupBox("InterfaceInfo");
    gbox->setLayout(layout);

    infoLayout = new QGridLayout();
    QGroupBox *ibox = new QGroupBox("FieldInfo");
    ibox->setLayout(infoLayout);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(gbox, 0, 0);
    mainLayout->addWidget(ibox, 1, 0);
}

InterfaceDialog::~InterfaceDialog()
{}

/*************************************************************
** Time        : 2022-08-16 20:53:18                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
InterfaceDialog* InterfaceDialog::GetInstance(QWidget *parent)
{
    if (inst == nullptr) {
	inst = new InterfaceDialog(parent);
    }

    return inst;
}

/*************************************************************
** Time        : 2022-08-16 21:00:13                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
void InterfaceDialog::ShowInterfaceInfo(InterfaceInfo &ifInfo)
{
    ifNameEdit->setText(ifInfo.name.c_str());
    fieldNumEdit->setText(QString(to_string(ifInfo.fields.size()).c_str()));

    for (size_t i = fieldNameEdit.size(); i < ifInfo.fields.size(); i++) {
	QLineEdit *nameEdit = new QLineEdit();
	fieldNameEdit.push_back(nameEdit);
	QLineEdit *widthEdit = new QLineEdit();
	fieldWidthEdit.push_back(widthEdit);
	infoLayout->addWidget(nameEdit, i, 0);
	infoLayout->addWidget(widthEdit, i, 1);
    }

    for (size_t i = 0; i < ifInfo.fields.size(); i++) {
	fieldNameEdit[i]->setText(ifInfo.fields[i].name.c_str());
	fieldWidthEdit[i]->setText(QString(to_string(ifInfo.fields[i].width).c_str()));
	fieldNameEdit[i]->setVisible(true);
	fieldWidthEdit[i]->setVisible(true);
    }

    for (size_t i = ifInfo.fields.size(); i < fieldNameEdit.size(); i++) {
	fieldNameEdit[i]->setVisible(false);
	fieldWidthEdit[i]->setVisible(false);
    }
}
