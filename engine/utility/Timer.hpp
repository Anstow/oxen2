#ifndef OXENGINE_TIMER_HPP
#define OXENGINE_TIMER_HPP

#include <chrono>
#include <string>

#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
#include <windows.h>
#else
#include <thread>
#endif

namespace oxEngine {

class Timer
{
    /*!
     * \brief Whether the timer is started
     */
    bool m_started;
    /*!
     * \brief Whether the timer is paused
     */
    bool m_paused;

    /*!
     * \brief The start time of the timer
     */
    std::chrono::steady_clock::time_point m_startTime;
    /*!
     * \brief The time between the timer being started and the timer being
     * paused
     */
    std::chrono::steady_clock::duration m_pausedTime;

public:
    Timer();
    ~Timer();

    /*!
     * \brief Stops the timer
     */
    void stop();
    /*!
     * \brief Starts the timer
     */
    void start();
    /*!
     * \brief This restarts the clock at 0 and returns the current passed time.
     *
     * \tparam T The interval to measure time in.
     *
     * \return The time passed since the timer was last started. If it is
     * paused it returns the length of time before it was paused.
     */
    template <typename T=std::chrono::microseconds>
    unsigned long restart();
    /*!
     * \brief Resets the timer to 0. Even when paused.
     */
    void reset();
    /*!
     * \brief Pauses the timer
     */
    void pause();

    /*!
     * \brief Gets the time since the timer was last started.
     *
     * \tparam T The interval to measure the time in, it defaults to
     * microseconds.
     *
     * \return The time since the timer was started. If the timer is paused it
     * returns the length of time before it was paused.
     */
    template <typename T=std::chrono::microseconds>
    unsigned long getTime();

    /*!
     * \brief Gets whether the timer is currently paused. (If it hasn't been
     * started this counts as paused.
     *
     * \return whether the timer is currently running.
     */
    bool getPaused();
    /*!
     * \brief Gets whether the timer has been started. It returns true even if
     * the timer is paused.
     *
     * \return Whether the timer has been started.
     */
    bool getStarted();

    template< class Rep, class Period >
    void waitFor(std::chrono::duration<Rep,Period> wait);

    // TODO: templatify this, see the templatification for getTime.
    template <typename T=std::chrono::microseconds>
    static void delay(unsigned long delay);
};

template <typename T>
unsigned long Timer::restart() {
    // TODO: when 2014 comes out, do the check whether T is a duration
    if (m_started && not m_paused) {
        std::chrono::steady_clock::time_point tempTime = m_startTime;
        m_startTime = std::chrono::steady_clock::now();

        return std::chrono::duration_cast<T>(
                m_startTime - tempTime).count();
    } else  if (m_paused) {
        m_started = true;
        m_paused = false;
        m_startTime = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<T>(
                m_pausedTime).count();
    } else {
        m_started = true;
        m_paused = false;
        m_startTime = std::chrono::steady_clock::now();
        return 0;
    }
}

template <typename T>
unsigned long Timer::getTime() {
    // TODO: when 2014 comes out, do the check whether T is a duration
    if (m_started && not m_paused) {
        return std::chrono::duration_cast<T>(
                std::chrono::steady_clock::now() - m_startTime).count();
    } else if (m_paused) {
        return std::chrono::duration_cast<T>(
                m_pausedTime).count();
    } else {
        return 0;
    }
}

template< class Rep, class Period >
void Timer::waitFor(std::chrono::duration<Rep,Period> wait) {
    if (m_startTime + wait > std::chrono::steady_clock::now()) {
        std::this_thread::sleep_until(m_startTime + wait);
    }
}

template <typename T>
void Timer::delay(unsigned long delay) {
    T waitTime(delay);
#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)
	Sleep(std::chrono::duration_cast<millisecs>(waitTime));
#else
    std::this_thread::sleep_for(waitTime);
#endif
}
    
} // namespace oxEngine

#endif // OXENGINE_TIMER_HPP
