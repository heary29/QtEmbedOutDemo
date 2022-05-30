#ifndef EMBED_THREAD_H
#define EMBED_THREAD_H
#include <QThread>
#include <QDebug>
#include <QMessageBox>
#include <QMutexLocker>

#include<Windows.h>

class EmbedThread :public QThread
{
	Q_OBJECT
public:
	EmbedThread(QObject* parent = nullptr);
	~EmbedThread();
	void Stop();
	//static EmbedThread* _cur;

signals:
	void EmbedThreadSignal(QString msg);
	
public slots:
	void EmbedThreadSlotEnd();
	void EmbedThreadSlotRv();
protected:
	void run() override;
private:

	HANDLE m_hPipe_;
	bool m_bconnected_;
	volatile bool m_bend_;
	QMutex m_mutex_;
};

#endif // Embed_THREAD_H

