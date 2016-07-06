#pragma once
#include <iostream>
struct tag_student
{
	char sName[11];
	int nScores[3];
	struct tag_student * next;
	int Aver()	{
		return this->nScores[0];
	}
	void OutPut()	{
		std::cout << sName;
	}
};
typedef struct tag_student Student;
class structlink
{
	
public:
	structlink(const char * pFilefullPathName);

	Student * GetLinkTableFromFile(const char * pFileFullPathName);
	void OutPutLink(Student * pHeader);
	void DeleteElement(Student * pHeader, const char * pName);
	void AddElement(Student * pHeader, const char *pName, int nScore1, int nScore2, int nScore3);
	void Sort(Student * pHeader, int nFlag, bool bDec);
	Student GetElementByName(Student * pHeader, const char *pName);
	void Clear(Student * pHeader);
	Student * CopyLink(Student * pHeader);
	void inversion(Student *pHeader);
	~structlink();
};

