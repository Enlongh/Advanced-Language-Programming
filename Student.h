#pragma once
#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>
using namespace std;
class Student {  //ѧ����Ϣ
public:
	Student();  //Ĭ�Ϲ��캯��
	Student(string id_, string name_, string gender_, string age_, string clase_);  //���캯��

	bool findID(string ID) const;  //�ж�ID�Ƿ���Student�е�ѧ��id���
	bool findName(string stuname) const;  //�ж�stuname�Ƿ���Student�е�����name���
	bool findgender(string stugender) const;  //�ж�stugender�Ƿ���Student�е��Ա�gender���
	bool findage(string stuage) const;  //�ж�stuage�Ƿ���Student�е�����age���
	bool findclase(string stuclase) const;  //�ж�stuclase�Ƿ���Student�еİ༶clase���

	friend ostream& operator << (ostream& out, const Student& s);  //����<<���������ӡStudent

	const string getid() const;  //��ȡѧ��
	const string getname() const;  //��ȡ����
	const string getgender() const;  //��ȡ�Ա�
	const string getage() const;  //��ȡ����
	const string getclase() const;  //��ȡ�༶

	void changeid(string id_);  //����ѧ��
	void changename(string name_);  //��������
	void changegender(string gender_);  //�����Ա�
	void changeage(string age_);  //��������
	void changeclass(string clase_);  //���İ༶
	void changeall(string id_, string name_, string gender_, string age_, string clase_);  //��������

private:
	string id;  //ѧ��
	string name;  //����
	string gender;  //�Ա�
	string age;  //����
	string clase;  //�༶
};
#endif