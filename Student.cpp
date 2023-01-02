#include "Student.h"
#include "Function.h"
#include <iostream>
#include <string>
#include <algorithm>
Student::Student() {  //默认构造函数
	id = " ";
	name = " ";
	gender = " ";
	age = " ";
	clase = " ";
}
Student::Student(string id_, string name_, string gender_, string age_, string clase_) {  //构造函数
	id = id_;
	name = name_;
	gender = gender_;
	age = age_;
	clase = clase_;
}
bool Student::findID(string ID) const {  //判断学号是否相等
	if (id == ID) return true;
	return false;
}
bool Student::findName(string stuName) const {  //判断姓名是否相等
	if (isAnagram(name, stuName)) return true;  //isAnagram()判断两个string（无论大小写）是否相等
	return false;
}
bool Student::findgender(string stugender) const {  //判断性别是否相等
	if (isAnagram(gender, stugender)) return true;  //
	return false;
}
bool Student::findage(string stuage) const {  //判断年龄是否相等 
	if (age == stuage) return true;
	return false;
}
bool Student::findclase(string stuclase) const {  //判断班级是否相等
	if (getNum(clase) == getNum(stuclase)) return true;  //getNum()函数获取string中的数字
	return false;
}
ostream& operator << (ostream& out, const Student& s) {  //输出运算符重载
	out << s.id << "\t" << s.name << "\t" << s.gender << "\t" << s.age << "\t" << s.clase;
	return out;
}
const string Student::getid() const {  //获取id
	return id;
}
const string Student::getname() const {  //获取姓名
	return name;
}
const string Student::getgender() const {  //获取性别
	return gender;
}
const string Student::getage() const {  //获取年龄
	return age;
}
const string Student::getclase() const {  //获取班级
	return clase;
}
void Student::changeid(string id_) {  //改变学号
	id = id_;
}
void Student::changename(string name_) {  //改变姓名
	name = name_;
}
void Student::changegender(string gender_) {  //改变性别
	gender = gender_;
}
void Student::changeage(string age_) {  //改变年龄
	age = age_;
}
void Student::changeclass(string clase_) {  //改变班级
	clase = clase_;
}
void Student::changeall(string id_, string name_, string gender_, string age_, string clase_) {  //改变所有信息
	id = id_;
	name = name_;
	gender = gender_;
	age = age_;
	clase = clase_;
}
