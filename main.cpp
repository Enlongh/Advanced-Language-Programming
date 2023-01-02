#include "Student.h"
#include "Attendance.h"
#include "Function.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


template<class T>  //�ں����в�֪��Ϊʲô�ᱨ��
void show(vector<T> list) {
	for (int i = 0; i < list.size(); i++) {
		cout << list.at(i) << endl;
	}
}
/*����1�������Ϣ
void writeStudent(const string strStu, const Student &s);
void writeAttendance(const string strAtt, const Attendance &a);*/
void addList(vector<Student>& stuList, vector<Attendance>& attList, const string strStu, const string strAtt) {
	char type;  //ѡ��ı������
	cout << "��ѡ����ӵ����(S(ѧ����Ϣ)��A(������Ϣ)��E(�˳�)): ";
	while (true) {
		cin.sync();
		type = cin.get();
		if (type == 'S' || type == 's') {  //�޸�ѧ����Ϣ
			string id;
			cout << "������ѧ�ţ�";
		IDS: cin >> id;
			int i = 0;
			for (i = 0; i < stuList.size(); i++) {  //�Ƚ�ѧ�ţ�����ظ�ֹͣ����
				if (stuList.at(i).findID(id)) {
					cout << "ѧ���ظ������������룺";
					break;
				}
			}
			if (i != stuList.size()) {  //û�б����꣬˵�����ظ� 
				goto IDS;  //��������ѧ��
			}
			vector<string> str;  //�����������
			string temp;
			cout << "�밴���������Ա����䡢�༶˳������ѧ����Ϣ(ʹ�ûس�����): ";
			cin.sync();
			for (int j = 0; j < 4; j++) {
				getline(cin, temp);  //��������ո�
				str.push_back(temp);
			}
			Student sysu(id, str.at(0), str.at(1), str.at(2), str.at(3));
			stuList.push_back(sysu);  //��ӵ�stuList��
			show(stuList);  //չʾ�����ɺ��
			char opt = 'Y';
			cout << "��ѡ���Ƿ񱣴棨Y/N����Ĭ�ϱ���:";
			cin.sync(); //������뻺���� 
			opt = cin.get();  //�����롢��������YΪ����
			if (opt == 'N' || opt == 'n') {//������
				stuList.pop_back();  //��stuList��ɾ��
				show(stuList);
			}
			else {  //����
				writeStudent(strStu, sysu);  //д��Student�ļ�
				cout << "����ɹ�" << endl;
			}
			break;
		}
		else if (type == 'A' || type == 'a') {  //�޸Ŀ�����Ϣ
			string id;
			cout << "������ѧ�ţ�";
		IDA: cin >> id;
			int i = 0;
			for (; i < stuList.size(); i++) {  //�ȱȽ�ѧ�� 
				if (stuList.at(i).findID(id)) {
					break;
				}
			}
			if (i == stuList.size()) {  //ѭ���꣬˵��û�ҵ���ͬѧ��
				cout << "ѧ����Ϣ��δ�鵽��ͬѧ�ţ�����������ѧ�ţ�";
				goto IDA;  //δ��ѧ����Ϣ���ҵ���ͬѧ�ţ���Ҫ��������
			}
			string temp;
			vector<string> str;
			cout << "�밴��ȱ�����ڡ��ڼ��ڿΡ��γ����ơ�ѧ��������ȱ������˳������ѧ����Ϣ(ʹ�ûس�����): ";
			cin.sync();
			for (int j = 0; j < 5; j++) {
				getline(cin, temp);
				str.push_back(temp);
			}
			while (true) {  //����̶���ʽ���ڣ���Ҫ8λ������2023/01/01
				if (getNum(str.at(0)).length() != 8) {
					cout << "���ڸ�ʽ���������ʹ��0�����λ�����»��գ�";
					cin >> str.at(0);
				}
				else break;
			}
			Attendance sysuatt(str.at(0), str.at(1), str.at(2), str.at(3), str.at(4), id);
			attList.push_back(sysuatt);
			show(attList);
			char opt = 'Y';
			cout << "��ѡ���Ƿ񱣴棨Y/N����Ĭ�ϱ���:";
			cin.sync(); //������뻺���� 
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {//ɾ��
				attList.pop_back();
				show(attList);
			}
			else {
				writeAttendance(strAtt, sysuatt);  //��Attendnace�������Ϣ
				cout << "����ɹ�" << endl;
			}
			break;
		}
		else if (type == 'E' || type == 'e') {  //�˳���ǰ�Ӳ˵�
			return;
		}
		else {  //�������������
			cout << "��������ȷ��� S(s) / A(a) / E(e): ";
			continue;
		}
	}
}

/*����2�����ң���������
bool isrepeat(vector<int> index, int n);
string getNum(string str)*/
vector<int> findStu(vector<Student> stuList) {  //����ѧ����Ϣ
	string id, name, gender, age, clase;
	char type, flag;
	int count = 0, i = 0;
	vector<int> stuIndex;  //ʹ��push_back��û��ʹ��clear()����β�ѯ������ۼӡ����洢��ѯ�����Ӧ�����
	cout << "============��ѯѧ����Ϣ============" << endl;
	cout << "1����ѧ�Ų�ѯѧ����Ϣ��" << endl;
	cout << "2����������ѯѧ����Ϣ��" << endl;
	cout << "3�����Ա��ѯѧ����Ϣ��" << endl;
	cout << "4���������ѯѧ����Ϣ��" << endl;
	cout << "5�����༶��ѯѧ����Ϣ��" << endl;
	cout << "0: �����ϼ��˵�" << endl;
	cout << "=====================================" << endl;
	while (true) {
		cout << "��ѡ���ѯ��ʽ��";
		cin.sync();
		type = cin.get();
		switch (type) {
		case '1':
			cout << "������ѧ�ţ�";
			cin >> id;
			count = 0;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findID(id)) {
					count++;
					if (isrepeat(stuIndex, i) == false) {  //�ж��Ƿ���stuIndex�е�����ظ����ظ������
						stuIndex.push_back(i);  //��Ӧ�� 
						cout << "��ţ�" << i << "  ";
						cout << stuList.at(i) << endl;
					}
					else {
						cout << "�ظ�����" << " ";
						cout << stuList.at(i) << endl;
					}
				}
			}
			if (count == 0) {  //û�ҵ���Ӧid
				cout << "δ�ҵ������Ϣ" << endl;
			}
			cout << "��ѡ���Ƿ񷵻��ϼ��˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return stuIndex;
			break;
		case '2':
			cout << "������������";
			cin.sync();
			getline(cin, name);  //����Ҳ�����м��пո� 
			count = 0;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findName(name)) {
					count++;
					if (isrepeat(stuIndex, i) == false) {
						stuIndex.push_back(i);  //��Ӧ�� 
						cout << "��ţ�" << i << "  "; 
						cout << stuList.at(i) << endl;
					}
					else {
						cout << "�ظ�����" << " ";
						cout << stuList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "δ�ҵ������Ϣ" << endl;
			}
			cout << "��ѡ���Ƿ񷵻��ϼ��˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return stuIndex;
			break;
		case '3':
			cout << "�������Ա�";
			cin >> gender;
			count = 0;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findgender(gender)) {
					count++;
					if (isrepeat(stuIndex, i) == false) {
						stuIndex.push_back(i);  //��Ӧ�� 
						cout << "��ţ�" << i << "  ";
						cout << stuList.at(i) << endl;
					}
					else {
						cout << "�ظ�����" << " ";
						cout << stuList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "δ�ҵ������Ϣ" << endl;
			}
			cout << "��ѡ���Ƿ񷵻��ϼ��˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return stuIndex;
			break;
		case '4':
			cout << "���������䣺";
			cin >> age;
			count = 0;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findage(age)) {
					count++;
					if (isrepeat(stuIndex, i) == false) {
						stuIndex.push_back(i);  //��Ӧ�� 
						cout << "��ţ�" << i << "  ";
						cout << stuList.at(i) << endl;
					}
					else {
						cout << "�ظ�����" << " ";
						cout << stuList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "δ�ҵ������Ϣ" << endl;
			}
			cout << "��ѡ���Ƿ񷵻��ϼ��˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return stuIndex;
			break;
		case '5':
			cout << "������༶��";
			cin.sync();
			getline(cin, clase);  //�༶֮��Ҳ�����пո�
			count = 0;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findclase(clase)) {
					count++;
					if (isrepeat(stuIndex, i) == false) {
						stuIndex.push_back(i);  //��Ӧ�� 
						cout << "��ţ�" << i << "  ";
						cout << stuList.at(i) << endl;
					}
					else {
						cout << "�ظ�����" << " ";
						cout << stuList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "δ�ҵ������Ϣ" << endl;
			}
			cout << "��ѡ���Ƿ񷵻��ϼ��˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return stuIndex;
			break;
		case '0':
			return stuIndex;
		default:
			cout << "�����������������" << endl;
			continue;
		}

	}

}
vector<int> findCourse(vector<Attendance> attList, vector<Student> stuList) {  //��ѯȱ����Ϣ���ж�����Ϸ�ʽ 
	string  date, courseNumber, courseName, studentName, absenteeismType, id;	
	int count = 0, i = 0;
	char type, flag;
	vector<int> attIndex;  //���ۼӲ�ѯ��� 
	cout << "===========��ѯȱ�μ�¼===========" << endl;
	cout << "1�����γ�����ѯȱ�μ�¼��" << endl;
	cout << "2����ѧ��������ѯȱ�μ�¼��" << endl;  //ѧ���ж��ڲ��� 
	cout << "3�����γ�����ѧ��������ѯȱ�μ�¼��" << endl;
	cout << "4����ȱ�����ڲ�ѯȱ�μ�¼��" << endl;
	cout << "5�����ڼ��ڿβ�ѯȱ�μ�¼��" << endl;  //4��5Ҳ�������
	cout << "6����ȱ�����ں͵ڼ��ڿβ�ѯȱ�μ�¼��" << endl;
	cout << "7����ȱ�����Ͳ�ѯȱ�μ�¼��" << endl;
	cout << "0: �����ϼ��˵�" << endl;
	cout << "==================================" << endl;

	while (true) {
		cout << "��ѡ���ѯ��ʽ: ";
		cin.sync();
		type = cin.get();
		switch (type) {
		case '1':
			cout << "������γ�����";
			cin >> courseName;
			count = 0;
			for (int i = 0; i < attList.size(); i++) {  //�������пγ�
				if (attList.at(i).findCourse(courseName)) {
					count++;
					if (isrepeat(attIndex, i) == false) {
						attIndex.push_back(i); 
						cout << "��ţ�" << i << "  ";
						cout << attList.at(i) << endl;
					}
					else {
						cout << "�ظ�����" << " ";
						cout << attList.at(i) << endl;
					}

				}
			}
			if (count == 0) {
				cout << "δ�ҵ������Ϣ" << endl;
			}
			cout << "��ѡ���Ƿ񷵻��ϼ��˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return attIndex;  //���ز�ѯ������������ı༭��ɾ��ʹ��
			break;
		case '2':  //��֤Ψһ������ʹ��ѧ�� 
			cout << "������ѧ�ţ�";
		IDC: cin >> id;
			count = 0;
			for (i = 0; i < attList.size(); i++) {  //�ȱȽ�ѧ�� 
				if (stuList.at(i).findID(id)) {
					break;
				}
			}
			if (i == stuList.size()) {  //ѭ���꣬˵��û�ҵ���ͬѧ��
				cout << "ѧ����Ϣ��δ�鵽��ͬѧ�ţ�����������ѧ�ţ�";
				goto IDC;
			}
			cout << "������ѧ��������";
			cin.sync();
			getline(cin, studentName);
			for (int i = 0; i < attList.size(); i++) {
				if (attList.at(i).findStudent(studentName, id)) {
					count++;
					if (isrepeat(attIndex, i) == false) {
						attIndex.push_back(i);  //��Ӧ�� 
						cout << "��ţ�" << i << "  ";
						cout << attList.at(i) << endl;
					}
					else {
						cout << "�ظ�����" << " ";
						cout << attList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "δ�ҵ������Ϣ" << endl;
			}
			cout << "��ѡ���Ƿ񷵻��ϼ��˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return attIndex;
			break;
		case '3':
			cout << "������ѧ�ţ�";
		IDD: cin >> id;
			count = 0;
			for (i = 0; i < attList.size(); i++) {  //�ȱȽ�ѧ��
				if (stuList.at(i).findID(id)) {
					break;
				}
			}
			if (i == stuList.size()) {  //ѭ���꣬˵��û�ҵ���ͬѧ��
				cout << "ѧ����Ϣ��δ�鵽��ͬѧ�ţ�����������ѧ�ţ�";
				goto IDD;
			}
			cout << "������γ�����ѧ������(ʹ�ÿո����)��";
			cin >> courseName >> studentName;
			for (int i = 0; i < attList.size(); i++) {
				if (attList.at(i).findCouStu(courseName, studentName, id)) {  //���ҿγ�����ѧ��������ѧ�Ŷ���ͬ��
					count++;
					if (isrepeat(attIndex, i) == false) {
						attIndex.push_back(i);  //��Ӧ�� 
						cout << "��ţ�" << i << "  ";
						cout << attList.at(i) << endl;
					}
					else {
						cout << "�ظ�����" << " ";
						cout << attList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "δ�ҵ������Ϣ" << endl;
			}
			cout << "��ѡ���Ƿ񷵻��ϼ��˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return attIndex;
		case '4':  //ֻ�Ա������е�����
			cout << "���������ڣ�";
			cin >> date;
			while (true) {
				if (getNum(date).length() != 8) {  //��ȡ����getNum
					cout << "���ڸ�ʽ���������ʹ��0�����λ�����»���: ";
					cin >> date;
				}
				else break;
			}
			count = 0;
			for (i = 0; i < attList.size(); i++) {
				if (attList.at(i).finddate(date)) {
					count++;
					if (isrepeat(attIndex, i) == false) {
						attIndex.push_back(i);  //��Ӧ�� 
						cout << "��ţ�" << i << "  ";
						cout << attList.at(i) << endl;
					}
					else {
						cout << "�ظ�����" << " ";
						cout << attList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "δ�ҵ������Ϣ" << endl;
			}
			cout << "��ѡ���Ƿ񷵻��ϼ��˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return attIndex;
			break;
		case '5':  //ֻ�Աȿγ̵�����
			cout << "������ڼ��ڿΣ�";
			cin >> courseNumber;
			count = 0;
			for (i = 0; i < attList.size(); i++) {
				if (attList.at(i).findcourseNumber(courseNumber)) {  //ֻ�Ա�����
					count++;
					if (isrepeat(attIndex, i) == false) {
						attIndex.push_back(i);
						cout << "��ţ�" << i << "  ";
						cout << attList.at(i) << endl;
					}
					else {
						cout << "�ظ�����" << " ";
						cout << attList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "δ�ҵ������Ϣ" << endl;
			}
			cout << "��ѡ���Ƿ񷵻��ϼ��˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return attIndex;
			break;
		case '6':
			date = " "; courseNumber = " ";
			cout << "���������ں͵ڼ��ڿΣ�ʹ�ÿո������";
			cin >> date >> courseNumber;
			while (true) {
				if (getNum(date).length() != 8) {
					cout << "���ڸ�ʽ���������ʹ��0�����λ�����»���: ";
					cin >> date;
				}
				else break;
			}

			count = 0;
			for (i = 0; i < attList.size(); i++) {
				if (attList.at(i).finddate(date) && attList.at(i).findcourseNumber(courseNumber)) {  //ֻ�Ա�����
					count++;
					if (isrepeat(attIndex, i) == false) {
						attIndex.push_back(i);  //��Ӧ�� 
						cout << "��ţ�" << i << "  ";
						cout << attList.at(i) << endl;
					}
					else {
						cout << "�ظ�����" << " ";
						cout << attList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "δ�ҵ������Ϣ" << endl;
			}
			cout << "��ѡ���Ƿ񷵻��ϼ��˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return attIndex;
			break;
		case '7':
			cout << "������ȱ�����ͣ�";
			cin >> absenteeismType;
			count = 0;
			for (i = 0; i < attList.size(); i++) {  
				if (attList.at(i).getabsenteeismType() == absenteeismType) {  //�����ִ�Сд
					count++;
					if (isrepeat(attIndex, i) == false) {
						attIndex.push_back(i);
						cout << "��ţ�" << i << "  ";
						cout << attList.at(i) << endl;
					}
					else {
						cout << "�ظ�����" << " ";
						cout << attList.at(i) << endl;
					}
				}
			}
			if (count == 0) {
				cout << "δ�ҵ������Ϣ" << endl;
			}
			cout << "��ѡ���Ƿ񷵻��ϼ��˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return attIndex;
			break;
		case '0':
			return attIndex;  //�˳�������attIndex
		default:
			cout << "�����������������" << endl;
			continue;
		}
	}	
}

/*����3����ʾ
�õ�template*/

void showStudent(vector<Student> stuList) {  //
	if (stuList.empty()) {
		cout << "ѧ����Ϣ��Ϊ��" << endl;
		return;
	}
	cout << "***************��ʾѧ���ļ�¼***************" << endl;
	cout << "ѧ��\t" << "����\t" << "�Ա�\t" << "����\t" << "�༶" << endl;
	show(stuList);  //ʹ��show()����ģ��
}
void showAttendance(vector<Attendance> attList) {  //
	if (attList.empty()) {
		cout << "������Ϣ��Ϊ��" << endl;
		return;
	}
	cout << "********************************��ʾȱ�εļ�¼********************************" << endl;
	cout << "ȱ������\t" << "�ڼ��ڿ�\t" << "�γ�����\t" << "ѧ������\t" << "ȱ������" << endl;
	show(attList);  //ʹ��show()����ģ��
}

/*����4���޸ı༭
void rewriteStudent(const string strStu, const vector<Student> &sList);
void rewriteAttendance(const string strAtt, const vector<Attendance> &aList);*/
void editStudent(vector<Student>& stuList, vector<Attendance>& attList, vector<int> stuIndex, string strStu, string strAtt) {  //ѡ���޸���Ϣ��ȫ���޸ģ�stuList�д洢��ѯ�Ľ�� 
	char type, opt, flag;
	bool rep = false;
	int i = 0, n = 0, stuNum = 0;  //ѭ���õ� 
	string id, name, gender, age, clase;
	string tempid, tempname, tempgender, tempage, tempclase;  //�ݴ��޸�֮ǰ��
	string temp;
	vector<string> str;  //����ȫ���޸ĵ�������Ϣ
	if (stuIndex.size() == 0) {
		cout << "δ�ҵ������Ϣ���˳��༭" << endl;
		return;
	}
	for (i = 0; i < stuIndex.size(); i++) {  //�����Ĳ�ѯ����ŵ� 
		cout << "���: " << stuIndex.at(i) << " ";
		cout << stuList.at(stuIndex.at(i)) << endl;
	}
	while (true) {
		cout << "��ѡ����Ҫ���ĵ���ţ�";
		cin.sync();
		cin >> stuNum;
		for (i = 0; i < stuIndex.size(); i++) {  //�ж������Ƿ���ȷ
			if (stuNum == stuIndex.at(i)) {
				rep = true;
				break;
			}
		}
		if (rep) break;
		else cout << "��Ŵ�������������" << endl;
	}
	cout << "===========ѧ����Ϣ�޸�===========" << endl;
	cout << "1���޸�ѧ�ţ�" << endl;
	cout << "2���޸�������" << endl;  //ѧ���ж��ڲ��� 
	cout << "3���޸��Ա�" << endl;
	cout << "4���޸����䣻" << endl;
	cout << "5���޸İ༶��" << endl;
	cout << "6��ȫ���޸ģ�" << endl;
	cout << "0: �������˵�" << endl;
	cout << "==================================" << endl;

	while (true) {
		cout << "��ѡ����Ҫ�޸ĵ���Ϣ: ";
		cin.sync();
		type = cin.get();
		switch (type) {
		case '1':  //����Ҫ��Attendance��id 
			cout << "�������޸ĺ��ѧ�ţ�";
		IDE: cin >> id;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findID(id)) {
					cout << "ѧ���ظ�������������ѧ�ţ�";
					goto IDE;
				}
			}
			tempid = stuList.at(stuNum).getid();
			stuList.at(stuNum).changeid(id);
			cout << "�޸ĺ����Ϣ����" << endl;
			cout << stuList.at(stuNum) << endl;
			cout << "�����Ƿ񱣴�(Y/N)��Ĭ����: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				stuList.at(stuNum).changeid(tempid);  //����������ٸĻ�ȥ
				cout << stuList.at(stuNum) << endl;
			}
			else {
				for (n = 0; n < attList.size(); n++) {  //ͬʱ��Ҫ�޸�Attendance�е�ѧ��
					if (attList.at(n).getid() == tempid) {
						attList.at(n).changeid(id);
					}
				}
				rewriteAttendance(strAtt, attList);  //����д��������Ϣ
				rewriteStudent(strStu, stuList);  //����д��������Ϣ
				cout << "����ɹ�" << endl;
			}
			cout << "��ѡ���Ƿ񷵻����˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '2':
			cout << "�������޸ĺ��ѧ������: ";
			cin.sync();
			getline(cin, name);
			tempid = stuList.at(stuNum).getid();
			tempname = stuList.at(stuNum).getname();
			stuList.at(stuNum).changename(name);
			cout << "�޸ĺ����Ϣ����" << endl;
			cout << stuList.at(stuNum) << endl;
			cout << "�����Ƿ񱣴�(Y/N)��Ĭ����: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				stuList.at(stuNum).changename(tempname);
				cout << stuList.at(stuNum) << endl;
			}
			else {
				for (n = 0; n < attList.size(); n++) {  //ͬʱ��Ҫ�޸�Attendance�ж�Ӧѧ�ŵ����� 
					if (attList.at(n).getid() == tempid) {
						attList.at(n).changestudentName(name, tempid);
					}
				}
				rewriteAttendance(strAtt, attList);
				rewriteStudent(strStu, stuList);
				cout << "����ɹ�" << endl;
			}
			cout << "��ѡ���Ƿ񷵻����˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '3':
			cout << "������ĺ��ѧ���Ա�: ";
			cin >> gender;
			tempgender = stuList.at(stuNum).getgender();
			stuList.at(stuNum).changegender(gender);
			cout << "�޸ĺ����Ϣ����" << endl;
			cout << stuList.at(stuNum) << endl;
			cout << "�����Ƿ񱣴�(Y/N)��Ĭ����: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				stuList.at(stuNum).changegender(tempgender);
				cout << stuList.at(stuNum) << endl;
			}
			else {
				rewriteStudent(strStu, stuList);
				cout << "����ɹ�" << endl;
			}
			cout << "��ѡ���Ƿ񷵻����˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '4':
			cout << "������ĺ��ѧ������: ";
			cin >> age;
			tempage = stuList.at(stuNum).getage();
			stuList.at(stuNum).changeage(age);
			cout << "�޸ĺ����Ϣ����" << endl;
			cout << stuList.at(stuNum) << endl;
			cout << "�����Ƿ񱣴�(Y/N)��Ĭ����: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				stuList.at(stuNum).changeage(tempage);
				cout << stuList.at(stuNum) << endl;
			}
			else {
				rewriteStudent(strStu, stuList);
				cout << "����ɹ�" << endl;
			}
			cout << "��ѡ���Ƿ񷵻����˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '5':
			cout << "������ĺ��ѧ���༶: ";
			cin.sync();
			getline(cin, clase);
			tempclase = clase;
			stuList.at(stuNum).changeclass(clase);
			cout << "�޸ĺ����Ϣ����" << endl;
			cout << stuList.at(stuNum) << endl;
			cout << "�����Ƿ񱣴�(Y/N)��Ĭ����: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				stuList.at(stuNum).changeclass(tempclase);
				cout << stuList.at(stuNum) << endl;
			}
			else {
				rewriteStudent(strStu, stuList);
				cout << "����ɹ�" << endl;
			}
			cout << "��ѡ���Ƿ񷵻����˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '6':
			str.clear();
			cout << "�������޸ĺ��ѧ�ţ�";
		IDF: cin >> id;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findID(id)) {
					cout << "ѧ���ظ�������������ѧ�ţ�";
					goto IDF;
				}
			}
			cout << "�밴˳������ĺ���������Ա����䡢�༶��ʹ�ûس�������: ";    //ʹ��cinֱ�����������Ͱ༶�пո��ʱ�������
			cin.sync();
			for (int j = 0; j < 4; j++) {
				getline(cin, temp);
				str.push_back(temp);
			}
			name = str.at(0); gender = str.at(1); age = str.at(2); clase = str.at(3);
			tempid = stuList.at(stuNum).getid(); tempname = stuList.at(stuNum).getname();
			tempgender = stuList.at(stuNum).getgender(); tempage = stuList.at(stuNum).getage(); tempclase = stuList.at(stuNum).getclase();
			stuList.at(stuNum).changeall(id, name, gender, age, clase);
			cout << "�޸ĺ����Ϣ����" << endl;
			cout << stuList.at(stuNum) << endl;
			cout << "�����Ƿ񱣴�(Y/N)��Ĭ����: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				stuList.at(stuNum).changeall(tempid, tempname, tempgender, tempage, tempclase);
				cout << stuList.at(stuNum) << endl;
			}
			else {
				for (n = 0; n < attList.size(); n++) {  //�Ƚ�ѧ�� 
					if (attList.at(n).getid() == tempid) {
						//							attList.at(n).changeid(id);
						attList.at(n).changestudentName(name, id);  //ǰ��д��˳�����id 
						//							cout <<  attList.at(n) << endl;
					}
					//						cout << "����" << endl; 
				}
				rewriteAttendance(strAtt, attList);
				rewriteStudent(strStu, stuList);
				cout << "����ɹ�" << endl;
			}
			cout << "��ѡ���Ƿ񷵻����˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '0':
			return;
		default:
			cout << "�����������������" << endl;
			continue;
		}

	}
}
void editAttendance(vector<Attendance>& attList, vector<int>& attIndex, string strAtt, vector<Student>& stuList) {  //�༭������Ϣ��attList�д洢��ѯ���
	int i = 0, index = 0, count = 0;
	bool rep = false;
	if (attIndex.size() == 0) {
		cout << "δ�ҵ������Ϣ���˳��༭" << endl;
		return;
	}
	for (i = 0; i < attIndex.size(); i++) {  //�����Ĳ�ѯ����ŵ� 
		cout << "���: " << attIndex.at(i) << " ";
		cout << attList.at(attIndex.at(i)) << endl;
	}
	while (true) {
		cout << "��ѡ����Ҫ���ĵ���ţ�";
		cin.sync();
		cin >> index;
		for (i = 0; i < attIndex.size(); i++) {
			if (index == attIndex.at(i)) {
				rep = true;
				break;
			}
		}
		if (rep) break;
		else cout << "��Ŵ�������������" << endl;
	}
	string date, courseNumber, courseName, studentName, absenteeismType, id;
	string tempdate, tempcourseNumber, tempcourseName, tempstudentName, tempabsenteeismType, tempid;
	tempid = attList.at(index).getid();  //����֮ǰ�� 
	string temp;
	vector<string> str;
	char type, opt, flag, re;
	cout << "===========ȱ����Ϣ�޸�===========" << endl;
	cout << "1.�޸�����" << endl;
	cout << "2.�޸ĵڼ��ڿ�" << endl;
	cout << "3.�޸Ŀγ�����" << endl;
	cout << "4.�޸�ѧ������" << endl;
	cout << "5.�޸�ȱ������" << endl;
	cout << "6.�޸�������Ϣ" << endl;
	cout << "0: �������˵�" << endl;
	cout << "===================================" << endl;
	while (true) {
		cout << "��ѡ����Ҫ�޸ĵ���Ϣ��";
		cin.sync();
		type = cin.get();
		switch (type) {
		case '1':
			cout << "�������޸ĺ��ȱ������: ";
			cin >> date;
			while (true) {  //�ж����ڸ�ʽ�Ƿ��������
				if (getNum(date).length() != 8) {
					cout << "���ڸ�ʽ���������ʹ��0�����λ�����»���: ";
					cin >> date;
				}
				else break;
			}
			tempdate = attList.at(index).getdate();
			attList.at(index).changedate(date);
			cout << "�޸ĺ����Ϣ����" << endl;
			cout << attList.at(index) << endl;
			cout << "�����Ƿ񱣴�(Y/N)��Ĭ����: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				attList.at(index).changedate(tempdate);
				cout << attList.at(index) << endl;
			}
			else {
				rewriteAttendance(strAtt, attList);
				cout << "����ɹ�" << endl;
			}
			cout << "��ѡ���Ƿ񷵻����˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '2':
			cout << "�������޸ĺ��Ϊ�ڼ��ڿ�: ";
			cin >> courseNumber;
			tempcourseNumber = attList.at(index).getcourseNumber();
			cout << "�޸ĺ����Ϣ����" << endl;
			attList.at(index).changecourseNumber(courseNumber);
			cout << attList.at(index) << endl;
			cout << "�����Ƿ񱣴�(Y/N)��Ĭ����: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				attList.at(index).changecourseNumber(tempcourseNumber);
				cout << attList.at(index) << endl;
			}
			else {
				rewriteAttendance(strAtt, attList);
				cout << "����ɹ�" << endl;
			}
			cout << "��ѡ���Ƿ񷵻����˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '3':
			cout << "�������޸ĺ�Ŀγ�����: ";
			cin >> courseName;
			tempcourseName = attList.at(index).getcourseName();
			attList.at(index).changecourseName(courseName);
			cout << "�޸ĺ����Ϣ����" << endl;
			cout << attList.at(index) << endl;
			cout << "�����Ƿ񱣴�(Y/N)��Ĭ����: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				attList.at(index).changecourseName(tempcourseName);
				cout << attList.at(index) << endl;
			}
			else {
				rewriteAttendance(strAtt, attList);
				cout << "����ɹ�" << endl;
			}
			cout << "��ѡ���Ƿ񷵻����˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '4':
			count = 0;
		IDH: cout << "�������޸ĺ��ѧ������: ";  //��ѧ��������ͶԲ���ѧ���ˣ�����Ҳ��Ҫ��Attendance�е�ѧ��
			cin.sync();
			getline(cin, studentName);
		IDG: cout << "�������ѧ����ѧ�ţ�";
			cin >> id;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findID(id) && stuList.at(i).getname() == studentName) {  //�����ϸ����
					count++;
					break;
				}
			}
			if (count == 0) {
				re = 'I';
				cout << "ѧ����Ϣ��û�и�ѧ�ţ���ѡ��������������(n/N)����ѧ��(i/I)��Ĭ����������ѧ��:";
				cin.sync();
				re = cin.get();
				if (re == 'N' || re == 'n') goto IDH;
				else goto IDG;
			}
			tempstudentName = attList.at(index).getstudentName();
			attList.at(index).changestudentName(studentName, id);  //����������ѧ��
			cout << "�޸ĺ����Ϣ����" << endl;
			cout << attList.at(index) << endl;
			cout << "�����Ƿ񱣴�(Y/N)��Ĭ����: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				attList.at(index).changestudentName(tempcourseName, tempid);  
				cout << attList.at(index) << endl;
			}
			else {
				rewriteAttendance(strAtt, attList);
				cout << "����ɹ�" << endl;
			}
			cout << "��ѡ���Ƿ񷵻����˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '5':
			cout << "�������޸ĺ��ȱ������: ";
			cin >> absenteeismType;
			tempabsenteeismType = attList.at(index).getabsenteeismType();
			attList.at(index).changeabsenteeismType(absenteeismType);
			cout << "�޸ĺ����Ϣ����" << endl;
			cout << attList.at(index) << endl;
			cout << "�����Ƿ񱣴�(Y/N)��Ĭ����: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				attList.at(index).changeabsenteeismType(tempabsenteeismType);
				cout << attList.at(index) << endl;
			}
			else {
				rewriteAttendance(strAtt, attList);
				cout << "����ɹ�" << endl;
			}
			cout << "��ѡ���Ƿ񷵻����˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '6':
			str.clear();
			count = 0;
		IDI: cout << "�������޸ĺ��ѧ������: ";  //��ѧ��������ͶԲ���ѧ���ˣ�����Ҳ��Ҫ�� 
			cin.sync();
			getline(cin, studentName);
		IDJ: cout << "�������ѧ����ѧ�ţ�";
			cin >> id;
			for (i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findID(id) && stuList.at(i).getname() == studentName) {  //���������ϸ���� 
					count++;
					break;
				}
			}
			if (count == 0) {
				re = 'I';
				cout << "ѧ����Ϣ��û�и�ѧ�ţ���ѡ��������������(n/N)����ѧ��(i/I)��Ĭ����������ѧ��:";
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

			cout << "�����밴˳�������޸ĺ��ȱ�����ڡ��ڼ��ڿΡ��γ����ơ�ȱ�����ͣ�ʹ�ûس�������: ";  //������ȷ������ѧ�ź���ܸ���������Ϣ
			cin.sync();
			for (int j = 0; j < 4; j++) {
				getline(cin, temp);
				str.push_back(temp);
			}
			while (true) {  //���������ʽ��ȷ
				if (getNum(str.at(0)).length() != 8) {
					cout << "���ڸ�ʽ���������ʹ��0�����λ�����»��գ�";
					cin >> str.at(0);
				}
				else break;
			}
			attList.at(index).changeall(str.at(0), str.at(1), str.at(2), studentName, str.at(3), id);
			cout << "�޸ĺ����Ϣ����" << endl;
			cout << attList.at(index) << endl;
			cout << "�����Ƿ񱣴�(Y/N)��Ĭ����: ";
			opt = 'Y';
			cin.sync();
			opt = cin.get();
			if (opt == 'N' || opt == 'n') {
				attList.at(index).changeall(tempdate, tempcourseNumber, tempcourseName, tempstudentName, tempabsenteeismType, tempid);
				cout << attList.at(index) << endl;
			}
			else {
				rewriteAttendance(strAtt, attList);
				cout << "����ɹ�" << endl;
			}
			cout << "��ѡ���Ƿ񷵻����˵�(Y/N)��Ĭ�Ϸ�: ";
			flag = 'N';
			cin.sync();
			flag = cin.get();
			if (flag == 'Y' || flag == 'y') return;
			break;
		case '0':
			return;
		default:
			cout << "�����������������" << endl;
			continue;
		}
	}

}

/*����5��ɾ����������������༭��ͬ��*/
void deleteStudent(vector<Student>& stuList, vector<Attendance>& attList, vector<int> stuIndex, string strStu, string strAtt) {  //ɾ��Student��Ϣ��ͬʱҲ��ɾ����Ӧѧ�ŵ�Attendance��Ϣ
	bool rep = false, flag = false;
	int i = 0, n = 0, stuNum = 0, count = 0, index = 0;
	vector<int> deleteindex;  //����Ҫɾ�������
	char opt, ex, all;
	if (stuIndex.size() == 0) {  //��ѯ���Ϊ��
		cout << "δ�ҵ������Ϣ���˳�" << endl;
		return;
	}
	for (i = 0; i < stuIndex.size(); i++) {  //�����Ĳ�ѯ����ŵ� 
		cout << "���: " << stuIndex.at(i) << " ";
		cout << stuList.at(stuIndex.at(i)) << endl;
	}
	while (true) {
		while (true) {
			cin.sync();
			cout << "��ѡ����Ҫɾ������ţ�";  //�����ɾ���ظ������ɾ���ͻ���� 
			cin >> stuNum;
			for (i = 0; i < deleteindex.size(); i++) {  //�ж��Ƿ��Ѿ�ɾ����
				if (stuNum == deleteindex.at(i)) {
					flag = true;
					cout << "����ظ�������������" << endl;
					break;
				}
			}
			if (flag) {
				flag = false;
				continue;
			}
			for (i = 0; i < stuIndex.size(); i++) {  //�ж����������Ƿ���stuIndex��
				if (stuNum == stuIndex.at(i)) {
					rep = true;
					break;
				}
			}
			if (rep) {
				rep = false;
				break;
			}
			else cout << "��Ŵ�������������" << endl;
		}
		deleteindex.push_back(stuNum);  //��ӽ���
		if (deleteindex.size() == stuIndex.size()) {  //���������Ϣ����ɾ��
			cout << "���ҵ���Ϣ��ȫ��ѡ���Ƿ񱣴沢�˳���Ĭ���ǣ�";
			cin.sync();
			all = cin.get();
			if (all == 'N' || all == 'n') {
				cout << "ȡ�����沢�˳�" << endl;
				return;
			}
			else {  //ɾ����Ӧ��Ϣ������
				for (int j = 0; j < deleteindex.size(); j++) {  //ɾ��attList��Ϣ
					for (i = 0; i < attList.size(); i++) {
						if (stuList.at(deleteindex.at(j)).getid() == attList.at(i).getid()) {
							attList.erase(attList.begin() + i);
						}
					}
				}
				for (i = 0; i < deleteindex.size(); i++) {  //ɾ��stuList��Ϣ
					stuList.erase(stuList.begin() + deleteindex.at(i));
				}
				rewriteStudent(strStu, stuList);
				rewriteAttendance(strAtt, attList);
				cout << "����ɹ�" << endl;
				return;
			}
		}
		//������ɾ��һ��������Ϣ��û��ȫ��ɾ����
		cout << "�����Ƿ񱣴�(Y/N)���˳���Ĭ����: ";  //��ȡȫ��Ҫɾ���ĺ��ٱ����˳� 
		opt = 'Y';
		cin.sync();
		opt = cin.get();
		if (opt == 'N' || opt == 'n') {
			cout << "��ѡ���Ƿ��˳���Ĭ�Ϸ�";
			ex = 'N';
			cin.sync();
			ex = cin.get();
			if (ex == 'Y' || ex == 'y') {
				cout << "ȡ�����沢�˳�" << endl;
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
			cout << "����ɹ�" << endl;
			return;
		}
	}
}
void deleteAttendance(vector<Attendance>& attList, vector<int> attIndex, string strAtt) {  //ɾ��Attendance��Ϣ
	bool rep = false, flag = false;
	int i = 0, n = 0, attNum = 0, count = 0, index = 0;
	vector<int> deleteindex;
	char opt, ex, all;
	if (attIndex.size() == 0) {
		cout << "δ�ҵ������Ϣ���˳�" << endl;
		return;
	}
	for (i = 0; i < attIndex.size(); i++) {  //�����Ĳ�ѯ����ŵ� 
		cout << "���: " << attIndex.at(i) << " ";
		cout << attList.at(attIndex.at(i)) << endl;
	}
	while (true) {
		while (true) {
			cout << "��ѡ����Ҫɾ������ţ�"; 
			cin.sync();
			cin >> attNum;
			for (i = 0; i < deleteindex.size(); i++) {
				if (attNum == deleteindex.at(i)) {
					flag = true;
					cout << "����ظ�������������" << endl;
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
			else cout << "��Ŵ�������������" << endl;
		}
		deleteindex.push_back(attNum);
		if (deleteindex.size() == attIndex.size()) {  //ȫ����Ϣ��ѡ�񣬲�����Ҫ����������ţ�ֱ��ѡ���Ƿ񱣴�
			cout << "���ҵ���Ϣ��ȫ��ѡ���Ƿ񱣴沢�˳���Ĭ���ǣ�";
			cin.sync();
			all = cin.get();
			if (all == 'N' || all == 'n') {
				cout << "ȡ�����沢�˳�" << endl;
				return;
			}
			else {
				for (i = 0; i < deleteindex.size(); i++) {
					attList.erase(attList.begin() + deleteindex.at(i));
				}
				rewriteAttendance(strAtt, attList);
				cout << "����ɹ�" << endl;
				return;
			}
		}
		//ÿѡ��һ����ź�����
		cout << "�����Ƿ񱣴�(Y/N)���˳���Ĭ����: ";
		opt = 'Y';
		cin.sync();
		opt = cin.get();
		if (opt == 'N' || opt == 'n') {
			cout << "��ѡ���Ƿ��˳���Ĭ�Ϸ�";
			ex = 'N';
			cin.sync();
			ex = cin.get();
			if (ex == 'Y' || ex == 'y') {
				cout << "ȡ�����沢�˳�" << endl;
				return;
			}

		}
		else {
			for (i = 0; i < deleteindex.size(); i++) {
				attList.erase(attList.begin() + deleteindex.at(i));
			}
			rewriteAttendance(strAtt, attList);
			cout << "����ɹ�" << endl;
			return;
		}
	}
}

/*����6��ͳ��
bool openfile(const string str)
void readAttendanceList(string str, vector<Attendance> &attList)
void readStudentList(const string str, vector<Student> &stuList);
*/
void bubbleCourse(vector<Attendance>& att, char type, char rule) {
	for (int i = att.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (rule == '2') {
				switch (type) {  //����Ч�ʸо���̫�� 
				case '1':
					if (getNum(att.at(i).getdate()) > getNum(att.at(j).getdate())) {  //�Ӵ�С 
						Attendance temp = att[i];
						att[i] = att[j];
						att[j] = temp;
					}
					break;
				case '2':
					if (att.at(i).getcourseNumber() > att.at(j).getcourseNumber()) {  //�Ӵ�С 
						Attendance temp = att[i];
						att[i] = att[j];
						att[j] = temp;
					}
					break;
				case '3':
					if (att.at(i).getcourseName() > att.at(j).getcourseName()) {  //�Ӵ�С 
						Attendance temp = att[i];
						att[i] = att[j];
						att[j] = temp;
					}
					break;
				case '4':
					if (att.at(i).getstudentName() > att.at(j).getstudentName()) {  //�Ӵ�С 
						Attendance temp = att[i];
						att[i] = att[j];
						att[j] = temp;
					}
					break;
				case '5':
					if (att.at(i).getabsenteeismType() > att.at(j).getabsenteeismType()) {  //�Ӵ�С 
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
	vector<Attendance> att;  //�ݴ��˳�򣬿�����������Ƿ����˳�򱣴浽һ���µ��ļ��� 
	vector<Attendance> attread;
	cin.sync();
	char sta, type, rule, save, read, ret;
	cout << "=============ͳ������=============" << endl;  /////////////////////////////////�о������Լ�һ����ʱ���ͳ�� 
	cout << "1.��ȱ������ͳ��" << endl;
	cout << "2.���ڼ��ڿ�ͳ��" << endl;  //���Ҳ���Կ�һ���ĳ�������� 
	cout << "3.���γ�����ͳ��" << endl;
	cout << "4.��ѧ������ͳ��" << endl;
	cout << "5.��ȱ������ͳ��" << endl;
	cout << "6.������ʱ���ͳ��" << endl;
	cout << "7.���ض����ڵĵڼ��ڿ�ͳ��" << endl;
	cout << "0.�������˵�" << endl;
	cout << "==================================" << endl;
	while (true) {
		cout << "��ѡ��ͳ�����ͣ�";
		cin.sync();
		sta = cin.get();
		switch (sta) {
		case '1':
			att.clear();
			type = '0';
			rule = '0';
			if (openfile("Attdate")) {//Ϊʲô�����жϣ���
				//					file.close();
				attread.clear();
				cout << "����֮ǰ������ͳ���ļ����Ƿ��ȡ��Y/N����Ĭ�Ϸ�";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readAttendanceList("Attdate", attread);
					showAttendance(attread);
					cout << "�����Ƿ񷵻��ϼ��˵���Y/N����Ĭ�Ϸ�";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}


			cout << "������ȱ�����ڣ�";  //////////////////////���ڻ�����Ҫ�涨�ģ���Ϊ01��01�պ� 1��1�նԱȲ�ͬ������ǰ���getNum���� 
			cin.sync();
			cin >> date;
			while (true) {
				if (getNum(date).length() != 8) {
					cout << "���ڸ�ʽ���������ʹ��0�����λ�����»��գ�";
					cin >> date;
				}
				else break;
			}

			for (int i = 0; i < attList.size(); i++) {
				if (attList.at(i).finddate(date)) {  //�����ʵ�ֲ��� 
					att.push_back(attList.at(i));
				}
			}
			if (att.size() == 0) {
				cout << "δ�ҵ�������ڣ�������ѡ��" << endl;
				break;
			}
			//ʵ������
			while (true) {
				cout << "�������������ݣ�2���ڼ��ڿΣ� 3���γ����ƣ� 4��ѧ�������� 5��ȱ�����ͣ�: ";
				cin.sync();
				type = cin.get();
				if (type > '1' && type <= '5') break;
				else {
					cout << "��������ȷ�����" << endl;
					continue;
				}
			}
			cout << "�������������1����С���� 2���Ӵ�С��Ĭ�ϴ�С����: ";  //�ջ��ߴ�����1 
			cin.sync();
			rule = cin.get();
			bubbleCourse(att, type, rule);
			show(att);
			cout << "����" << att.size() << "�����" << endl;

			cout << "�����Ƿ񱣴�����Ĭ�Ϸ�";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //�Ͳ��������������˰� 
				rewriteAttendance("Attdate", att);
			}
			else cout << "ȡ������ͳ�ƽ��" << endl;
			break;
		case '2':
			att.clear();
			type = '0';
			rule = '0';
			if (openfile("AttcourseNumber")) {
				attread.clear();
				cout << "����֮ǰ������ͳ���ļ����Ƿ��ȡ��Y/N����Ĭ�Ϸ�";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readAttendanceList("AttcouresNumber", attread);
					showAttendance(attread);
					cout << "�����Ƿ񷵻��ϼ��˵���Y/N����Ĭ�Ϸ�";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}

			cout << "������ڼ��ڿΣ�";  //////////////////////���ڻ�����Ҫ�涨�ģ���Ϊ01��01�պ� 1��1�նԱȲ�ͬ������ǰ���getNum���� 
			cin.sync();
			cin >> courseNumber;
			for (int i = 0; i < attList.size(); i++) {
				if (attList.at(i).findcourseNumber(courseNumber)) {
					att.push_back(attList.at(i));
				}
			}
			if (att.size() == 0) {
				cout << "δ�ҵ���ش˶ογ̣�������ѡ��" << endl;
				break;
			}
			//ʵ������
			while (true) {
				cout << "�������������ݣ�1�����ڣ� 3���γ����ƣ� 4��ѧ�������� 5��ȱ�����ͣ�: ";
				cin.sync();
				type = cin.get();
				if (type >= '1' && type <= '5' && type != '2') break;
				else {
					cout << "��������ȷ�����" << endl;
					continue;
				}
			}
			cout << "�������������1����С���� 2���Ӵ�С��Ĭ�ϴ�С����: ";  //�ջ��ߴ�����1 
			cin.sync();
			rule = cin.get();
			bubbleCourse(att, type, rule);
			show(att);
			cout << "����" << att.size() << "�����" << endl;

			cout << "�����Ƿ񱣴�����Ĭ�Ϸ�";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //�Ͳ��������������˰� 
				rewriteAttendance("AttcourseNumber", att);
			}
			else cout << "ȡ������ͳ�ƽ��" << endl;

			break;
		case '3':
			att.clear();  //��Ҫ��գ����Ᵽ����һ�η���ѯ���
			type = '0';
			rule = '0';

			if (openfile("AttcourseName")) {
				attread.clear();
				cout << "����֮ǰ������ͳ���ļ����Ƿ��ȡ��Y/N����Ĭ�Ϸ�";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readAttendanceList("AttcourseName", attread);
					showAttendance(attread);
					cout << "�����Ƿ񷵻��ϼ��˵���Y/N����Ĭ�Ϸ�";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}


			cout << "������γ�����: ";  //��Сд���⡪��find��ʵ�ֲ����ִ�Сд 
			cin.sync();
			cin >> courseName;
			for (int i = 0; i < attList.size(); i++) {
				if (attList.at(i).findCourse(courseName)) {
					att.push_back(attList.at(i));
				}
			}
			if (att.size() == 0) {
				cout << "δ�ҵ���ؿγ̣�������ѡ��" << endl;
				break;
			}
			//ʵ������
			while (true) {
				cout << "�������������ݣ�1�����ڣ� 2���ڼ��ڿΣ� 4��ѧ�������� 5��ȱ�����ͣ�: ";
				cin.sync();
				type = cin.get();
				if (type >= '1' && type <= '5' && type != '3') break;
				else {
					cout << "��������ȷ�����" << endl;
					continue;
				}
			}
			cout << "�������������1����С���� 2���Ӵ�С��Ĭ�ϴ�С����: ";  //�ջ��ߴ�����1 
			cin.sync();
			rule = cin.get();
			bubbleCourse(att, type, rule);
			show(att);
			cout << "����" << att.size() << "�����" << endl;

			cout << "�����Ƿ񱣴�����Ĭ�Ϸ�";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //�Ͳ��������������˰� 
				rewriteAttendance("AttcourseName", att);
			}
			else cout << "ȡ������ͳ�ƽ��" << endl;
			break;
		case '4':
			att.clear();
			type = '0';
			rule = '0';

			if (openfile("AttstudentName")) {
				attread.clear();
				cout << "����֮ǰ������ͳ���ļ����Ƿ��ȡ��Y/N����Ĭ�Ϸ�";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readAttendanceList("AttstudentName", attread);
					showAttendance(attread);
					cout << "�����Ƿ񷵻��ϼ��˵���Y/N����Ĭ�Ϸ�";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}


			cout << "������ѧ��������";  //////////////////////���ڻ�����Ҫ�涨�ģ���Ϊ01��01�պ� 1��1�նԱȲ�ͬ������ǰ���getNum���� 
			cin.sync();
			getline(cin, studentName);
			for (int i = 0; i < attList.size(); i++) {
				if (attList.at(i).findstudentName(studentName)) {
					att.push_back(attList.at(i));
				}
			}
			if (att.size() == 0) {
				cout << "δ�ҵ����ѧ����������ѡ��" << endl;
				break;
			}
			//ʵ������
			while (true) {
				cout << "�������������ݣ�1�����ڣ� 2���ڼ��ڿΣ� 3���γ����ƣ� 5��ȱ�����ͣ�: ";
				cin.sync();
				type = cin.get();
				if (type >= '1' && type <= '5' && type != '4') break;
				else {
					cout << "��������ȷ�����" << endl;
					continue;
				}
			}
			cout << "�������������1����С���� 2���Ӵ�С��Ĭ�ϴ�С����: ";  //�ջ��ߴ�����1 
			cin.sync();
			rule = cin.get();
			bubbleCourse(att, type, rule);
			show(att);
			cout << "����" << att.size() << "�����" << endl;

			cout << "�����Ƿ񱣴�����Ĭ�Ϸ�";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //�Ͳ��������������˰� 
				rewriteAttendance("AttstudentName", att);
			}
			else cout << "ȡ������ͳ�ƽ��" << endl;
			break;
		case '5':
			att.clear();
			type = '0';
			rule = '0';
			if (openfile("AttabsenteeismType")) {
				attread.clear();
				cout << "����֮ǰ������ͳ���ļ����Ƿ��ȡ��Y/N����Ĭ�Ϸ�";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readAttendanceList("AttabsenteeismType", attread);
					showAttendance(attread);
					cout << "�����Ƿ񷵻��ϼ��˵���Y/N����Ĭ�Ϸ�";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}

			cout << "������ȱ�����ͣ�";  //////////////////////���ڻ�����Ҫ�涨�ģ���Ϊ01��01�պ� 1��1�նԱȲ�ͬ������ǰ���getNum���� 
			cin.sync();
			cin >> absenteeismType;
			for (int i = 0; i < attList.size(); i++) {
				if (attList.at(i).findabsenteeism(absenteeismType)) {
					att.push_back(attList.at(i));
				}
			}
			if (att.size() == 0) {
				cout << "δ�ҵ����ȱ�����ͣ�������ѡ��" << endl;
				break;
			}
			//ʵ������
			while (true) {
				cout << "�������������ݣ�1�����ڣ� 2���ڼ��ڿΣ� 3���γ����ƣ� 4��ѧ��������: ";
				cin.sync();
				type = cin.get();
				if (type >= '1' && type < '5') break;
				else {
					cout << "��������ȷ�����" << endl;
					continue;
				}
			}
			cout << "�������������1����С���� 2���Ӵ�С��Ĭ�ϴ�С����: ";  //�ջ��ߴ�����1 
			cin.sync();
			rule = cin.get();
			bubbleCourse(att, type, rule);
			show(att);
			cout << "����" << att.size() << "�����" << endl;

			cout << "�����Ƿ񱣴�����Ĭ�Ϸ�";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //�Ͳ��������������˰� 
				rewriteAttendance("AttabsenteeismType", att);
			}
			else cout << "ȡ������ͳ�ƽ��" << endl;
			break;
		case '6':
			att.clear();
			type = '0';
			rule = '0';
			if (openfile("Attperiod")) {
				attread.clear();
				cout << "����֮ǰ������ͳ���ļ����Ƿ��ȡ��Y/N����Ĭ�Ϸ�";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readAttendanceList("Attperiod", attread);
					showAttendance(attread);
					cout << "�����Ƿ񷵻��ϼ��˵���Y/N����Ĭ�Ϸ�";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}


			cout << "��������ʼȱ�����ڣ�";  //////////////////////���ڻ�����Ҫ�涨�ģ���Ϊ01��01�պ� 1��1�նԱȲ�ͬ������ǰ���getNum���� 
			cin.sync();
			cin >> date;
			while (true) {
				if (getNum(date).length() != 8) {
					cout << "���ڸ�ʽ���������ʹ��0�����λ�����»��գ�";
					cin >> date;
				}
				else break;
			}
			cout << "���������ȱ�����ڣ�";  //////////////////////���ڻ�����Ҫ�涨�ģ���Ϊ01��01�պ� 1��1�նԱȲ�ͬ������ǰ���getNum���� 
			cin.sync();
			cin >> dateend;
			while (true) {
				if (getNum(dateend).length() != 8) {
					cout << "���ڸ�ʽ���������ʹ��0�����λ�����»��գ�";
					cin >> dateend;
				}
				else break;
			}

			for (int i = 0; i < attList.size(); i++) {
				if (getNum(attList.at(i).getdate()) >= getNum(date) && getNum(attList.at(i).getdate()) <= getNum(dateend)) {  //�����ʵ�ֲ��� 
					att.push_back(attList.at(i));
				}
			}
			if (att.size() == 0) {
				cout << "δ�ҵ�������ڣ�������ѡ��" << endl;
				break;
			}
			//ʵ������
			while (true) {
				cout << "�������������ݣ�1��ȱ�����ڣ� 2���ڼ��ڿΣ� 3���γ����ƣ� 4��ѧ�������� 5��ȱ�����ͣ�: ";
				cin.sync();
				type = cin.get();
				if (type >= '1' && type <= '5') break;
				else {
					cout << "��������ȷ�����" << endl;
					continue;
				}
			}
			cout << "�������������1����С���� 2���Ӵ�С��Ĭ�ϴ�С����: ";  //�ջ��ߴ�����1 
			cin.sync();
			rule = cin.get();
			bubbleCourse(att, type, rule);
			show(att);
			cout << "����" << att.size() << "�����" << endl;

			cout << "�����Ƿ񱣴�����Ĭ�Ϸ�";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //�Ͳ��������������˰� 
				rewriteAttendance("Attperiod", att);
			}
			else cout << "ȡ������ͳ�ƽ��" << endl;
			break;
		case '7':
			att.clear();
			type = '0';
			rule = '0';
			if (openfile("AttdateCourse")) {//Ϊʲô�����жϣ���
				//					file.close();
				attread.clear();
				cout << "����֮ǰ������ͳ���ļ����Ƿ��ȡ��Y/N����Ĭ�Ϸ�";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readAttendanceList("AttdateCourse", attread);
					showAttendance(attread);
					cout << "�����Ƿ񷵻��ϼ��˵���Y/N����Ĭ�Ϸ�";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}


			cout << "������ȱ�����ڣ�";
			cin.sync();
			cin >> date;
			while (true) {
				if (getNum(date).length() != 8) {
					cout << "���ڸ�ʽ���������ʹ��0�����λ�����»��գ�";
					cin >> date;
				}
				else break;
			}
			cout << "������ڼ��ڿΣ�";  //////////////////////���ڻ�����Ҫ�涨�ģ���Ϊ01��01�պ� 1��1�նԱȲ�ͬ������ǰ���getNum���� 
			cin.sync();
			cin >> courseNumber;

			for (int i = 0; i < attList.size(); i++) {
				if (attList.at(i).finddate(date) && attList.at(i).findcourseNumber(courseNumber)) {  //�����ʵ�ֲ��� 
					att.push_back(attList.at(i));
				}
			}
			if (att.size() == 0) {
				cout << "δ�ҵ���ؽ����������ѡ��" << endl;
				break;
			}
			//ʵ������
			while (true) {
				cout << "�������������ݣ�3���γ����ƣ� 4��ѧ�������� 5��ȱ�����ͣ�: ";
				cin.sync();
				type = cin.get();
				if (type > '2' && type <= '5') break;
				else {
					cout << "��������ȷ�����" << endl;
					continue;
				}
			}
			cout << "�������������1����С���� 2���Ӵ�С��Ĭ�ϴ�С����: ";  //�ջ��ߴ�����1 
			cin.sync();
			rule = cin.get();
			bubbleCourse(att, type, rule);
			show(att);
			cout << "����" << att.size() << "�����" << endl;

			cout << "�����Ƿ񱣴�����Ĭ�Ϸ�";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //�Ͳ��������������˰� 
				rewriteAttendance("AttdateCourse", att);
			}
			else cout << "ȡ������ͳ�ƽ��" << endl;
			break;
		case '0':
			return;
		default:
			cout << "�����������������" << endl;
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
					if (stu.at(i).getname() > stu.at(j).getname()) {  //�Ӵ�С 
						Student temp = stu[i];
						stu[i] = stu[j];
						stu[j] = temp;
					}
					break;
				case '2':
					if (stu.at(i).getgender() > stu.at(j).getgender()) {  //�Ӵ�С 
						Student temp = stu[i];
						stu[i] = stu[j];
						stu[j] = temp;
					}
					break;
				case '3':
					if (stu.at(i).getage() > stu.at(j).getage()) {  //�Ӵ�С 
						Student temp = stu[i];
						stu[i] = stu[j];
						stu[j] = temp;
					}
					break;
				case '4':
					if (stu.at(i).getclase() > stu.at(j).getclase()) {  //�Ӵ�С 
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
void countStudent(vector<Student>& stuList) {  //���Ǻ�����Ĳ��һ�£���main��ѡ��ȽϺã��о��������ܹ��� 
	string name, gender, age, clase;
	vector<Student> stu;  //�ݴ��˳�򣬿�����������Ƿ����˳�򱣴浽һ���µ��ļ��� 
	vector<Student> sturead;
	cin.sync();
	char sta, type, rule, save, read, ret;
	cout << "=============ͳ������=============" << endl;
	//	cout << "1.��ѧ��ͳ��" << endl;  //����Ҫ 
	cout << "1.������ͳ��" << endl;
	cout << "2.���Ա�ͳ��" << endl;
	cout << "3.������ͳ��" << endl;
	cout << "4.���༶ͳ��" << endl;
	cout << "0.�������˵�" << endl;
	cout << "==================================" << endl;
	while (true) {
		cout << "��ѡ��ͳ�����ͣ�";
		cin.sync();
		sta = cin.get();
		switch (sta) {
		case '1':
			stu.clear();
			type = '0';
			rule = '0';
			if (openfile("Stuname")) {
				sturead.clear();
				cout << "����֮ǰ������ͳ���ļ����Ƿ��ȡ��Y/N����Ĭ�Ϸ�";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readStudentList("Stuname", sturead);
					showStudent(sturead);
					cout << "�����Ƿ񷵻��ϼ��˵���Y/N����Ĭ�Ϸ�";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}

			cout << "������������";  //////////////////////���ڻ�����Ҫ�涨�ģ���Ϊ01��01�պ� 1��1�նԱȲ�ͬ������ǰ���getNum���� 
			cin.sync();
			getline(cin, name);
			for (int i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findName(name)) {
					stu.push_back(stuList.at(i));
				}
			}
			if (stu.size() == 0) {
				cout << "δ�ҵ���ͬ������������ѡ��" << endl;
				break;
			}
			//ʵ������
			while (true) {
				cout << "�������������ݣ�2���Ա� 3�����䣻 4���༶��: ";
				cin.sync();
				type = cin.get();
				if (type > '1' && type <= '4') break;
				else {
					cout << "��������ȷ�����" << endl;
					continue;
				}
			}
			cout << "�������������1����С���� 2���Ӵ�С��Ĭ�ϴ�С����: ";  //�ջ��ߴ�����1 
			cin.sync();
			rule = cin.get();
			bubbleStudent(stu, type, rule);
			show(stu);
			cout << "����" << stu.size() << "�����" << endl;

			cout << "�����Ƿ񱣴�����Ĭ�Ϸ�";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //�Ͳ��������������˰� 
				rewriteStudent("Stuname", stu);
			}
			else cout << "ȡ������ͳ�ƽ��" << endl;
			break;
		case '2':
			stu.clear();
			type = '0';
			rule = '0';

			if (openfile("Stugender")) {
				sturead.clear();
				cout << "����֮ǰ������ͳ���ļ����Ƿ��ȡ��Y/N����Ĭ�Ϸ�";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readStudentList("Stugender", sturead);
					showStudent(sturead);
					cout << "�����Ƿ񷵻��ϼ��˵���Y/N����Ĭ�Ϸ�";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}

			cout << "�������Ա�";  //////////////////////���ڻ�����Ҫ�涨�ģ���Ϊ01��01�պ� 1��1�նԱȲ�ͬ������ǰ���getNum���� 
			cin >> gender;
			for (int i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findgender(gender)) {
					stu.push_back(stuList.at(i));
				}
			}
			if (stu.size() == 0) {
				cout << "δ�ҵ���ͬ�Ա�������ѡ��" << endl;
				break;
			}
			//ʵ������
			while (true) {
				cout << "�������������ݣ�1�������� 3�����䣻 4���༶��: ";
				cin.sync();
				type = cin.get();
				if (type >= '1' && type <= '4' && type != 2) break;
				else {
					cout << "��������ȷ�����" << endl;
					continue;
				}
			}
			cout << "�������������1����С���� 2���Ӵ�С��Ĭ�ϴ�С����: ";  //�ջ��ߴ�����1 
			cin.sync();
			rule = cin.get();
			bubbleStudent(stu, type, rule);
			show(stu);
			cout << "����" << stu.size() << "�����" << endl;

			cout << "�����Ƿ񱣴�����Ĭ�Ϸ�";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //�Ͳ��������������˰� 
				rewriteStudent("Stugender", stu);
			}
			else cout << "ȡ������ͳ�ƽ��" << endl;
			break;
		case '3':
			stu.clear();
			type = '0';
			rule = '0';

			if (openfile("Stuage")) {
				sturead.clear();
				cout << "����֮ǰ������ͳ���ļ����Ƿ��ȡ��Y/N����Ĭ�Ϸ�";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readStudentList("Stuage", sturead);
					showStudent(sturead);
					cout << "�����Ƿ񷵻��ϼ��˵���Y/N����Ĭ�Ϸ�";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}

			cout << "���������䣺";  //////////////////////���ڻ�����Ҫ�涨�ģ���Ϊ01��01�պ� 1��1�նԱȲ�ͬ������ǰ���getNum���� 
			cin >> age;
			for (int i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findage(age)) {
					stu.push_back(stuList.at(i));
				}
			}
			if (stu.size() == 0) {
				cout << "δ�ҵ���ͬ���䣬������ѡ��" << endl;
				break;
			}
			//ʵ������
			while (true) {
				cout << "�������������ݣ�1�������� 2���Ա� 4���༶��: ";
				cin.sync();
				type = cin.get();
				if (type >= '1' && type <= '4' && type != 3) break;
				else {
					cout << "��������ȷ�����" << endl;
					continue;
				}
			}
			cout << "�������������1����С���� 2���Ӵ�С��Ĭ�ϴ�С����: ";  //�ջ��ߴ�����1 
			cin.sync();
			rule = cin.get();
			bubbleStudent(stu, type, rule);
			show(stu);
			cout << "����" << stu.size() << "�����" << endl;

			cout << "�����Ƿ񱣴�����Ĭ�Ϸ�";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //�Ͳ��������������˰� 
				rewriteStudent("Stuage", stu);
			}
			else cout << "ȡ������ͳ�ƽ��" << endl;
			break;
		case '4':
			stu.clear();
			type = '0';
			rule = '0';

			if (openfile("Stuclass")) {
				sturead.clear();
				cout << "����֮ǰ������ͳ���ļ����Ƿ��ȡ��Y/N����Ĭ�Ϸ�";
				read = 'N';
				cin.sync();
				read = cin.get();
				if (read == 'Y' || read == 'y') {
					readStudentList("Stuclass", sturead);
					showStudent(sturead);
					cout << "�����Ƿ񷵻��ϼ��˵���Y/N����Ĭ�Ϸ�";
					ret = 'N';
					cin.sync();
					ret = cin.get();
					if (ret == 'Y' || ret == 'y') break;
				}
			}

			cout << "������༶��";  //////////////////////���ڻ�����Ҫ�涨�ģ���Ϊ01��01�պ� 1��1�նԱȲ�ͬ������ǰ���getNum���� 
			cin.sync();
			getline(cin, clase);
			for (int i = 0; i < stuList.size(); i++) {
				if (stuList.at(i).findclase(clase)) {
					stu.push_back(stuList.at(i));
				}
			}
			if (stu.size() == 0) {
				cout << "δ�ҵ���ͬ�༶��������ѡ��" << endl;
				break;
			}
			//ʵ������
			while (true) {
				cout << "�������������ݣ�1�������� 2���Ա� 3�����䣩: ";
				cin.sync();
				type = cin.get();
				if (type >= '1' && type < '4') break;
				else {
					cout << "��������ȷ�����" << endl;
					continue;
				}
			}
			cout << "�������������1����С���� 2���Ӵ�С��Ĭ�ϴ�С����: ";  //�ջ��ߴ�����1 
			cin.sync();
			rule = cin.get();
			bubbleStudent(stu, type, rule);
			show(stu);
			cout << "����" << stu.size() << "�����" << endl;

			cout << "�����Ƿ񱣴�����Ĭ�Ϸ�";
			save = 'N';
			cin.sync();
			save = cin.get();
			if (save == 'Y' || save == 'y') {  //�Ͳ��������������˰� 
				rewriteStudent("Stuclass", stu);
			}
			else cout << "ȡ������ͳ�ƽ��" << endl;
			break;
		case '0':
			return;
		default:
			cout << "�����������������" << endl;
			continue;

		}
	}

}


int main() {
	int stuNum = 0;
	vector<int> attIndex, stuIndex;
	//  int i;
	//	string id; 

	//1��ȡ�ļ���ʼ���б� 
	string strStu = "Student";
	string strAtt = "Attendance";
	vector<Student> stuList;
	vector<Attendance> attList;
	readStudentList(strStu, stuList);
	readAttendanceList(strAtt, attList);

	showStudent(stuList);
	showAttendance(attList);

	int n;
	cout << "**************ѧ����Ϣ����ϵͳ**************" << endl;
	cout << "*           1.¼��ѧ����Ϣ������Ϣ" << "       *" << endl;
	cout << "*           2.��ʾ��ǰϵͳ������ѧ���ļ�¼" << " *" << endl;
	cout << "*           3.��ʾ��ǰϵͳ�����е�ȱ�μ�¼" << " *" << endl;
	cout << "*           4.��ѯѧ����Ϣ" << "                 *" << endl;
	cout << "*           5.��ѯȱ�μ�¼" << "                 *" << endl;
	cout << "*           6.�޸�ѧ����Ϣ(tips:���ֶ�����)" << "*" << endl;
	cout << "*           7.�޸�ȱ����Ϣ(tips:���ֶ�����)" << "*" << endl;
	cout << "*           8.ɾ��ѧ����Ϣ(tips:���ֶ�����)" << "*" << endl;
	cout << "*           9.ɾ��������Ϣ(tips:���ֶ�����)" << "*" << endl;
	cout << "*           10.ͳ��ȱ����Ϣ" << "                *" << endl;
	cout << "*           11.ͳ��ѧ����Ϣ" << "                *" << endl;
	//�о������԰����Ա����䡢�༶ͳ��ѧ����Ϣ 
	cout << "*           0.�˳�����ϵͳ" << "                 *" << endl;
	cout << "********************************************" << endl;
	while (true) {
		cout << "��ѡ�����:";
		cin.sync();
		//		n = cin.get();
		cin >> n;
		//		cout << n << endl;
		switch (n) {
			//1��� 
		case 1:  //���û��д�˳�����if���Ҳ�У������е��ƻ��� 
			addList(stuList, attList, strStu, strAtt);  //���ɵ�һ��������
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
			attIndex.clear();  //�������Ԫ�� 
			attIndex = findCourse(attList, stuList);
			editAttendance(attList, attIndex, strAtt, stuList);
			break;
		case 8:  //
			stuIndex.clear();
			stuIndex = findStu(stuList);
			deleteStudent(stuList, attList, stuIndex, strStu, strAtt);
			break;
		case 9:
			attIndex.clear();  //�������Ԫ�� 
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
			cout << "�����������������" << endl;
			continue;
		}
	}
	return 0;
}