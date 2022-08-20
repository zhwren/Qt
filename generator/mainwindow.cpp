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
    this->resize(1000, 500);
    leftLayout = new QGridLayout();
    rightLayout = new QGridLayout();
    mainLayout  = new QGridLayout(this);
    mainLayout->addLayout(leftLayout, 0, 0);
    mainLayout->addLayout(rightLayout, 0, 1);

    AddFieldInfoGroup();
    AddProjectInfoGroup(0, 0);
    AddInterfaceSelectionGroup(1, 0);
    AddFunctionalGroup(2, 0);
}

MainWindow::~MainWindow()
{
}

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
void MainWindow::AddFieldInfoGroup()
{
    QLabel *ifNameLabel = new QLabel("InterfaceName:");
    ifNameEdit = new QLineEdit();
    QLabel *fieldNumLabel = new QLabel("FieldNumber:");
    fieldNumEdit = new QLineEdit();
    fieldNumEdit->setValidator(new QIntValidator(1, 99, this));
    QPushButton *saveButton = new QPushButton("Save");
    QPushButton *cancButton = new QPushButton("Cancle");
    
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(ifNameLabel, 0, 0);
    layout->addWidget(ifNameEdit,  0, 1);
    layout->addWidget(fieldNumLabel, 1, 0);
    layout->addWidget(fieldNumEdit,  1, 1);

    QGroupBox *gbox = new QGroupBox("InterfaceInfo");
    gbox->setLayout(layout);

    infoLayout = new QGridLayout();
    infoLayout->addWidget(saveButton, 100, 0);
    infoLayout->addWidget(cancButton, 100, 1);
    QGroupBox *ibox = new QGroupBox("FieldInfo");
    ibox->setLayout(infoLayout);

    rightLayout->addWidget(gbox, 0, 0);
    rightLayout->addWidget(ibox, 1, 0);
    connect(saveButton, SIGNAL(clicked()), this, SLOT(SaveFieldInfoProcess()));
    connect(fieldNumEdit, SIGNAL(returnPressed()), this, SLOT(ChangeFieldNumber()));
}

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
void MainWindow::SaveFieldInfoProcess()
{
    int index = ifSelectBox->currentIndex();
    interfaces[index].name = ifNameEdit->text().toStdString();
    ifSelectBox->setItemText(index, ifNameEdit->text());
    interfaces[index].fields.clear();

    for (int i = 0; i < fieldNumEdit->text().toInt(); i++) {
        FieldInfo field;
        field.name = fieldNameEdit[i]->text().toStdString();
        field.width = fieldWidthEdit[i]->text().toInt();
        interfaces[index].fields.push_back(field);
    }
}

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
void MainWindow::ChangeFieldNumber()
{
    int len = fieldNumEdit->text().toInt();

    for (size_t i = fieldNameEdit.size(); i < (size_t)len; i++) {
	QLineEdit *nameEdit = new QLineEdit();
	fieldNameEdit.push_back(nameEdit);
	QLineEdit *widthEdit = new QLineEdit();
	fieldWidthEdit.push_back(widthEdit);
	infoLayout->addWidget(nameEdit, i, 0);
	infoLayout->addWidget(widthEdit, i, 1);
    }

    for (int i = 0; i < len; i++) {
	fieldNameEdit[i]->setVisible(true);
	fieldWidthEdit[i]->setVisible(true);
    }

    for (size_t i = len; i < fieldNameEdit.size(); i++) {
	fieldNameEdit[i]->setVisible(false);
	fieldWidthEdit[i]->setVisible(false);
    }

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
    leftLayout->addWidget(gbox, row, column);
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

    QGridLayout *layout = new QGridLayout();
    QGridLayout *flayout = new QGridLayout();
    QPushButton *addButton = new QPushButton("Add");
    QPushButton *delButton = new QPushButton("Delete");

    layout->addWidget(ifSelectLabel, 0, 0);
    layout->addWidget(ifSelectBox,   0, 1, 1, 2);
    layout->addLayout(flayout,       1, 0);
    layout->addWidget(addButton,     1, 1);
    layout->addWidget(delButton,     1, 2);

    QGroupBox *gbox = new QGroupBox("InterfaceInfo");
    gbox->setLayout(layout);
    leftLayout->addWidget(gbox, row, column);

    UpdateInterfaceLists();
    connect(addButton, SIGNAL(clicked()), this, SLOT(AddInterfaceProcess()));
    connect(ifSelectBox, SIGNAL(currentIndexChanged(int)), this, SLOT(ShowInterfaceDetail()));
}

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
void MainWindow::AddInterfaceProcess()
{
    size_t index = interfaces.size();
    InterfaceInfo interface;
    interfaces.push_back(interface);
    
    ifSelectBox->addItem("");
    ifSelectBox->setCurrentIndex(index);

    for (size_t i = 0; i < fieldNameEdit.size(); i++) {
        fieldNameEdit[i]->clear();
        fieldWidthEdit[i]->clear();
    }
    ShowInterfaceDetail();
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
    InterfaceInfo ifInfo = interfaces[index];

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

    leftLayout->addWidget(gbox, row, column);
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
       << " " << "repeat (" + ifInfo.name + "_dec::VLD2DATA_DLY) @vif.drv_cb;" << endl;

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
       << " " << "repeat (" + ifInfo.name + "_dec::VLD2DATA_DLY) @vif.mon_cb;" << endl;

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
string GetUtilsFilecontex(InterfaceInfo &ifInfo, string line)
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
void GenerateUtilFile(string projName, InterfaceInfo &ifInfo, string appendex)
{
    string iName = "demo/demo" + appendex + ".sv";
    string oName = projName + "/utils/" + ifInfo.name + "/" + ifInfo.name + appendex + ".sv";

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
	oFile << GetUtilsFilecontex(ifInfo, line) << endl;
    }
    iFile.close();
    oFile.close();
}

/*************************************************************
** Time        : 2022-08-17 10:43:54                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
void GenerateUtil(string projName, InterfaceInfo &ifInfo)
{
    string cmd = "mkdir -p " + projName + "/utils/" + ifInfo.name;
    FILE *fp = popen(cmd.c_str(), "w");
    pclose(fp);

    string appendex[] = {"_dec", "_xaction", "_interface", 
	"_agent", "_driver", "_monitor", "_sequence", "_sequencer"
    };
    size_t len = sizeof(appendex) / sizeof(appendex[0]);

    string fileName = projName + "/utils/" + ifInfo.name + "/" + ifInfo.name + ".f";
    ofstream oFile(fileName.c_str());
    oFile << "+incdir+." << endl;

    for (size_t i = 0; i < len; i++) {
	GenerateUtilFile(projName, ifInfo, appendex[i]);
        oFile << ifInfo.name << appendex[i] << ".sv" << endl;
    }
    oFile.close();
}

/*************************************************************
** Time        : 2022-08-17 10:41:19                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
void MainWindow::GenerateUtils()
{
    string projName = prjNameEdit->text().toStdString();
    if (projName.size() == 0) {
        cout << "Project Name if Empty!" << endl;
        return;
    }

    for (size_t i = 0; i < interfaces.size(); i++) {
	GenerateUtil(projName, interfaces[i]);
    }
}

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
string GetTopIncludeContext(vector<InterfaceInfo> &ifInfo)
{
    stringstream ss;
    ss << endl;

    for (size_t i = 0; i < ifInfo.size(); i++) {
        ss << "`include \"" << ifInfo[i].name << "_interface.sv\"" << endl;
    }

    return ss.str();
}

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
string GetTopDeclareContext(vector<InterfaceInfo> &ifInfo)
{
    stringstream ss;
    ss << endl;

    for (size_t i = 0; i < ifInfo.size(); i++) {
        ss << setw(4) << " " << "virtual " << setw(30) << std::left
           << ifInfo[i].name + "_interface" << " " << ifInfo[i].name
           << "_vif[" << ToUpper(ifInfo[i].name + "_NUM") << "];" << endl;
    }

    ss << endl;
    for (size_t i = 0; i < ifInfo.size(); i++) {
        ss << setw(4) << " " << setw(38) << std::left
           << ifInfo[i].name + "_interface" << " " << ifInfo[i].name
           << "_if[" << ToUpper(ifInfo[i].name + "_NUM") << "](clk, rst_n);"
           << endl;
    }

    ss << endl;
    ss << setw(4) << " " << "initial begin" << endl;
    for (size_t i = 0; i < ifInfo.size(); i++) {
        ss << setw(8) << " " << ifInfo[i].name + "_vif = "
           << ifInfo[i].name + "_if;" << endl;

        ss << setw(8) << " " << "foreach (" << ifInfo[i].name << "_vif[i]) begin"
           << endl << setw(12) << " " << "uvm_config_db#(virtual " << ifInfo[i].name
           << "_interface)::set(null, \"*\", $sformatf(\"" << ifInfo[i].name
           << "_interface[%0d]\", i), " << ifInfo[i].name << "_vif[i]);" << endl
           << setw(8) << " " << "end" << endl;
    }
    ss << setw(4) << " " << "end" << endl;

    return ss.str();
}

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
string GetEnvIncludeContext(vector<InterfaceInfo> &ifInfo)
{
    stringstream ss;
    ss << endl;

    for (size_t i = 0; i < ifInfo.size(); i++) {
        ss << "`include \"" << ifInfo[i].name << "_agent.sv\"" << endl;
    }

    return ss.str();
}

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
string GetEnvDeclareContext(vector<InterfaceInfo> &ifInfo)
{
    stringstream ss;
    ss << endl;

    for (size_t i = 0; i < ifInfo.size(); i++) {
        ss << setw(4) << " " << setw(30) << std::left
           << ifInfo[i].name +  "_agent" << " "
           << ifInfo[i].name << "_agt["  << ToUpper(ifInfo[i].name + "_NUM")
           << "];" << endl;
    }

    return ss.str();
}

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
string GetEnvBuildContext(vector<InterfaceInfo> &ifInfo)
{
    stringstream ss;
    ss << endl;

    for (size_t i = 0; i < ifInfo.size(); i++) {
        ss << setw(4) << " " << "foreach (" << ifInfo[i].name
           << "_agt[i]) begin " << endl
           << setw(8) << " " << ifInfo[i].name << "_agt[i] = "
           << ifInfo[i].name << "_agent::type_id::create($sformatf(\""
           << ifInfo[i].name << "_agt[%0d]\", i), this);" << endl
           << setw(8) << " " << ifInfo[i].name << "_agt[i].inst_id = i;" << endl
           << setw(4) << " " << "end" << endl;
    }

    return ss.str();
}

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
string GetEnvDecContext(vector<InterfaceInfo> &ifInfo)
{
    stringstream ss;
    ss << endl;

    for (size_t i = 0; i < ifInfo.size(); i++) {
        ss << setw(4) << " " << "parameter " << setw(20) << std::left
           << ToUpper(ifInfo[i].name + "_NUM") << " = "
           << ifInfo[i].fields[ifInfo[i].fields.size() - 1].width
           << ";" << endl;
    }

    return ss.str();
}

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
string GetEnvFilecontex(string moduleName, vector<InterfaceInfo> &ifInfo, string line)
{
    size_t pos;

    while ((pos = line.find("demo")) != string::npos) {
        line = line.replace(pos, 4, moduleName);
    }
    while ((pos = line.find("DEMO")) != string::npos) {
        line = line.replace(pos, 4, ToUpper(moduleName));
    }

    if ((pos = line.find("TIME_CONTEXT")) != string::npos) {
	line = line.replace(pos, 19, GetTimeContext());
    } else if ((pos = line.find("TOP_INCLUDE_CONTEXT")) != string::npos) {
        line = GetTopIncludeContext(ifInfo);
    } else if ((pos = line.find("TOP_DECLARE_CONTEXT")) != string::npos) {
        line = GetTopDeclareContext(ifInfo);
    } else if ((pos = line.find("ENV_INCLUDE_CONTEXT")) != string::npos) {
        line = GetEnvIncludeContext(ifInfo);
    } else if ((pos = line.find("ENV_DECLARE_CONTEXT")) != string::npos) {
        line = GetEnvDeclareContext(ifInfo);
    } else if ((pos = line.find("ENV_BUILD_CONTEXT")) != string::npos) {
        line = GetEnvBuildContext(ifInfo);
    } else if ((pos = line.find("DEC_ENV_CONTEXT")) != string::npos) {
        line = GetEnvDecContext(ifInfo);
    }

    return line;
}

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
void GenerateEnvFile(string projName, string moduleName, vector<InterfaceInfo> &ifInfo, string appendex)
{
    string iName = "demo/demo" + appendex + ".sv";
    string oName = projName + "/env/" + moduleName + appendex + ".sv";

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
	oFile << GetEnvFilecontex(moduleName, ifInfo, line) << endl;
    }
    iFile.close();
    oFile.close();
}

/*****************************************************************************
** Time        : TIME_CONTEXT                                               **
** Author      : generator                                                  **
** Description : Create                                                     **
*****************************************************************************/
void GenerateMakefile(string projName, string moduleName, vector<InterfaceInfo> &ifInfo)
{
    string iName = "demo/Makefile";
    string oName = projName + "/env/Makefile";

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
        if (line != "SRC_CONTEXT") {
            oFile << line << endl;
            continue;
        }

        stringstream ss;
        ss << "FILELIST :=\\" << endl;
        for (size_t i = 0; i < ifInfo.size(); i++) {
            ss << "\t-F ../utils/" << ifInfo[i].name << "/" << ifInfo[i].name 
               << ".f\\" << endl;
        }
        oFile << ss.str() << endl;
        oFile << endl << "SRCS := " << moduleName << "_top.sv" << endl;
    }
    oFile.close();
}

/*************************************************************
** Time        : 2022-08-17 10:41:32                        **
** Author      : ZhuHaiWen                                  **
** Description : Create                                     **
*************************************************************/
void MainWindow::GenerateEnvironment()
{
    string projName = prjNameEdit->text().toStdString();
    string moduleName = moduleNameEdit->text().toStdString();

    if (projName.size() == 0 || moduleName.size() == 0) {
        cout << "Project Name or Module Name is Empty!" << endl;
        return;
    }

    string cmd = "mkdir -p " + projName + "/env";
    FILE *fp = popen(cmd.c_str(), "w");
    pclose(fp);

    string appendex[] = {"_env_dec", "_env", "_rm", "_e2e_chk",
        "_top", "_tc", "_model"
    };
    size_t len = sizeof(appendex) / sizeof(appendex[0]);

    for (size_t i = 0; i < len; i++) {
	GenerateEnvFile(projName, moduleName, interfaces, appendex[i]);
    }

    GenerateMakefile(projName, moduleName, interfaces);
}
