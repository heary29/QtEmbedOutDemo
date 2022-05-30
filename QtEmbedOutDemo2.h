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
	
public slots:
    void on_processStarted();
    void on_sendClicked();
    void on_revDataFunc(QString msg);

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
   // WId    wid;
};
