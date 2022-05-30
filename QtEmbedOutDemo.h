#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtEmbedOutDemo.h"
#include "EmbedThread.h"
#include "EmbedThreadSev.h"
#include <QProcess>
#include <QMessageBox>
#include <QWindow>
#include <QWidget>

class QtEmbedOutDemo : public QMainWindow
{
    Q_OBJECT

public:
    QtEmbedOutDemo(QWidget *parent = Q_NULLPTR);
    ~QtEmbedOutDemo();
    void initIpc();
    bool startEmbed(QString exePath);

signals:
   void updateEmbedThread();
   void updateFusionError();
   void updateFusionError2();
   void startEmbed(qint64 _chlidProcessid);
	
public slots:
    void on_processStarted(qint64 _chlidProcessid);
    void on_sendClicked();
    void on_revDataFunc(QString msg);

public:
    void closeEvent(QCloseEvent* event);
private:
	bool _launchExternalSoftware(QString exePath);
    void _clearProcessByProcessName(qint64 processid);

private:
    Ui::QtEmbedOutDemoClass ui;
    EmbedThreadSev* m_pfthrdsev;
	EmbedThread* m_pfthrd;
    QProcess* m_process;
    QWindow* m_window;
    QWidget* m_widget;
    BOOL     startret;
    qint64   m_chlidProcessid;
	PROCESS_INFORMATION pi;
};
