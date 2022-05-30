#include "QtEmbedOutDemo.h"
#include "QtEmbedOutDemo1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
#if (QT_VERSION >= QT_VERSION_CHECK(5,6,0))
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
	QApplication a(argc, argv);

	//QtEmbedOutDemo1 w;
	QtEmbedOutDemo w;
	w.startEmbed(nullptr);
	w.show();
	return a.exec();
}
