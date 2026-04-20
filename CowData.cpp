#include "CowData.h"
#include <iostream>
#include <vector>
#include <algorithm>

//need the load in function to read in the data from the file and create cow objects, 
// then store them in a vector or array.
// I need to add a get size function to return the size of the herd.
// 
// 
//the methods here, may get rid of them
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