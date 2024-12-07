#pragma once
#include "Component.h"
class Texture;
class SpriteRenderer :
    public Component
{
public:
    SpriteRenderer();
    ~SpriteRenderer();
public:
    virtual void LateUpdate() override;
    virtual void Render(HDC _hdc) override;
public:
    void SetOffset(Vec2 _offset) { m_offset = _offset; }
    Vec2 GetOffset() { return m_offset; }
    void SetTexture(Texture* _texture) { m_texture = _texture; }
    Texture* GetTexture() { return m_texture; }
    void SetScale(float _scale) { m_scale = _scale; }
    float GetScale() { return m_scale; }
    void OnTransparent() { m_isTransparent = true; }
    bool IsTransparent() { return m_isTransparent; }
private:
    Vec2 m_offset;
    Texture* m_texture;
    float m_scale;
    bool m_isTransparent;
};

