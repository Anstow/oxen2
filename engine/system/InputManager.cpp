#include "InputManager.hpp"

#include "Game.hpp"

#include <OgreStringConverter.h>

namespace oxEngine {

InputManager::InputManager(Ogre::RenderWindow* pRenderWnd)
    : OIS::KeyListener()
    , OIS::MouseListener()
{
    // Set up OIS (the input system)
    size_t hWnd = 0;
    pRenderWnd->getCustomAttribute("WINDOW", &hWnd);

    OIS::ParamList paramList;

    paramList.insert(OIS::ParamList::value_type("WINDOW", Ogre::StringConverter::toString(hWnd)));

    m_pInputMgr = OIS::InputManager::createInputSystem(paramList);

    m_pKeyboard = static_cast<OIS::Keyboard*>(m_pInputMgr->createInputObject(OIS::OISKeyboard, true));
    m_pMouse = static_cast<OIS::Mouse*>(m_pInputMgr->createInputObject(OIS::OISMouse, true));

    m_pKeyboard->setEventCallback(this);
    m_pMouse->setEventCallback(this);

    m_pMouse->getMouseState().height = pRenderWnd->getHeight();
    m_pMouse->getMouseState().width  = pRenderWnd->getWidth();
}

InputManager::~InputManager() {
    if (m_pMouse) {
        m_pInputMgr->destroyInputObject(m_pMouse);
    }
    if (m_pKeyboard) {
        m_pInputMgr->destroyInputObject(m_pKeyboard);
    }
    OIS::InputManager::destroyInputSystem(m_pInputMgr);
}

void InputManager::captureInput() {
    m_pKeyboard->capture();
    m_pMouse->capture();
}

bool InputManager::keyPressed(const OIS::KeyEvent &keyEventRef) {
    if (keyEventRef.key == OIS::KC_ESCAPE) {
        Game::quit();
    }
    return Game::m_pGuiManager->InjectOISkeyDown(keyEventRef);
}

bool InputManager::keyReleased(const OIS::KeyEvent &keyEventRef) {
    return Game::m_pGuiManager->InjectOISkeyUp(keyEventRef);
}

bool InputManager::mouseMoved(const OIS::MouseEvent &evt) {
    return Game::m_pGuiManager->InjectOISMouseMove(evt);
}

bool InputManager::mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id) {
    return Game::m_pGuiManager->InjectOISMouseButtonDown(evt, id);
}

bool InputManager::mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id) {
    return Game::m_pGuiManager->InjectOISMouseButtonUp(evt, id);
}

} // namespace oxEngine
