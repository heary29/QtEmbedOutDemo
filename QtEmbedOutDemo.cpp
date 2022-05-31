#include "QtEmbedOutDemo.h"
#include "getWindowUtil.h"
#include <qDebug>


QtEmbedOutDemo::QtEmbedOutDemo(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	m_process = nullptr;
	initIpc();
}

QtEmbedOutDemo::~QtEmbedOutDemo()
{
	if (m_process)
	{
		_clearProcessByProcessName(m_process->processId());
		delete m_process;
		m_process = nullptr;
	}

	if (m_pfthrd)
	{
		m_pfthrd->Stop();
		m_pfthrd->exit(0);
		m_pfthrd->terminate();
		m_pfthrd->wait();
	}

	if (m_pfthrdsev)
	{
		m_pfthrdsev->Stop();
		m_pfthrdsev->exit(0);
		m_pfthrdsev->terminate();
		m_pfthrd->wait();

	}
}

void QtEmbedOutDemo::initIpc()
{
	connect(ui.pushButton_send, SIGNAL(clicked()), this, SLOT(on_sendClicked()));

	//heary
	m_pfthrdsev = new EmbedThreadSev(this);
	if (m_pfthrdsev)
	{
		//QObject::connect(this, SIGNAL(fusionCreateThreadSev()), m_pfthrdsev, SLOT(FusionThreadSevCreate()), Qt::QueuedConnection);
		QObject::connect(this, SIGNAL(updateEmbedThread()), m_pfthrdsev, SLOT(EmbedThreadSevSlotSend()), Qt::QueuedConnection);
		//QObject::connect(m_pfthrdsev, SIGNAL(updateFusionError(QString)), this, SLOT(showTestMsg(QString)), Qt::QueuedConnection);
		m_pfthrdsev->start();
	}

	//heary
	m_pfthrd = new EmbedThread(this);
	if (m_pfthrd)
	{
		QObject::connect(m_pfthrd, SIGNAL(EmbedThreadSignal(QString)), this, SLOT(on_revDataFunc(QString)), Qt::QueuedConnection);
		//m_pfthrd->start();
	}
}

bool QtEmbedOutDemo::startEmbed(QString exePath)
{
	//QString exePaths = "D:\\CMake\\bin\\cmake-gui.exe";
	//QString exePaths = "C:\\Users\\yangchunhai-ls\\Desktop\\Release0523\\Release\\MeshLab\\meshlab.exe";
	//QString exePaths = "E:\\Codes\\meshlabsvnLocal2\\meshlab\\src\\distrib\\meshlab.exe";
	QString exePaths = "E:/Codes/meshlabsvnLocal2/meshlab/src/distrib/meshlab.exe";
	//QString exePaths = "D:\\LargeV\\FusionAnalyser\\FusionAnalyser.exe";
	//QString exePaths = "D:/Notepad++/notepad++.exe";
	//QString exePaths = QCoreApplication::applicationDirPath()+ "/MeshLab/meshlab.exe";

	return _launchExternalSoftware(exePaths);
}

void QtEmbedOutDemo::_clearProcessByProcessName(qint64 processid)
{
	QString strCmdLine = QString("TASKKILL /IM %1 /F").arg(processid);
	int nExitCode = QProcess::execute(strCmdLine);
}

//启动外部程序
bool QtEmbedOutDemo::_launchExternalSoftware(QString exePath)
{
	//启动外部程序
	m_process = new QProcess(this);
	connect(m_process, &QProcess::started, this, &QtEmbedOutDemo::on_processStarted);

	QString exeName = exePath.mid(exePath.lastIndexOf("/"));
	std::string str = exeName.mid(1).toStdString();
	const char* ch = str.c_str();
	qint64 processid = GetProcessidFromName(ch);
	if (processid > 0)
		_clearProcessByProcessName(processid);

	m_process->setCreateProcessArgumentsModifier([](QProcess::CreateProcessArguments* args) {
		args->startupInfo->wShowWindow = SW_HIDE;
		args->startupInfo->dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
		});
	m_process->start(exePath, QStringList());
	return true;


	/*QString program = exePath;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	si.cb = sizeof(STARTUPINFO);
	GetStartupInfo(&si);
	si.wShowWindow = SW_HIDE;
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;

	if (!CreateProcess(NULL, (LPWSTR)program.utf16(), NULL, NULL, TRUE, NULL, NULL, NULL, &si, &pi))
	{
		qDebug() << "create process fail";
	}
	return true;*/


	/*QString program = exePath.toLatin1();
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	si.dwFlags = STARTF_USESHOWWINDOW ;
	si.wShowWindow = false;
	CreateProcess(NULL, (LPWSTR)program.toStdWString().c_str(), NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	return true;*/
	
}

//嵌入外部程序
void QtEmbedOutDemo::on_processStarted()
{
	qint64 id = 0;
	if (m_process)
	{
		id = m_process->processId();//如果程序没有运行，将会返回0
		if (id == 0)
		{
			QMessageBox::information(NULL, "提示", "程序没有启动");
			return;
		}
	}
	
	Sleep(1500);
	qDebug() << "Status: " << m_process->state();
	HWND mainwindowHwnd = nullptr;
	for (int i = 0; i < 20; i++)
	{
		mainwindowHwnd = FindMainWindow(id);
		qDebug() << "mainwindowHwnd: " << mainwindowHwnd;
		if (mainwindowHwnd)
			break;
	}
	if (mainwindowHwnd == nullptr)
	{
		QMessageBox::information(NULL, "提示", "获取程序句柄失败");
		return;
	}

	m_window = QWindow::fromWinId((WId)mainwindowHwnd);//windows的代理窗口
	m_window->setFlags(Qt::FramelessWindowHint);//去除窗口

	m_widget = new QWidget(this);
	m_widget = QWidget::createWindowContainer(m_window, ui.centralWidget);//窗口封装为一个QWidget控件
	m_widget->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
	m_widget->adjustSize();
	ui.verticalLayout->addWidget(m_widget);
	
	if (m_pfthrd)
		m_pfthrd->start();

}

void QtEmbedOutDemo::on_sendClicked()
{
	emit updateEmbedThread();
}

void QtEmbedOutDemo::on_revDataFunc(QString msg)
{
	ui.label_rev->clear();
	ui.label_rev->setText(msg);
	ui.label_rev->update();
}



