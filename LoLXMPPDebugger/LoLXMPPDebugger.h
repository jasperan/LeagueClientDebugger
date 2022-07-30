#pragma once

#include <QtWidgets/QMainWindow>
#include <QDateTime>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QtCore>
#include <QTcpSocket>
#include <QTcpServer>
#include <QNetworkProxy>
#include <QProcess>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>

#include "ui_LoLXMPPDebugger.h"

class LoLXMPPDebugger : public QMainWindow
{
	Q_OBJECT

public:
	LoLXMPPDebugger(QWidget* parent = Q_NULLPTR);
	~LoLXMPPDebugger();

private slots:
	void on_pushButton_clicked();
	void on_pushButton_LaunchLeague_clicked();

	void on_outgoingScrollToBottom_toggled(bool);
	void on_incomingScrollToBottom_toggled(bool);

	void on_outgoingButtonClear_clicked();
	void on_incomingButtonClear_clicked();

	void on_actionExit_triggered();
	void on_actionAbout_triggered();
	void on_actionOutgoing_triggered();
	void on_actionIncoming_triggered();
	void on_actionBoth_triggered();
	void on_actionChoose_directory_triggered();
	void onNewConnection();
	void onSocketStateChanged(QAbstractSocket::SocketState socketState);
	void onReadyRead();
	void onFinishRequest(QNetworkReply* response);
private:
	Ui::LoLXMPPDebuggerClass ui;

	QDateTime startTime;
	QString saveDir;
	QTcpSocket* socket;
	QTcpServer* server;
	QTcpSocket* leagueSocket;
	int port;
	int chatPort;

	QList<QTcpSocket*>clients;

	QString clientConfigUrl = "https://clientconfig.rpg.riotgames.com";
	QString geoPasUrl = "https://riot-geo.pas.si.riotgames.com/pas/v1/service/chat";
	int counter = 0;
};