#include "Game.hpp"

#include "../utility/Timer.hpp"

#include <OgreWindowEventUtilities.h>
#include <OgreConfigFile.h>

#include <chrono>
#include <ratio>

namespace oxEngine {

bool Game::initialized_(false);
bool Game::running_(false);

Ogre::Root* Game::m_pRoot(0);
Ogre::RenderWindow* Game::m_pRenderWnd(0);
Ogre::Log* Game::m_pLog(0);
Ogre::Timer* Game::m_pTimer(0);

InputManager* Game::m_pInputMgr(0);
MenuManager* Game::m_pGuiManager(0);

bool Game::initialize(const std::string& wndTitle) {
    if (not initialized_) {
        // Set up the log manager
        Ogre::LogManager* logMgr = new Ogre::LogManager();

        m_pLog = Ogre::LogManager::getSingleton().createLog("OgreLogfile.log", true, true, false);
        m_pLog->setDebugOutputEnabled(true);

        // Create the root
        m_pRoot = new Ogre::Root();

        // TODO: replace the config dialog on start up by some default settings and in game menu
        // show the config dialog
        if(!m_pRoot->restoreConfig() && !m_pRoot->showConfigDialog()) {
            return false;
        }
        // create the render window
        m_pRenderWnd = m_pRoot->initialise(true, wndTitle);

        m_pInputMgr = new InputManager(m_pRenderWnd);

        // TODO: Make own resource loading functions to load all the resource
        // locations from one file
        //
        // Load the resources
        Ogre::String secName, typeName, archName;
        Ogre::ConfigFile cf;
        cf.load("resources.cfg");

        Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
        while (seci.hasMoreElements())
        {
            secName = seci.peekNextKey();
            Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
            Ogre::ConfigFile::SettingsMultiMap::iterator i;
            for (i = settings->begin(); i != settings->end(); ++i)
            {
                typeName = i->first;
                archName = i->second;
                Ogre::ResourceGroupManager::getSingleton().addResourceLocation(archName, typeName, secName);
            }
        }
        Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
        Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

        // Create and start our timer for timing between frames 
        m_pTimer = new Ogre::Timer();
        m_pTimer->reset();

        // Put the window in the foreground?
        m_pRenderWnd->setActive(true);

        m_pGuiManager = new MenuManager(*m_pRenderWnd);

        initialized_ = true;
    }

    return initialized_;
}

void Game::run() {
    running_ = true;

    Timer timer;
    timer.start();

    unsigned long timePassed = 0;

    int count = 0;



    while(running_) {
        timePassed = timer.restart();
        Ogre::WindowEventUtilities::messagePump();

        m_pInputMgr->captureInput();

        if (++count > 300) {
            running_ = false;
        }

        m_pRoot->renderOneFrame();

        timer.waitFor(std::chrono::duration<long, std::ratio<1,60>>(1));
    }
}

void Game::quit() {
    running_ = false;
}

bool Game::destroy() {
    if (running_) {
        return false;
    }
    if (initialized_) {
        delete m_pTimer;
        delete m_pInputMgr;
        delete m_pGuiManager;
        delete m_pRoot;
    }
    
    return not initialized_;
}

} // namespace oxEngine
