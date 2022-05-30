#include "EmbedThread.h"

using namespace std;

EmbedThread::EmbedThread(QObject* parent)
	:QThread(parent)
{
	  m_hPipe_ =NULL;
	  m_bconnected_ = false;
	  m_bend_ = false;
}

EmbedThread::~EmbedThread()
{
	if (m_hPipe_)
	{
		DisconnectNamedPipe(m_hPipe_);
		CloseHandle(m_hPipe_);
	}
}

void EmbedThread::Stop()
{
	qDebug() << "Worker Stop Thread : " << QThread::currentThreadId();
	QMutexLocker locker(&m_mutex_);
	m_bend_ = true;
}

void EmbedThread::run()
{
	while(!m_bend_)
	{
		//创建管道
		do 
		{
			if (!m_bconnected_)
			{
				if (!WaitNamedPipe(TEXT("//./pipe/QInPipe"),1))
				{
					qDebug() << "no available pipe QInPipe.";
					break;
				}

				m_hPipe_ = CreateFile(TEXT("//./pipe/QInPipe"), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
				if (INVALID_HANDLE_VALUE == m_hPipe_)
				{
					qDebug() << "open pipe failed QInPipe.";
					if (m_hPipe_)
					{
						CloseHandle(m_hPipe_);
						m_hPipe_ = NULL;
					}
					break;
				}
				qDebug() << "connect pipe QInPipe success.";
				m_bconnected_ = true;
				break;
			}

			//读数据
			char buftmp[100];
			char buf[100];
			DWORD dwRead;
			if (!ReadFile(m_hPipe_, buftmp, 100, &dwRead, NULL))
			{
				sleep(1000);
				break;
			}
			
			strncpy_s(buf, buftmp, dwRead);
			qDebug() << "read from QInPipe:" << QString(buf).simplified();
			// 发送信号
			emit EmbedThreadSignal(QString(buf).simplified());
		} while (0);
		
	}
}

void EmbedThread::EmbedThreadSlotEnd()
{
	qDebug() << "EmbedThreadSlotEnd() start to execute";
	qDebug() << "current thread ID:" << QThread::currentThreadId() << '\n';
	QMutexLocker locker(&m_mutex_);
	m_bend_= true;
}

void EmbedThread::EmbedThreadSlotRv()
{
	qDebug() << "client EmbedThreadSlotRv() current thread ID:" << QThread::currentThreadId() << '\n';
	char buf[]="hello,world from client.";
    DWORD dwWrite;
	try
	{
		if (m_hPipe_)
		{
			if (!WriteFile(m_hPipe_, buf, strlen(buf) + 1, &dwWrite, NULL))
			{
				qDebug() << "write data failed.";
				return;
			}
		}
	}
	catch (exception e)
	{
		qDebug() << e.what();
	}
}


