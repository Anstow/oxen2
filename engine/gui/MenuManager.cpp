#include "MenuManager.hpp"

#include "../system/Game.hpp"

namespace oxEngine {

MenuManager::MenuManager(Ogre::RenderWindow &pWnd)
    : m_renderer(CEGUI::OgreRenderer::bootstrapSystem(pWnd))
    , m_system(CEGUI::System::getSingleton())
    , m_defaultGuiContext(m_system.getDefaultGUIContext())
    , m_pRootWnd(CEGUI::WindowManager::getSingletonPtr()->createWindow("DefaultWindow", "root_"))
{
	CEGUI::ImageManager::setImagesetDefaultResourceGroup("Imagesets");
	CEGUI::Font::setDefaultResourceGroup("Fonts");
	CEGUI::Scheme::setDefaultResourceGroup("Schemes");
	CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
	CEGUI::WindowManager::setDefaultResourceGroup("Layouts");
	
	// Load the scheme
	CEGUI::SchemeManager::getSingletonPtr()->createFromFile("TaharezLook.scheme");

	// Create the mouse cursor
    m_defaultGuiContext.getMouseCursor().setDefaultImage("TaharezLook/MouseArrow");

	// Make the root window ignore mouse clicks
	m_pRootWnd->setMousePassThroughEnabled(true);

	m_defaultGuiContext.setRootWindow(m_pRootWnd);
}

MenuManager::~MenuManager() {
	// TODO: I'm not sure if this is necessary, remove if it isn't
	// CEGUI::WindowManager::getSingletonPtr()->destroyAllWindows();
}

bool MenuManager::InjectOISkeyDown(const OIS::KeyEvent &inKey) {
	m_defaultGuiContext.injectKeyDown(static_cast<CEGUI::Key::Scan>(inKey.key));
	return m_defaultGuiContext.injectChar(inKey.text);
}

bool MenuManager::InjectOISkeyUp(const OIS::KeyEvent &inKey) {
	return m_defaultGuiContext.injectKeyUp(static_cast<CEGUI::Key::Scan>(inKey.key));
}

bool MenuManager::InjectOISMouseButtonDown(const OIS::MouseEvent &arg, const OIS::MouseButtonID &inButton) {
	switch (inButton) {
	case OIS::MB_Left:
		return m_defaultGuiContext.injectMouseButtonDown(CEGUI::LeftButton);
	case OIS::MB_Middle:
		return m_defaultGuiContext.injectMouseButtonDown(CEGUI::MiddleButton);
	case OIS::MB_Right:
		return m_defaultGuiContext.injectMouseButtonDown(CEGUI::RightButton);
	case OIS::MB_Button3:
		return m_defaultGuiContext.injectMouseButtonDown(CEGUI::X1Button);
	case OIS::MB_Button4:
		return m_defaultGuiContext.injectMouseButtonDown(CEGUI::X2Button);
	default:	
		break;
	}
	return false;;
}

bool MenuManager::InjectOISMouseButtonUp(const OIS::MouseEvent &arg, const OIS::MouseButtonID &inButton) {
	switch (inButton) {
	case OIS::MB_Left:
		return m_defaultGuiContext.injectMouseButtonUp(CEGUI::LeftButton);
	case OIS::MB_Middle:
		return m_defaultGuiContext.injectMouseButtonUp(CEGUI::MiddleButton);
	case OIS::MB_Right:
		return m_defaultGuiContext.injectMouseButtonUp(CEGUI::RightButton);
	case OIS::MB_Button3:
		return m_defaultGuiContext.injectMouseButtonUp(CEGUI::X1Button);
	case OIS::MB_Button4:
		return m_defaultGuiContext.injectMouseButtonUp(CEGUI::X2Button);
	default:	
		break;
	}
	return false;
}

bool MenuManager::InjectOISMouseMove(const OIS::MouseEvent &arg) {
	// Scroll wheel.
	if (arg.state.Z.rel != 0) {
		m_defaultGuiContext.injectMouseWheelChange(arg.state.Z.rel / 120.0f);
	}
	return m_defaultGuiContext.injectMouseMove(arg.state.X.rel, arg.state.Y.rel);
}

Vector2i MenuManager::getMousePos() {
	CEGUI::Vector2f p = m_defaultGuiContext.getMouseCursor().getPosition();
	return { static_cast<int>(p.d_x), static_cast<int>(p.d_y) };
}

} // namespace oxEngine
