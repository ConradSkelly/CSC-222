#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Cards.h"
#include <iostream>
#include <string>
#include <doctest/doctest.h>


TEST_CASE("Test can create and render Cards") {
    Cards::Card c1(Cards::Suit::Diamond, Cards::Rank::Jack);
    CHECK(c1.to_string() == "Jack of Diamonds");

    Cards::Card c2;
    CHECK(c2.to_string() == "Joker");

    Cards::Card c3(Cards::Suit::Heart, Cards::Rank::Queen);
    CHECK(c3.to_string() == "Queen of Hearts");

    Cards::Card c4(Cards::Suit::Spade, Cards::Rank::Seven);
    CHECK(c4.to_string() == "7 of Spades");
}

TEST_CASE("Test for comparison of Cards") {
    Cards::Card c1(Cards::Suit::Heart, Cards::Rank::Queen);
    Cards::Card c2(Cards::Suit::Heart, Cards::Rank::Queen);
    Cards::Card c3(Cards::Suit::Spade, Cards::Rank::Ace);
    Cards::Card c4(Cards::Suit::Heart, Cards::Rank::Five);
    Cards::Card c5(Cards::Suit::Heart, Cards::Rank::Four);
    Cards::Card c6(Cards::Suit::Diamond, Cards::Rank::Four);
    CHECK((c1 == c2) == true);
    CHECK((c1 == c3) == false);
    CHECK((c1 > c5) == true);
    CHECK((c1 <= c5) == false);
}

TEST_CASE("Test create Deck with two constructors") {
    Cards::Deck d1(10);
    CHECK(d1.cards.size() == 10);
    CHECK(d1.cards[0].to_string() == "Joker");
    Cards::Deck d2;
    CHECK(d2.cards.size() == 52);
    CHECK(d2.cards[0].to_string() == "2 of Clubs");
    CHECK(d2.cards[51].to_string() == "Ace of Spades");
}
/*
TEST_CASE("Test find Card in Deck") {
    Cards::Deck d;
    Cards::Card c(Cards::Suit::Heart, Cards::Rank::Queen);
    int pos = d.find(c);
    CHECK(d.cards[pos].to_string() == "Queen of Hearts");
    // Create non-existant card to confirm it isn't in the deck
    Cards::Card c2(Cards::Suit::None, Cards::Rank::Queen);
    int pos2 = d.find(c2);
    CHECK(pos2 == -1);
}

TEST_CASE("Test swap_cards in Deck") {
    Cards::Deck d;
    d.swap_cards(0, 51);
    CHECK(d.cards[0].to_string() == "Ace of Spades");
    CHECK(d.cards[51].to_string() == "2 of Clubs");
}

TEST_CASE("Test remove_card and add_card") {
    Cards::Deck deck;
    deck.shuffle();
    CHECK(deck.cards.size() == 52);
    Cards::Card c = deck.remove_card();
    CHECK(deck.cards.size() == 51);
    Cards::Deck deck2(0);
    CHECK(deck2.cards.size() == 0);
    deck2.add_card(c);
    CHECK(deck2.cards.size() == 1);
    CHECK((deck2.cards[0] == c) == true);
}

TEST_CASE("Test can swap two random cards") {
    Cards::Card c1(Cards::Suit::Heart, Cards::Rank::Queen);
    Cards::Card c2(Cards::Suit::Diamond, Cards::Rank::Jack);
    Cards::swap_card(&c1, &c2);
    CHECK(c1.to_string() == "Jack of Diamonds");
    CHECK(c2.to_string() == "Queen of Hearts");
}

TEST_CASE("Test create subdecks") {
    Cards::Deck deck;
    Cards::Deck subdeck = deck.subdeck(2, 10);
    CHECK(subdeck.cards.size() == 9);
    CHECK(subdeck.cards[0].to_string() == "4 of Clubs");
}

TEST_CASE("Test find_lowest_between and sort") {
    Cards::Deck d(0);
    d.add_card(Cards::Card(Cards::Suit::Heart, Cards::Rank::Jack));   // index 0
    d.add_card(Cards::Card(Cards::Suit::Heart, Cards::Rank::Two));    // index 1
    d.add_card(Cards::Card(Cards::Suit::Heart, Cards::Rank::Nine));   // index 2
    d.add_card(Cards::Card(Cards::Suit::Heart, Cards::Rank::Four));   // index 3
    d.add_card(Cards::Card(Cards::Suit::Heart, Cards::Rank::Seven));  // index 4
    d.add_card(Cards::Card(Cards::Suit::Heart, Cards::Rank::Six));    // index 5
    d.add_card(Cards::Card(Cards::Suit::Heart, Cards::Rank::Five));   // index 6
    d.add_card(Cards::Card(Cards::Suit::Heart, Cards::Rank::Eight));  // index 7
    d.add_card(Cards::Card(Cards::Suit::Heart, Cards::Rank::Three));  // index 8
    d.add_card(Cards::Card(Cards::Suit::Heart, Cards::Rank::Ten));    // index 9
    CHECK(d.find_lowest(0, 9) == 1);
    CHECK(d.find_lowest(2, 7) == 3);
    CHECK(d.find_lowest(5, 9) == 8);

    d.sort();
    CHECK(d.cards[0].to_string() == "2 of Hearts");
    CHECK(d.cards[1].to_string() == "3 of Hearts");
    CHECK(d.cards[3].to_string() == "5 of Hearts");
    CHECK(d.cards[8].to_string() == "10 of Hearts");
    CHECK(d.cards[9].to_string() == "Jack of Hearts");
}

TEST_CASE("Test merge_sort") {
    Cards::Deck d(0);
    d.add_card(Cards::Card(Cards::Suit::Heart, Cards::Rank::Queen));
    d.add_card(Cards::Card(Cards::Suit::Spade, Cards::Rank::Ace));
    d.add_card(Cards::Card(Cards::Suit::Club, Cards::Rank::Four));
    d.add_card(Cards::Card(Cards::Suit::Diamond, Cards::Rank::Four));
    d.add_card(Cards::Card(Cards::Suit::Club, Cards::Rank::Five));
    d.add_card(Cards::Card(Cards::Suit::Heart, Cards::Rank::Ten));
    d.add_card(Cards::Card(Cards::Suit::Club, Cards::Rank::Two));
    Cards::Deck d2 = d.merge_sort();
    CHECK(d2.cards[0].to_string() == "2 of Clubs");
    CHECK(d2.cards[1].to_string() == "4 of Clubs");
    CHECK(d2.cards[5].to_string() == "Queen of Hearts");
    CHECK(d2.cards[6].to_string() == "Ace of Spades");
    // Check d is not changed.
    CHECK(d.cards[0].to_string() == "Queen of Hearts");
    CHECK(d.cards[3].to_string() == "4 of Diamonds");
    CHECK(d.cards[6].to_string() == "2 of Clubs");
}
*/
