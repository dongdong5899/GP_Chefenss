#pragma once
#include "Scene.h"
class EndScene :
    public Scene
{
public:
    EndScene();
    ~EndScene();
public:
    void Init() override;
};

