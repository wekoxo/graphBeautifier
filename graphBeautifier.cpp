#include "graphBeautifier.h"

#include <QtCore/QProcess>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>

#include "../../qrutils/xmlUtils.h"
#include "../../qrutils/outFile.h"
#include "../../qrkernel/settingsManager.h"

// Q_EXPORT_PLUGIN2(<graphBeautifier>, <graphBeautifier::GraphBeautifier>);

using namespace qReal;
using namespace graphBeautifier;

GraphBeautifierPlugin::GraphBeautifierPlugin()
    : mAction(NULL)
{
	connect(&mAction, SIGNAL(triggered()), this, SLOT(beautify()));
}

GraphBeautifierPlugin::~GraphBeautifierPlugin()
{
}

void GraphBeautifierPlugin::init(PluginConfigurator const &configurator)
{
    mLogicalModelApi = &configurator.logicalModelApi();
	mGraphicalModelApi = &configurator.graphicalModelApi();

    mMainWindowIFace = &configurator.mainWindowInterpretersInterface();

}

QList<qReal::ActionInfo> GraphBeautifierPlugin::actions()
{
    mAction.setText(tr("Beautify"));
    ActionInfo generateEditorForQrxcActionInfo(&mAction, "generators", "tools");

    return QList<ActionInfo>() << generateEditorForQrxcActionInfo;

}

void GraphBeautifierPlugin::beautify()
{
    IdList const childrenIDs = mLogicalModelApi->children(Id::rootId());
//	QHash<QString, IdList> diagramIds;
//	foreach(Id const &childId, childrenIDs) {
//		if (childId == mMainWindowIFace->activeDiagram())
//		{
//			QString elementName = mGraphicalModelApi->name(childId).replace(" ", "")
//				.replace("(", "").replace(")", "");
//			if (!elementName.isEmpty())
//			{
//                IdList list;
//				list << childId;
//                diagramIds.insert("Filename.qrs", list);
//			}
//		}
//	}

}
