#include <FlamingoBase/Transform.h>
#include <btBulletCollisionCommon.h>

class FlamingoMotionState : public btDefaultMotionState
{
  public:
    FlamingoMotionState(btTransform t_initial_transform, Transform* t_flamingo_transform)
        : m_transform(t_initial_transform)
        , m_flamingo_transform(t_flamingo_transform)
        , btDefaultMotionState(t_initial_transform)
    {
    }

    virtual void getWorldTransform(btTransform& t_world_transform) const
    {
        t_world_transform = m_transform;
    }

    virtual void setWorldTransform(const btTransform& t_world_transform)
    {
        m_transform = t_world_transform;
        m_flamingo_transform->setPosition(SVector3::bulletToSVector3(t_world_transform.getOrigin()));
        m_flamingo_transform->setRotation(SQuaternion::bulletToQuaternion(t_world_transform.getRotation()));
    }

  private:
    btTransform m_transform;
    Transform* m_flamingo_transform;
};
