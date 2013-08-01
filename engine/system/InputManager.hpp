#ifndef OXENGINE_INPUTMANAGER_HPP
#define OXENGINE_INPUTMANAGER_HPP

#include <OgreRenderWindow.h>

#include <OISEvents.h>
#include <OISKeyboard.h>
#include <OISMouse.h>
#include <OISInputManager.h>

namespace oxEngine {

class InputManager
    : public OIS::KeyListener
    , public OIS::MouseListener
{
	OIS::InputManager* m_pInputMgr;
	OIS::Keyboard* m_pKeyboard;
	OIS::Mouse* m_pMouse;

public:
    InputManager(Ogre::RenderWindow* pRenderWnd);
    ~InputManager();

    void captureInput();

    // Key Listener
	virtual bool keyPressed(const OIS::KeyEvent &keyEventRef) override final;
	virtual bool keyReleased(const OIS::KeyEvent &keyEventRef) override final;

    // Mouse Listener
	virtual bool mouseMoved(const OIS::MouseEvent &evt) override final;
	virtual bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id) override final;
	virtual bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id) override final;
};

} // namespace oxEngine

#endif // OXENGINE_INPUTMANAGER_HPP
