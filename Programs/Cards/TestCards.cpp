#include "Cards.h"
#include <iostream>

int main() {
    auto deck = Cards::createDeck();
    Cards::printDeck(deck);

    Cards::Card searchCard(Cards::Suit::Hearts, Cards::Rank::Queen);
    std::cout << "Card to search: " << searchCard.toString() << std::endl;

    int linearIndex = Cards::findCardInDeck(deck, searchCard);
    std::cout << "Linear search index: " << linearIndex << std::endl;

    int binaryIndex = Cards::binarySearchDeck(deck, searchCard);
    std::cout << "Binary search index: " << binaryIndex << std::endl;

    return 0;
}
