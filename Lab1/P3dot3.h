#pragma once
#include <string>
#include <exception>
#include <stdexcept>

// Give C++ code for performing add(e) and remove(i) functions for game entries stored in
// an array a, as in class Scores in Section 3.1.1, except this time, don't maintain the 
// game entries in order. Assume that we still need to keep n entries stored in indices 0
// to n−1. Try to implement the add and remove functions without using any loops, so that
// the number of steps they perform does not depend on n.

namespace P3dot3 {
	class GameEntry {
	public:
		GameEntry(const std::string& name = "", int score = 0);
		
		std::string getName() const;
		void setName(std::string name);
		
		int getScore() const; 
		void setScore(int score);

	
	private:
		std::string m_name; 
		
		int m_score; 
	};

	class Scores {
	public:
		Scores(int maxEnt = 10);
		
		~Scores();
		
		void add(const GameEntry& entry);
		
		GameEntry remove(int index) throw(std::out_of_range);
	private:
		int m_maxEntries;
		
		int m_numEntries;
		
		GameEntry* m_entries;
	};

	void run();
}