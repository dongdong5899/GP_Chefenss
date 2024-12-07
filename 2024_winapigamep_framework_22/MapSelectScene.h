#pragma once
#include "Scene.h"
class MapSelectScene :
    public Scene
{
public:
    MapSelectScene();
    ~MapSelectScene();
public:
    virtual void Init() override;
};

