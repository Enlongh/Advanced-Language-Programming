#pragma once
#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include "Student.h"
#include "Attendance.h"
#include <iostream> 
#include <string>
#include <vector>
using namespace std;
bool isAnagram(string str1, string str2);  //无论大小写比较两字符串是否相等
string getNum(string str);  //获取字符串中的数字
bool isrepeat(vector<int> index, int n);  //判断n是否在index中
bool openfile(const string str);  //判断是否打开文件
void writeStudent(const string strStu, const Student& s);  //向Student文件写入一个Student类数据
void writeAttendance(const string strAtt, const Attendance& a);  //向Attendance文件写入一个Attendance类数据
void rewriteStudent(const string strStu, const vector<Student>& sList);  //重写Student中的所有数据
void rewriteAttendance(const string strAtt, const vector<Attendance>& aList);  //重写Attendnace中的所有数据
void createfile(const string str);  //创建一个文件
void readStudentList(const string str, vector<Student>& stuList);  //读取Student中的数据
void readAttendanceList(string str, vector<Attendance>& attList);  //读取Attendance中的数据
#endif
