/**********************************************************************
	Copyright (C) 2002-2012 DAZ 3D, Inc. All Rights Reserved.

	This file is part of the DAZ Studio SDK.

	This file may be used only in accordance with the DAZ Studio SDK 
	license provided with the DAZ Studio SDK.

	The contents of this file may not be disclosed to third parties, 
	copied or duplicated in any form, in whole or in part, without the 
	prior written permission of DAZ 3D, Inc, except as explicitly
	allowed in the DAZ Studio SDK license.

	See http://www.daz3d.com to contact DAZ 3D, Inc or for more 
	information about the DAZ Studio SDK.
**********************************************************************/

/*****************************
   Include files
*****************************/
#include "SequentialLoad.h"

#include <QtCore/QObject>
#include <QtCore/qiodevice>
#include <QtGui/QVBoxLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QPushButton>

#include "dzapp.h"
#include "dzscene.h"
#include "dzfacetmesh.h"
#include "dzstyle.h"
#include <dzskeleton.h>

static const int c_minWidth = 200;
static const int c_minHeight = 150;
static SequentialLoadProcessing *oSLP = new SequentialLoadProcessing();

SequentialLoadProcessing::SequentialLoadProcessing() : QObject()
{
	nCurrent = -1;
}

void SequentialLoadProcessing::setCurrent(int nStartCurrent)
{
	nCurrent = nStartCurrent;
}

void SequentialLoadProcessing::setCurrentText(QString sText)
{
	g_LabelCurrent->setText(sText);
	int nStart = sText.indexOf("_");
	int nEnd = sText.indexOf("_", nStart+1);
	g_LineEditCurrent->setText(sText.mid(nStart+1, nEnd-nStart-1));
}

void SequentialLoadProcessing::textChange()
{
	if (g_LineEditFolder->text().length() > 0) {
		if (nCurrent < 0 || nCurrent == 0)
		{
			g_LabelPrevious->setText(g_ListWidgetFile->item(g_ListWidgetFile->count() - 1)->text());
			if(nCurrent == 0)
			{
				setCurrentText(g_ListWidgetFile->item(0)->text());
				g_LabelNext->setText(g_ListWidgetFile->item(1)->text());
			}
			else
			{
				setCurrentText("[void]");
				g_LabelCurrent->setText("[void]");
				g_LabelNext->setText(g_ListWidgetFile->item(0)->text());
			}
		}
		else
		{
			g_LabelPrevious->setText( g_ListWidgetFile->item(nCurrent - 1)->text() );
			setCurrentText( g_ListWidgetFile->item(nCurrent)->text() );

			if( nCurrent == g_ListWidgetFile->count()-1 )
			{
				g_LabelNext->setText(g_ListWidgetFile->item(0)->text());
			}
			else
			{
				g_LabelNext->setText(g_ListWidgetFile->item(nCurrent + 1)->text());
			}
		}
	}
}

void SequentialLoadProcessing::loadDazFile(int nNumber)
{
	nCurrent = nNumber;
	if (g_ListWidgetFile != NULL && g_LineEditFolder != NULL && nNumber >= 0)
	{
		if (g_ListWidgetFile->count() > nNumber) {
			QString sLoadName = (g_LineEditFolder->text()) + "/" + (g_ListWidgetFile->item(nNumber)->text());

			if (g_ListWidgetTarget->currentRow() >= 0)
			{
				DzNode* tempNode = dzScene->getSelectedNode(0);
				DzSkeleton* tempSkeleton = dzScene->findSkeletonByLabel( g_ListWidgetTarget->currentItem()->text() );

				if (tempNode != NULL)
				{
					tempNode->select(false) ;
				}
				if (tempSkeleton != NULL)
				{
					tempSkeleton->select(true);
				}

				dzApp->getContentMgr()->openFile(sLoadName);

				if (tempSkeleton != NULL)
				{
					tempSkeleton->select(false);
				}
				if (tempNode != NULL)
				{
					tempNode->select(true);
				}

			}
			else
			{
				dzApp->getContentMgr()->openFile(sLoadName);
			}

		}
	}
}

void SequentialLoadProcessing::previous()
{
	if (nCurrent <= 0)
	{
		nCurrent = g_ListWidgetFile->count() - 1;
	}
	else
	{
		--nCurrent;
	}
	//		QMessageBox::information(0, QString::number(g_ListWidgetFile->currentRow()), dzApp->getContentMgr()->getDefaultContentDir(), QMessageBox::Ok);
	g_ListWidgetFile->setCurrentRow(nCurrent);
}

void SequentialLoadProcessing::next()
{
	if (nCurrent >= (g_ListWidgetFile->count() - 1) )
	{
		nCurrent = 0;
	}
	else
	{
		++nCurrent;
	}
	g_ListWidgetFile->setCurrentRow(nCurrent);
}

/**
**/
SequentialLoadActionNext::SequentialLoadActionNext() : DzAction(tr("Sequential Load Next"),
	tr(". Use the Slash key to Load."))
{
}

/**
**/
void SequentialLoadActionNext::executeAction()
{
	oSLP->next();
}


/**
**/
SequentialLoadActionPrevious::SequentialLoadActionPrevious() : DzAction(tr("Sequential Load Previous"),
	tr(". Use the Slash key to Load."))
{
}

/**
**/
void SequentialLoadActionPrevious::executeAction()
{
	oSLP->previous();
}


/**
**/
SequentialLoadPane::SequentialLoadPane() : DzPane( "Sequential Load" )
{
	// Declarations
	int margin = style()->pixelMetric( DZ_PM_GeneralMargin );

	// Define the layout for the pane
	QVBoxLayout *mainLyt = new QVBoxLayout();
	mainLyt->setMargin( margin );
	mainLyt->setSpacing( margin );

	//... more widgets/layouts here
	QGroupBox *groupBoxFolder = new QGroupBox(tr("Folder: "));

	g_LineEditFolder = new QLineEdit();
	g_LineEditFolder->setObjectName(QString("%1LineEditFolder").arg("SequentialLoad"));
	g_LineEditFolder->setMinimumHeight(style()->pixelMetric(DZ_PM_ButtonHeight));
	g_LineEditFolder->setMinimumWidth(style()->pixelMetric(DZ_PM_ButtonMinWidth));
	g_LineEditFolder->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum));
	g_LineEditFolder->setText("");
	connect(g_LineEditFolder, SIGNAL(returnPressed()), this, SLOT(addList()));

	QPushButton *folderPushButton = new QPushButton(tr("Select Folder"));
	folderPushButton->setObjectName(QString("%1PushButtonFolder").arg("SequentialLoad"));
	folderPushButton->setFixedHeight(style()->pixelMetric(DZ_PM_ButtonHeight));
	folderPushButton->setMinimumWidth(style()->pixelMetric(DZ_PM_ButtonMinWidth));
	connect(folderPushButton, SIGNAL(pressed()), this, SLOT(selectFolder()));

	QHBoxLayout *folderHBoxLayout = new QHBoxLayout;
	folderHBoxLayout->addWidget(g_LineEditFolder);
	folderHBoxLayout->addWidget(folderPushButton);
	folderHBoxLayout->addStretch(1);
	groupBoxFolder->setLayout(folderHBoxLayout);

	mainLyt->addWidget(groupBoxFolder);

	//
	QGroupBox* targetFigureGroupBox = new QGroupBox(tr("Target Figure: "));

	g_ListWidgetTarget = new QListWidget();
	g_ListWidgetTarget->setFixedHeight( (style()->pixelMetric(DZ_PM_ButtonHeight))*3 );
	g_ListWidgetTarget->setSelectionMode(QAbstractItemView::SingleSelection);

	QPushButton* listPushButton = new QPushButton(tr("List"));
	listPushButton->setObjectName(QString("%1PushButtonList").arg("SequentialLoad"));
	listPushButton->setFixedHeight(style()->pixelMetric(DZ_PM_ButtonHeight));
	listPushButton->setMinimumWidth(style()->pixelMetric(DZ_PM_ButtonMinWidth));
	connect(listPushButton, SIGNAL(pressed()), this, SLOT(listFigure()));

	QHBoxLayout* targetFigureHBoxLayout = new QHBoxLayout;
	targetFigureHBoxLayout->addWidget(g_ListWidgetTarget);
	targetFigureHBoxLayout->addWidget(listPushButton);
	targetFigureGroupBox->setLayout(targetFigureHBoxLayout);
	targetFigureGroupBox->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

	mainLyt->addWidget(targetFigureGroupBox);

	//
	QGroupBox* previousGroupBox = new QGroupBox(tr("Previous: "));

	g_LabelPrevious = new QLabel("[void]");
	g_LabelPrevious->setObjectName(QString("%1LabelPrevious").arg("SequentialLoad"));
	g_LabelPrevious->setFixedHeight(style()->pixelMetric(DZ_PM_ButtonHeight));
	g_LabelPrevious->setMinimumWidth(style()->pixelMetric(DZ_PM_ButtonMinWidth));

	QPushButton* previousPushButton = new QPushButton(tr("Previous"));
	previousPushButton->setObjectName(QString("%1PushButtonPrevious").arg("SequentialLoad"));
	previousPushButton->setFixedHeight(style()->pixelMetric(DZ_PM_ButtonHeight));
	previousPushButton->setMinimumWidth(style()->pixelMetric(DZ_PM_ButtonMinWidth));
	connect(previousPushButton, SIGNAL(pressed()), oSLP, SLOT(previous()));

	QVBoxLayout* previousVBoxLayout = new QVBoxLayout;
	previousVBoxLayout->addWidget(g_LabelPrevious);
	previousVBoxLayout->addWidget(previousPushButton);
	previousGroupBox->setLayout(previousVBoxLayout);

	mainLyt->addWidget(previousGroupBox);

	//
	QGroupBox* currentGroupBox = new QGroupBox(tr("Current: "));

	g_LabelCurrent = new QLabel("[void]");
	g_LabelCurrent->setObjectName(QString("%1LabelCurrent").arg("SequentialLoad"));
	g_LabelCurrent->setFixedHeight(style()->pixelMetric(DZ_PM_ButtonHeight));
	g_LabelCurrent->setMinimumWidth(style()->pixelMetric(DZ_PM_ButtonMinWidth));

	g_LineEditCurrent = new QLineEdit("[void]");
	g_LineEditCurrent->setObjectName(QString("%1LineEditCurrent").arg("SequentialLoad"));
	g_LineEditCurrent->setMinimumHeight(style()->pixelMetric(DZ_PM_ButtonHeight));
	g_LineEditCurrent->setMinimumWidth(style()->pixelMetric(DZ_PM_ButtonMinWidth));
	g_LineEditCurrent->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum));

	QVBoxLayout* currentVBoxLayout = new QVBoxLayout;
	currentVBoxLayout->addWidget(g_LabelCurrent);
	currentVBoxLayout->addWidget(g_LineEditCurrent);
	currentGroupBox->setLayout(currentVBoxLayout);

	mainLyt->addWidget(currentGroupBox);

	//
	QGroupBox* nextGroupBox = new QGroupBox(tr("Next: "));

	g_LabelNext = new QLabel("[void]");
	g_LabelNext->setObjectName(QString("%1LabelNext").arg("SequentialLoad"));
	g_LabelNext->setFixedHeight(style()->pixelMetric(DZ_PM_ButtonHeight));
	g_LabelNext->setMinimumWidth(style()->pixelMetric(DZ_PM_ButtonMinWidth));

	QPushButton* nextPushButton = new QPushButton(tr("Next"));
	nextPushButton->setObjectName(QString("%1PushButtonNext").arg("SequentialLoad"));
	nextPushButton->setFixedHeight(style()->pixelMetric(DZ_PM_ButtonHeight));
	nextPushButton->setMinimumWidth(style()->pixelMetric(DZ_PM_ButtonMinWidth));
	connect(nextPushButton, SIGNAL(pressed()), oSLP, SLOT(next()) );

	QVBoxLayout* nextVBoxLayout = new QVBoxLayout;
	nextVBoxLayout->addWidget(g_LabelNext);
	nextVBoxLayout->addWidget(nextPushButton);
	nextGroupBox->setLayout(nextVBoxLayout);

	mainLyt->addWidget(nextGroupBox);

	//
	g_ListWidgetFile = new QListWidget();
	g_ListWidgetFile->setMinimumHeight(style()->pixelMetric(DZ_PM_ButtonHeight));
	g_ListWidgetFile->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
	g_ListWidgetFile->setSelectionMode(QAbstractItemView::SingleSelection);
	connect(g_ListWidgetFile, SIGNAL(itemSelectionChanged()), this, SLOT(listBoxClicked()));

	mainLyt->addWidget(g_ListWidgetFile);

	// Set the layout for the pane
	setLayout(mainLyt);

	setMinimumSize( c_minWidth, c_minHeight );

	oSLP->setCurrent(loadPath());
	addList();
	oSLP->textChange();
}

/**
**/
SequentialLoadPane::~SequentialLoadPane()
{
	savePath();
	delete g_LineEditFolder;
//	g_ListWidgetFile->clear();
//	delete g_ListWidgetFile;
	delete g_LabelPrevious;
	delete g_LabelNext;
	delete g_LabelCurrent;
	delete g_LineEditCurrent;
	delete oSLP;
}


void SequentialLoadPane::selectFolder() {
	QFileDialog::Options options =
		QFileDialog::ShowDirsOnly | QFileDialog::HideNameFilterDetails |
		QFileDialog::DontUseNativeDialog;

	QString dirName = QFileDialog::getExistingDirectory(
		this,
		tr("フォルダ選択"),
		dzApp->getDataFolderPathBase() ,
		options
	);

	if (!(dirName.isEmpty())) {
		g_LineEditFolder->setText(dirName);
		addList();
	}

}

void SequentialLoadPane::listBoxClicked() {
	oSLP->loadDazFile(g_ListWidgetFile->currentRow());
	oSLP->textChange();
}

void SequentialLoadPane::listFigure() {
	DzSkeletonListIterator nodeIt(dzScene->skeletonListIterator());
	DzSkeleton* skeleton;

	if (g_ListWidgetTarget->count() > 0)
	{
		g_ListWidgetTarget->clear();
	}

	while (nodeIt.hasNext()) {
		skeleton = nodeIt.next();
		g_ListWidgetTarget->addItem(skeleton->getLabel());
	}
}


int SequentialLoadPane::loadPath() {
	QString sPluginsPath = dzApp->getPluginsPath();
	QFile oFile(sPluginsPath + "/SequentialLoad.txt");
	QString sPath;
	int	nCurrent = -1;

	if (oFile.exists()) {
		if (!oFile.open(QIODevice::ReadOnly | QIODevice::Text))
			return -2;

		QTextStream in(&oFile);
		sPath = in.readLine();
		g_LineEditFolder->setText(sPath);
		QString sCurrent = in.readLine();
		nCurrent = sCurrent.toInt();

		oFile.close();
	}
	else {
		if (!oFile.open(QIODevice::WriteOnly))
			return -2;

		QTextStream out(&oFile);
		out << "" << endl;
		out << -1 << endl;

		oFile.close();
	}

	return nCurrent;
}

bool SequentialLoadPane::savePath() {
	QString sPluginsPath = dzApp->getPluginsPath();
	QFile oFile(sPluginsPath + "/SequentialLoad.txt");

	if (!oFile.open(QIODevice::WriteOnly))
		return "Open Error Save";

	QTextStream out(&oFile);
	out << (g_LineEditFolder->text()) << endl;

	if( (g_ListWidgetFile->currentRow()) >=0)
	{
		out << g_ListWidgetFile->currentRow() << endl;
	}
	else
	{
		out << -1 << endl;
	}

	oFile.close();

	return false;
}


int SequentialLoadPane::addList() {
	int nNumber = 0;

	if (g_LineEditFolder->text().length() > 0) {
		QDir oDir = QDir(g_LineEditFolder->text());
		QFileInfoList oFileInfoList = oDir.entryInfoList();

		if (g_ListWidgetFile->count() > 0)
		{
			g_ListWidgetFile->clear();
		}

		QListIterator<QFileInfo> iterator_list(oFileInfoList);
		while (iterator_list.hasNext())
		{
			QString sTempFileName = iterator_list.next().fileName();
			if (sTempFileName.indexOf(".d") > -1)
			{
				g_ListWidgetFile->addItem(sTempFileName);
				++nNumber;
			}
		}

		savePath();
	}

	oSLP->textChange();
	return nNumber;
}
