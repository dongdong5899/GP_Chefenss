#pragma once
#include "Object.h"
class TextPro;
class Waver :
    public Object
{
public:
    Waver();
    ~Waver();
public:

private:
    TextPro* m_waveText;
};

