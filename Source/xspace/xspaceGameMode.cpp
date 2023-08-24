// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "xspaceGameMode.h"
#include "xspacePawn.h"

AxspaceGameMode::AxspaceGameMode()
{
	// set default pawn class to our flying pawn
	DefaultPawnClass = AxspacePawn::StaticClass();

	this->xNameGenerator = NewObject<UXNameGenerator>();

}
