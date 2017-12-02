#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

// Instructions for P1dot1:
// A common punishment for school children is to write out the same sentence multiple 
// times. Write a C++ stand - alone program that will write out the following sentence 
// one hundred times : "I will always use object oriented design." Your program should 
// number each of the sentences and it should "accidentally" make eight different random
// - looking typos at various points in the listing, so that it looks like a human typed 
// it all by hand.

namespace P1dot1
{
	class Punishment {
	public:
		Punishment(std::string phraseToRepeat, unsigned numberOfRepetitions, unsigned numberOfTypos);

		~Punishment();
		const void write();
		const unsigned getRandomCharacterInPhrase();
		void randomizePhraseTypos();

	private:
		std::string m_phraseToRepeat;
		unsigned m_numberOfRepetitions;
		unsigned m_numberOfTypos;
		int* m_phrasesWithTypos;
	};

	void run();
}