#include "pch.h"
#include "UnitManager.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"

void UnitManager::Init()
{
	m_currentUnit = UNIT_TYPE::END;
}

void UnitManager::Update()
{
}

Unit* UnitManager::GenerateUnit()
{
	switch (m_currentUnit)
	{
	case UNIT_TYPE::PAWN:
		return new Pawn;
	case UNIT_TYPE::KNIGHT:
		return new Knight;
	case UNIT_TYPE::BISHOP:
		return new Bishop;
	case UNIT_TYPE::ROOK:
		return new Rook;
	case UNIT_TYPE::QUEEN:
		return new Queen;
	case UNIT_TYPE::END:
		return nullptr;
	}
}


