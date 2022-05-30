#include "QtEmbedOutDemo1.h"
#include "getWindowUtil.h"
#include <qDebug>


QtEmbedOutDemo1::QtEmbedOutDemo1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	m_process = nullptr;
	startret = FALSE;
	m_chlidProcessid = 0;
	initIpc();
}

QtEmbedOutDemo1::~QtEmbedOutDemo1()
{
	//_clearProcessByProcessName();
	TerminateProcess(pi.hProcess, 0);//终止进程
	::CloseHandle(pi.hThread);
	::CloseHandle(pi.hProcess);

	//_clearProcessByProcessName(m_chlidProcessid);

	/*if (m_process)
	{
		m_process->terminate();
		delete m_process;
		m_process = nullptr;
	}*/
	
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

void QtEmbedOutDemo1::initIpc()
{
	connect(ui.pushButton_send, SIGNAL(clicked()), this, SLOT(on_sendClicked()));

	//heary
	m_pfthrdsev = new EmbedThreadSev(this);
	if (m_pfthrdsev)
	{
		//QObject::connect(this, SIGNAL(fusionCreateThreadSev()), m_pfthrdsev, SLOT(FusionThreadSevCreate()), Qt::QueuedConnection);
		QObject::connect(this, SIGNAL(updateEmbedThread()), m_pfthrdsev, SLOT(EmbedThreadSevSlotSend()), Qt::QueuedConnection);
		QObject::connect(this, SIGNAL(updateFusionError()), m_pfthrdsev, SLOT(EmbedThreadSevSlotSevEnd()), Qt::QueuedConnection);
		m_pfthrdsev->start();
	}

	//heary
	m_pfthrd = new EmbedThread(this);
	if (m_pfthrd)
	{
		QObject::connect(m_pfthrd, SIGNAL(EmbedThreadSignal(QString)), this, SLOT(on_revDataFunc(QString)), Qt::QueuedConnection);
		QObject::connect(this, SIGNAL(updateFusionError2()), m_pfthrd, SLOT(EmbedThreadSlotEnd()), Qt::QueuedConnection);
		//m_pfthrd->start();
	}
}

bool QtEmbedOutDemo1::startEmbed(QString exePath)
{
	//QString exePaths = "D:/Notepad++/notepad++.exe";
	//QString exePaths = "D:/Everything/Everything.exe";
	//QString exePaths = "D:\\CMake\\bin\\cmake-gui.exe";
	//QString exePaths = "C:\\Users\\yangchunhai-ls\\Desktop\\Release0523\\Release\\MeshLab\\meshlab.exe";
	//QString exePaths = "E:\\Codes\\meshlabsvnLocal2\\meshlab\\src\\distrib\\meshlab.exe";
	//QString exePaths = "E:/Codes/meshlabsvnLocal2/meshlab/src/distrib/meshlab.exe";
	//QString exePaths = "D:\\LargeV\\FusionAnalyser\\FusionAnalyser.exe";
	QString exePaths = QCoreApplication::applicationDirPath() + "/MeshLab/meshlab.exe";
	return _launchExternalSoftware(exePaths);
}

void QtEmbedOutDemo1::_clearProcessByProcessName(qint64 processid)
{
	QString strCmdLine = QString("TASKKILL /IM %1 /F").arg(processid);
	int nExitCode = QProcess::execute(strCmdLine);
}

//启动外部程序
bool QtEmbedOutDemo1::_launchExternalSoftware(QString exePath)
{
	//启动外部程序
	connect(this, SIGNAL(startEmbed(qint64)), this, SLOT(on_processStarted(qint64)));
	//m_process->setParent(this);
	/*QStringList arg;
	arg << "";*/
	QString exeName = exePath.mid(exePath.lastIndexOf("/"));
	std::string strr = exeName.mid(2).toStdString();
	const char* ch = strr.c_str();
	qint64 processid = GetProcessidFromName(ch);
	if (processid > 0)
		_clearProcessByProcessName(processid);

	STARTUPINFO si;
	si.cb = sizeof(STARTUPINFO);
	si.lpReserved = NULL;
	si.lpDesktop = NULL;
	si.lpTitle = NULL;
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	si.wShowWindow = SW_HIDE | SW_MINIMIZE;
	si.cbReserved2 = NULL;
	si.lpReserved2 = NULL;
	std::wstring str = exePath.toStdWString();
	startret = CreateProcess(NULL, (LPTSTR)str.c_str(), NULL, NULL, FALSE, CREATE_SUSPENDED | CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
	if (!startret)
	{
		qDebug() << "create process fail";
		return false;
	}
	m_chlidProcessid = pi.dwProcessId;
	emit startEmbed(m_chlidProcessid);
	if (m_pfthrd)
		m_pfthrd->start();
	return true;
}

//嵌入外部程序
void QtEmbedOutDemo1::on_processStarted(qint64 _chlidProcessid)
{
	if (_chlidProcessid == 0)
	{
		QMessageBox::information(NULL, "提示", "程序没有启动");
		return;
	}


	HWND mainwindowHwnd = nullptr;
	for (int i= 0; i < 20; i++)
	{
		mainwindowHwnd = FindMainWindow(_chlidProcessid);
		qDebug() << "mainwindowHwnd: " << mainwindowHwnd;
		if (mainwindowHwnd)
			break;
	}

	::ResumeThread((HANDLE)pi.hThread);
	Sleep(2500);

	/*HWND mainwindowHwnd = nullptr;
	while (true)
	{
		HWND mainwindowHwnd = FindMainWindow(_chlidProcessid);
		qDebug() << "mainwindowHwnd: " << mainwindowHwnd;
		if (!mainwindowHwnd)
		{
			qDebug() << "get handle fail";
		}
		else
		{
			qDebug() << "get handle success";
			break;
		}
	}*/
	

	//test1
	//ShowWindow(mainwindowHwnd, SW_HIDE);
	//WId wid = (WId)mainwindowHwnd;
	//m_window = QWindow::fromWinId(wid);
	//m_widget = QWidget::createWindowContainer(m_window); //第二个参数是作为window的父类，也可以用layout，此处就不解
	//ui.scrollArea->setWidget(m_widget);
	//ui.scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);


	//test2
	m_window = new QWindow();
	m_window = QWindow::fromWinId((WId)mainwindowHwnd);//windows的代理窗口
	m_window->setFlags(Qt::FramelessWindowHint);//去除窗口

	m_widget = new QWidget(this);
	m_widget = QWidget::createWindowContainer(m_window, ui.centralWidget);//窗口封装为一个QWidget控件
	m_widget->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
	m_widget->adjustSize();
	ui.verticalLayout->addWidget(m_widget);
}

void QtEmbedOutDemo1::on_sendClicked()
{
	emit updateEmbedThread();
}

void QtEmbedOutDemo1::on_revDataFunc(QString msg)
{
	ui.label_rev->clear();
	ui.label_rev->setText(msg);
	ui.label_rev->update();
}

void QtEmbedOutDemo1::closeEvent(QCloseEvent* event)
{
	emit updateFusionError();
	emit updateFusionError2();
}


