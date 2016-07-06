#include <iostream>
using namespace std;
struct tag_student1
{
	char sName[11];
	int nScores[3];
	struct tag_student1 * next;
	int Aver()	{
		return this->nScores[0];
	}
	void OutPut()	{
		cout << sName;
	}
};
typedef struct tag_student1 Student1;


//从文件中读取数据，形成链表
Student1 * GetLinkTableFromFile(const char * pFileFullPathName);
void OutPutLink(Student1 * pHeader);
void DeleteElement(Student1 * pHeader, const char * pName);
void AddElement(Student1 * pHeader, const char *pName, int nScore1, int nScore2, int nScore3);
void Sort(Student1 * pHeader, int nFlag, bool bDec);

Student1 GetElementByName(Student1 * pHeader, const char *pName);
void Clear(Student1 * pHeader);
Student1 * CopyLink(Student1 * pHeader);
void inversion(Student1 *pHeader);//实现翻转
