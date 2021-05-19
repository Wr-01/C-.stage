#include<iostream>
using namespace std;
#include<string>
#include<Windows.h>
//ͨѶ¼����ϵͳ
#define MAX 100


void menu() {
	cout << "   ************************************" << endl;
	cout << "   *********  ͨѶ¼����ϵͳ  *********" << endl;
	cout << "   *********                  *********" << endl;
	cout << "   *********  1. �����ϵ��   *********" << endl;
	cout << "   *********  2. ��ʾ��ϵ��   *********" << endl;
	cout << "   *********  3. ɾ����ϵ��   *********" << endl;
	cout << "   *********  4. ������ϵ��   *********" << endl;
	cout << "   *********  5. �޸���ϵ��   *********" << endl;
	cout << "   *********  6. ���ͨѶ¼   *********" << endl;
	cout << "   *********  0. �˳�ͨѶ¼   *********" << endl;
	cout << "   ************************************" << endl;
}

struct person {
	string Pname;
	int Psex;
	string Pphone;
	string Paddress;
};
struct addressbooks {
	struct person Paddressbooks[MAX];
	int Pnum;
};

void addPerson(addressbooks *adp) {
	if (adp->Pnum > MAX) {
		cout << "ͨѶ¼���������������ϵ�ˣ�" << endl;
	}
	else {
		string name;
		cout << "��������Ҫ��ӵ���ϵ��������" << endl;
		cin >> name;
		adp->Paddressbooks[adp->Pnum].Pname = name;
		int sex;
	S:
		cout << "��������Ҫ��ӵ���ϵ���Ա�(1-�У�2-Ů)��" << endl;
		cin >> sex;
		if (sex == 1 || sex == 2) {
			adp->Paddressbooks[adp->Pnum].Psex = sex;
		}
		else {
			cout << "�������" << endl;
			goto S;
		}
		string phone;
	P:
		cout << "��������Ҫ��ӵ���ϵ�˵绰��" << endl;
		cin >> phone;
		if (size(phone) == 8 || size(phone) == 11) {
			adp->Paddressbooks[adp->Pnum].Pphone = phone;
		}
		else {
			cout << "������󣬵绰Ϊ8λ��11λ��" << endl;
			goto P;
		}
		string address;
		cout << "��������Ҫ��ӵ���ϵ�˵�ַ��" << endl;
		cin >> address;
		adp->Paddressbooks[adp->Pnum].Paddress = address;
		adp->Pnum++;
		cout << "�����ϵ�˳ɹ���" << endl;
	}
}

void showPerson(addressbooks* adp) {
	if (adp->Pnum == 0) {
		cout << "��ͨѶ¼Ϊ�գ���û����ϵ�ˣ�" << endl;
	}
	else{
		for (int i = 0; i < adp->Pnum; i++) {
			cout << "������" << adp->Paddressbooks[i].Pname << "\t";
			cout << "�Ա�" << (adp->Paddressbooks[i].Psex==1 ? "��":"Ů") << "\t";
			cout << "�绰��" << adp->Paddressbooks[i].Pphone << "\t";
			cout << "��ַ��" << adp->Paddressbooks[i].Paddress << endl;
		}
	}
}

int exist(addressbooks* adp,string name) {
	for (int i = 0; i < adp->Pnum; i++) {
		if (adp->Paddressbooks[i].Pname == name) {
			return i;
		}
		else {
			cout << "���޴��ˣ�" << endl;
			return -1;
		}
	}
}

void deletePerson(addressbooks* adp) {
	string name;
	cout << "��������Ҫɾ������ϵ��������" << endl;
	cin >> name;
	int ret = exist(adp, name);
	if(ret!=-1){
		for (int i = ret; i < adp->Pnum; i++) {
			adp->Paddressbooks[i] = adp->Paddressbooks[i + 1];
			adp->Pnum--;
		}
		cout << "ɾ���ɹ���" << endl;
	}
}

void findPerson(addressbooks* adp) {
	string name;
	cout<<"����Ҫ������ϵ������"<<endl;
	cin>>name;
	int ret = exist(adp,name);
	if(ret!=-1)
	{
		cout<<"������"<<adp->Paddressbooks[ret].Pname<<"\t";
		cout<<"�Ա�"<< (adp->Paddressbooks[ret].Psex == 1 ? "��" : "Ů") <<"\t";
		cout<<"�绰��"<<adp->Paddressbooks[ret].Pphone<<"\t";
		cout<<"��ַ��"<<adp->Paddressbooks[ret].Paddress<<endl;
	}
}

void modifyPerson(addressbooks* adp) {
	string name;
	cout << "��������Ҫ�޸ĵ���ϵ��������" <<endl;
	cin >> name;
	int ret = exist(adp, name);
	if (ret != -1) {
		int num = 0;
		while (1) {
			cout << "��Ҫ�޸ĸ���ϵ������������1��" << endl;
			cout << "��Ҫ�޸ĸ���ϵ���Ա�������2��" << endl;
			cout << "��Ҫ�޸ĸ���ϵ�˵绰������3��" << endl;
			cout << "��Ҫ�޸ĸ���ϵ�˵�ַ������4��" << endl;
			cout << "�޸���ɣ�����5 �˳��޸ģ�" << endl;
			cin >> num;
			if (num == 1) {
				string name;
				cout << "�������޸ĵ�������" << endl;
				cin >> name;
				adp->Paddressbooks[ret].Pname = name;
			}
			if (num == 2) {
				int sex;
			S:
				cout << "�������޸ĵ��Ա�(1-�У�2-Ů)��" << endl;
				cin >> sex;
				if (sex == 1 || sex == 2) {
					adp->Paddressbooks[ret].Psex = sex;
				}
				else {
					cout << "�������" << endl;
					goto S;
				}
			}
			if (num == 3) {
				string phone;
			P:
				cout << "�������޸ĵĵ绰��" << endl;
				cin >> phone;
				if (size(phone) == 8 || size(phone) == 11) {
					adp->Paddressbooks[ret].Pphone = phone;
				}
				else {
					cout << "������󣬵绰Ϊ8λ��11λ��" << endl;
					goto P;
				}
			}
			if (num == 4) {
				string address;
				cout << "�������޸ĵĵ�ַ��" << endl;
				cin >> address;
				adp->Paddressbooks[ret].Paddress = address;
			}
			if (num == 5) {
				break;
			}
		}
		cout << "�ѳɹ��޸ģ�" << endl;
	}
}
void cleanPerson(addressbooks* adp) {
	if (adp->Pnum == 0) {
		cout << "��ͨѶ¼����Ϊ�գ�" << endl;
	}
	else {
		adp->Pnum = 0;
		cout << "�ѳɹ����ͨѶ¼��" << endl;
	}
	system("pause");
}


int main() {
	struct addressbooks adp;
	adp.Pnum = 0;
	while (1) {
		system("cls");
		//ͨѶ¼�˵�
		menu();
		int select = 0;
		cout << "��������ѡ��Ĺ�����ţ�" << endl;
		cin >> select;
		switch (select) {
			case 1://�����ϵ��
				addPerson(&adp);
				break;
			case 2://��ʾ��ϵ��
				showPerson(&adp);
				break;
			case 3://ɾ����ϵ��
				deletePerson(&adp);
				break;
			case 4://������ϵ��
				findPerson(&adp);
				break;
			case 5://�޸���ϵ��
				modifyPerson(&adp);
				break;
			case 6://�����ϵ��
				cleanPerson(&adp);
				break;
			case 0://�˳�ͨѶ¼
				cout << "�����˳�ͨѶ¼����ӭ�´�ʹ�ã�" << endl;
				system("pause");
				return 0;
				break;
			default:
				system("cls");
				cout << "��������ȷ�Ĺ�����ţ�" << endl;
				break;
		}
		Sleep(1000);
	}
	system("pause");//�밴������������൱����ͣ����
	return 0;
}