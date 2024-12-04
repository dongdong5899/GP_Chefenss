#pragma once
#include "Component.h"
#include "Action.h"

class Button :
    public Component
{
public:
    Button();
    ~Button();
public:
    // Component을(를) 통해 상속됨
    void LateUpdate() override;
    void Render(HDC _hdc) override;
public:
    void SetPos(Vec2 _pos) { m_pos = _pos; }
    Vec2 GetPos() { return m_pos; }
    void SetSize(Vec2 _size) { m_size = _size; }
    Vec2 GetSize() { return m_size; }
public:
    Action onClick;
private:
    Vec2 m_pos;
    Vec2 m_size;
};

