#include<iostream>
using namespace std;
class Student
{
private:
	string name;
	int score;

public:
	Student(string n, int c) :name(n), score(c) {};
	

	bool operator<(const Student &s)
	{
		return score != s.score ? score > s.score : name < s.name;
	}

	friend ostream& operator<<(ostream &os, const Student &s)
	{
		os << "Student:" << s.name << " " << s.score << endl;
		return os;
	}
};
