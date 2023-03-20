#ifndef DebugDrawer_h__
#define DebugDrawer_h__

#include <OgreFrameListener.h>
#include <OgreVector.h>
#include <OgreColourValue.h>
#include <btBulletDynamicsCommon.h>

class OgreDebugDrawer : public btIDebugDraw, public Ogre::FrameListener
{
  public:
    OgreDebugDrawer(Ogre::SceneManager* scm, Ogre::Root* root);
    ~OgreDebugDrawer();
    virtual void drawLine(const btVector3& from_, const btVector3& to_, const btVector3& color_);
    virtual void drawTriangle(const btVector3& v0, const btVector3& v1, const btVector3& v2, const btVector3& color_, btScalar);
    virtual void drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color_);
    virtual void reportErrorWarning(const char* warningString);
    virtual void draw3dText(const btVector3& location, const char* textString);
    virtual void setDebugMode(int debugMode);
    virtual int getDebugMode() const;

  protected:
    bool frameStarted(const Ogre::FrameEvent& evt) override;
    bool frameEnded(const Ogre::FrameEvent& evt) override;

  private:
    struct ContactPoint
    {
        Ogre::Vector3 from;
        Ogre::Vector3 to;
        Ogre::ColourValue color;
        size_t dieTime;
    };
    DebugDrawModes mDebugModes;
    Ogre::ManualObject* mLines;
    Ogre::ManualObject* mTriangles;
    std::vector<ContactPoint>* mContactPoints;
    std::vector<ContactPoint> mContactPoints1;
    std::vector<ContactPoint> mContactPoints2;
};

#endif // DebugDrawer_h__