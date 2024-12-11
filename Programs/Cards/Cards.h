#pragma once

#include <string>
#include <vector>

namespace Cards {

    enum class Suit { Clubs, Diamonds, Hearts, Spades };

    enum class Rank {
        Joker,
        Ace,
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
        King
    };

    class Card {
    public:
        Suit suit;
        Rank rank;

        Card(Suit suit, Rank rank);

        bool operator==(const Card& other) const;
        bool operator>(const Card& other) const;
        bool operator<(const Card& other) const;
        bool operator<=(const Card& other) const;
        bool operator>=(const Card& other) const;

        std::string toString() const;
    };

    std::vector<Card> createDeck();
    std::string deckToString(const std::vector<Card>& deck);
    void printDeck(const std::vector<Card>& deck);
    int findCardInDeck(const std::vector<Card>& deck, const Card& card);
    int binarySearchDeck(const std::vector<Card>& deck, const Card& card);

} // namespace Cards
