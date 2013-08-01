#ifndef OXENGINE_MENUMANAGER_HPP
#define OXENGINE_MENUMANAGER_HPP

#include <CEGUI/CEGUI.h>
#include <OgreRenderWindow.h>
#include <Renderer.h>

#include <OISEvents.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

#include "../utility/Vector2.hpp"

namespace oxEngine {

class MenuManager
{
	CEGUI::OgreRenderer& m_renderer;
    CEGUI::System& m_system;
    CEGUI::GUIContext& m_defaultGuiContext;

	CEGUI::Window* m_pRootWnd;

public:
	/**
	 * @brief Sets up CEGUI, using the window
	 *
	 * @param pWnd The window to render to
	 *
	 * @return The success of setting up CEGUI
	 */
	MenuManager(Ogre::RenderWindow &pWnd);
	/**
	 * @brief Deletes the resources taken by the MenuManager
	 */
	~MenuManager();

	/**
	 * @brief Injects a key down event
	 *
	 * @param inKey The key data
	 *
	 * @return whether the input has been used by the menus
	 */
	bool InjectOISkeyDown(const OIS::KeyEvent &inKey);
	/**
	 * @brief Injects a key up event
	 *
	 * @param inKey The key data
	 *
	 * @return Whether the input has been used by a menu
	 */
	bool InjectOISkeyUp(const OIS::KeyEvent &inKey);
	/**
	 * @brief Injects and translates a mouse button down event
	 *
	 * @param arg The key data
	 * @param inButton The button ID
	 *
	 * @return Whether the mouse is over the gui
	 */
	bool InjectOISMouseButtonDown(const OIS::MouseEvent &arg, const OIS::MouseButtonID &inButton);
	/**
	 * @brief Injects and translates a mouse botton up event
	 *
	 * @param arg The key data
	 * @param inButton The botton ID
	 *
	 * @return Whether the mouse is over the gui
	 */
	bool InjectOISMouseButtonUp(const OIS::MouseEvent &arg, const OIS::MouseButtonID &inButton);
	/**
	 * @brief Injects the mouse cursor move event including scroll wheel
	 *
	 * @param arg The key data
	 *
	 * @return Whether the mouse is over the gui
	 */
	bool InjectOISMouseMove(const OIS::MouseEvent &arg);
	/**
	 * @brief This injects the mouse cursor position
	 *
	 * @param xPos The x position
	 * @param yPos The y position
	 *
	 * @return true
	 */
	bool InjectOISMousePosition(float xPos, float yPos);

	/**
	 * @brief Get the mouse position on the screen
	 *
	 * @return The position of the mouse in pixels
	 */
	Vector2i getMousePos();
};

} // namespace oxEngine

#endif // OXENGINE_MENUMANAGER_HPP
