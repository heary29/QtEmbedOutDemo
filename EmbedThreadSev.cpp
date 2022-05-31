#include "EmbedThreadSev.h"

using namespace std;

EmbedThreadSev::EmbedThreadSev(QObject* parent)
	:QThread(parent)
{
	  m_hPipe_ =NULL;
	  m_bconnected_ = false;
	  m_bend_ = false;
	  _index_ = 0;
}

EmbedThreadSev::~EmbedThreadSev()
{
	if (m_hPipe_)
	{
		DisconnectNamedPipe(m_hPipe_);
		CloseHandle(m_hPipe_);
	}
}

void EmbedThreadSev::Stop()
{
	qDebug() << "Worker Stop Thread : " << QThread::currentThreadId();
	QMutexLocker locker(&m_mutex_);
	m_bend_ = true;
}

void EmbedThreadSev::run()
{
	while(!m_bend_)
	{
		//创建管道
		do 
		{
			if (!m_bconnected_)
			{
				if (m_hPipe_ == nullptr)
				{
					m_hPipe_ = CreateNamedPipe(TEXT("//./pipe/QOutPipe"), PIPE_ACCESS_DUPLEX, 0, 1, 0, 0, 1000, NULL);
					if (INVALID_HANDLE_VALUE == m_hPipe_)
					{
						m_hPipe_ = NULL;
						qDebug() << "CreateNamedPipe QOutPipe failed!";
						break;
					}
				}

				qDebug() << "Server is now running ......";
				if (m_hPipe_ != nullptr && ConnectNamedPipe(m_hPipe_, NULL) == 0) // 等待客户机的连接
				{
					qDebug() << "ConnectNamedPipe QOutPipe failed!";
					CloseHandle(m_hPipe_);
					
				}
				else
				{
					qDebug() << "ConnectNamedPipe QOutPipe success!\n";
					m_bconnected_ = true;
					return;
				}
			}
		} while (0);
	}
}


void EmbedThreadSev::EmbedThreadSevSlotSevEnd()
{
	qDebug() << "EmbedThreadSevSlotSevEnd() end";
	qDebug() << "current thread ID:" << QThread::currentThreadId() << '\n';
	m_bend_ = true;
	if (m_hPipe_)
		DisconnectNamedPipe(m_hPipe_);
	
}

void EmbedThreadSev::EmbedThreadSevCreate()
{
	//bconnected = true;
}

void EmbedThreadSev::EmbedThreadSevSlotSend()
{
	qDebug() << "server current thread ID:" << QThread::currentThreadId() << '\n';
	//sleep(1000);
	char buf[] = "hello from outter";
	char ss[32] = {0};
	itoa(_index_++, ss, 10);
	strcat(buf, ss);
	strcat(buf, "\n");
    DWORD dwWrite;
	try
	{
		if (m_hPipe_ && m_bconnected_)
		{
			if (!WriteFile(m_hPipe_, buf, strlen(buf) + 1, &dwWrite, NULL))
			{
				qDebug() << "send named pipe data failed!";
				return;
			}
		}
	}
	catch (exception e)
	{
		qDebug() << e.what();
	}
}


