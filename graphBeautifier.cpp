#include "graphBeautifier.h"

// Q_EXPORT_PLUGIN2(<graphBeautifier>, <graphBeautifier::GraphBeautifier>);

using namespace qReal;
using namespace graphBeautifier;

GraphBeautifier::GraphBeautifier()
	: mAction(tr("beautify"), NULL)
{
	connect(&mAction, SIGNAL(triggered()), this, SLOT(beautify()));
}

GraphBeautifier::~GraphBeautifier()
{
}

void GraphBeautifier::init(PluginConfigurator const &configurator)
{
	// mErrorReporter = configurator.mainWindowInterpretersInterface().errorReporter(); //it possible to not work. if so -- add it.
	mLogicalModelApi = &configurator.logicalModelApi();
	mGraphicalModelApi = &configurator.graphicalModelApi();

}

QList<qReal::ActionInfo> GraphBeautifier::actions()
{
	qReal::ActionInfo info(&mAction, "file", "tools");
	QList<qReal::ActionInfo> result;
	result << info;
	return result;
}

void GraphBeautifier::beautify()
{

}
