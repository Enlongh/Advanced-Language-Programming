#include "Student.h"
#include "Function.h"
#include <iostream>
#include <string>
#include <algorithm>
Student::Student() {  //Ĭ�Ϲ��캯��
	id = " ";
	name = " ";
	gender = " ";
	age = " ";
	clase = " ";
}
Student::Student(string id_, string name_, string gender_, string age_, string clase_) {  //���캯��
	id = id_;
	name = name_;
	gender = gender_;
	age = age_;
	clase = clase_;
}
bool Student::findID(string ID) const {  //�ж�ѧ���Ƿ����
	if (id == ID) return true;
	return false;
}
bool Student::findName(string stuName) const {  //�ж������Ƿ����
	if (isAnagram(name, stuName)) return true;  //isAnagram()�ж�����string�����۴�Сд���Ƿ����
	return false;
}
bool Student::findgender(string stugender) const {  //�ж��Ա��Ƿ����
	if (isAnagram(gender, stugender)) return true;  //
	return false;
}
bool Student::findage(string stuage) const {  //�ж������Ƿ���� 
	if (age == stuage) return true;
	return false;
}
bool Student::findclase(string stuclase) const {  //�жϰ༶�Ƿ����
	if (getNum(clase) == getNum(stuclase)) return true;  //getNum()������ȡstring�е�����
	return false;
}
ostream& operator << (ostream& out, const Student& s) {  //������������
	out << s.id << "\t" << s.name << "\t" << s.gender << "\t" << s.age << "\t" << s.clase;
	return out;
}
const string Student::getid() const {  //��ȡid
	return id;
}
const string Student::getname() const {  //��ȡ����
	return name;
}
const string Student::getgender() const {  //��ȡ�Ա�
	return gender;
}
const string Student::getage() const {  //��ȡ����
	return age;
}
const string Student::getclase() const {  //��ȡ�༶
	return clase;
}
void Student::changeid(string id_) {  //�ı�ѧ��
	id = id_;
}
void Student::changename(string name_) {  //�ı�����
	name = name_;
}
void Student::changegender(string gender_) {  //�ı��Ա�
	gender = gender_;
}
void Student::changeage(string age_) {  //�ı�����
	age = age_;
}
void Student::changeclass(string clase_) {  //�ı�༶
	clase = clase_;
}
void Student::changeall(string id_, string name_, string gender_, string age_, string clase_) {  //�ı�������Ϣ
	id = id_;
	name = name_;
	gender = gender_;
	age = age_;
	clase = clase_;
}
