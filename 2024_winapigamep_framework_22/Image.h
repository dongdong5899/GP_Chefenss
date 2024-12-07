#pragma once
#include "Object.h"
class Texture;
class Image :
    public Object
{
public:
    Image();
    ~Image();
public:
    void Update() override;
    void Render(HDC _hdc) override;
public:
    void SetImage(Texture* _texure, float _scale, bool isTransparent = false);
};

