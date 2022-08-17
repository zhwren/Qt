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
#include <QDate>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>

#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/ini_parser.hpp"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    mainLayout = new QGridLayout(this);
    AddProjectInfoGroup(0, 0);
    AddInterfaceSelectionGroup(1, 0);
    AddFunctionalGroup(2, 0);
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
    //QPushButton *detailButton = new QPushButton("Detail");

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(ifSelectLabel, 0, 0);
    layout->addWidget(ifSelectBox,   0, 1);
    //layout->addWidget(detailButton,  0, 2);

    QGroupBox *gbox = new QGroupBox("InterfaceInfo");
    gbox->setLayout(layout);
    mainLayout->addWidget(gbox, row, column);

    UpdateInterfaceLists();
    //connect(detailButton, SIGNAL(clicked()), this, SLOT(ShowInterfaceDetail()));
    connect(ifSelectBox, SIGNAL(currentIndexChanged(int)), this, SLOT(ShowInterfaceDetail()));
}

/*************************************************************
** Time        : 2022-08-16 20:31:49                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
void MainWindow::UpdateInterfaceLists()
{
    FieldInfo     field;
    InterfaceInfo interface;
    boost::property_tree::ptree ptr;
    boost::property_tree::ini_parser::read_ini("cfg.ini", ptr);
    boost::property_tree::ptree::iterator it, pt;

    for (it = ptr.begin(); it != ptr.end(); it++) {
	interface.name = it->first.data();
	interface.fields.clear();
	for (pt = it->second.begin(); pt != it->second.end(); pt++) {
	    field.name = pt->first.data();
	    field.width = atoi(pt->second.data().c_str());
	    interface.fields.push_back(field);
	}
        interfaces.push_back(interface);
    }

    for (size_t i = 0; i < interfaces.size(); i++) {
	ifSelectBox->addItem(interfaces[i].name.c_str());
    }

    ShowInterfaceDetail();
}

/*************************************************************
** Time        : 2022-08-16 21:17:45                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
void MainWindow::ShowInterfaceDetail()
{
    int index = ifSelectBox->currentIndex();
    InterfaceDialog::GetInstance(this)->ShowInterfaceInfo(interfaces[index]);
    InterfaceDialog::GetInstance(this)->show();
}

/*************************************************************
** Time        : 2022-08-17 10:13:03                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
void MainWindow::AddFunctionalGroup(int row, int column)
{
    QPushButton *genVip = new QPushButton("GenVIP");
    QPushButton *genEnv = new QPushButton("GenENV");
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(genVip, 0, 0);
    layout->addWidget(genEnv, 0, 1);

    QGroupBox *gbox = new QGroupBox();
    gbox->setLayout(layout);

    mainLayout->addWidget(gbox, row, column);
    connect(genVip, SIGNAL(clicked()), this, SLOT(GenerateUtils()));
    connect(genEnv, SIGNAL(clicked()), this, SLOT(GenerateEnvironment()));
}

/*************************************************************
** Time        : 2022-08-17 13:13:29                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
string ToUpper(string s)
{
    for (size_t i = 0; i < s.size(); i++) {
	s[i] = toupper(s[i]);
    }

    return s;
}

/*************************************************************
** Time        : 2022-08-17 13:28:21                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
string GetDeccontext(InterfaceInfo &ifInfo)
{
    stringstream ss;
    ss << endl;
    ss << setw(14) << std::right << "parameter "
       << setw(20) << std::left  << "VLD2DATA_DLY" << " = 0;" << endl;
    for (size_t i = 0; i < ifInfo.fields.size(); i++) {
	ss << setw(14) << std::right << "parameter " 
	   << setw(20) << std::left  << ToUpper(ifInfo.fields[i].name + "_WIDTH")
	   << " = " << ifInfo.fields[i].width << ";" << endl;
    }

    return ss.str();
}

/*************************************************************
** Time        : 2022-08-17 13:43:22                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
string GetXactionContext(InterfaceInfo &ifInfo, string prefix)
{
    stringstream ss;
    ss << endl;
    for (size_t i = 0; i < ifInfo.fields.size(); i++) {
	ss << setw(prefix.size() + 4) << std::right << prefix << " ["
	   << setw(20) << std::left  << ToUpper(ifInfo.fields[i].name + "_WIDTH")
	   << "-1:0] " << ifInfo.fields[i].name << ";" << endl;
    }

    return ss.str();
}

/*************************************************************
** Time        : 2022-08-17 14:57:29                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
string GetTimeContext()
{
    string contex = QDate::currentDate().toString("yyyy-MM-dd").toStdString();
    contex += " ";
    contex += QTime::currentTime().toString("HH:mm:ss").toStdString();
    return contex;
}

/*************************************************************
** Time        : 2022-08-17 16:32:37                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
string GetClockingCbContext(InterfaceInfo &ifInfo, string prefix)
{
    stringstream ss;
    ss << endl;
    for (size_t i = 0; i < ifInfo.fields.size(); i++) {
	ss << setw(prefix.size() + 8) << std::right << prefix
	   << " " << ifInfo.fields[i].name << ";" << endl;
    }

    return ss.str();
}

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
string GetDriverContext(InterfaceInfo &ifInfo)
{
    stringstream ss;
    ss << endl;

    ss << setw(4) << " " << "vif." << ifInfo.fields[0].name
       << " <= tr." << ifInfo.fields[0].name << ";" << endl
       << setw(4) << " " << "fork begin" << endl << setw(8)
       << " " << "repeat (VLD2DATA_DLY) @vif.drv_cb;" << endl;

    for (size_t i = 1; i < ifInfo.fields.size(); i++) {
	ss << setw(8) << std::right << " "
	   << "vif."  << setw(20) << std::left << ifInfo.fields[i].name
	   << " <= tr."  << ifInfo.fields[i].name << ";" << endl;
    }

    ss << setw(4) << " " << "end join_none" << endl;

    return ss.str();
}

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
string GetMonitorContext(InterfaceInfo &ifInfo)
{
    stringstream ss;
    ss << endl;

    ss << setw(8) << " " << "tr." << ifInfo.fields[0].name
       << " = vif." << ifInfo.fields[0].name << ";" << endl
       << setw(8) << " " << "fork begin" << endl << setw(12)
       << " " << "repeat (VLD2DATA_DLY) @vif.mon_cb;" << endl;

    for (size_t i = 1; i < ifInfo.fields.size(); i++) {
	ss << setw(12) << " " << "tr." << setw(20) << std::left
	   << ifInfo.fields[i].name
	   << " = vif." << ifInfo.fields[i].name << ";" << endl;
    }

    ss << setw(8) << " " << "end join_none" << endl;
    return ss.str();
}

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
string GetFilecontex(InterfaceInfo &ifInfo, string line)
{
    size_t pos;

    while ((pos = line.find("demo")) != string::npos) {
	line = line.replace(pos, 4, ifInfo.name);
    }
    while ((pos = line.find("DEMO")) != string::npos) {
	line = line.replace(pos, 4, ToUpper(ifInfo.name));
    }

    if ((pos = line.find("DEC_CONTEXT")) != string::npos) {
	line = GetDeccontext(ifInfo);
    } else if ((pos = line.find("XACTION_CONTEXT")) != string::npos) {
	line = GetXactionContext(ifInfo, "rand bit");
    } else if ((pos = line.find("INTERFACE_CONTEXT")) != string::npos) {
	line = GetXactionContext(ifInfo, "logic");
    } else if ((pos = line.find("TIME_CONTEXT")) != string::npos) {
	line = line.replace(pos, 19, GetTimeContext());
    } else if ((pos = line.find("DRVCB_CONTEXT")) != string::npos) {
	line = GetClockingCbContext(ifInfo, "inout");
    } else if ((pos = line.find("MONCB_CONTEXT")) != string::npos) {
	line = GetClockingCbContext(ifInfo, "input");
    } else if ((pos = line.find("VLD_CONTEXT")) != string::npos) {
	line = line.replace(pos, 11, ifInfo.fields[0].name);
    } else if ((pos = line.find("DRIVER_CONTEXT")) != string::npos) {
	line = GetDriverContext(ifInfo);
    } else if ((pos = line.find("MONITOR_CONTEXT")) != string::npos) {
	line = GetMonitorContext(ifInfo);
    }
    return line;
}

/*************************************************************
** Time        : 2022-08-17 12:56:25                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
void GenerateUtilFile(InterfaceInfo &ifInfo, string appendex)
{
    string iName = "demo/demo" + appendex + ".sv";
    string oName = ifInfo.name + appendex + ".sv";

    ifstream iFile(iName.c_str());
    if (!iFile.is_open()) {
	return;
    }

    ofstream oFile(oName.c_str());
    if (!oFile.is_open()) {
	iFile.close();
	return;
    }

    string line;
    while (getline(iFile, line)) {
	oFile << GetFilecontex(ifInfo, line) << endl;
    }
    iFile.close();
    oFile.close();
}

/*************************************************************
** Time        : 2022-08-17 10:43:54                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
void GenerateUtil(InterfaceInfo &ifInfo)
{
    string appendex[] = {"_dec", "_xaction", "_interface", 
	"_agent", "_driver", "_monitor", "_sequence", "_sequencer"};
    size_t len = sizeof(appendex) / sizeof(appendex[0]);

    for (size_t i = 0; i < len; i++) {
	GenerateUtilFile(ifInfo, appendex[i]);
    }
}

/*************************************************************
** Time        : 2022-08-17 10:41:19                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
void MainWindow::GenerateUtils()
{
    for (size_t i = 0; i < interfaces.size(); i++) {
	GenerateUtil(interfaces[i]);
    }
}

/*************************************************************
** Time        : 2022-08-17 10:41:32                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
void MainWindow::GenerateEnvironment()
{}
