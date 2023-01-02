#pragma once
#ifndef _ATTENDANCE_H_
#define _ATTENDANCE_H_
#include <string>
using namespace std;
class Attendance {  //考勤信息
public:
	Attendance();  //默认构造函数
	Attendance(string date_, string courseNumber_, string courseName_, string studentName_, string absenteeismType_, string id_);  //构造函数
	
	bool findCourse(string course) const;  //判断course是否与Attendance中的courseName相等
	bool findStudent(string student, string studentid) const;  //判断student和studentid是否与Attendance中的studentName和id相等
	bool findCouStu(string course, string student, string studentid) const;  //判断course、student和studentid是否与Attendance中的courseName、studentName和id相等
	bool finddate(string attdate) const;  //判断attdate是否与Attendance中的date相等
	bool findcourseNumber(string attnumber) const;  //判断arrnumber是否与Attendance中的courseNumber相等
	bool findstudentName(string attname) const;  //判断attname是否与Attendance中的studentName相等
	bool findabsenteeism(string attabsenteeism) const;  //判断attabsenteeism是否与Attendance中的absenteeismType相等

	friend ostream& operator << (ostream& out, const Attendance& a);  //输出运算符重载，打印Attendance

	void changeid(string id_);  //改变学号
	void changedate(string date_);  //改变日期 
	void changecourseNumber(string courseNumber_);  //改变第几节课
	void changecourseName(string courseName_);  //改变课程姓名
	void changestudentName(string studentName_, string id_);  //同时改变学生姓名和学号
	void changeabsenteeismType(string absenteeismType_);  //改变缺课类型
	void changeall(string date_, string courseNumber_, string courseName_, string studentName_, string absenteeismType_, string id_);  //改变所有信息
	
	const string getdate() const;  //获取日期
	const string getcourseNumber() const;  //获取第几节课
	const string getcourseName() const;  //获取课程名称
	const string getstudentName() const;  //获取学生姓名
	const string getabsenteeismType() const;  //获取缺课类型
	const string getid() const;  //获取学号

private:
	string date;  //缺课日期
	string courseNumber;  //第几节课
	string courseName;  //课程名称
	string studentName;  //学生姓名
	string absenteeismType;  //缺课类型（迟到、早退、请假和旷课）
	string id;  //学号 
};
#endif

