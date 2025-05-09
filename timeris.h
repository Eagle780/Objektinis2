/**
 * @file timeris.h
 * @author Eglė
 * @brief Klasė naudojama atliekamų funkcijų matavimui
 * @version 0.1
 * @date 2025-05-09
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef TIMER_H
#define TIMER_H

#include "header.h"

class Timer
{
private:
    using hrClock = std::chrono::high_resolution_clock;
    using durationDouble = std::chrono::duration<double>;
    std::chrono::time_point<hrClock> start;

public:
    /**
     * @brief Konstruktorius, kuris išsaugo laiką, kada buvo iškviestas
     *
     */
    Timer() : start{hrClock::now()} {}
    /**
     * @brief restartuoja laiko kintamąjį
     *
     */
    void reset()
    {
        start = hrClock::now();
    }
    /**
     * @brief iš dabartinio laiko atima išsaugotą
     *
     * @return Laikas nuo konstruktoriaus iškvietimo iki dabar
     */
    double elapsed() const
    {
        return durationDouble(hrClock::now() - start).count();
    }
};

#endif