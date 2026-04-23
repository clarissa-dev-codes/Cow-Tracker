#include "CowData.h"
#include "ErrorClass.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

//need the load in function to read in the data from the file and create cow objects, 
// then store them in a vector or array.

//use binary files to save and load for more efficient storage and retrieval.
//helper functions

Cow::Cow() : numCows(0)
{
	cowData.tagNum = 0;
	cowData.registered = false;
	cowData.sold = false;
	cowData.status = "Alive";
}

Cow::Cow(const string& filename) : numCows(0)
{
	loadFromFile(filename);
}

int Cow::getHerdSize()
{
	return static_cast<int>(cows.size());
}

void Cow::markSold()
{
	cowData.sold = true;
	cowData.status = "Sold";
}

void Cow::markDead()
{
	cowData.status = "Dead";
}

//setters
void Cow::setTagNum(int tagNum)
{
	cowData.tagNum = tagNum;
}
void Cow::setRegistered(bool registered)
{
	cowData.registered = registered;
}
void Cow::setGender(string gender)
{
	cowData.gender = gender;
}
void Cow::setBreed(string breed)
{
	cowData.breed = breed;
}
void Cow::setStatus(string status)
{
	cowData.status = status;
}
void Cow::setBirthDate(string birthDate)
{
	cowData.birthDate = birthDate;
}
void Cow::setDeathDate(string deathDate)
{
	cowData.deathDate = deathDate;
}

//getters
int Cow::getTagNum()
{
	return cowData.tagNum;
}
bool Cow::getRegistered()
{
	return cowData.registered;
}
string Cow::getGender()
{
	return cowData.gender;
}
string Cow::getBreed()
{
	return cowData.breed;
}
string Cow::getStatus()
{
	return cowData.status;
}
string Cow::getBirthDate()
{
	return cowData.birthDate;
}
string Cow::getDeathDate()
{
	return cowData.deathDate;
}

Cow& Cow::findCow(int tagNum)
{
	for (auto& cow : cows)
	{
		if (cow.getTagNum() == tagNum)
		{
			return cow;
		}
		else
		{
			throw animalNotFoundException();
		}
	}
	
}

void Cow::removeCow(int tagNum, const string& filename)
{
	vector<Cow> tempList;
	bool found = false;

	for (size_t i = 0; i < cows.size(); ++i)
	{
		if (cows[i].getTagNum() == tagNum)
		{
			found = true;
			continue; // Skip the cow to be removed
		}
		tempList.push_back(cows[i]);
	}

	if(!found)
	{
		throw animalNotFoundException();
	}
	else
	{
		this->cows = tempList;
		saveToFile(filename);
	}
}

void Cow::moveDeadCows(const string& filename, int id)
{
	Cow& tempCow = findCow(id);
	tempCow.setStatus("Dead");
	if (tempCow.getStatus() == "Dead")
	{
		removeCow(id, filename);
	}
	else
	{
		throw wrongIDException();
	}

	removeCow(id, "mainHerd.dat");
	saveToFile("deadCows.dat");
}

void Cow::moveSoldCows(const string& filename, int id)
{
	
}

void Cow::addCow(const CowData& data, const string& filename)
{

}



void writeString(ostream& out, const string& str) 
{
	size_t length = str.size();
	out.write(reinterpret_cast<const char*>(&length), sizeof(length));
	out.write(str.c_str(), length);
}

string readString(istream& in) 
{
	size_t length;
	in.read(reinterpret_cast<char*>(&length), sizeof(length));
	string str(length, '\0');
	in.read(&str[0], length);
	return str;
}

void Cow::saveToFile(const string& saveFile) const
{
	ofstream out(saveFile, ios::binary);
	if (!out)
	{
		throw fileErrorException();
	}

	for (const auto& c : cows)
	{
		out.write(reinterpret_cast<const char*>(&c.cowData.tagNum), sizeof(c.cowData.tagNum));
		out.write(reinterpret_cast<const char*>(&c.cowData.registered), sizeof(c.cowData.registered));
		out.write(reinterpret_cast<const char*>(&c.cowData.sold), sizeof(c.cowData.sold));

		writeString(out, c.cowData.status);
		writeString(out, c.cowData.gender);
		writeString(out, c.cowData.breed);
		writeString(out, c.cowData.birthDate);
		writeString(out, c.cowData.deathDate);
	}

	out.close();
}

void Cow::loadFromFile(const string& loadFile)
{
	ifstream in(loadFile, ios::binary);
	if (!in)
	{
		throw fileErrorException();
	}
	while (in.peek() != EOF)
	{
		CowData data;
		in.read(reinterpret_cast<char*>(&data.tagNum), sizeof(data.tagNum));
		in.read(reinterpret_cast<char*>(&data.registered), sizeof(data.registered));
		in.read(reinterpret_cast<char*>(&data.sold), sizeof(data.sold));
		data.status = readString(in);
		data.gender = readString(in);
		data.breed = readString(in);
		data.birthDate = readString(in);
		data.deathDate = readString(in);

		Cow cow;
		cow.cowData = data;
		cows.push_back(cow);
	}

	in.close();

}