#pragma once
enum class LAYER
{
	DEFAULT,
	BACKGROUND,
	PLAYER,
	PROJECTILE,
	ENEMY,
	UI,
	END
};

enum class PEN_TYPE
{
	HOLLOW, RED, GREEN,
	BLUE, YELLOW, END
};

enum class BRUSH_TYPE
{
	HOLLOW, RED, GREEN,
	BLUE, YELLOW, WHITE, END
};


enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,
	END,
};

enum class MAP_SIZE
{
	SMALL,
	BIG,
};

enum class UNIT_TYPE 
{
	PAWN = 0,
	KNIGHT = 1,
	BISHOP = 2,
	ROOK = 3,
	QUEEN = 4,
	END
};
