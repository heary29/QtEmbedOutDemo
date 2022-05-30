#ifndef EMBED_THREADSEV_H
#define EMBED_THREADSEV_H
#include <QThread>
#include <QDebug>
#include <QMessageBox>
#include <QMutexLocker>

#include<Windows.h>

class EmbedThreadSev :public QThread
{
	Q_OBJECT
public:
	EmbedThreadSev(QObject* parent = nullptr);
	~EmbedThreadSev();
	void Stop();

signals:
	//void EmbedThreadSevSevSignal(const int);
	//void updateEmbedError(QString);
	//×Ô¶¨Òå²Û
public slots:
	void EmbedThreadSevCreate();
	void EmbedThreadSevSlotSevEnd();
	void EmbedThreadSevSlotSend();
protected:
	void run() override;
private:
	HANDLE m_hPipe_, handleEvent;
	OVERLAPPED  op;
	bool m_bconnected_;
	volatile bool m_bend_;
	QMutex m_mutex_;
	int  _index_;
};

#endif // Embed_THREAD_H

