#include<iostream>
using namespace std;
#include<string>
#include<Windows.h>
//通讯录管理系统
#define MAX 100


void menu() {
	cout << "   ************************************" << endl;
	cout << "   *********  通讯录管理系统  *********" << endl;
	cout << "   *********                  *********" << endl;
	cout << "   *********  1. 添加联系人   *********" << endl;
	cout << "   *********  2. 显示联系人   *********" << endl;
	cout << "   *********  3. 删除联系人   *********" << endl;
	cout << "   *********  4. 查找联系人   *********" << endl;
	cout << "   *********  5. 修改联系人   *********" << endl;
	cout << "   *********  6. 清空通讯录   *********" << endl;
	cout << "   *********  0. 退出通讯录   *********" << endl;
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
		cout << "通讯录已满，不能添加联系人！" << endl;
	}
	else {
		string name;
		cout << "请输入需要添加的联系人姓名：" << endl;
		cin >> name;
		adp->Paddressbooks[adp->Pnum].Pname = name;
		int sex;
	S:
		cout << "请输入需要添加的联系人性别(1-男，2-女)：" << endl;
		cin >> sex;
		if (sex == 1 || sex == 2) {
			adp->Paddressbooks[adp->Pnum].Psex = sex;
		}
		else {
			cout << "输入错误！" << endl;
			goto S;
		}
		string phone;
	P:
		cout << "请输入需要添加的联系人电话：" << endl;
		cin >> phone;
		if (size(phone) == 8 || size(phone) == 11) {
			adp->Paddressbooks[adp->Pnum].Pphone = phone;
		}
		else {
			cout << "输入错误，电话为8位或11位！" << endl;
			goto P;
		}
		string address;
		cout << "请输入需要添加的联系人地址：" << endl;
		cin >> address;
		adp->Paddressbooks[adp->Pnum].Paddress = address;
		adp->Pnum++;
		cout << "添加联系人成功！" << endl;
	}
}

void showPerson(addressbooks* adp) {
	if (adp->Pnum == 0) {
		cout << "该通讯录为空，还没有联系人！" << endl;
	}
	else{
		for (int i = 0; i < adp->Pnum; i++) {
			cout << "姓名：" << adp->Paddressbooks[i].Pname << "\t";
			cout << "性别：" << (adp->Paddressbooks[i].Psex==1 ? "男":"女") << "\t";
			cout << "电话：" << adp->Paddressbooks[i].Pphone << "\t";
			cout << "地址：" << adp->Paddressbooks[i].Paddress << endl;
		}
	}
}

int exist(addressbooks* adp,string name) {
	for (int i = 0; i < adp->Pnum; i++) {
		if (adp->Paddressbooks[i].Pname == name) {
			return i;
		}
		else {
			cout << "查无此人！" << endl;
			return -1;
		}
	}
}

void deletePerson(addressbooks* adp) {
	string name;
	cout << "请输入需要删除的联系人姓名：" << endl;
	cin >> name;
	int ret = exist(adp, name);
	if(ret!=-1){
		for (int i = ret; i < adp->Pnum; i++) {
			adp->Paddressbooks[i] = adp->Paddressbooks[i + 1];
			adp->Pnum--;
		}
		cout << "删除成功！" << endl;
	}
}

void findPerson(addressbooks* adp) {
	string name;
	cout<<"输入要查找联系人姓名"<<endl;
	cin>>name;
	int ret = exist(adp,name);
	if(ret!=-1)
	{
		cout<<"姓名："<<adp->Paddressbooks[ret].Pname<<"\t";
		cout<<"性别："<< (adp->Paddressbooks[ret].Psex == 1 ? "男" : "女") <<"\t";
		cout<<"电话："<<adp->Paddressbooks[ret].Pphone<<"\t";
		cout<<"地址："<<adp->Paddressbooks[ret].Paddress<<endl;
	}
}

void modifyPerson(addressbooks* adp) {
	string name;
	cout << "请输入需要修改的联系人姓名：" <<endl;
	cin >> name;
	int ret = exist(adp, name);
	if (ret != -1) {
		int num = 0;
		while (1) {
			cout << "需要修改该联系人姓名请输入1；" << endl;
			cout << "需要修改该联系人性别请输入2；" << endl;
			cout << "需要修改该联系人电话请输入3；" << endl;
			cout << "需要修改该联系人地址请输入4；" << endl;
			cout << "修改完成，输入5 退出修改！" << endl;
			cin >> num;
			if (num == 1) {
				string name;
				cout << "请输入修改的姓名：" << endl;
				cin >> name;
				adp->Paddressbooks[ret].Pname = name;
			}
			if (num == 2) {
				int sex;
			S:
				cout << "请输入修改的性别(1-男，2-女)：" << endl;
				cin >> sex;
				if (sex == 1 || sex == 2) {
					adp->Paddressbooks[ret].Psex = sex;
				}
				else {
					cout << "输入错误！" << endl;
					goto S;
				}
			}
			if (num == 3) {
				string phone;
			P:
				cout << "请输入修改的电话：" << endl;
				cin >> phone;
				if (size(phone) == 8 || size(phone) == 11) {
					adp->Paddressbooks[ret].Pphone = phone;
				}
				else {
					cout << "输入错误，电话为8位或11位！" << endl;
					goto P;
				}
			}
			if (num == 4) {
				string address;
				cout << "请输入修改的地址：" << endl;
				cin >> address;
				adp->Paddressbooks[ret].Paddress = address;
			}
			if (num == 5) {
				break;
			}
		}
		cout << "已成功修改！" << endl;
	}
}
void cleanPerson(addressbooks* adp) {
	if (adp->Pnum == 0) {
		cout << "该通讯录本就为空！" << endl;
	}
	else {
		adp->Pnum = 0;
		cout << "已成功清空通讯录！" << endl;
	}
	system("pause");
}


int main() {
	struct addressbooks adp;
	adp.Pnum = 0;
	while (1) {
		system("cls");
		//通讯录菜单
		menu();
		int select = 0;
		cout << "请输入你选择的功能序号：" << endl;
		cin >> select;
		switch (select) {
			case 1://添加联系人
				addPerson(&adp);
				break;
			case 2://显示联系人
				showPerson(&adp);
				break;
			case 3://删除联系人
				deletePerson(&adp);
				break;
			case 4://查找联系人
				findPerson(&adp);
				break;
			case 5://修改联系人
				modifyPerson(&adp);
				break;
			case 6://清空联系人
				cleanPerson(&adp);
				break;
			case 0://退出通讯录
				cout << "您已退出通讯录，欢迎下次使用！" << endl;
				system("pause");
				return 0;
				break;
			default:
				system("cls");
				cout << "请输入正确的功能序号：" << endl;
				break;
		}
		Sleep(1000);
	}
	system("pause");//请按任意键继续，相当于暂停作用
	return 0;
}