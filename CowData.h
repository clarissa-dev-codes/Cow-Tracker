#ifndef COWDATA_H
#define COWDATA_H

#include <iostream>
#include <string>

using namespace std;


struct CowData
{
	int tagNum;
	bool registered;
	string status = "Alive";
	string gender;
	bool sold;
	string breed;
	string birthDate;
	string deathDate;
};

class Cow
{
private:
	vector<Cow> cows;
	CowData cowData;
	int numCows;

public:
	Cow();
	Cow(const string& filename);

	int getHerdSize();


	void markSold();
	void markDead();


	//setters
	void setTagNum(int tagNum);
	void setRegistered(bool registered);
	void setGender(string gender);
	void setBreed(string breed);
	void setStatus(string status);
	void setBirthDate(string birthDate);
	void setDeathDate(string deathDate);

	//getters
	int getTagNum();
	bool getRegistered();
	string getGender();
	string getBreed();
	string getStatus();
	string getBirthDate();
	string getDeathDate();
	int getHerdSize();


	//needs to be a hash sort
	void sortByTag();

	void removeCow(int tagNum, const string& filename);
	void moveDeadCows(const string& filename, int id);
	void moveSoldCows(const string& filename, int id);
	void addCow(const CowData& data, const string& filename);
	Cow& findCow(int tagNum);

	//save and load functions
	void saveToFile(const string& saveFile) const;
	void loadFromFile(const string& loadFile);


	~Cow() = default;
};
#endif // CowData.h