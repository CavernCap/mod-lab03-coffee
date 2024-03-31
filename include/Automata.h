//Copyright 2024 Kapochkin Mikhail
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
enum class STATES {
    OFF,
    ON,
    WAITING,
    ACCEPT,
    COOKING
};
class Automata {
 private:
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;
 public:
    Automata();
    void on();
    void off();
    void coin(int amount);
    void getMenu();
    STATES getState() const;
    int getCash() const;
    void choice(const std::string& item);
    bool check(int price) const;
    void cancel();
    void cook(const std::string& item);
    void finish();
};
