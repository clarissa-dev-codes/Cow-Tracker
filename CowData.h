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
	CowData data;

public:
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


	//needs to be a hash sort
	void sortByTag(Cow* cows);


	~Cow() = default;
};
#endif // CowData.h