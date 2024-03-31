#include "pch.h"
#include "Automata.h"


// Конструктор
Automata::Automata() {
    cash = 0;
    state = STATES::OFF;
    menu.push_back("Latte");
    menu.push_back("Americano");
    menu.push_back("HotChocolate");
    menu.push_back("BlackTea");
    prices.push_back(100);
    prices.push_back(80);
    prices.push_back(60);
    prices.push_back(30);
}

// Включение автомата
void Automata::on() {
    state = STATES::ON;
    //std::cout << "Automata is turned on." << std::endl;
}

// Выключение автомата
void Automata::off() {
    state = STATES::OFF;
    //std::cout << "Automata is turned off." << std::endl;
}
// Занесение денег на счет
void Automata::coin(int amount) {
    if (state == STATES::WAITING || state == STATES::ON) {
        cash += amount;
        //std::cout << amount << " added to the balance. Total: " << cash << std::endl;
        state = STATES::WAITING;
    }
    else {
        //std::cout << "Invalid operation. Automata is not waiting for a coin." << std::endl;
    }
}

// Получение меню
void Automata::getMenu() {
    std::cout << "Menu\n";
    for (unsigned int i = 0; i < menu.size(); i++) {
        //std::cout << menu[i] << " - " << prices[i] << '\n';
    }
}

// Получение текущего состояния
STATES Automata::getState() const {
    return state;
}

int Automata::getCash()const {
    return cash;
}

// Выбор напитка
void Automata::choice(const std::string& item) {
    if (state == STATES::WAITING) {
        auto it = std::find(menu.begin(), menu.end(), item);
        if (it != menu.end()) {
            int index = std::distance(menu.begin(), it);
            int price = prices[index];
            if (check(price)) {
                //std::cout << "You've chosen " << item << ". Please wait while it's being prepared." << std::endl;
                state = STATES::COOKING;
                cook(item);
            }
            else {
                //std::cout << "Insufficient funds. Please add more money." << std::endl;
            }
        }
        else {
            //std::cout << "Invalid choice. Please select from the menu." << std::endl;
        }
    }
    else {
        //std::cout << "Invalid operation. Automata is not waiting for a choice." << std::endl;
    }
}

// Проверка наличия необходимой суммы
bool Automata::check(int price) const {
    return cash >= price;
}

// Отмена сеанса обслуживания
void Automata::cancel() {
    if (state == STATES::WAITING || state == STATES::ACCEPT) {
        //std::cout << "Transaction canceled. Returning money." << std::endl;
        cash = 0;
        state = STATES::ON;
    }
    else {
        //std::cout << "Invalid operation. No transaction to cancel." << std::endl;
    }
}

// Имитация приготовления напитка
void Automata::cook(const std::string& item) {
    //std::cout << "Preparing " << item << "... Done." << std::endl;
    finish();
}

// Завершение обслуживания
void Automata::finish() {
    //std::cout << "Transaction completed. Enjoy your drink!" << std::endl;
    cash = 0;
    state = STATES::ON;
}
