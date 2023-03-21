#ifndef DebugDrawer_h__
#define DebugDrawer_h__

#include <OgreFrameListener.h>
#include <OgreVector.h>
#include <OgreColourValue.h>
#include <btBulletDynamicsCommon.h>

class OgreDebugDrawer : public btIDebugDraw
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
    virtual void clearLines() override;
    
  private:
    DebugDrawModes mDebugModes;
    std::vector<Ogre::ManualObject*> mLines;

    Ogre::SceneManager* m_scn_mngr = nullptr;
};

#endif // DebugDrawer_h__