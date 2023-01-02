#pragma once
#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include "Student.h"
#include "Attendance.h"
#include <iostream> 
#include <string>
#include <vector>
using namespace std;
bool isAnagram(string str1, string str2);  //���۴�Сд�Ƚ����ַ����Ƿ����
string getNum(string str);  //��ȡ�ַ����е�����
bool isrepeat(vector<int> index, int n);  //�ж�n�Ƿ���index��
bool openfile(const string str);  //�ж��Ƿ���ļ�
void writeStudent(const string strStu, const Student& s);  //��Student�ļ�д��һ��Student������
void writeAttendance(const string strAtt, const Attendance& a);  //��Attendance�ļ�д��һ��Attendance������
void rewriteStudent(const string strStu, const vector<Student>& sList);  //��дStudent�е���������
void rewriteAttendance(const string strAtt, const vector<Attendance>& aList);  //��дAttendnace�е���������
void createfile(const string str);  //����һ���ļ�
void readStudentList(const string str, vector<Student>& stuList);  //��ȡStudent�е�����
void readAttendanceList(string str, vector<Attendance>& attList);  //��ȡAttendance�е�����
#endif
