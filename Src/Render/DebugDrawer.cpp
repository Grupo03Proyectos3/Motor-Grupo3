#include "DebugDrawer.h"

#include <FlamingoUtils/SVector3.h>
#include <Ogre.h>
#include <OgreLogManager.h>
#include <OgreManualObject.h>
#include <OgreMaterial.h>
#include <OgreMaterialManager.h>
#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreTechnique.h>
#include <OgreTextureUnitState.h>
#include <OgreTimer.h>
#include <FlamingoBase/SceneManager.h>

using namespace Ogre;

OgreDebugDrawer::OgreDebugDrawer(Ogre::SceneManager* scm, Ogre::Root* root)
{
    m_scn_mngr = scm;
    mDebugModes = (DebugDrawModes)DBG_DrawWireframe;
}

OgreDebugDrawer::~OgreDebugDrawer()
{
}

void OgreDebugDrawer::drawLine(const btVector3& from, const btVector3& to, const btVector3& color)
{
    Ogre::ManualObject* line = m_scn_mngr->createManualObject();
    line->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_LINE_LIST);
    line->position(from.x(), from.y(), from.z());
    line->position(to.x(), to.y(), to.z());
    line->colour(Ogre::ColourValue(color.x(), color.y(), color.z()));
    line->end();
    Flamingo::FlamingoSceneManager().getSceneActive()->getSceneManger()->getRootSceneNode()->createChildSceneNode()->attachObject(line);
    mLines.push_back(line);
}

void OgreDebugDrawer::drawTriangle(const btVector3& v0, const btVector3& v1, const btVector3& v2, const btVector3& color, btScalar alpha)
{
  /*  ColourValue c(color.getX(), color.getY(), color.getZ(), alpha);
    c.saturate();
    mTriangles->position(SVector3::bulletToSVector3(v0));
    mTriangles->colour(c);
    mTriangles->position(SVector3::bulletToSVector3(v1));
    mTriangles->colour(c);
    mTriangles->position(SVector3::bulletToSVector3(v2));
    mTriangles->colour(c);*/
}

void OgreDebugDrawer::drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color)
{
  /*  mContactPoints->resize(mContactPoints->size() + 1);
    ContactPoint p = mContactPoints->back();
    p.from = SVector3::bulletToSVector3(PointOnB);
    p.to = p.from + SVector3::bulletToSVector3(normalOnB) * distance;
    p.dieTime = Root::getSingleton().getTimer()->getMilliseconds() + lifeTime;
    p.color.r = color.x();
    p.color.g = color.y();
    p.color.b = color.z();*/
}

void OgreDebugDrawer::reportErrorWarning(const char* warningString)
{
    LogManager::getSingleton().getDefaultLog()->logMessage(warningString);
}

void OgreDebugDrawer::draw3dText(const btVector3& location, const char* textString)
{
}

void OgreDebugDrawer::setDebugMode(int debugMode)
{
    mDebugModes = (DebugDrawModes)debugMode;
}

int OgreDebugDrawer::getDebugMode() const
{
    return mDebugModes;
}

void OgreDebugDrawer::clearLines()
{
    for (auto i : mLines)
    {
        m_scn_mngr->destroyManualObject(i);
    }

    mLines.clear();
}
