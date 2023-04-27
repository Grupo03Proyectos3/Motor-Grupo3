#include "System.h"
namespace Flamingo
{

    System::System()
        : m_mngr(nullptr)
        , m_group(GROUP_EXAMPLE)
    {
    }

    System::~System()
    {
    }

    void System::setContext(Manager* t_mngr)
    {
        m_mngr = t_mngr;
    }

    void System::initSystem()
    {
    }

    void System::update(float t_delta_time)
    {
    }

    void System::recieve(const Message&)
    {
    }
} // namespace Flamingo