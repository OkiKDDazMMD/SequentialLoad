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
#include "dzplugin.h"

#include "version.h"
#include "SequentialLoad.h"

/*****************************
   Plugin Definition
*****************************/

DZ_PLUGIN_DEFINITION( "Sequential Load (Test)" );
DZ_PLUGIN_AUTHOR( "Oki_KD" );
DZ_PLUGIN_VERSION( PLUGIN_MAJOR, PLUGIN_MINOR, PLUGIN_REV, PLUGIN_BUILD );

DZ_PLUGIN_DESCRIPTION(
	"Sequential Load"
	"<br><br>"
	);

DZ_PLUGIN_CLASS_GUID( SequentialLoadPaneAction, C8F6D7E9-F013-4F3D-AF41-0EDF7058E869);
DZ_PLUGIN_CLASS_GUID( SequentialLoadPane, 4AFE248D-C31A-4F1E-80D9-84594011ADFD);
DZ_PLUGIN_CLASS_GUID( SequentialLoadActionNext, 6C081796-0C35-4077-B258-6F0A101D21C2);
DZ_PLUGIN_CLASS_GUID( SequentialLoadActionPrevious, 545A244C-E753-4598-AE57-1218CCCC5160);