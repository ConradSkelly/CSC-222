#include "Cards.h"
#include <iostream>

namespace Cards {

    Card::Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}

    bool Card::operator==(const Card& other) const {
        return (suit == other.suit && rank == other.rank);
    }

    bool Card::operator>(const Card& other) const {
        return suit > other.suit || (suit == other.suit && rank > other.rank);
    }

    bool Card::operator<(const Card& other) const {
        return suit < other.suit || (suit == other.suit && rank < other.rank);
    }

    bool Card::operator<=(const Card& other) const {
        return !(*this > other);
    }

    bool Card::operator>=(const Card& other) const {
        return !(*this < other);
    }

    std::string Card::toString() const {
        static const std::string rankNames[] = {
            "Joker", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
            "Eight", "Nine", "Ten", "Jack", "Queen", "King"
        };

        static const std::string suitNames[] = {
            "Clubs", "Diamonds", "Hearts", "Spades"
        };

        return rankNames[static_cast<int>(rank)] + " of " + suitNames[static_cast<int>(suit)];
    }

    std::vector<Card> createDeck() {
        std::vector<Card> deck;
        for (int suit = 0; suit < 4; ++suit) {
            for (int rank = 1; rank <= 13; ++rank) {
                deck.emplace_back(static_cast<Suit>(suit), static_cast<Rank>(rank));
            }
        }
        return deck;
    }

    std::string deckToString(const std::vector<Card>& deck) {
        std::string result;
        for (const auto& card : deck) {
            result += card.toString() + ", ";
        }
        if (!result.empty()) {
            result.pop_back();
            result.pop_back();
        }
        return result;
    }

    void printDeck(const std::vector<Card>& deck) {
        std::cout << deckToString(deck) << std::endl;
    }

    int findCardInDeck(const std::vector<Card>& deck, const Card& card) {
        for (size_t i = 0; i < deck.size(); ++i) {
            if (deck[i] == card) return static_cast<int>(i);
        }
        return -1;
    }

    int binarySearchDeck(const std::vector<Card>& deck, const Card& card) {
        int low = 0, high = static_cast<int>(deck.size()) - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (deck[mid] == card) return mid;
            if (deck[mid] > card) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }

} // namespace Cards
