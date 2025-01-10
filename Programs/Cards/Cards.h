#pragma once

#include <string>
#include <vector>

namespace Cards {

    enum class Suit { Club, Diamond, Heart, Spade, None };

    enum class Rank {
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King,
        Ace,
        Joker
    };

    class Card {
    public:
        Suit suit;
        Rank rank;
        bool empty;

        Card(Suit suit, Rank rank);
        Card();

        bool operator==(const Card& other) const;
        bool operator>(const Card& other) const;
        bool operator<(const Card& other) const;
        bool operator<=(const Card& other) const;
        bool operator>=(const Card& other) const;

        std::string to_string() const;
    };

    // std::vector<Card> createDeck();
    // std::string deckToString(const std::vector<Card>& deck);
    // void printDeck(const std::vector<Card>& deck);
    // int findCardInDeck(const std::vector<Card>& deck, const Card& card);
    // int binarySearchDeck(const std::vector<Card>& deck, const Card& card);

    void swap_card(Card *card1, Card *card2);
    
    class Deck {
    public:
        std::vector<Card> cards;

        Deck();
        Deck(int size);
        int find(Card card);
        void swap_cards(int card1, int card2);
        void shuffle();
        void add_card(Card card);
        Card remove_card();
        Deck subdeck(int start, int end);
        int find_lowest(int start, int end);
        void sort();
        Deck merge_sort();
    };

} // namespace Cards
