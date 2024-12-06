#pragma once
#include <functional>

using ActionEvent = std::function<void()>;

class Action
{
public:
    void operator+=(const ActionEvent _func)
    {
        m_eventVec.push_back(_func);
    }
    void Clear();
    void Invoke();
private:
    vector<ActionEvent> m_eventVec;
};