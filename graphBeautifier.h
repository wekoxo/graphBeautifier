#pragma once

#include <QtWidgets/QMenu>

#include "../../../qrgui/toolPluginInterface/toolPluginInterface.h"
#include "../../../qrgui/toolPluginInterface/pluginConfigurator.h"

namespace qReal {
namespace graphBeautifier {

class GraphBeautifier : public QObject, public qReal::ToolPluginInterface
{
	Q_OBJECT
	Q_INTERFACES(qReal::ToolPluginInterface)

public:
	GraphBeautifier();
	virtual ~GraphBeautifier();

	virtual void init(qReal::PluginConfigurator const &configurator);
	virtual QList<qReal::ActionInfo> actions();

	// virtual QPair<QString, PreferencesPage *> preferencesPage();

private:
	LogicalModelAssistInterface *mLogicalModelApi;
	GraphicalModelAssistInterface *mGraphicalModelApi;
	QAction mAction;

private slots:
	void beautify();

};
}
}