#pragma once
#include "Scene.h"
class ClearScene :
    public Scene
{
public:
    ClearScene();
    ~ClearScene();
public:
    void Init() override;
};

