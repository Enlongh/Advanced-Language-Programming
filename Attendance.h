#pragma once
#ifndef _ATTENDANCE_H_
#define _ATTENDANCE_H_
#include <string>
using namespace std;
class Attendance {  //������Ϣ
public:
	Attendance();  //Ĭ�Ϲ��캯��
	Attendance(string date_, string courseNumber_, string courseName_, string studentName_, string absenteeismType_, string id_);  //���캯��
	
	bool findCourse(string course) const;  //�ж�course�Ƿ���Attendance�е�courseName���
	bool findStudent(string student, string studentid) const;  //�ж�student��studentid�Ƿ���Attendance�е�studentName��id���
	bool findCouStu(string course, string student, string studentid) const;  //�ж�course��student��studentid�Ƿ���Attendance�е�courseName��studentName��id���
	bool finddate(string attdate) const;  //�ж�attdate�Ƿ���Attendance�е�date���
	bool findcourseNumber(string attnumber) const;  //�ж�arrnumber�Ƿ���Attendance�е�courseNumber���
	bool findstudentName(string attname) const;  //�ж�attname�Ƿ���Attendance�е�studentName���
	bool findabsenteeism(string attabsenteeism) const;  //�ж�attabsenteeism�Ƿ���Attendance�е�absenteeismType���

	friend ostream& operator << (ostream& out, const Attendance& a);  //�����������أ���ӡAttendance

	void changeid(string id_);  //�ı�ѧ��
	void changedate(string date_);  //�ı����� 
	void changecourseNumber(string courseNumber_);  //�ı�ڼ��ڿ�
	void changecourseName(string courseName_);  //�ı�γ�����
	void changestudentName(string studentName_, string id_);  //ͬʱ�ı�ѧ��������ѧ��
	void changeabsenteeismType(string absenteeismType_);  //�ı�ȱ������
	void changeall(string date_, string courseNumber_, string courseName_, string studentName_, string absenteeismType_, string id_);  //�ı�������Ϣ
	
	const string getdate() const;  //��ȡ����
	const string getcourseNumber() const;  //��ȡ�ڼ��ڿ�
	const string getcourseName() const;  //��ȡ�γ�����
	const string getstudentName() const;  //��ȡѧ������
	const string getabsenteeismType() const;  //��ȡȱ������
	const string getid() const;  //��ȡѧ��

private:
	string date;  //ȱ������
	string courseNumber;  //�ڼ��ڿ�
	string courseName;  //�γ�����
	string studentName;  //ѧ������
	string absenteeismType;  //ȱ�����ͣ��ٵ������ˡ���ٺͿ��Σ�
	string id;  //ѧ�� 
};
#endif

