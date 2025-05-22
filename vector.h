/**
 * @file vector.h
 * @author Eglė
 * @brief Mano sukurto vektoriaus klasė, kuri turi beveik visą įprasto vektoriaus funkcionalumą
 * @version 0.1
 * @date 2025-05-22
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include <iostream>
#include <memory>

template <typename T>
class Vector
{
public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using pointer = T *;
    using const_pointer = const T *;
    using iterator = T *;
    using const_iterator = const T *;
    using reverse_iterator = T *;
    using const_reverse_iterator = const T *;
    using allocator_type = std::allocator<T>;

private:
    int Size;
    int Capacity;
    T *array;
    allocator_type alloc;

public:
    /**
     * @brief Naujo vektoriaus konstruktorius
     *
     */
    Vector();
    /**
     * @brief Kopijavimo konstruktorius
     *
     * @param rhs Vektorius, iš kurio kopijuojama
     */
    Vector(const Vector<T> &rhs);
    /**
     * @brief Vektoriaus perkėlimo konstruktorius
     *
     * @param rhs Vektorius, kurio duomenys perkeliami
     */
    Vector(Vector<T> &&rhs) noexcept;
    /**
     * @brief Vektoriaus konstruktorius, kuris užpildo vektorių tam tikru skaičiumi ir tuo pačiu objektu
     *
     * @param elements Nusako kokio dydžio vektoriaus norime
     * @param value Objekto reikšmė, kuria bus užpildomas vektorius
     */
    Vector(int elements, const T &value = T());
    /**
     * @brief Vektoriaus konstruktorius iš pateikto sąrašo
     *
     * @param list sąrašas, kurį norima įdėti į vektorių
     */
    Vector(const std::initializer_list<T> &list);
    /**
     * @brief Vektoriaus destruktorius
     *
     */
    ~Vector();

    /**
     * @brief prideda duotą objektą į vektoriaus galą
     *
     * @param value Objektas, kurį norima pridėti
     */
    void push_back(const T &value);
    /**
     * @brief pašalina paskutinį vektoriaus elementą
     *
     */
    void pop_back();

    /**
     * @brief tikrina, ar vektorius tuščias
     *
     * @return true Vektorius tuščias
     * @return false Vektorius ne tuščias
     */
    bool empty() const;
    /**
     * @brief grąžina vektoriaus dydį
     *
     * @return int Dydis
     */
    int size() const;
    /**
     * @brief grąžina vektoriaus talpą
     *
     * @return int Talpa
     */
    int capacity() const;
    /**
     * @brief Pakeičia vektoriaus talpą į duotąją, jei ji nėra mažesnė už dabartinę
     *
     * @param new_cap naujoji norima talpa
     */
    void reserve(int new_cap);
    /**
     * @brief sumažina vektoriaus talpą iki jo dydžio
     *
     */
    void shrink_to_fit();

    /**
     * @brief lygybės operatorius
     *
     * @param rhs Vektorius, su kuriuo lyginama
     * @return true Vektoriai lygūs
     * @return false Vektoriai nelygūs
     */
    bool operator==(const Vector<T> &rhs) const;
    /**
     * @brief nelygybės operatorius
     *
     * @param rhs Vektorius, su kuriuo lyginama
     * @return true Vektoriai nelygūs
     * @return false Vektoriai lygūs
     */
    bool operator!=(const Vector<T> &rhs) const;
    /**
     * @brief daugiau operatorius, pirmi nesutampantys elementai tame pačiame indekse nustato grąžinąmą reikšmę,
     * jei visi elementai lygūs, didesnis yra tas, kuris turi daugiau elementų
     *
     * @param rhs Vektorius, su kuriuo lyginama
     * @return true Vektorius kairėje didesnis
     * @return false Vektorius kairėje nedidesnis
     */
    bool operator>(const Vector<T> &rhs) const;
    /**
     * @brief daugiau operatorius, pirmi nesutampantys elementai tame pačiame indekse nustato grąžinąmą reikšmę,
     * jei visi elementai lygūs, didesnis yra tas, kuris turi daugiau elementų
     *
     * @param rhs Vektorius, su kuriuo lyginama
     * @return true Vektorius kairėje didesnis arba lygus
     * @return false Vektorius kairėje mažesnis
     */
    bool operator>=(const Vector<T> &rhs) const;
    /**
     * @brief daugiau operatorius, pirmi nesutampantys elementai tame pačiame indekse nustato grąžinąmą reikšmę,
     * jei visi elementai lygūs, didesnis yra tas, kuris turi daugiau elementų
     *
     * @param rhs Vektorius, su kuriuo lyginama
     * @return true Vektorius kairėje mažesnis
     * @return false Vektorius kairėje nemažesnis
     */
    bool operator<(const Vector<T> &rhs) const;
    /**
     * @brief daugiau operatorius, pirmi nesutampantys elementai tame pačiame indekse nustato grąžinąmą reikšmę,
     * jei visi elementai lygūs, didesnis yra tas, kuris turi daugiau elementų
     *
     * @param rhs Vektorius, su kuriuo lyginama
     * @return true Vektorius kairėje mažesnis arba lygus
     * @return false Vektorius kairėje didesnis
     */
    bool operator<=(const Vector<T> &rhs) const;

    /**
     * @brief Kopijavimo operacija
     *
     * @param rhs Vektorius, iš kurio kopijuojama
     * @return Vector<T>&
     */
    Vector<T> &operator=(const Vector<T> &rhs);
    /**
     * @brief Perkėlimo operacija
     *
     * @param rhs Vektorius, iš kurio perkeliama
     * @return Vector<T>&
     */
    Vector<T> &operator=(Vector<T> &&rhs) noexcept;
    allocator_type get_allocator() const;

    /**
     * @brief indekso operatorius
     *
     * @param index Norimas indeksas
     * @return value_type& Elementas tame indekse
     */
    value_type &operator[](int index);
    /**
     * @brief indekso funkcija
     *
     * @param index Norimas indeksas
     * @return value_type& Elementas tame indekse
     */
    value_type &at(int index);
    /**
     * @brief Pirmasis vektoriaus elementas
     *
     * @return value_type& elemento adresas
     */
    value_type &front();
    /**
     * @brief Paskutinis vektoriaus elementas
     *
     * @return value_type& elemento adresas
     */
    value_type &back();

    pointer data();
    const_pointer data() const;

    /**
     * @brief įterpimas
     *
     * @param index indeksas, po kurio norimma įterpti
     * @param value objektas, kurį norima įterpti
     */
    void insert(int index, const T &value);
    /**
     * @brief elemento pašalinimas
     *
     * @param index indeksas, kurio vietoje esantį objektą norima pašalinti
     */
    void erase(int index);
    iterator erase(const_iterator pos);
    iterator erase(const_iterator first, const_iterator last);
    /**
     * @brief viso vektoriaus išvalymas
     *
     */
    void clear();

    /**
     * @brief Elemento įterpimas gale
     *
     * @tparam Args Objekto tipas
     * @param args Objektas, kurį norima įterpti
     */
    template <typename... Args>
    void emplace_back(Args &&...args);
    /**
     * @brief Elemento įterpimas indekse
     *
     * @tparam Args Objekto tipas
     * @param index Indeksas, kuriame norima įterpti
     * @param args Objektas, kurį norima įterpti
     * @return T*
     */
    template <typename... Args>
    T *emplace(int index, Args &&...args);

    /**
     * @brief Priskyrimas, visi prieš tai buvę elementai pašalinami, o naujasis įterpiamas tiek kartų, koks yra 'count'
     *
     * @param count Norimas elementų skaičius
     * @param value priskiriama reikšmė
     */
    void assign(int count, const T &value);
    /**
     * @brief Priskyrimas, visi prieš tai buvę elementai pašalinami, o vietoj tų elementų įterpiami sąrašo elementai
     *
     * @param ilist Sąrašas
     */
    void assign(std::initializer_list<T> ilist);

    /**
     * @brief Pradžios iteratorius
     *
     * @return iterator Iteratorius, kuris nurodo vektoriaus pradžią
     */
    iterator begin() { return array; }
    /**
     * @brief Pabaigos iteratorius, nurodo sekančią vietą po paskutinio vektoriaus elemento
     *
     * @return iterator Iteratorius, kuris nurodo vektoriaus pabaigą
     */
    iterator end() { return array + Size; }
    const_iterator begin() const { return array; }
    const_iterator end() const { return array + Size; }
    const_iterator cbegin() const { return array; }
    const_iterator cend() const { return array + Size; }

    /**
     * @brief Atvirkštinis pradžios iteratorius nurodo sekančią vietą prieš pirmąjį vektoriaus elementą
     *
     * @return iterator Iteratorius, kuris nurodo vektoriaus atvirkštinę pradžią
     */
    iterator rbegin() { return array + Size - 1; }
    /**
     * @brief Atvirkštinis pabaigos iteratorius
     *
     * @return iterator Iteratorius, kuris nurodo vektoriaus atvirkštinę pabaigą
     */
    iterator rend() { return array - 1; }
    const_iterator rbegin() const { return array + Size - 1; }
    const_iterator rend() const { return array - 1; }

    /**
     * @brief Vektoriaus dydžio pakeitimas, tuščios vektoriaus vietos užpildomos numatytu objektu
     *
     * @param count Norimas naujasis dydis
     */
    void resize(int count);
    /**
     * @brief Vektoriaus dydžio pakeitimas, tuščios vektoriaus vietos užpildomos duotuoju objektu
     *
     * @param count Norimas naujasis dydis
     * @param value Objektas, kuriuo užpildomos tuščios vektoriaus vietos
     */
    void resize(int count, const T &value);
};

#include "vector.tpp"