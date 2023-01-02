#include "Attendance.h"
#include "Function.h"
#include <iostream>
#include <string>
Attendance::Attendance() {  //默认构造函数
	date = " ";
	courseNumber = " ";
	courseName = " ";
	studentName = " ";
	absenteeismType = " ";
	id = " ";
}
Attendance::Attendance(string date_, string courseNumber_, string courseName_, string studentName_, string absenteeismType_, string id_) {  //构造函数
	date = date_;
	courseNumber = courseNumber_;
	courseName = courseName_;
	studentName = studentName_;
	absenteeismType = absenteeismType_;  //四种类型 
	id = id_;
}
bool Attendance::findCourse(string course) const {  //判断课程名是否相等
	if (isAnagram(courseName, course)) return true;  //判断两字符串无论大小写是否相等
	return false;
}
bool Attendance::findStudent(string student, string studentid) const {  //判断学生姓名和学号是否相等
	if (isAnagram(studentName, student) && (id == studentid)) return true;
	return false;
}
bool Attendance::findCouStu(string course, string student, string studentid) const {  //判断课程名、学生姓名和学号是否相等
	if (isAnagram(courseName, course) && isAnagram(studentName, student) && (id == studentid)) return true;
	return false;
}
bool Attendance::finddate(string attdate) const {  //判断日期是否相等
	if (getNum(date) == getNum(attdate)) return true;  //获取字符串中的数字
	return false;
}
bool Attendance::findcourseNumber(string attnumber) const {  //判断课程节数是否相等
	if (getNum(courseNumber) == getNum(attnumber)) return true;
	return false;
}
bool Attendance::findstudentName(string attname) const {  //判断学生姓名是否相等
	if (isAnagram(studentName, attname)) return true;
	return false;
}
bool Attendance::findabsenteeism(string attabsenteeism) const {  //判断课程类型是否相等
	if (isAnagram(absenteeismType, attabsenteeism)) return true;
	return false;
}
ostream& operator << (ostream& out, const Attendance& a) {  //输出运算符重载
	out << a.date << "\t" << a.courseNumber << "\t" << a.courseName << "\t\t" << a.studentName << "\t\t" << a.absenteeismType;
	return out;
}
void Attendance::changeid(string id_) {  //改变学号
	id = id_;
}
void Attendance::changedate(string date_) {  //改变日期
	date = date_;
}
void Attendance::changecourseNumber(string courseNumber_) {  //改变第几节课
	courseNumber = courseNumber_;
}
void Attendance::changecourseName(string courseName_) {  //改变课程名称
	courseName = courseName_;
}
void Attendance::changestudentName(string studentName_, string id_) {  //改变学生姓名
	studentName = studentName_;
	id = id_;
}
void Attendance::changeabsenteeismType(string absenteeismType_) {  //改变缺课类型
	absenteeismType = absenteeismType_;
}
void Attendance::changeall(string date_, string courseNumber_, string courseName_, string studentName_, string absenteeismType_, string id_) {  //改变所有信息
	date = date_;
	courseNumber = courseNumber_;
	courseName = courseName_;
	studentName = studentName_;
	absenteeismType = absenteeismType_;
	id = id_;
}
const string Attendance::getdate() const {  //获取日期
	return date;
}
const string Attendance::getcourseNumber() const {  //获取第几节课
	return courseNumber;
}
const string Attendance::getcourseName() const {  //获取课程名称
	return courseName;
}
const string Attendance::getstudentName() const {  //获取学生姓名
	return studentName;
}
const string Attendance::getabsenteeismType() const {  //获取缺课类型
	return absenteeismType;
}
const string Attendance::getid() const {  //获取学号
	return id;
}