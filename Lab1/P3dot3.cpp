#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
#include "P3dot3.h"

namespace P3dot3 {
	GameEntry::GameEntry(const std::string& name, int score)
	{
		m_name = name;
		m_score = score;
	}

	std::string GameEntry::getName() const
	{
		return m_name;
	}

	void GameEntry::setName(std::string name)
	{
		m_name = name;
	}

	int GameEntry::getScore() const
	{
		return m_score;
	}

	void GameEntry::setScore(int score)
	{
		m_score = score;
	}

	Scores::Scores(int maxEntries)
	{
		m_maxEntries = maxEntries; // save the max size
		m_entries = new GameEntry[maxEntries]; // allocate array storage
		m_numEntries = 0; // initially no elements

		for (int i = 0; i < m_maxEntries; i++)
		{
			m_entries[i] = GameEntry("", 0);
		}
	}

	Scores::~Scores()
	{
		delete[] m_entries;
	}

	void Scores::add(const GameEntry& entry)
	{
		if (m_numEntries < m_maxEntries)
		{
			m_entries[m_numEntries] = entry;
			m_numEntries++;
		}
		else
		{
			throw std::out_of_range("The entry list is full");
		}
	}

	GameEntry Scores::remove(int index)
	{
		if (index < 0 || index > m_numEntries)
		{
			throw(std::out_of_range("The index entered is out of range!"));
		}

		// Store the values temporarily so we can return them
		std::string nameFromDeleted = m_entries[index].getName();
		int scoreFromDeleted = m_entries[index].getScore();

		// Swap this entry with the last entry
		m_entries[index].setName(m_entries[m_maxEntries - 1].getName());
		m_entries[index].setScore(m_entries[m_maxEntries - 1].getScore());

		// Blank out the last entry
		m_entries[m_maxEntries - 1].setName("");
		m_entries[m_maxEntries - 1].setScore(0);

		// Return a copy of what we just deleted
		return GameEntry(nameFromDeleted, scoreFromDeleted);
	}

	void run() {

		Scores scoreboard = Scores(10);

		GameEntry game1 = GameEntry("Jamie", 10000);
		GameEntry game2 = GameEntry("Jamie", 20000);
		GameEntry game3 = GameEntry("Jamie", 30000);
		GameEntry game4 = GameEntry("Jamie", 40000);
		GameEntry game5 = GameEntry("Jamie", 50000);
		GameEntry game6 = GameEntry("Jamie", 60000);
		GameEntry game7 = GameEntry("Jamie", 70000);
		GameEntry game8 = GameEntry("Jamie", 80000);
		GameEntry game9 = GameEntry("Jamie", 90000);
		GameEntry game10 = GameEntry("Jamie", 100000);
		GameEntry game11 = GameEntry("Jamie", 110000);

		try
		{
			scoreboard.add(game1);
		}
		catch (std::out_of_range exception)
		{
			std::cout << exception.what() << std::endl << std::endl;
		}

		try
		{
			scoreboard.add(game2);
		}
		catch (std::out_of_range exception)
		{
			std::cout << exception.what() << std::endl << std::endl;
		}

		try
		{
			scoreboard.add(game3);
		}
		catch (std::out_of_range exception)
		{
			std::cout << exception.what() << std::endl << std::endl;
		}

		try
		{
			scoreboard.add(game4);
		}
		catch (std::out_of_range exception)
		{
			std::cout << exception.what() << std::endl << std::endl;
		}

		try
		{
			scoreboard.add(game5);
		}
		catch (std::out_of_range exception)
		{
			std::cout << exception.what() << std::endl << std::endl;
		}

		try
		{
			scoreboard.add(game6);
		}
		catch (std::out_of_range exception)
		{
			std::cout << exception.what() << std::endl << std::endl;
		}

		try
		{
			scoreboard.add(game7);
		}
		catch (std::out_of_range exception)
		{
			std::cout << exception.what() << std::endl << std::endl;
		}

		try
		{
			scoreboard.add(game8);
		}
		catch (std::out_of_range exception)
		{
			std::cout << exception.what() << std::endl << std::endl;
		}

		try
		{
			scoreboard.add(game9);
		}
		catch (std::out_of_range exception)
		{
			std::cout << exception.what() << std::endl << std::endl;
		}

		try
		{
			scoreboard.add(game10);
		}
		catch (std::out_of_range exception)
		{
			std::cout << exception.what() << std::endl << std::endl;
		}

		try
		{
			scoreboard.add(game11);
		}
		catch (std::out_of_range exception)
		{
			std::cout << exception.what() << std::endl << std::endl;
		}

		try
		{
			GameEntry toRemove = scoreboard.remove(0);
			std::cout << toRemove.getName() << " " << toRemove.getScore() << " removed." << std::endl << std::endl;
		}
		catch (std::out_of_range exception)
		{
			std::cout << exception.what() << std::endl << std::endl;
		}

		try
		{
			scoreboard.remove(0);
		}
		catch (std::out_of_range exception)
		{
			std::cout << exception.what() << std::endl << std::endl;
		}
	}
}