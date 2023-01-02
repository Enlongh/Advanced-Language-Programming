#pragma once
#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>
using namespace std;
class Student {  //学生信息
public:
	Student();  //默认构造函数
	Student(string id_, string name_, string gender_, string age_, string clase_);  //构造函数

	bool findID(string ID) const;  //判断ID是否与Student中的学号id相等
	bool findName(string stuname) const;  //判断stuname是否与Student中的姓名name相等
	bool findgender(string stugender) const;  //判断stugender是否与Student中的性别gender相等
	bool findage(string stuage) const;  //判断stuage是否与Student中的年龄age相等
	bool findclase(string stuclase) const;  //判断stuclase是否与Student中的班级clase相等

	friend ostream& operator << (ostream& out, const Student& s);  //重载<<运算符，打印Student

	const string getid() const;  //获取学号
	const string getname() const;  //获取姓名
	const string getgender() const;  //获取性别
	const string getage() const;  //获取年龄
	const string getclase() const;  //获取班级

	void changeid(string id_);  //更改学号
	void changename(string name_);  //更改姓名
	void changegender(string gender_);  //更改性别
	void changeage(string age_);  //更改年龄
	void changeclass(string clase_);  //更改班级
	void changeall(string id_, string name_, string gender_, string age_, string clase_);  //更改所有

private:
	string id;  //学号
	string name;  //姓名
	string gender;  //性别
	string age;  //年龄
	string clase;  //班级
};
#endif