#include "pch.h"
#include "Action.h"

void Action::Clear()
{
    m_eventVec.clear();
}

void Action::Invoke()
{
    for (ActionEvent evt : m_eventVec)
        evt();
}
