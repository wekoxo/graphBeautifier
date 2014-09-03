#pragma once

#include <QtCore/QTranslator>
#include <QtWidgets/QMenu>

#include "../../qrkernel/ids.h"
#include "../../qrutils/metamodelGeneratorSupport.h"
#include "toolPluginInterface/toolPluginInterface.h"
#include "toolPluginInterface/pluginConfigurator.h"
#include "../../qrgui/mainwindow/errorReporter.h"

namespace qReal {
namespace graphBeautifier {

class GraphBeautifierPlugin : public QObject, public qReal::ToolPluginInterface
{
	Q_OBJECT
	Q_INTERFACES(qReal::ToolPluginInterface)
    Q_PLUGIN_METADATA(IID "qReal.graphBeautifier.GraphBeautifierPlugin")

public:
    GraphBeautifierPlugin();
    virtual ~GraphBeautifierPlugin();

	virtual void init(qReal::PluginConfigurator const &configurator);
	virtual QList<qReal::ActionInfo> actions();

	// virtual QPair<QString, PreferencesPage *> preferencesPage();

private:
	LogicalModelAssistInterface *mLogicalModelApi;
	GraphicalModelAssistInterface *mGraphicalModelApi;

	gui::MainWindowInterpretersInterface *mMainWindowIFace;
	QString mQRealSourceFilesPath;
	QString mPathToRefactoringExamples;

	QAction mAction;

private slots:
	void beautify();

};
}
}
