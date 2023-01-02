#include "Student.h"
#include "Attendance.h"
#include "Function.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


template<class T>  //在函数中不知道为什么会报错
void show(vector<T> list) {
	for (int i = 0; i < list.size(); i++) {
		cout << list.at(i) << endl;
	}
}
/*功能1：添加信息
void writeStudent(const string strStu, const Student &s);
void writeAttendance(const string strAtt, const Attendance &a);*/
void addList(vector<Student>& stuList, vector<Attendance>& attList, const string strStu, const string strAtt) {
	char type;  //选择改变的类型
	cout << "请选择添加的类别(S(学生信息)、A(考勤信息)、E(退出)): ";
	while (true) {
		cin.sync();
		type = cin.get();
		if (type == 'S' || type == 's') {  //修改学生信息
			string id;
			cout << "请输入学号：";
		IDS: cin >> id;
			int i = 0;
			for (i = 0; i < stuList.size(); i++) {  //比较学号，如果重复停止输入
				if (stuList.at(i).findID(id)) {
					cout << "学号重复，请重新输入：";
					break;
				}
			}
			if (i != stuList.size()) {  //没有遍历完，说明有重复 
				goto IDS;  //重新输入学号
			}
			vector<string> str;  //存输入的数据
			string temp;
			cout << "请按照姓名、性别、年龄、班级顺序输入学生信息(使用回车隔开): ";
			cin.sync();
			for (int j = 0; j < 4; j++) {
				getline(cin, temp);  //可以输入空格
				str.push_back(temp);
			}
			Student sysu(id, str.at(0), str.at(1), str.at(2), str.at(3));
			stuList.push_back(sysu);  //添加到stuList中
			show(stuList);  //展示添加完成后的
			char opt = 'Y';
			cout << "请选择是否保存（Y/N），默认保存:";
			cin.sync(); //清空输入缓冲区 
			opt = cin.get();  //不输入、输入错误或Y为保存
			if (opt == 'N' || opt == 'n') {//不保存
				stuList.pop_back();  //从stuList中删除
				show(stuList);
			}
			else {  //保存
				writeStudent(strStu, sysu);  //写入Student文件
				cout << "保存成功" << endl;
			}
			break;
		}
		else if (type == 'A' || type == 'a') {  //修改考勤信息
			string id;
			cout << "请输入学号：";
		IDA: cin >> id;
			int i = 0;
			for (; i < stuList.size(); i++) {  //先比较学号 
				if (stuList.at(i).findID(id)) {
					break;
				}
			}
			if (i == stuList.size()) {  //循环完，说明没找到相同学号
				cout << "学生信息中未查到相同学号，请重新输入学号：";
				goto IDA;  //未在学生信息中找到相同学号，需要重新输入
			}
			string temp;
			vector<string> str;
			cout << "请按照缺课日期、第几节课、课程名称、学生姓名、缺课类型顺序输入学生信息(使用回车隔开): ";
			cin.sync();
			for (int j = 0; j < 5; j++) {
				getline(cin, temp);
				str.push_back(temp);
			}
			while (true) {  //输入固定格式日期，需要8位数字如2023/01/01
				if (getNum(str.at(0)).length() != 8) {
					cout << "日期格式输入错误，请使用0补充个位数的月或日：";
					cin >> str.at(0);
				}
				else break;
			}
			Attendance sysuatt(str.at(0), str.at(1), str.at(2), str.at(3), str.at(4), id);
			attList.push_back(sysuatt);
			show(attList);
			char opt = 'Y';
			cout << "请选择是否保存（Y/N），默认保存:";
			cin.sync(); //清空输入缓冲区 
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {//删除
				attList.pop_back();
				show(attList);
			}
			else {
				writeAttendance(strAtt, sysuatt);  //向Attendnace中添加信息
				cout << "保存成功" << endl;
			}
			break;
		}
		else if (type == 'E' || type == 'e') {  //退出当前子菜单
			return;
		}
		else {  //不是上面的输入
			cout << "请输入正确类别 S(s) / A(a) / E(e): ";
			continue;
		}
	}
}

/*功能2：查找，有两个，
bool isrepeat(vector<int> index, int n);
string getNum(string str)*/
vector<int> findStu(vector<Student> stuList) {  //查找学生信息
	string id, name, gender, age, clase;
	char type, flag;
	int count = 0, i = 0;
	vector<int> stuIndex;  //使用push_back，没有使用clear()，多次查询结果会累加——存储查询结果对应的序号
	cout << "============查询学生信息============" << endl;
	cout << "1：按学号查询学生信息；" << endl;
	cout << "2：按姓名查询学生信息；" << endl;
	cout << "3：按性别查询学生信息；" << endl;
	cout << "4：按年龄查询学生信息；" << endl;
	cout << "5：按班级查询学生信息；" << endl;
	cout << "0: 返回上级菜单" << endl;
	cout << "=====================================" << endl;
	while (true) {
		cout << "请选择查询方式：";
		cin.sync();
		type = cin.get();
		switch (type) {
		case '1':
			cout << "请输入学号：";
			cin >> id;
			count = 0;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findID(id)) {
					count++;
					if (isrepeat(stuIndex, i) == false) {  //判断是否与stuIndex中的序号重复，重复则不添加
						stuIndex.push_back(i);  //对应的 
						cout << "序号：" << i << "  ";
						cout << stuList.at(i) << endl;
					}
					else {
						cout << "重复查找" << " ";
						cout << stuList.at(i) << endl;
					}
				}
			}
			if (count == 0) {  //没找到对应id
				cout << "未找到相关信息" << endl;
			}
			cout << "请选择是否返回上级菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return stuIndex;
			break;
		case '2':
			cout << "请输入姓名：";
			cin.sync();
			getline(cin, name);  //姓名也可能中间有空格 
			count = 0;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findName(name)) {
					count++;
					if (isrepeat(stuIndex, i) == false) {
						stuIndex.push_back(i);  //对应的 
						cout << "序号：" << i << "  "; 
						cout << stuList.at(i) << endl;
					}
					else {
						cout << "重复查找" << " ";
						cout << stuList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "未找到相关信息" << endl;
			}
			cout << "请选择是否返回上级菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return stuIndex;
			break;
		case '3':
			cout << "请输入性别：";
			cin >> gender;
			count = 0;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findgender(gender)) {
					count++;
					if (isrepeat(stuIndex, i) == false) {
						stuIndex.push_back(i);  //对应的 
						cout << "序号：" << i << "  ";
						cout << stuList.at(i) << endl;
					}
					else {
						cout << "重复查找" << " ";
						cout << stuList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "未找到相关信息" << endl;
			}
			cout << "请选择是否返回上级菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return stuIndex;
			break;
		case '4':
			cout << "请输入年龄：";
			cin >> age;
			count = 0;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findage(age)) {
					count++;
					if (isrepeat(stuIndex, i) == false) {
						stuIndex.push_back(i);  //对应的 
						cout << "序号：" << i << "  ";
						cout << stuList.at(i) << endl;
					}
					else {
						cout << "重复查找" << " ";
						cout << stuList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "未找到相关信息" << endl;
			}
			cout << "请选择是否返回上级菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return stuIndex;
			break;
		case '5':
			cout << "请输入班级：";
			cin.sync();
			getline(cin, clase);  //班级之间也可能有空格
			count = 0;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findclase(clase)) {
					count++;
					if (isrepeat(stuIndex, i) == false) {
						stuIndex.push_back(i);  //对应的 
						cout << "序号：" << i << "  ";
						cout << stuList.at(i) << endl;
					}
					else {
						cout << "重复查找" << " ";
						cout << stuList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "未找到相关信息" << endl;
			}
			cout << "请选择是否返回上级菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return stuIndex;
			break;
		case '0':
			return stuIndex;
		default:
			cout << "输入错误，请重新输入" << endl;
			continue;
		}

	}

}
vector<int> findCourse(vector<Attendance> attList, vector<Student> stuList) {  //查询缺课信息，有多种组合方式 
	string  date, courseNumber, courseName, studentName, absenteeismType, id;	
	int count = 0, i = 0;
	char type, flag;
	vector<int> attIndex;  //会累加查询结果 
	cout << "===========查询缺课记录===========" << endl;
	cout << "1：按课程名查询缺课记录；" << endl;
	cout << "2：按学生姓名查询缺课记录；" << endl;  //学号判断在不在 
	cout << "3：按课程名和学生姓名查询缺课记录；" << endl;
	cout << "4：按缺课日期查询缺课记录；" << endl;
	cout << "5：按第几节课查询缺课记录；" << endl;  //4和5也可以组合
	cout << "6：按缺课日期和第几节课查询缺课记录；" << endl;
	cout << "7：按缺课类型查询缺课记录；" << endl;
	cout << "0: 返回上级菜单" << endl;
	cout << "==================================" << endl;

	while (true) {
		cout << "请选择查询方式: ";
		cin.sync();
		type = cin.get();
		switch (type) {
		case '1':
			cout << "请输入课程名：";
			cin >> courseName;
			count = 0;
			for (int i = 0; i < attList.size(); i++) {  //查找所有课程
				if (attList.at(i).findCourse(courseName)) {
					count++;
					if (isrepeat(attIndex, i) == false) {
						attIndex.push_back(i); 
						cout << "序号：" << i << "  ";
						cout << attList.at(i) << endl;
					}
					else {
						cout << "重复查找" << " ";
						cout << attList.at(i) << endl;
					}

				}
			}
			if (count == 0) {
				cout << "未找到相关信息" << endl;
			}
			cout << "请选择是否返回上级菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return attIndex;  //返回查询的索引，后面的编辑和删除使用
			break;
		case '2':  //保证唯一，所以使用学号 
			cout << "请输入学号：";
		IDC: cin >> id;
			count = 0;
			for (i = 0; i < attList.size(); i++) {  //先比较学号 
				if (stuList.at(i).findID(id)) {
					break;
				}
			}
			if (i == stuList.size()) {  //循环完，说明没找到相同学号
				cout << "学生信息中未查到相同学号，请重新输入学号：";
				goto IDC;
			}
			cout << "请输入学生姓名：";
			cin.sync();
			getline(cin, studentName);
			for (int i = 0; i < attList.size(); i++) {
				if (attList.at(i).findStudent(studentName, id)) {
					count++;
					if (isrepeat(attIndex, i) == false) {
						attIndex.push_back(i);  //对应的 
						cout << "序号：" << i << "  ";
						cout << attList.at(i) << endl;
					}
					else {
						cout << "重复查找" << " ";
						cout << attList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "未找到相关信息" << endl;
			}
			cout << "请选择是否返回上级菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return attIndex;
			break;
		case '3':
			cout << "请输入学号：";
		IDD: cin >> id;
			count = 0;
			for (i = 0; i < attList.size(); i++) {  //先比较学号
				if (stuList.at(i).findID(id)) {
					break;
				}
			}
			if (i == stuList.size()) {  //循环完，说明没找到相同学号
				cout << "学生信息中未查到相同学号，请重新输入学号：";
				goto IDD;
			}
			cout << "请输入课程名和学生姓名(使用空格隔开)：";
			cin >> courseName >> studentName;
			for (int i = 0; i < attList.size(); i++) {
				if (attList.at(i).findCouStu(courseName, studentName, id)) {  //查找课程名和学生姓名、学号都相同的
					count++;
					if (isrepeat(attIndex, i) == false) {
						attIndex.push_back(i);  //对应的 
						cout << "序号：" << i << "  ";
						cout << attList.at(i) << endl;
					}
					else {
						cout << "重复查找" << " ";
						cout << attList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "未找到相关信息" << endl;
			}
			cout << "请选择是否返回上级菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return attIndex;
		case '4':  //只对比日期中的数字
			cout << "请输入日期：";
			cin >> date;
			while (true) {
				if (getNum(date).length() != 8) {  //获取数字getNum
					cout << "日期格式输入错误，请使用0补充个位数的月或日: ";
					cin >> date;
				}
				else break;
			}
			count = 0;
			for (i = 0; i < attList.size(); i++) {
				if (attList.at(i).finddate(date)) {
					count++;
					if (isrepeat(attIndex, i) == false) {
						attIndex.push_back(i);  //对应的 
						cout << "序号：" << i << "  ";
						cout << attList.at(i) << endl;
					}
					else {
						cout << "重复查找" << " ";
						cout << attList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "未找到相关信息" << endl;
			}
			cout << "请选择是否返回上级菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return attIndex;
			break;
		case '5':  //只对比课程的数字
			cout << "请输入第几节课：";
			cin >> courseNumber;
			count = 0;
			for (i = 0; i < attList.size(); i++) {
				if (attList.at(i).findcourseNumber(courseNumber)) {  //只对比数字
					count++;
					if (isrepeat(attIndex, i) == false) {
						attIndex.push_back(i);
						cout << "序号：" << i << "  ";
						cout << attList.at(i) << endl;
					}
					else {
						cout << "重复查找" << " ";
						cout << attList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "未找到相关信息" << endl;
			}
			cout << "请选择是否返回上级菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return attIndex;
			break;
		case '6':
			date = " "; courseNumber = " ";
			cout << "请输入日期和第几节课，使用空格隔开：";
			cin >> date >> courseNumber;
			while (true) {
				if (getNum(date).length() != 8) {
					cout << "日期格式输入错误，请使用0补充个位数的月或日: ";
					cin >> date;
				}
				else break;
			}

			count = 0;
			for (i = 0; i < attList.size(); i++) {
				if (attList.at(i).finddate(date) && attList.at(i).findcourseNumber(courseNumber)) {  //只对比数字
					count++;
					if (isrepeat(attIndex, i) == false) {
						attIndex.push_back(i);  //对应的 
						cout << "序号：" << i << "  ";
						cout << attList.at(i) << endl;
					}
					else {
						cout << "重复查找" << " ";
						cout << attList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "未找到相关信息" << endl;
			}
			cout << "请选择是否返回上级菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return attIndex;
			break;
		case '7':
			cout << "请输入缺课类型：";
			cin >> absenteeismType;
			count = 0;
			for (i = 0; i < attList.size(); i++) {  
				if (attList.at(i).getabsenteeismType() == absenteeismType) {  //不区分大小写
					count++;
					if (isrepeat(attIndex, i) == false) {
						attIndex.push_back(i);
						cout << "序号：" << i << "  ";
						cout << attList.at(i) << endl;
					}
					else {
						cout << "重复查找" << " ";
						cout << attList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "未找到相关信息" << endl;
			}
			cout << "请选择是否返回上级菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return attIndex;
			break;
		case '0':
			return attIndex;  //退出并返回attIndex
		default:
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
	}	
}

/*功能3：显示
用到template*/

void showStudent(vector<Student> stuList) {  //
	if (stuList.empty()) {
		cout << "学生信息表为空" << endl;
		return;
	}
	cout << "***************显示学生的记录***************" << endl;
	cout << "学号\t" << "姓名\t" << "性别\t" << "年龄\t" << "班级" << endl;
	show(stuList);  //使用show()函数模板
}
void showAttendance(vector<Attendance> attList) {  //
	if (attList.empty()) {
		cout << "考勤信息表为空" << endl;
		return;
	}
	cout << "********************************显示缺课的记录********************************" << endl;
	cout << "缺课日期\t" << "第几节课\t" << "课程名称\t" << "学生姓名\t" << "缺课类型" << endl;
	show(attList);  //使用show()函数模板
}

/*功能4：修改编辑
void rewriteStudent(const string strStu, const vector<Student> &sList);
void rewriteAttendance(const string strAtt, const vector<Attendance> &aList);*/
void editStudent(vector<Student>& stuList, vector<Attendance>& attList, vector<int> stuIndex, string strStu, string strAtt) {  //选择修改信息和全部修改，stuList中存储查询的结果 
	char type, opt, flag;
	bool rep = false;
	int i = 0, n = 0, stuNum = 0;  //循环用的 
	string id, name, gender, age, clase;
	string tempid, tempname, tempgender, tempage, tempclase;  //暂存修改之前的
	string temp;
	vector<string> str;  //保存全部修改的输入信息
	if (stuIndex.size() == 0) {
		cout << "未找到相关信息，退出编辑" << endl;
		return;
	}
	for (i = 0; i < stuIndex.size(); i++) {  //连续的查询会接着的 
		cout << "序号: " << stuIndex.at(i) << " ";
		cout << stuList.at(stuIndex.at(i)) << endl;
	}
	while (true) {
		cout << "请选择想要更改的序号：";
		cin.sync();
		cin >> stuNum;
		for (i = 0; i < stuIndex.size(); i++) {  //判断输入是否正确
			if (stuNum == stuIndex.at(i)) {
				rep = true;
				break;
			}
		}
		if (rep) break;
		else cout << "序号错误，请重新输入" << endl;
	}
	cout << "===========学生信息修改===========" << endl;
	cout << "1：修改学号；" << endl;
	cout << "2：修改姓名；" << endl;  //学号判断在不在 
	cout << "3：修改性别；" << endl;
	cout << "4：修改年龄；" << endl;
	cout << "5：修改班级；" << endl;
	cout << "6：全部修改；" << endl;
	cout << "0: 返回主菜单" << endl;
	cout << "==================================" << endl;

	while (true) {
		cout << "请选择想要修改的信息: ";
		cin.sync();
		type = cin.get();
		switch (type) {
		case '1':  //还需要改Attendance的id 
			cout << "请输入修改后的学号：";
		IDE: cin >> id;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findID(id)) {
					cout << "学号重复，请重新输入学号：";
					goto IDE;
				}
			}
			tempid = stuList.at(stuNum).getid();
			stuList.at(stuNum).changeid(id);
			cout << "修改后的信息如下" << endl;
			cout << stuList.at(stuNum) << endl;
			cout << "请问是否保存(Y/N)，默认是: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				stuList.at(stuNum).changeid(tempid);  //如果不保存再改回去
				cout << stuList.at(stuNum) << endl;
			}
			else {
				for (n = 0; n < attList.size(); n++) {  //同时需要修改Attendance中的学号
					if (attList.at(n).getid() == tempid) {
						attList.at(n).changeid(id);
					}
				}
				rewriteAttendance(strAtt, attList);  //重新写入所有信息
				rewriteStudent(strStu, stuList);  //重新写入所有信息
				cout << "保存成功" << endl;
			}
			cout << "请选择是否返回主菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '2':
			cout << "请输入修改后的学生姓名: ";
			cin.sync();
			getline(cin, name);
			tempid = stuList.at(stuNum).getid();
			tempname = stuList.at(stuNum).getname();
			stuList.at(stuNum).changename(name);
			cout << "修改后的信息如下" << endl;
			cout << stuList.at(stuNum) << endl;
			cout << "请问是否保存(Y/N)，默认是: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				stuList.at(stuNum).changename(tempname);
				cout << stuList.at(stuNum) << endl;
			}
			else {
				for (n = 0; n < attList.size(); n++) {  //同时需要修改Attendance中对应学号的姓名 
					if (attList.at(n).getid() == tempid) {
						attList.at(n).changestudentName(name, tempid);
					}
				}
				rewriteAttendance(strAtt, attList);
				rewriteStudent(strStu, stuList);
				cout << "保存成功" << endl;
			}
			cout << "请选择是否返回主菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '3':
			cout << "请输入改后的学生性别: ";
			cin >> gender;
			tempgender = stuList.at(stuNum).getgender();
			stuList.at(stuNum).changegender(gender);
			cout << "修改后的信息如下" << endl;
			cout << stuList.at(stuNum) << endl;
			cout << "请问是否保存(Y/N)，默认是: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				stuList.at(stuNum).changegender(tempgender);
				cout << stuList.at(stuNum) << endl;
			}
			else {
				rewriteStudent(strStu, stuList);
				cout << "保存成功" << endl;
			}
			cout << "请选择是否返回主菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '4':
			cout << "请输入改后的学生年龄: ";
			cin >> age;
			tempage = stuList.at(stuNum).getage();
			stuList.at(stuNum).changeage(age);
			cout << "修改后的信息如下" << endl;
			cout << stuList.at(stuNum) << endl;
			cout << "请问是否保存(Y/N)，默认是: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				stuList.at(stuNum).changeage(tempage);
				cout << stuList.at(stuNum) << endl;
			}
			else {
				rewriteStudent(strStu, stuList);
				cout << "保存成功" << endl;
			}
			cout << "请选择是否返回主菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '5':
			cout << "请输入改后的学生班级: ";
			cin.sync();
			getline(cin, clase);
			tempclase = clase;
			stuList.at(stuNum).changeclass(clase);
			cout << "修改后的信息如下" << endl;
			cout << stuList.at(stuNum) << endl;
			cout << "请问是否保存(Y/N)，默认是: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				stuList.at(stuNum).changeclass(tempclase);
				cout << stuList.at(stuNum) << endl;
			}
			else {
				rewriteStudent(strStu, stuList);
				cout << "保存成功" << endl;
			}
			cout << "请选择是否返回主菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '6':
			str.clear();
			cout << "请输入修改后的学号：";
		IDF: cin >> id;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findID(id)) {
					cout << "学号重复，请重新输入学号：";
					goto IDF;
				}
			}
			cout << "请按顺序输入改后的姓名、性别、年龄、班级（使用回车隔开）: ";    //使用cin直接输入姓名和班级有空格的时候读不出
			cin.sync();
			for (int j = 0; j < 4; j++) {
				getline(cin, temp);
				str.push_back(temp);
			}
			name = str.at(0); gender = str.at(1); age = str.at(2); clase = str.at(3);
			tempid = stuList.at(stuNum).getid(); tempname = stuList.at(stuNum).getname();
			tempgender = stuList.at(stuNum).getgender(); tempage = stuList.at(stuNum).getage(); tempclase = stuList.at(stuNum).getclase();
			stuList.at(stuNum).changeall(id, name, gender, age, clase);
			cout << "修改后的信息如下" << endl;
			cout << stuList.at(stuNum) << endl;
			cout << "请问是否保存(Y/N)，默认是: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				stuList.at(stuNum).changeall(tempid, tempname, tempgender, tempage, tempclase);
				cout << stuList.at(stuNum) << endl;
			}
			else {
				for (n = 0; n < attList.size(); n++) {  //比较学号 
					if (attList.at(n).getid() == tempid) {
						//							attList.at(n).changeid(id);
						attList.at(n).changestudentName(name, id);  //前面写的顺便改了id 
						//							cout <<  attList.at(n) << endl;
					}
					//						cout << "结束" << endl; 
				}
				rewriteAttendance(strAtt, attList);
				rewriteStudent(strStu, stuList);
				cout << "保存成功" << endl;
			}
			cout << "请选择是否返回主菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '0':
			return;
		default:
			cout << "输入错误，请重新输入" << endl;
			continue;
		}

	}
}
void editAttendance(vector<Attendance>& attList, vector<int>& attIndex, string strAtt, vector<Student>& stuList) {  //编辑考勤信息。attList中存储查询结果
	int i = 0, index = 0, count = 0;
	bool rep = false;
	if (attIndex.size() == 0) {
		cout << "未找到相关信息，退出编辑" << endl;
		return;
	}
	for (i = 0; i < attIndex.size(); i++) {  //连续的查询会接着的 
		cout << "序号: " << attIndex.at(i) << " ";
		cout << attList.at(attIndex.at(i)) << endl;
	}
	while (true) {
		cout << "请选择想要更改的序号：";
		cin.sync();
		cin >> index;
		for (i = 0; i < attIndex.size(); i++) {
			if (index == attIndex.at(i)) {
				rep = true;
				break;
			}
		}
		if (rep) break;
		else cout << "序号错误，请重新输入" << endl;
	}
	string date, courseNumber, courseName, studentName, absenteeismType, id;
	string tempdate, tempcourseNumber, tempcourseName, tempstudentName, tempabsenteeismType, tempid;
	tempid = attList.at(index).getid();  //保存之前的 
	string temp;
	vector<string> str;
	char type, opt, flag, re;
	cout << "===========缺课信息修改===========" << endl;
	cout << "1.修改日期" << endl;
	cout << "2.修改第几节课" << endl;
	cout << "3.修改课程名称" << endl;
	cout << "4.修改学生姓名" << endl;
	cout << "5.修改缺课类型" << endl;
	cout << "6.修改所有信息" << endl;
	cout << "0: 返回主菜单" << endl;
	cout << "===================================" << endl;
	while (true) {
		cout << "请选择想要修改的信息：";
		cin.sync();
		type = cin.get();
		switch (type) {
		case '1':
			cout << "请输入修改后的缺课日期: ";
			cin >> date;
			while (true) {  //判断日期格式是否输入错误
				if (getNum(date).length() != 8) {
					cout << "日期格式输入错误，请使用0补充个位数的月或日: ";
					cin >> date;
				}
				else break;
			}
			tempdate = attList.at(index).getdate();
			attList.at(index).changedate(date);
			cout << "修改后的信息如下" << endl;
			cout << attList.at(index) << endl;
			cout << "请问是否保存(Y/N)，默认是: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				attList.at(index).changedate(tempdate);
				cout << attList.at(index) << endl;
			}
			else {
				rewriteAttendance(strAtt, attList);
				cout << "保存成功" << endl;
			}
			cout << "请选择是否返回主菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '2':
			cout << "请输入修改后的为第几节课: ";
			cin >> courseNumber;
			tempcourseNumber = attList.at(index).getcourseNumber();
			cout << "修改后的信息如下" << endl;
			attList.at(index).changecourseNumber(courseNumber);
			cout << attList.at(index) << endl;
			cout << "请问是否保存(Y/N)，默认是: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				attList.at(index).changecourseNumber(tempcourseNumber);
				cout << attList.at(index) << endl;
			}
			else {
				rewriteAttendance(strAtt, attList);
				cout << "保存成功" << endl;
			}
			cout << "请选择是否返回主菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '3':
			cout << "请输入修改后的课程名称: ";
			cin >> courseName;
			tempcourseName = attList.at(index).getcourseName();
			attList.at(index).changecourseName(courseName);
			cout << "修改后的信息如下" << endl;
			cout << attList.at(index) << endl;
			cout << "请问是否保存(Y/N)，默认是: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				attList.at(index).changecourseName(tempcourseName);
				cout << attList.at(index) << endl;
			}
			else {
				rewriteAttendance(strAtt, attList);
				cout << "保存成功" << endl;
			}
			cout << "请选择是否返回主菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '4':
			count = 0;
		IDH: cout << "请输入修改后的学生姓名: ";  //改学生姓名后就对不上学号了，所以也需要改Attendance中的学号
			cin.sync();
			getline(cin, studentName);
		IDG: cout << "请输入该学生的学号：";
			cin >> id;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findID(id) && stuList.at(i).getname() == studentName) {  //姓名严格相等
					count++;
					break;
				}
			}
			if (count == 0) {
				re = 'I';
				cout << "学生信息中没有该学号，请选择重新输入姓名(n/N)还是学号(i/I)，默认重新输入学号:";
				cin.sync();
				re = cin.get();
				if (re == 'N' || re == 'n') goto IDH;
				else goto IDG;
			}
			tempstudentName = attList.at(index).getstudentName();
			attList.at(index).changestudentName(studentName, id);  //更改姓名和学号
			cout << "修改后的信息如下" << endl;
			cout << attList.at(index) << endl;
			cout << "请问是否保存(Y/N)，默认是: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				attList.at(index).changestudentName(tempcourseName, tempid);  
				cout << attList.at(index) << endl;
			}
			else {
				rewriteAttendance(strAtt, attList);
				cout << "保存成功" << endl;
			}
			cout << "请选择是否返回主菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '5':
			cout << "请输入修改后的缺课类型: ";
			cin >> absenteeismType;
			tempabsenteeismType = attList.at(index).getabsenteeismType();
			attList.at(index).changeabsenteeismType(absenteeismType);
			cout << "修改后的信息如下" << endl;
			cout << attList.at(index) << endl;
			cout << "请问是否保存(Y/N)，默认是: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				attList.at(index).changeabsenteeismType(tempabsenteeismType);
				cout << attList.at(index) << endl;
			}
			else {
				rewriteAttendance(strAtt, attList);
				cout << "保存成功" << endl;
			}
			cout << "请选择是否返回主菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '6':
			str.clear();
			count = 0;
		IDI: cout << "请输入修改后的学生姓名: ";  //改学生姓名后就对不上学号了，所以也需要改 
			cin.sync();
			getline(cin, studentName);
		IDJ: cout << "请输入该学生的学号：";
			cin >> id;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findID(id) && stuList.at(i).getname() == studentName) {  //姓名必须严格相等 
					count++;
					break;
				}
			}
			if (count == 0) {
				re = 'I';
				cout << "学生信息中没有该学号，请选择重新输入姓名(n/N)还是学号(i/I)，默认重新输入学号:";
				cin.sync();
				re = cin.get();
				if (re == 'N' || re == 'n') goto IDI;
				else goto IDJ;
			}
			tempdate = attList.at(index).getdate();
			tempcourseNumber = attList.at(index).getcourseNumber();
			tempcourseName = attList.at(index).getcourseName();
			tempstudentName = attList.at(index).getstudentName();
			tempabsenteeismType = attList.at(index).getabsenteeismType();

			cout << "请输入按顺序输入修改后的缺课日期、第几节课、课程名称、缺课类型（使用回车隔开）: ";  //必须先确定姓名学号后才能更改其它信息
			cin.sync();
			for (int j = 0; j < 4; j++) {
				getline(cin, temp);
				str.push_back(temp);
			}
			while (true) {  //日期输入格式正确
				if (getNum(str.at(0)).length() != 8) {
					cout << "日期格式输入错误，请使用0补充个位数的月或日：";
					cin >> str.at(0);
				}
				else break;
			}
			attList.at(index).changeall(str.at(0), str.at(1), str.at(2), studentName, str.at(3), id);
			cout << "修改后的信息如下" << endl;
			cout << attList.at(index) << endl;
			cout << "请问是否保存(Y/N)，默认是: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				attList.at(index).changeall(tempdate, tempcourseNumber, tempcourseName, tempstudentName, tempabsenteeismType, tempid);
				cout << attList.at(index) << endl;
			}
			else {
				rewriteAttendance(strAtt, attList);
				cout << "保存成功" << endl;
			}
			cout << "请选择是否返回主菜单(Y/N)，默认否: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '0':
			return;
		default:
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
	}

}

/*功能5：删除——基本流程与编辑相同）*/
void deleteStudent(vector<Student>& stuList, vector<Attendance>& attList, vector<int> stuIndex, string strStu, string strAtt) {  //删除Student信息，同时也会删除对应学号的Attendance信息
	bool rep = false, flag = false;
	int i = 0, n = 0, stuNum = 0, count = 0, index = 0;
	vector<int> deleteindex;  //保存要删除的序号
	char opt, ex, all;
	if (stuIndex.size() == 0) {  //查询结果为空
		cout << "未找到相关信息，退出" << endl;
		return;
	}
	for (i = 0; i < stuIndex.size(); i++) {  //连续的查询会接着的 
		cout << "序号: " << stuIndex.at(i) << " ";
		cout << stuList.at(stuIndex.at(i)) << endl;
	}
	while (true) {
		while (true) {
			cin.sync();
			cout << "请选择想要删除的序号：";  //如果再删除重复的序号删除就会错乱 
			cin >> stuNum;
			for (i = 0; i < deleteindex.size(); i++) {  //判断是否已经删除过
				if (stuNum == deleteindex.at(i)) {
					flag = true;
					cout << "序号重复，请重新输入" << endl;
					break;
				}
			}
			if (flag) {
				flag = false;
				continue;
			}
			for (i = 0; i < stuIndex.size(); i++) {  //判断输入的序号是否在stuIndex中
				if (stuNum == stuIndex.at(i)) {
					rep = true;
					break;
				}
			}
			if (rep) {
				rep = false;
				break;
			}
			else cout << "序号错误，请重新输入" << endl;
		}
		deleteindex.push_back(stuNum);  //添加进入
		if (deleteindex.size() == stuIndex.size()) {  //如果所有信息都已删除
			cout << "查找的信息已全部选择，是否保存并退出，默认是：";
			cin.sync();
			all = cin.get();
			if (all == 'N' || all == 'n') {
				cout << "取消保存并退出" << endl;
				return;
			}
			else {  //删除对应信息并保存
				for (int j = 0; j < deleteindex.size(); j++) {  //删除attList信息
					for (i = 0; i < attList.size(); i++) {
						if (stuList.at(deleteindex.at(j)).getid() == attList.at(i).getid()) {
							attList.erase(attList.begin() + i);
						}
					}
				}
				for (i = 0; i < deleteindex.size(); i++) {  //删除stuList信息
					stuList.erase(stuList.begin() + deleteindex.at(i));
				}
				rewriteStudent(strStu, stuList);
				rewriteAttendance(strAtt, attList);
				cout << "保存成功" << endl;
				return;
			}
		}
		//下面是删除一条或几条信息（没有全部删除）
		cout << "请问是否保存(Y/N)并退出，默认是: ";  //获取全部要删除的后再保存退出 
		opt = 'Y';
		cin.sync();
		opt = cin.get();
		if (opt == 'N' || opt == 'n') {
			cout << "请选择是否退出，默认否：";
			ex = 'N';
			cin.sync();
			ex = cin.get();
			if (ex == 'Y' || ex == 'y') {
				cout << "取消保存并退出" << endl;
				return;
			}
		}
		else {
			for (int j = 0; j < deleteindex.size(); j++) {
				for (i = 0; i < attList.size(); i++) {
					if (stuList.at(deleteindex.at(j)).getid() == attList.at(i).getid()) {
						attList.erase(attList.begin() + i);
					}
				}
			}
			for (i = 0; i < deleteindex.size(); i++) {
				stuList.erase(stuList.begin() + deleteindex.at(i));
			}
			rewriteStudent(strStu, stuList);
			rewriteAttendance(strAtt, attList);
			cout << "保存成功" << endl;
			return;
		}
	}
}
void deleteAttendance(vector<Attendance>& attList, vector<int> attIndex, string strAtt) {  //删除Attendance信息
	bool rep = false, flag = false;
	int i = 0, n = 0, attNum = 0, count = 0, index = 0;
	vector<int> deleteindex;
	char opt, ex, all;
	if (attIndex.size() == 0) {
		cout << "未找到相关信息，退出" << endl;
		return;
	}
	for (i = 0; i < attIndex.size(); i++) {  //连续的查询会接着的 
		cout << "序号: " << attIndex.at(i) << " ";
		cout << attList.at(attIndex.at(i)) << endl;
	}
	while (true) {
		while (true) {
			cout << "请选择想要删除的序号："; 
			cin.sync();
			cin >> attNum;
			for (i = 0; i < deleteindex.size(); i++) {
				if (attNum == deleteindex.at(i)) {
					flag = true;
					cout << "序号重复，请重新输入" << endl;
					break;
				}
			}
			if (flag) {
				flag = false;
				continue;
			}
			for (i = 0; i < attIndex.size(); i++) {
				if (attNum == attIndex.at(i)) {
					rep = true;
					break;
				}
			}
			if (rep) {
				rep = false;
				break;
			}
			else cout << "序号错误，请重新输入" << endl;
		}
		deleteindex.push_back(attNum);
		if (deleteindex.size() == attIndex.size()) {  //全部信息以选择，不再需要继续输入序号，直接选择是否保存
			cout << "查找的信息已全部选择，是否保存并退出，默认是：";
			cin.sync();
			all = cin.get();
			if (all == 'N' || all == 'n') {
				cout << "取消保存并退出" << endl;
				return;
			}
			else {
				for (i = 0; i < deleteindex.size(); i++) {
					attList.erase(attList.begin() + deleteindex.at(i));
				}
				rewriteAttendance(strAtt, attList);
				cout << "保存成功" << endl;
				return;
			}
		}
		//每选择一个序号后运行
		cout << "请问是否保存(Y/N)并退出，默认是: ";
		opt = 'Y';
		cin.sync();
		opt = cin.get();
		if (opt == 'N' || opt == 'n') {
			cout << "请选择是否退出，默认否：";
			ex = 'N';
			cin.sync();
			ex = cin.get();
			if (ex == 'Y' || ex == 'y') {
				cout << "取消保存并退出" << endl;
				return;
			}

		}
		else {
			for (i = 0; i < deleteindex.size(); i++) {
				attList.erase(attList.begin() + deleteindex.at(i));
			}
			rewriteAttendance(strAtt, attList);
			cout << "保存成功" << endl;
			return;
		}
	}
}

/*功能6：统计
bool openfile(const string str)
void readAttendanceList(string str, vector<Attendance> &attList)
void readStudentList(const string str, vector<Student> &stuList);
*/
void bubbleCourse(vector<Attendance>& att, char type, char rule) {
	for (int i = att.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (rule == '2') {
				switch (type) {  //这样效率感觉不太高 
				case '1':
					if (getNum(att.at(i).getdate()) > getNum(att.at(j).getdate())) {  //从大到小 
						Attendance temp = att[i];
						att[i] = att[j];
						att[j] = temp;
					}
					break;
				case '2':
					if (att.at(i).getcourseNumber() > att.at(j).getcourseNumber()) {  //从大到小 
						Attendance temp = att[i];
						att[i] = att[j];
						att[j] = temp;
					}
					break;
				case '3':
					if (att.at(i).getcourseName() > att.at(j).getcourseName()) {  //从大到小 
						Attendance temp = att[i];
						att[i] = att[j];
						att[j] = temp;
					}
					break;
				case '4':
					if (att.at(i).getstudentName() > att.at(j).getstudentName()) {  //从大到小 
						Attendance temp = att[i];
						att[i] = att[j];
						att[j] = temp;
					}
					break;
				case '5':
					if (att.at(i).getabsenteeismType() > att.at(j).getabsenteeismType()) {  //从大到小 
						Attendance temp = att[i];
						att[i] = att[j];
						att[j] = temp;
					}
					break;
				}
			}
			else {
				switch (type) {
				case '1':
					if (att.at(i).getdate() < att.at(j).getdate()) {
						Attendance temp = att[i];
						att[i] = att[j];
						att[j] = temp;
					}
					break;
				case '2':
					if (att.at(i).getcourseNumber() < att.at(j).getcourseNumber()) {
						Attendance temp = att[i];
						att[i] = att[j];
						att[j] = temp;
					}
					break;
				case '3':
					if (att.at(i).getcourseName() < att.at(j).getcourseName()) {
						Attendance temp = att[i];
						att[i] = att[j];
						att[j] = temp;
					}
					break;
				case '4':
					if (att.at(i).getstudentName() < att.at(j).getstudentName()) {
						Attendance temp = att[i];
						att[i] = att[j];
						att[j] = temp;
					}
					break;
				case '5':
					if (att.at(i).getabsenteeismType() < att.at(j).getabsenteeismType()) {
						Attendance temp = att[i];
						att[i] = att[j];
						att[j] = temp;
					}
					break;
				}
			}

		}
	}
}
void countAttendance(vector<Attendance>& attList) {
	string date, courseName, courseNumber, studentName, absenteeismType;
	string dateend;
	//	int count = 0, i = 0;
	vector<Attendance> att;  //暂存的顺序，可以最后再问是否按这个顺序保存到一个新的文件中 
	vector<Attendance> attread;
	cin.sync();
	char sta, type, rule, save, read, ret;
	cout << "=============统计类型=============" << endl;  /////////////////////////////////感觉还可以加一个按时间段统计 
	cout << "1.按缺课日期统计" << endl;
	cout << "2.按第几节课统计" << endl;  //这个也可以看一天的某个节数的 
	cout << "3.按课程名称统计" << endl;
	cout << "4.按学生姓名统计" << endl;
	cout << "5.按缺课类型统计" << endl;
	cout << "6.按日期时间段统计" << endl;
	cout << "7.按特定日期的第几节课统计" << endl;
	cout << "0.返回主菜单" << endl;
	cout << "==================================" << endl;
	while (true) {
		cout << "请选择统计类型：";
		cin.sync();
		sta = cin.get();
		switch (sta) {
		case '1':
			att.clear();
			type = '0';
			rule = '0';
			if (openfile("Attdate")) {//为什么不会判断？？
				//					file.close();
				attread.clear();
				cout << "已有之前创建的统计文件，是否读取（Y/N），默认否：";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readAttendanceList("Attdate", attread);
					showAttendance(attread);
					cout << "请问是否返回上级菜单（Y/N），默认否：";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}


			cout << "请输入缺课日期：";  //////////////////////日期还是需要规定的，因为01月01日和 1月1日对比不同——改前面的getNum函数 
			cin.sync();
			cin >> date;
			while (true) {
				if (getNum(date).length() != 8) {
					cout << "日期格式输入错误，请使用0补充个位数的月或日：";
					cin >> date;
				}
				else break;
			}

			for (int i = 0; i < attList.size(); i++) {
				if (attList.at(i).finddate(date)) {  //就这个实现查找 
					att.push_back(attList.at(i));
				}
			}
			if (att.size() == 0) {
				cout << "未找到相关日期，请重新选择" << endl;
				break;
			}
			//实现排序
			while (true) {
				cout << "请输入排序依据（2：第几节课； 3；课程名称： 4：学生姓名； 5：缺课类型）: ";
				cin.sync();
				type = cin.get();
				if (type > '1' && type <= '5') break;
				else {
					cout << "请输入正确的序号" << endl;
					continue;
				}
			}
			cout << "请输入排序规则（1：从小到大； 2：从大到小；默认从小到大）: ";  //空或者错误都是1 
			cin.sync();
			rule = cin.get();
			bubbleCourse(att, type, rule);
			show(att);
			cout << "共有" << att.size() << "个结果" << endl;

			cout << "请问是否保存结果，默认否：";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //就不保存最后的行数了吧 
				rewriteAttendance("Attdate", att);
			}
			else cout << "取消保存统计结果" << endl;
			break;
		case '2':
			att.clear();
			type = '0';
			rule = '0';
			if (openfile("AttcourseNumber")) {
				attread.clear();
				cout << "已有之前创建的统计文件，是否读取（Y/N），默认否：";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readAttendanceList("AttcouresNumber", attread);
					showAttendance(attread);
					cout << "请问是否返回上级菜单（Y/N），默认否：";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}

			cout << "请输入第几节课：";  //////////////////////日期还是需要规定的，因为01月01日和 1月1日对比不同——改前面的getNum函数 
			cin.sync();
			cin >> courseNumber;
			for (int i = 0; i < attList.size(); i++) {
				if (attList.at(i).findcourseNumber(courseNumber)) {
					att.push_back(attList.at(i));
				}
			}
			if (att.size() == 0) {
				cout << "未找到相关此段课程，请重新选择" << endl;
				break;
			}
			//实现排序
			while (true) {
				cout << "请输入排序依据（1：日期； 3；课程名称： 4：学生姓名； 5：缺课类型）: ";
				cin.sync();
				type = cin.get();
				if (type >= '1' && type <= '5' && type != '2') break;
				else {
					cout << "请输入正确的序号" << endl;
					continue;
				}
			}
			cout << "请输入排序规则（1：从小到大； 2：从大到小；默认从小到大）: ";  //空或者错误都是1 
			cin.sync();
			rule = cin.get();
			bubbleCourse(att, type, rule);
			show(att);
			cout << "共有" << att.size() << "个结果" << endl;

			cout << "请问是否保存结果，默认否：";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //就不保存最后的行数了吧 
				rewriteAttendance("AttcourseNumber", att);
			}
			else cout << "取消保存统计结果" << endl;

			break;
		case '3':
			att.clear();  //需要清空，避免保存上一次发查询结果
			type = '0';
			rule = '0';

			if (openfile("AttcourseName")) {
				attread.clear();
				cout << "已有之前创建的统计文件，是否读取（Y/N），默认否：";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readAttendanceList("AttcourseName", attread);
					showAttendance(attread);
					cout << "请问是否返回上级菜单（Y/N），默认否：";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}


			cout << "请输入课程名称: ";  //大小写问题——find中实现不区分大小写 
			cin.sync();
			cin >> courseName;
			for (int i = 0; i < attList.size(); i++) {
				if (attList.at(i).findCourse(courseName)) {
					att.push_back(attList.at(i));
				}
			}
			if (att.size() == 0) {
				cout << "未找到相关课程，请重新选择" << endl;
				break;
			}
			//实现排序
			while (true) {
				cout << "请输入排序依据（1：日期； 2：第几节课； 4：学生姓名； 5：缺课类型）: ";
				cin.sync();
				type = cin.get();
				if (type >= '1' && type <= '5' && type != '3') break;
				else {
					cout << "请输入正确的序号" << endl;
					continue;
				}
			}
			cout << "请输入排序规则（1：从小到大； 2：从大到小；默认从小到大）: ";  //空或者错误都是1 
			cin.sync();
			rule = cin.get();
			bubbleCourse(att, type, rule);
			show(att);
			cout << "共有" << att.size() << "个结果" << endl;

			cout << "请问是否保存结果，默认否：";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //就不保存最后的行数了吧 
				rewriteAttendance("AttcourseName", att);
			}
			else cout << "取消保存统计结果" << endl;
			break;
		case '4':
			att.clear();
			type = '0';
			rule = '0';

			if (openfile("AttstudentName")) {
				attread.clear();
				cout << "已有之前创建的统计文件，是否读取（Y/N），默认否：";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readAttendanceList("AttstudentName", attread);
					showAttendance(attread);
					cout << "请问是否返回上级菜单（Y/N），默认否：";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}


			cout << "请输入学生姓名：";  //////////////////////日期还是需要规定的，因为01月01日和 1月1日对比不同——改前面的getNum函数 
			cin.sync();
			getline(cin, studentName);
			for (int i = 0; i < attList.size(); i++) {
				if (attList.at(i).findstudentName(studentName)) {
					att.push_back(attList.at(i));
				}
			}
			if (att.size() == 0) {
				cout << "未找到相关学生，请重新选择" << endl;
				break;
			}
			//实现排序
			while (true) {
				cout << "请输入排序依据（1：日期； 2：第几节课； 3；课程名称： 5：缺课类型）: ";
				cin.sync();
				type = cin.get();
				if (type >= '1' && type <= '5' && type != '4') break;
				else {
					cout << "请输入正确的序号" << endl;
					continue;
				}
			}
			cout << "请输入排序规则（1：从小到大； 2：从大到小；默认从小到大）: ";  //空或者错误都是1 
			cin.sync();
			rule = cin.get();
			bubbleCourse(att, type, rule);
			show(att);
			cout << "共有" << att.size() << "个结果" << endl;

			cout << "请问是否保存结果，默认否：";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //就不保存最后的行数了吧 
				rewriteAttendance("AttstudentName", att);
			}
			else cout << "取消保存统计结果" << endl;
			break;
		case '5':
			att.clear();
			type = '0';
			rule = '0';
			if (openfile("AttabsenteeismType")) {
				attread.clear();
				cout << "已有之前创建的统计文件，是否读取（Y/N），默认否：";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readAttendanceList("AttabsenteeismType", attread);
					showAttendance(attread);
					cout << "请问是否返回上级菜单（Y/N），默认否：";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}

			cout << "请输入缺课类型：";  //////////////////////日期还是需要规定的，因为01月01日和 1月1日对比不同——改前面的getNum函数 
			cin.sync();
			cin >> absenteeismType;
			for (int i = 0; i < attList.size(); i++) {
				if (attList.at(i).findabsenteeism(absenteeismType)) {
					att.push_back(attList.at(i));
				}
			}
			if (att.size() == 0) {
				cout << "未找到相关缺课类型，请重新选择" << endl;
				break;
			}
			//实现排序
			while (true) {
				cout << "请输入排序依据（1：日期； 2：第几节课； 3；课程名称： 4：学生姓名）: ";
				cin.sync();
				type = cin.get();
				if (type >= '1' && type < '5') break;
				else {
					cout << "请输入正确的序号" << endl;
					continue;
				}
			}
			cout << "请输入排序规则（1：从小到大； 2：从大到小；默认从小到大）: ";  //空或者错误都是1 
			cin.sync();
			rule = cin.get();
			bubbleCourse(att, type, rule);
			show(att);
			cout << "共有" << att.size() << "个结果" << endl;

			cout << "请问是否保存结果，默认否：";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //就不保存最后的行数了吧 
				rewriteAttendance("AttabsenteeismType", att);
			}
			else cout << "取消保存统计结果" << endl;
			break;
		case '6':
			att.clear();
			type = '0';
			rule = '0';
			if (openfile("Attperiod")) {
				attread.clear();
				cout << "已有之前创建的统计文件，是否读取（Y/N），默认否：";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readAttendanceList("Attperiod", attread);
					showAttendance(attread);
					cout << "请问是否返回上级菜单（Y/N），默认否：";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}


			cout << "请输入起始缺课日期：";  //////////////////////日期还是需要规定的，因为01月01日和 1月1日对比不同——改前面的getNum函数 
			cin.sync();
			cin >> date;
			while (true) {
				if (getNum(date).length() != 8) {
					cout << "日期格式输入错误，请使用0补充个位数的月或日：";
					cin >> date;
				}
				else break;
			}
			cout << "请输入结束缺课日期：";  //////////////////////日期还是需要规定的，因为01月01日和 1月1日对比不同——改前面的getNum函数 
			cin.sync();
			cin >> dateend;
			while (true) {
				if (getNum(dateend).length() != 8) {
					cout << "日期格式输入错误，请使用0补充个位数的月或日：";
					cin >> dateend;
				}
				else break;
			}

			for (int i = 0; i < attList.size(); i++) {
				if (getNum(attList.at(i).getdate()) >= getNum(date) && getNum(attList.at(i).getdate()) <= getNum(dateend)) {  //就这个实现查找 
					att.push_back(attList.at(i));
				}
			}
			if (att.size() == 0) {
				cout << "未找到相关日期，请重新选择" << endl;
				break;
			}
			//实现排序
			while (true) {
				cout << "请输入排序依据（1：缺课日期； 2：第几节课； 3；课程名称： 4：学生姓名； 5：缺课类型）: ";
				cin.sync();
				type = cin.get();
				if (type >= '1' && type <= '5') break;
				else {
					cout << "请输入正确的序号" << endl;
					continue;
				}
			}
			cout << "请输入排序规则（1：从小到大； 2：从大到小；默认从小到大）: ";  //空或者错误都是1 
			cin.sync();
			rule = cin.get();
			bubbleCourse(att, type, rule);
			show(att);
			cout << "共有" << att.size() << "个结果" << endl;

			cout << "请问是否保存结果，默认否：";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //就不保存最后的行数了吧 
				rewriteAttendance("Attperiod", att);
			}
			else cout << "取消保存统计结果" << endl;
			break;
		case '7':
			att.clear();
			type = '0';
			rule = '0';
			if (openfile("AttdateCourse")) {//为什么不会判断？？
				//					file.close();
				attread.clear();
				cout << "已有之前创建的统计文件，是否读取（Y/N），默认否：";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readAttendanceList("AttdateCourse", attread);
					showAttendance(attread);
					cout << "请问是否返回上级菜单（Y/N），默认否：";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}


			cout << "请输入缺课日期：";
			cin.sync();
			cin >> date;
			while (true) {
				if (getNum(date).length() != 8) {
					cout << "日期格式输入错误，请使用0补充个位数的月或日：";
					cin >> date;
				}
				else break;
			}
			cout << "请输入第几节课：";  //////////////////////日期还是需要规定的，因为01月01日和 1月1日对比不同——改前面的getNum函数 
			cin.sync();
			cin >> courseNumber;

			for (int i = 0; i < attList.size(); i++) {
				if (attList.at(i).finddate(date) && attList.at(i).findcourseNumber(courseNumber)) {  //就这个实现查找 
					att.push_back(attList.at(i));
				}
			}
			if (att.size() == 0) {
				cout << "未找到相关结果，请重新选择" << endl;
				break;
			}
			//实现排序
			while (true) {
				cout << "请输入排序依据（3；课程名称： 4：学生姓名； 5：缺课类型）: ";
				cin.sync();
				type = cin.get();
				if (type > '2' && type <= '5') break;
				else {
					cout << "请输入正确的序号" << endl;
					continue;
				}
			}
			cout << "请输入排序规则（1：从小到大； 2：从大到小；默认从小到大）: ";  //空或者错误都是1 
			cin.sync();
			rule = cin.get();
			bubbleCourse(att, type, rule);
			show(att);
			cout << "共有" << att.size() << "个结果" << endl;

			cout << "请问是否保存结果，默认否：";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //就不保存最后的行数了吧 
				rewriteAttendance("AttdateCourse", att);
			}
			else cout << "取消保存统计结果" << endl;
			break;
		case '0':
			return;
		default:
			cout << "输入错误，请重新输入" << endl;
			continue;

		}
	}

}
void bubbleStudent(vector<Student>& stu, char type, char rule) {/////////////////////////////////////////
	for (int i = stu.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (rule == '2') {
				switch (type) {
				case '1':
					if (stu.at(i).getname() > stu.at(j).getname()) {  //从大到小 
						Student temp = stu[i];
						stu[i] = stu[j];
						stu[j] = temp;
					}
					break;
				case '2':
					if (stu.at(i).getgender() > stu.at(j).getgender()) {  //从大到小 
						Student temp = stu[i];
						stu[i] = stu[j];
						stu[j] = temp;
					}
					break;
				case '3':
					if (stu.at(i).getage() > stu.at(j).getage()) {  //从大到小 
						Student temp = stu[i];
						stu[i] = stu[j];
						stu[j] = temp;
					}
					break;
				case '4':
					if (stu.at(i).getclase() > stu.at(j).getclase()) {  //从大到小 
						Student temp = stu[i];
						stu[i] = stu[j];
						stu[j] = temp;
					}
					break;
				}
			}
			else {
				switch (type) {
				case '1':
					if (stu.at(i).getname() < stu.at(j).getname()) {
						Student temp = stu[i];
						stu[i] = stu[j];
						stu[j] = temp;
					}
					break;
				case '2':
					if (stu.at(i).getgender() < stu.at(j).getgender()) {
						Student temp = stu[i];
						stu[i] = stu[j];
						stu[j] = temp;
					}
					break;
				case '3':
					if (stu.at(i).getage() < stu.at(j).getage()) {
						Student temp = stu[i];
						stu[i] = stu[j];
						stu[j] = temp;
					}
					break;
				case '4':
					if (stu.at(i).getclase() < stu.at(j).getclase()) {
						Student temp = stu[i];
						stu[i] = stu[j];
						stu[j] = temp;
					}
					break;
				}
			}

		}
	}
}
void countStudent(vector<Student>& stuList) {  //还是和上面的拆分一下，在main中选择比较好，感觉函数不能过长 
	string name, gender, age, clase;
	vector<Student> stu;  //暂存的顺序，可以最后再问是否按这个顺序保存到一个新的文件中 
	vector<Student> sturead;
	cin.sync();
	char sta, type, rule, save, read, ret;
	cout << "=============统计类型=============" << endl;
	//	cout << "1.按学号统计" << endl;  //不需要 
	cout << "1.按姓名统计" << endl;
	cout << "2.按性别统计" << endl;
	cout << "3.按年龄统计" << endl;
	cout << "4.按班级统计" << endl;
	cout << "0.返回主菜单" << endl;
	cout << "==================================" << endl;
	while (true) {
		cout << "请选择统计类型：";
		cin.sync();
		sta = cin.get();
		switch (sta) {
		case '1':
			stu.clear();
			type = '0';
			rule = '0';
			if (openfile("Stuname")) {
				sturead.clear();
				cout << "已有之前创建的统计文件，是否读取（Y/N），默认否：";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readStudentList("Stuname", sturead);
					showStudent(sturead);
					cout << "请问是否返回上级菜单（Y/N），默认否：";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}

			cout << "请输入姓名：";  //////////////////////日期还是需要规定的，因为01月01日和 1月1日对比不同——改前面的getNum函数 
			cin.sync();
			getline(cin, name);
			for (int i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findName(name)) {
					stu.push_back(stuList.at(i));
				}
			}
			if (stu.size() == 0) {
				cout << "未找到相同姓名，请重新选择" << endl;
				break;
			}
			//实现排序
			while (true) {
				cout << "请输入排序依据（2；性别： 3：年龄； 4：班级）: ";
				cin.sync();
				type = cin.get();
				if (type > '1' && type <= '4') break;
				else {
					cout << "请输入正确的序号" << endl;
					continue;
				}
			}
			cout << "请输入排序规则（1：从小到大； 2：从大到小；默认从小到大）: ";  //空或者错误都是1 
			cin.sync();
			rule = cin.get();
			bubbleStudent(stu, type, rule);
			show(stu);
			cout << "共有" << stu.size() << "个结果" << endl;

			cout << "请问是否保存结果，默认否：";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //就不保存最后的行数了吧 
				rewriteStudent("Stuname", stu);
			}
			else cout << "取消保存统计结果" << endl;
			break;
		case '2':
			stu.clear();
			type = '0';
			rule = '0';

			if (openfile("Stugender")) {
				sturead.clear();
				cout << "已有之前创建的统计文件，是否读取（Y/N），默认否：";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readStudentList("Stugender", sturead);
					showStudent(sturead);
					cout << "请问是否返回上级菜单（Y/N），默认否：";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}

			cout << "请输入性别：";  //////////////////////日期还是需要规定的，因为01月01日和 1月1日对比不同——改前面的getNum函数 
			cin >> gender;
			for (int i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findgender(gender)) {
					stu.push_back(stuList.at(i));
				}
			}
			if (stu.size() == 0) {
				cout << "未找到相同性别，请重新选择" << endl;
				break;
			}
			//实现排序
			while (true) {
				cout << "请输入排序依据（1：姓名； 3：年龄； 4：班级）: ";
				cin.sync();
				type = cin.get();
				if (type >= '1' && type <= '4' && type != 2) break;
				else {
					cout << "请输入正确的序号" << endl;
					continue;
				}
			}
			cout << "请输入排序规则（1：从小到大； 2：从大到小；默认从小到大）: ";  //空或者错误都是1 
			cin.sync();
			rule = cin.get();
			bubbleStudent(stu, type, rule);
			show(stu);
			cout << "共有" << stu.size() << "个结果" << endl;

			cout << "请问是否保存结果，默认否：";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //就不保存最后的行数了吧 
				rewriteStudent("Stugender", stu);
			}
			else cout << "取消保存统计结果" << endl;
			break;
		case '3':
			stu.clear();
			type = '0';
			rule = '0';

			if (openfile("Stuage")) {
				sturead.clear();
				cout << "已有之前创建的统计文件，是否读取（Y/N），默认否：";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readStudentList("Stuage", sturead);
					showStudent(sturead);
					cout << "请问是否返回上级菜单（Y/N），默认否：";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}

			cout << "请输入年龄：";  //////////////////////日期还是需要规定的，因为01月01日和 1月1日对比不同——改前面的getNum函数 
			cin >> age;
			for (int i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findage(age)) {
					stu.push_back(stuList.at(i));
				}
			}
			if (stu.size() == 0) {
				cout << "未找到相同年龄，请重新选择" << endl;
				break;
			}
			//实现排序
			while (true) {
				cout << "请输入排序依据（1：姓名； 2：性别； 4：班级）: ";
				cin.sync();
				type = cin.get();
				if (type >= '1' && type <= '4' && type != 3) break;
				else {
					cout << "请输入正确的序号" << endl;
					continue;
				}
			}
			cout << "请输入排序规则（1：从小到大； 2：从大到小；默认从小到大）: ";  //空或者错误都是1 
			cin.sync();
			rule = cin.get();
			bubbleStudent(stu, type, rule);
			show(stu);
			cout << "共有" << stu.size() << "个结果" << endl;

			cout << "请问是否保存结果，默认否：";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //就不保存最后的行数了吧 
				rewriteStudent("Stuage", stu);
			}
			else cout << "取消保存统计结果" << endl;
			break;
		case '4':
			stu.clear();
			type = '0';
			rule = '0';

			if (openfile("Stuclass")) {
				sturead.clear();
				cout << "已有之前创建的统计文件，是否读取（Y/N），默认否：";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readStudentList("Stuclass", sturead);
					showStudent(sturead);
					cout << "请问是否返回上级菜单（Y/N），默认否：";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}

			cout << "请输入班级：";  //////////////////////日期还是需要规定的，因为01月01日和 1月1日对比不同——改前面的getNum函数 
			cin.sync();
			getline(cin, clase);
			for (int i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findclase(clase)) {
					stu.push_back(stuList.at(i));
				}
			}
			if (stu.size() == 0) {
				cout << "未找到相同班级，请重新选择" << endl;
				break;
			}
			//实现排序
			while (true) {
				cout << "请输入排序依据（1：姓名； 2：性别； 3：年龄）: ";
				cin.sync();
				type = cin.get();
				if (type >= '1' && type < '4') break;
				else {
					cout << "请输入正确的序号" << endl;
					continue;
				}
			}
			cout << "请输入排序规则（1：从小到大； 2：从大到小；默认从小到大）: ";  //空或者错误都是1 
			cin.sync();
			rule = cin.get();
			bubbleStudent(stu, type, rule);
			show(stu);
			cout << "共有" << stu.size() << "个结果" << endl;

			cout << "请问是否保存结果，默认否：";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //就不保存最后的行数了吧 
				rewriteStudent("Stuclass", stu);
			}
			else cout << "取消保存统计结果" << endl;
			break;
		case '0':
			return;
		default:
			cout << "输入错误，请重新输入" << endl;
			continue;

		}
	}

}


int main() {
	int stuNum = 0;
	vector<int> attIndex, stuIndex;
	//  int i;
	//	string id; 

	//1读取文件初始化列表 
	string strStu = "Student";
	string strAtt = "Attendance";
	vector<Student> stuList;
	vector<Attendance> attList;
	readStudentList(strStu, stuList);
	readAttendanceList(strAtt, attList);

	showStudent(stuList);
	showAttendance(attList);

	int n;
	cout << "**************学生信息管理系统**************" << endl;
	cout << "*           1.录入学生信息或考勤信息" << "       *" << endl;
	cout << "*           2.显示当前系统中所有学生的记录" << " *" << endl;
	cout << "*           3.显示当前系统中所有的缺课记录" << " *" << endl;
	cout << "*           4.查询学生信息" << "                 *" << endl;
	cout << "*           5.查询缺课记录" << "                 *" << endl;
	cout << "*           6.修改学生信息(tips:请手动保存)" << "*" << endl;
	cout << "*           7.修改缺勤信息(tips:请手动保存)" << "*" << endl;
	cout << "*           8.删除学生信息(tips:请手动保存)" << "*" << endl;
	cout << "*           9.删除考勤信息(tips:请手动保存)" << "*" << endl;
	cout << "*           10.统计缺课信息" << "                *" << endl;
	cout << "*           11.统计学生信息" << "                *" << endl;
	//感觉还可以按照性别、年龄、班级统计学生信息 
	cout << "*           0.退出管理系统" << "                 *" << endl;
	cout << "********************************************" << endl;
	while (true) {
		cout << "请选择序号:";
		cin.sync();
		//		n = cin.get();
		cin >> n;
		//		cout << n << endl;
		switch (n) {
			//1添加 
		case 1:  //这个没有写退出，用if这个也行，但是有点破坏了 
			addList(stuList, attList, strStu, strAtt);  //集成到一个函数内
			break;
		case 2:
			showStudent(stuList);
			break;
		case 3:
			showAttendance(attList);
			break;
		case 4:
			findStu(stuList);
			break;
			//				findStu(stuList, id);
		case 5:
			findCourse(attList, stuList);
			break;
		case 6:  //
			stuIndex.clear();
			stuIndex = findStu(stuList);
			editStudent(stuList, attList, stuIndex, strStu, strAtt);
			break;
		case 7:  // 
			attIndex.clear();  //清除所有元素 
			attIndex = findCourse(attList, stuList);
			editAttendance(attList, attIndex, strAtt, stuList);
			break;
		case 8:  //
			stuIndex.clear();
			stuIndex = findStu(stuList);
			deleteStudent(stuList, attList, stuIndex, strStu, strAtt);
			break;
		case 9:
			attIndex.clear();  //清除所有元素 
			attIndex = findCourse(attList, stuList);
			deleteAttendance(attList, attIndex, strAtt);
			break;
		case 10:
			countAttendance(attList);
			break;
		case 11:
			countStudent(stuList);
			break;
		case 0:
			exit(0);
		default:
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
	}
	return 0;
}