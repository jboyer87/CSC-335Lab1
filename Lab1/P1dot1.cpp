#include "P1dot1.h"

namespace P1dot1 {
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

	const void Punishment::write()
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

	const unsigned Punishment::getRandomCharacterInPhrase()
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