// Design the data structures for a generic deck of cards.
// Explain how you would subclass the data structures to implement Blackjack
//
// Thoughts:
// 1. The core classes here are Deck and Card
//    - We may also want to list our suits and card values in an enum
// 2. When implementing Blackjack, an Ace may be considered a 1 or 11
//    - in general an Ace can be considered an 11 until the player busts
//    - then the Ace will be considered a 1
//    - If there are multiple Aces in a hand, one Ace may need a value of 11 while the other is a 1
//    - So when a player busts, we switch one Ace to a 1
//    - If the player busts again we can switch one more Ace to a 1
// 3. Also, during a game of Blackjack, we will also need a Hand class consisting of two or more cards

#include "stdafx.h"
#include <vector>

enum Suit
{
	HEARTS,
	SPADES,
	DIAMONDS,
	CLUBS,
};

enum Value
{
	ACE_ONE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 10,
	QUEEN = 10,
	KING = 10,
	ACE = 11
};

class Card
{
private:
	Suit m_suit;
	Value m_value;
public:
	Card(Suit suit, Value value) : m_suit{ suit }, m_value{ value }
	{

	}
};

class Deck
{
private:
	std::vector<Card> cards;
public:
	Deck()
	{
		// build 52 card deck
	}
	void shuffle()
	{
		// shuffle cards vector
	}
	Card drawCard()
	{
		// draw top card from cards vector
	}
};

class Hand
{
private:
	std::vector<Card> hand;
public:
	Hand()
	{
		// empty to begin with
	}
	void addCard()
	{
		// use Deck::drawCard() 
	}
};