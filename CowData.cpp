#include "CowData.h"
#include "ErrorClass.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//need the load in function to read in the data from the file and create cow objects, 
// then store them in a vector or array.
// I need to add a get size function to return the size of the herd.
int Cow::getHerdSize(Cow* cows)
{
	int count = 0;
	for (int i = 0; i < sizeof(cows) / sizeof(cows[0]); i++)
	{
		if (cows[i].getStatus() == "Alive")
		{
			count++;
		}
	}
	return count;
}

//use binary files to save and load for more efficient storage and retrieval.
//helper functions
void writeString(ofstream& out, const string& str)
{
	size_t length = str.size();
	out.write(reinterpret_cast<const char*>(&length), sizeof(length));
	out.write(str.c_str(), length);
}

void readString(ifstream& in, string& str)
{
	size_t length;
	in.read(reinterpret_cast<char*>(&length), sizeof(length));
	str.resize(length);
	in.read(&str[0], length);
}

//loading functions


//saving functions 
void Cow::saveToFile(const string& saveFile) const
{
	ofstream outFile(saveFile, ios::binary);
	if (!outFile)
	{
		throw fileErrorException();
	}
	
	//need the size from the getHerdSize function to know how many cows to save.
	
	
}




void Cow::markSold()
{
	data.sold = true;
}
void Cow::markDead()
{
	data.status = "Dead";
}

//setters
void Cow::setTagNum(int tagNum)
{
	data.tagNum = tagNum;
}
void Cow::setRegistered(bool registered)
{
	data.registered = registered;
}
void Cow::setGender(string gender)
{
	data.gender = gender;
}
void Cow::setBreed(string breed)
{
	data.breed = breed;
}
void Cow::setStatus(string status)
{
	data.status = status;
}
void Cow::setBirthDate(string birthDate)
{
	data.birthDate = birthDate;
}
void Cow::setDeathDate(string deathDate)
{
	data.deathDate = deathDate;
}

//getters
int Cow::getTagNum()
{
	return data.tagNum;
}
bool Cow::getRegistered()
{
	return data.registered;
}
string Cow::getGender()
{
	return data.gender;
}
string Cow::getBreed()
{
	return data.breed;
}
string Cow::getStatus()
{
	return data.status;
}
string Cow::getBirthDate()
{
	return data.birthDate;
}
string Cow::getDeathDate()
{
	return data.deathDate;
}


//hash sort
void Cow::sortByTag(Cow* cows)
{
	
}