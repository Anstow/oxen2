#ifndef OXENGINE_GAME_HPP
#define OXENGINE_GAME_HPP

#include <OgreSceneManager.h>
#include <OgreRoot.h>
#include <OgreRenderWindow.h>
#include <OgreViewport.h>
#include <OgreLogManager.h>
#include <OgreTimer.h>

#include <string>
 
#include "../gui/MenuManager.hpp"
#include "InputManager.hpp"

namespace oxEngine {

class Game
{
    static bool initialized_;
    static bool running_;

    Game();
    ~Game();

public:
    /*!
     * \brief Initializes the application including ogre and cegui.
     *
     * \return True if already initialized or the initialization was a success
     */
    static bool initialize(const std::string& wndTitle);
    static bool destroy();

    static void run();

    static void quit();

	static Ogre::Root* m_pRoot;
	static Ogre::RenderWindow* m_pRenderWnd;
	static Ogre::Log* m_pLog;
	static Ogre::Timer* m_pTimer;

    static InputManager* m_pInputMgr;
    static MenuManager* m_pGuiManager;
};

} // namespace oxEngine

#endif // OXENGINE_GAME_HPP
