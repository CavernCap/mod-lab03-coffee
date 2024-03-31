"Copyright [2024] <Kapochkin Mikhail>"
#include "Automata.h"

TEST(automata, turn_it_on) {
    Automata automata;
    automata.on();
    STATES current_state = automata.getState();
  EXPECT_EQ(STATES::ON, current_state);
}

TEST(automata, turn_it_off) {
    Automata automata;
    automata.on();
    automata.off();
    STATES current_state = automata.getState();
  EXPECT_EQ(STATES::OFF, current_state);
}

TEST(automata, coin_balance) {
    Automata automata;
    automata.on();
    automata.coin(10);
    STATES current_state = automata.getState();
    int current_balance = automata.getCash();
  EXPECT_EQ(STATES::WAITING, current_state);
  EXPECT_EQ(10, current_balance);
}

TEST(automata, buy_drink) {
    Automata automata;
    automata.on();
    automata.coin(60);
    automata.choice("HotChocolate");
    STATES current_state = automata.getState();
    int current_balance = automata.getCash();
  EXPECT_EQ(STATES::ON, current_state);
  EXPECT_EQ(0, current_balance);
}

TEST(automata, cancel_operation) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.cancel();
    STATES current_state = automata.getState();
    int current_balance = automata.getCash();
  EXPECT_EQ(STATES::ON, current_state);
  EXPECT_EQ(0, current_balance);
}
