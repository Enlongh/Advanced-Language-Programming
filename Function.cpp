#include "Function.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream> 
#include <sstream>

using namespace std;

bool isAnagram(string str1, string str2) {  //�Ƚ����ַ����Ƿ����
	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);  //ȫ��ת��Ϊ��д�Ƚϣ�ͬʱ����ı亯���������
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
	if (str1 == str2) return true;
	return false;
}

string getNum(string str) {  //��ȡ�ַ����е����� 
	string temp;
	for (int i = 0; i < str.length(); i++) {  //�����ַ����е������ַ�
		if (str[i] >= '0' && str[i] <= '9') {  //�ж����ַ�0~9
			temp += str[i];
		}
	}
	return temp;  //�����ַ�������
}

bool isrepeat(vector<int> index, int n) {  //�ж�index���Ƿ�����n��ͬ��
	for (int i = 0; i < index.size(); i++) {
		if (index[i] == n) return true;
	}
	return false;
}

bool openfile(const string str) {  //���ļ������༭ʱ��
	ifstream file;
	file.open(str + ".csv", ios::in);
	if (file) {  //����ɹ���
		file.close();
		return true;
	}
	file.close();
	return false;
}

void writeStudent(const string strStu, const Student& s) {  //��Student�ļ�д��һ��Student������ 
	ofstream outfile;
	outfile.open(strStu + ".csv", ios::out | ios::app);
	outfile << s.getid() << "," << s.getname() << "," << s.getgender() << "," << s.getage() << "," << s.getclase() << endl;
	outfile.close();
}
void rewriteStudent(const string strStu, const vector<Student>& sList) {  //��дStudent�е��������� 
	ofstream outfile;
	outfile.open(strStu + ".csv", ios::out | ios::trunc);  //ȫ�����Ǵ�
	for (int i = 0; i < sList.size(); i++) {
		outfile << sList.at(i).getid() << "," << sList.at(i).getname() << "," << sList.at(i).getgender() << "," << sList.at(i).getage() << "," << sList.at(i).getclase() << endl;
	}
	outfile.close();
}
void writeAttendance(const string strAtt, const Attendance& a) {  //��Attendance�ļ�д��һ��Attendance������
	ofstream outfile;
	outfile.open(strAtt + ".csv", ios::out | ios::app);
	outfile << a.getdate() << "," << a.getcourseNumber() << "," << a.getcourseName() << "," << a.getstudentName() << "," << a.getabsenteeismType() << "," << a.getid() << endl;
	outfile.close();
}
void rewriteAttendance(const string strAtt, const vector<Attendance>& aList) {  //��дAttendnace�е���������
	ofstream outfile;
	outfile.open(strAtt + ".csv", ios::out | ios::trunc);  //ȫ�����Ǵ�
	for (int i = 0; i < aList.size(); i++) {
		outfile << aList.at(i).getdate() << "," << aList.at(i).getcourseNumber() << "," << aList.at(i).getcourseName() << "," << aList.at(i).getstudentName() << "," << aList.at(i).getabsenteeismType() << "," << aList.at(i).getid() << endl;
	}
	outfile.close();
}
void createfile(const string str) {  //����һ���ļ���strΪ�ļ���
	ofstream outfile;
	outfile.open(str + ".csv", ios::out);
	outfile.close();
}
void readStudentList(const string str, vector<Student>& stuList) {  //��ȡStudent�е�����
	ifstream infile;
	Student stu;
	infile.open(str + ".csv", ios::in);
	if (!infile) {
		cout << "�ļ������ڣ������ļ�" << endl;
		createfile(str);
		return;
	}
	int i = 0;
	string line, field;
	while (getline(infile, line)) {  //getline(inFile, line)��ʾ���ж�ȡCSV�ļ��е�����
		istringstream sin(line); //�������ַ���line���뵽�ַ�����sin��
		getline(sin, field, ','); //���ַ�����sin�е��ַ����뵽field�ַ����У��Զ���Ϊ�ָ��� 
		stu.changeid(field.c_str());  //c_str()��ʾ����һ��constָ��
		getline(sin, field, ',');
		stu.changename(field.c_str());
		getline(sin, field, ',');
		stu.changegender(field.c_str());
		getline(sin, field, ',');
		stu.changeage(field.c_str());
		getline(sin, field);  //һ�е���� 
		stu.changeclass(field.c_str());
		stuList.push_back(stu);
		i++;
	}
	infile.close();
	cout << "����ȡ�ˣ�" << i << "��" << endl;
	cout << "��ȡ�������" << endl;
}
void readAttendanceList(string str, vector<Attendance>& attList) {  //��ȡAttendance�е�����
	ifstream infile;
	Attendance att;
	infile.open(str + ".csv", ios::in);
	if (!infile) {
		cout << "�ļ������ڣ������ļ�" << endl;
		createfile(str);
		return;
	}
	int i = 0;
	string line, field, temp;
	while (getline(infile, line)) {  //getline(inFile, line)��ʾ���ж�ȡCSV�ļ��е�����
		istringstream sin(line); //�������ַ���line���뵽�ַ�����sin��
		getline(sin, field, ','); //���ַ�����sin�е��ַ����뵽field�ַ����У��Զ���Ϊ�ָ��� 
		att.changedate(field.c_str());  //c_str()��ʾ����һ��constָ��
		getline(sin, field, ',');
		att.changecourseNumber(field.c_str());
		getline(sin, field, ',');
		att.changecourseName(field.c_str());
		getline(sin, field, ',');
		temp = field.c_str();  //��������� 
		getline(sin, field, ',');
		att.changeabsenteeismType(field.c_str());
		getline(sin, field);  //һ�е���� 
		att.changestudentName(temp, field.c_str());
		attList.push_back(att);
		i++;
	}
	infile.close();
	cout << "����ȡ�ˣ�" << i << "��" << endl;
	cout << "��ȡ�������" << endl;
}
