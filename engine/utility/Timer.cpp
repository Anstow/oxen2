#include "Timer.hpp"

namespace oxEngine {

Timer::Timer()
    : m_started(false)
    , m_paused(false)
{}

Timer::~Timer() 
{}

void Timer::stop() {
    m_started = false;
    m_paused = false;
}

void Timer::start() {
    if (not m_started) {
        m_started = true;
        m_paused = false;

        m_startTime = std::chrono::steady_clock::now();
    } else if (m_paused) {
        m_startTime = std::chrono::steady_clock::now() - m_pausedTime;
        m_paused = false;
    }
}

void Timer::reset() {
    if (m_started) {
        m_startTime = std::chrono::steady_clock::now();

        if (m_paused) {
            m_pausedTime = std::chrono::steady_clock::duration::zero();
        }
    }
}

void Timer::pause() {
    if (m_started) {
        m_paused = true;
        m_pausedTime = std::chrono::steady_clock::now() - m_startTime;
    }
}

bool Timer::getPaused() {
    return m_started && m_paused;
}

bool Timer::getStarted() {
    return m_started;
}

} // namespace oxEngine
