#include "Attendance.h"
#include "Function.h"
#include <iostream>
#include <string>
Attendance::Attendance() {  //Ĭ�Ϲ��캯��
	date = " ";
	courseNumber = " ";
	courseName = " ";
	studentName = " ";
	absenteeismType = " ";
	id = " ";
}
Attendance::Attendance(string date_, string courseNumber_, string courseName_, string studentName_, string absenteeismType_, string id_) {  //���캯��
	date = date_;
	courseNumber = courseNumber_;
	courseName = courseName_;
	studentName = studentName_;
	absenteeismType = absenteeismType_;  //�������� 
	id = id_;
}
bool Attendance::findCourse(string course) const {  //�жϿγ����Ƿ����
	if (isAnagram(courseName, course)) return true;  //�ж����ַ������۴�Сд�Ƿ����
	return false;
}
bool Attendance::findStudent(string student, string studentid) const {  //�ж�ѧ��������ѧ���Ƿ����
	if (isAnagram(studentName, student) && (id == studentid)) return true;
	return false;
}
bool Attendance::findCouStu(string course, string student, string studentid) const {  //�жϿγ�����ѧ��������ѧ���Ƿ����
	if (isAnagram(courseName, course) && isAnagram(studentName, student) && (id == studentid)) return true;
	return false;
}
bool Attendance::finddate(string attdate) const {  //�ж������Ƿ����
	if (getNum(date) == getNum(attdate)) return true;  //��ȡ�ַ����е�����
	return false;
}
bool Attendance::findcourseNumber(string attnumber) const {  //�жϿγ̽����Ƿ����
	if (getNum(courseNumber) == getNum(attnumber)) return true;
	return false;
}
bool Attendance::findstudentName(string attname) const {  //�ж�ѧ�������Ƿ����
	if (isAnagram(studentName, attname)) return true;
	return false;
}
bool Attendance::findabsenteeism(string attabsenteeism) const {  //�жϿγ������Ƿ����
	if (isAnagram(absenteeismType, attabsenteeism)) return true;
	return false;
}
ostream& operator << (ostream& out, const Attendance& a) {  //������������
	out << a.date << "\t" << a.courseNumber << "\t" << a.courseName << "\t\t" << a.studentName << "\t\t" << a.absenteeismType;
	return out;
}
void Attendance::changeid(string id_) {  //�ı�ѧ��
	id = id_;
}
void Attendance::changedate(string date_) {  //�ı�����
	date = date_;
}
void Attendance::changecourseNumber(string courseNumber_) {  //�ı�ڼ��ڿ�
	courseNumber = courseNumber_;
}
void Attendance::changecourseName(string courseName_) {  //�ı�γ�����
	courseName = courseName_;
}
void Attendance::changestudentName(string studentName_, string id_) {  //�ı�ѧ������
	studentName = studentName_;
	id = id_;
}
void Attendance::changeabsenteeismType(string absenteeismType_) {  //�ı�ȱ������
	absenteeismType = absenteeismType_;
}
void Attendance::changeall(string date_, string courseNumber_, string courseName_, string studentName_, string absenteeismType_, string id_) {  //�ı�������Ϣ
	date = date_;
	courseNumber = courseNumber_;
	courseName = courseName_;
	studentName = studentName_;
	absenteeismType = absenteeismType_;
	id = id_;
}
const string Attendance::getdate() const {  //��ȡ����
	return date;
}
const string Attendance::getcourseNumber() const {  //��ȡ�ڼ��ڿ�
	return courseNumber;
}
const string Attendance::getcourseName() const {  //��ȡ�γ�����
	return courseName;
}
const string Attendance::getstudentName() const {  //��ȡѧ������
	return studentName;
}
const string Attendance::getabsenteeismType() const {  //��ȡȱ������
	return absenteeismType;
}
const string Attendance::getid() const {  //��ȡѧ��
	return id;
}