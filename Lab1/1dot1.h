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
		void write();
		unsigned getRandomCharacterInPhrase();
		void randomizePhraseTypos();

	private:
		std::string m_phraseToRepeat;
		unsigned m_numberOfRepetitions;
		unsigned m_numberOfTypos;
		int* m_phrasesWithTypos;
	};

	Punishment::Punishment(std::string phraseToRepeat, unsigned numberOfRepetitions, unsigned numberOfTypos)
	{
		m_phraseToRepeat = phraseToRepeat;
		m_numberOfRepetitions = numberOfRepetitions;
		m_numberOfTypos = numberOfTypos;
		m_phrasesWithTypos = new int[m_numberOfTypos];

		randomizePhraseTypos();
	}

	Punishment::~Punishment()
	{
		delete[] m_phrasesWithTypos;
	}

	void Punishment::write()
	{
		// Grab the size of the array and the end of the array for use later
		size_t arraySize = sizeof(m_phrasesWithTypos) / sizeof(int);

		int *end = m_phrasesWithTypos + m_numberOfTypos;

		// Write the phrase the appropriate amount of times
		for (unsigned counter = 1; counter <= m_numberOfRepetitions; counter++)
		{
			int *result = std::find(m_phrasesWithTypos, end, counter);

			std::string phrase = m_phraseToRepeat;

			// if this is in the phrases with typos array
			if (result != end)
			{
				// add a typo to the phrase
				//phrase[letterToMessUp] = randomChar;
				phrase[this->getRandomCharacterInPhrase()] = 'a' + rand() % 26;
			}

			std::cout << counter << ": " << phrase << std::endl;
		}
	}

	unsigned Punishment::getRandomCharacterInPhrase()
	{
		// Return a random character in the phrase
		// Make sure it's not a space (while loop)
		return std::rand() % m_phraseToRepeat.length();
	}

	void Punishment::randomizePhraseTypos()
	{
		for (int counter = 0; counter < m_numberOfTypos; counter++)
		{
			// Get a random number between 1 and the number of repetitions
			int phraseToAddTypoTo = std::rand() % m_numberOfRepetitions + 1;

			// Mark that phrase in the phrases with typos array to be mangled later on
			m_phrasesWithTypos[counter] = phraseToAddTypoTo;
		}
	}

	void run()
	{
		Punishment testRun = Punishment("I will always use object oriented design", 100, 8);

		testRun.write();
	}
}