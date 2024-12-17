#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Cards.h"
#include <iostream>
#include <string>
#include <doctest.h>


TEST_CASE("Test can create and render Cards") {
    Cards::Card c1{Cards::Suit::Diamonds, Cards::Rank::Jack};
    CHECK(c1.toString() == "Jack of Diamonds");

    Cards::Card c2;
    CHECK(c2.toString() == "Joker");

    Cards::Card c3(Cards::Suit::Hearts, Cards::Rank::Queen);
    CHECK(c3.toString() == "Queen of Hearts");

    Cards::Card c4(Cards::Suit::Spades, Cards::Rank::Seven);
    CHECK(c4.toString() == "Seven of Spades");
}



