#pragma once

#ifndef DAZ_TEST_PANE_H
#define DAZ_TEST_PANE_H

/*****************************
   Include files
*****************************/
#include "dzpane.h"
#include "dzaction.h"
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <dzcontentmgr.h>

/****************************
   Forward declarations
****************************/
static QListWidget*	g_ListWidgetFile;
static QListWidget* g_ListWidgetTarget;
static QLabel*		g_LabelPrevious;
static QLabel*		g_LabelNext;
static QLabel*		g_LabelCurrent;
static QLineEdit*	g_LineEditCurrent;
static QLineEdit*	g_LineEditFolder;


/*****************************
   Class definitions
*****************************/

class SequentialLoadProcessing : public QObject
{
	Q_OBJECT
private:
	int nCurrent;

public:
	/** Constructor **/
	SequentialLoadProcessing();
	/** Destructor **/
	virtual ~SequentialLoadProcessing() {}

	void setCurrent(int nStartCurrent);
	void textChange();
	void loadDazFile(int nNumber);
	void setCurrentText(QString sText);

public slots:
	void previous();
	void next();
};


class SequentialLoadActionNext : public DzAction {
	Q_OBJECT
public:

	/** Constructor **/
	SequentialLoadActionNext();

	/** Destructor **/
	virtual ~SequentialLoadActionNext() {}

	/**
		We need to reimplement these virtual functions to provide defaults for our
		'action'. These get called by DzActionMgr during initialization. The user's
		settings file is then processed for customization.
	**/
	virtual QString			getActionGroup() const { return tr("Sequential Load"); }
	virtual QKeySequence	getDefaultAccel() const { return Qt::Key_Slash; }

	/**
		We need to reimplement this virtual function to perform our 'action'.
		This gets called whenever the user clicks on our action item.
	**/
	virtual void			executeAction();
};


class SequentialLoadActionPrevious : public DzAction {
	Q_OBJECT
public:

	/** Constructor **/
	SequentialLoadActionPrevious();

	/** Destructor **/
	virtual ~SequentialLoadActionPrevious() {}

	/**
		We need to reimplement these virtual functions to provide defaults for our
		'action'. These get called by DzActionMgr during initialization. The user's
		settings file is then processed for customization.
	**/
	virtual QString			getActionGroup() const { return tr("Sequential Load"); }
	virtual QKeySequence	getDefaultAccel() const { return Qt::Key_Backslash; }

	/**
		We need to reimplement this virtual function to perform our 'action'.
		This gets called whenever the user clicks on our action item.
	**/
	virtual void			executeAction();
};


/**
	This class is the menu action that will toggle the pane on/off in the interface
**/
class SequentialLoadPaneAction : public DzPaneAction {
	Q_OBJECT
public:
	SequentialLoadPaneAction() : DzPaneAction("SequentialLoadPane") { }
};


/**
	This class is the interface pane
**/
class SequentialLoadPane : public DzPane {
	Q_OBJECT
public:
	//
	// CREATORS
	//

	SequentialLoadPane();
	~SequentialLoadPane();

public slots:
	void	selectFolder();
	void	listBoxClicked();
	void	listFigure();

private:

	int		loadPath();
	bool	savePath();
	int		addList();
};

#endif // DAZ_TEST_PANE_H