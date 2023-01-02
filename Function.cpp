#include "Function.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream> 
#include <sstream>

using namespace std;

bool isAnagram(string str1, string str2) {  //比较两字符串是否相等
	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);  //全部转化为大写比较，同时不会改变函数外的数据
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
	if (str1 == str2) return true;
	return false;
}

string getNum(string str) {  //提取字符串中的数字 
	string temp;
	for (int i = 0; i < str.length(); i++) {  //遍历字符串中的所有字符
		if (str[i] >= '0' && str[i] <= '9') {  //判断在字符0~9
			temp += str[i];
		}
	}
	return temp;  //返回字符串类型
}

bool isrepeat(vector<int> index, int n) {  //判断index中是否有与n相同的
	for (int i = 0; i < index.size(); i++) {
		if (index[i] == n) return true;
	}
	return false;
}

bool openfile(const string str) {  //打开文件——编辑时用
	ifstream file;
	file.open(str + ".csv", ios::in);
	if (file) {  //如果成功打开
		file.close();
		return true;
	}
	file.close();
	return false;
}

void writeStudent(const string strStu, const Student& s) {  //向Student文件写入一个Student类数据 
	ofstream outfile;
	outfile.open(strStu + ".csv", ios::out | ios::app);
	outfile << s.getid() << "," << s.getname() << "," << s.getgender() << "," << s.getage() << "," << s.getclase() << endl;
	outfile.close();
}
void rewriteStudent(const string strStu, const vector<Student>& sList) {  //重写Student中的所有数据 
	ofstream outfile;
	outfile.open(strStu + ".csv", ios::out | ios::trunc);  //全部覆盖打开
	for (int i = 0; i < sList.size(); i++) {
		outfile << sList.at(i).getid() << "," << sList.at(i).getname() << "," << sList.at(i).getgender() << "," << sList.at(i).getage() << "," << sList.at(i).getclase() << endl;
	}
	outfile.close();
}
void writeAttendance(const string strAtt, const Attendance& a) {  //向Attendance文件写入一个Attendance类数据
	ofstream outfile;
	outfile.open(strAtt + ".csv", ios::out | ios::app);
	outfile << a.getdate() << "," << a.getcourseNumber() << "," << a.getcourseName() << "," << a.getstudentName() << "," << a.getabsenteeismType() << "," << a.getid() << endl;
	outfile.close();
}
void rewriteAttendance(const string strAtt, const vector<Attendance>& aList) {  //重写Attendnace中的所有数据
	ofstream outfile;
	outfile.open(strAtt + ".csv", ios::out | ios::trunc);  //全部覆盖打开
	for (int i = 0; i < aList.size(); i++) {
		outfile << aList.at(i).getdate() << "," << aList.at(i).getcourseNumber() << "," << aList.at(i).getcourseName() << "," << aList.at(i).getstudentName() << "," << aList.at(i).getabsenteeismType() << "," << aList.at(i).getid() << endl;
	}
	outfile.close();
}
void createfile(const string str) {  //创建一个文件，str为文件名
	ofstream outfile;
	outfile.open(str + ".csv", ios::out);
	outfile.close();
}
void readStudentList(const string str, vector<Student>& stuList) {  //读取Student中的数据
	ifstream infile;
	Student stu;
	infile.open(str + ".csv", ios::in);
	if (!infile) {
		cout << "文件不存在，创建文件" << endl;
		createfile(str);
		return;
	}
	int i = 0;
	string line, field;
	while (getline(infile, line)) {  //getline(inFile, line)表示按行读取CSV文件中的数据
		istringstream sin(line); //将整行字符串line读入到字符串流sin中
		getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
		stu.changeid(field.c_str());  //c_str()表示返回一个const指针
		getline(sin, field, ',');
		stu.changename(field.c_str());
		getline(sin, field, ',');
		stu.changegender(field.c_str());
		getline(sin, field, ',');
		stu.changeage(field.c_str());
		getline(sin, field);  //一行的最后 
		stu.changeclass(field.c_str());
		stuList.push_back(stu);
		i++;
	}
	infile.close();
	cout << "共读取了：" << i << "行" << endl;
	cout << "读取数据完成" << endl;
}
void readAttendanceList(string str, vector<Attendance>& attList) {  //读取Attendance中的数据
	ifstream infile;
	Attendance att;
	infile.open(str + ".csv", ios::in);
	if (!infile) {
		cout << "文件不存在，创建文件" << endl;
		createfile(str);
		return;
	}
	int i = 0;
	string line, field, temp;
	while (getline(infile, line)) {  //getline(inFile, line)表示按行读取CSV文件中的数据
		istringstream sin(line); //将整行字符串line读入到字符串流sin中
		getline(sin, field, ','); //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符 
		att.changedate(field.c_str());  //c_str()表示返回一个const指针
		getline(sin, field, ',');
		att.changecourseNumber(field.c_str());
		getline(sin, field, ',');
		att.changecourseName(field.c_str());
		getline(sin, field, ',');
		temp = field.c_str();  //存的是姓名 
		getline(sin, field, ',');
		att.changeabsenteeismType(field.c_str());
		getline(sin, field);  //一行的最后 
		att.changestudentName(temp, field.c_str());
		attList.push_back(att);
		i++;
	}
	infile.close();
	cout << "共读取了：" << i << "行" << endl;
	cout << "读取数据完成" << endl;
}
