#pragma once
#include "Scene.h"
class DieScene :
    public Scene
{
public:
    DieScene();
    ~DieScene();
public:
    void Init() override;
};

