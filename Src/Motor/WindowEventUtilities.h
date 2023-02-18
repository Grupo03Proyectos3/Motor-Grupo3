
// CLASE COPIADA DE OGRE: COMPONETS_BITES
// Las cosas comoentadas estan sujetas a un futuro uso en caso de que hagan falta,si no hacen falta se borrararan

#ifndef __WindowEventUtils_H__
#define __WindowEventUtils_H__

#include "OgreBitesPrerequisites.h"
#include "OgreCommon.h"
#include "OgreHeaderPrefix.h"
#include "OgrePlatform.h"
#include "OgrePrerequisites.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#include <wtypes.h>
#endif

namespace WindowEvents
{
    /** \addtogroup Optional
     *  @{
     */
    /** \addtogroup Bites
     *  @{
     */
    /**
        Callback class used to send out window events to client app
    */
    class _OgreBitesExport WindowEventListener
    {
      public:
        virtual ~WindowEventListener() {}

        /**
            Window has moved position
        @param rw
            The RenderWindow which created this events
        */
        virtual void windowMoved(Ogre::RenderWindow* rw) { (void)rw; }

        /**
            Window has resized
        @param rw
            The RenderWindow which created this events
        */
        virtual void windowResized(Ogre::RenderWindow* rw) { (void)rw; }

        /**
            Window is closing (Only triggered if user pressed the [X] button)
        @param rw
            The RenderWindow which created this events
        @return True will close the window(default).
        */
        virtual bool windowClosing(Ogre::RenderWindow* rw)
        {
            return true;
        }

        /**

            Window has been closed (Only triggered if user pressed the [X] button)
        @param rw
            The RenderWindow which created this events
        @note
            The window has not actually close yet when this event triggers. It's only closed after
            all windowClosed events are triggered. This allows apps to deinitialise properly if they
            have services that needs the window to exist when deinitialising.
        */
        virtual void windowClosed(Ogre::RenderWindow* rw) { (void)rw; }

        /**
            Window has lost/gained focus
        @param rw
            The RenderWindow which created this events
        */
        virtual void windowFocusChange(Ogre::RenderWindow* rw) { (void)rw; }
    };

    /**
        Utility class to handle Window Messages

        This only provides a minimal implementation for moving/ resizing windows.
        @note For input handling and proper platform integration rather use SDL2/ Qt/ whatever.
        @see ApplicationContext
    */
    class _OgreBitesExport WindowEventUtilities
    {
      public:
        /**
            Call this once per frame. This will update all registered RenderWindows.
        */
        static void messagePump();

        /**
            Add a listener to listen to renderwindow events (multiple listener's per renderwindow is fine)
            The same listener can listen to multiple windows, as the Window Pointer is sent along with
            any messages.
        @param window
            The RenderWindow you are interested in monitoring
        @param listener
            Your callback listener
        */
        static void addWindowEventListener(Ogre::RenderWindow* window, WindowEventListener* listener);

        /**
            Remove previously added listener
        @param window
            The RenderWindow you registered with
        @param listener
            The listener registered
        */
        static void removeWindowEventListener(Ogre::RenderWindow* window, WindowEventListener* listener);

        /**

            Call upon creation of Ogre windows. You are free to add your
            external windows here too if needed.
        @param window
            The RenderWindow to monitor
        */
        static void _addRenderWindow(Ogre::RenderWindow* window);

        /**
            Called upon deletion of previously registered windows.
        @param window
            The RenderWindow to remove from list
        */
        static void _removeRenderWindow(Ogre::RenderWindow* window);

        // backwards compatibility
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
        //! Internal winProc (RenderWindow's use this when creating the Win32 Window)
        static LRESULT CALLBACK _WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
#endif
    };
    /** @} */
    /** @} */
} // namespace WindowEvents

namespace Ogre
{
    // backwards compatibility
    typedef OGRE_DEPRECATED WindowEvents::WindowEventListener WindowEventListener;
    typedef OGRE_DEPRECATED WindowEvents::WindowEventUtilities WindowEventUtilities;
} // namespace Ogre

#include "OgreHeaderSuffix.h"

#endif