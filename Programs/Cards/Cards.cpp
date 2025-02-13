#include "Cards.h"
#include <iostream>
#include <random>

namespace Cards {

	  Card::Card() {
        suit = Suit::None;
        rank = Rank::Joker;
	  }

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

    std::string Card::to_string() const {
        if (suit == Suit::None || rank == Rank::Joker)
            return "Joker";
        
        static const std::string rankNames[] = {
            "2", "3", "4", "5", "6", "7", "8", "9",
            "10", "Jack", "Queen", "King", "Ace", "Joker"
        };

        static const std::string suitNames[] = {
            "Clubs", "Diamonds", "Hearts", "Spades", "None"
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
            result += card.to_string() + ", ";
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

    Deck::Deck() {
        cards = std::vector<Card>();

        for (int suit = 0; suit < 4; suit++)
            for (int rank = 0; rank < 13; rank++)
                cards.push_back(Card(static_cast<Suit>(suit), static_cast<Rank>(rank)));
    }

    Deck::Deck(int length) {
        while (cards.size() < length)
            cards.push_back(Card());
    }

    int Deck::find(Card card) {
        for (int index = 0; index < cards.size(); index++)
            if (cards[index] == card)
                return index;
        return -1;
    }

    void Deck::swap_cards(int card1, int card2) {
        Card temp = cards[card1];
        cards[card1] = cards[card2];
        cards[card2] = temp;
    }

    void Deck::add_card(Card card) {
        cards.push_back(card);
    }

    Card Deck::remove_card() {
        Card card = cards.back();
        cards.pop_back();
        return card;
    }

    void Deck::shuffle() {
        std::default_random_engine rng = std::default_random_engine();
        std::shuffle(cards.begin(), cards.end(), rng);
    }

    void swap_card(Card *card1, Card *card2) {
        Card temp = *card1;
        *card1 = *card2;
        *card2 = temp;
    }

} // namespace Cards
