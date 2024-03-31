"Copyright [2024] <Kapochkin Mikhail>"
#include "Automata.h"

int main() {
    Automata automata;
    automata.on();
    automata.coin(50);
    automata.coin(60);
    automata.getMenu();
    automata.choice("Latte");
    automata.off();
    return 0;
}
