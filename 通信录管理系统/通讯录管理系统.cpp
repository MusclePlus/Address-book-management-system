#include <iostream>
#include<array>
//#include<cctype>
#include <string>
using namespace std;
#define MAX 1000

struct Linkman { //联系人
	string m_name;
	string m_sex;
	string m_phone;
	string m_addr;
};
struct Book {
	struct Linkman b_personAddr[MAX];
	int b_size;
	int b_in;
	string b_transform; //转换 为 b_in
};

struct Menu {
	int number;
	string Tab;
	string Hz; //汉字
};

void show_menu(Menu Tab_Menu[], int len)
{
	cout << "****************************" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << "*****  " << Tab_Menu[i].number << " : " << Tab_Menu[i].Tab <<"  *****"<< endl;
	}
	cout << "****************************" << endl;
}
int add_phone(Book *Phone_book)
{
	string temp;
	if (Phone_book->b_size == MAX)
	{
		cout << "\n 联系人已满 " << endl;
		return 0;
	}
	else
	{
		cout << "名字：";
		cin >> temp;
		Phone_book->b_personAddr[Phone_book->b_size].m_name = temp;

		cout << "电话：";
		cin >> temp;
		Phone_book->b_personAddr[Phone_book->b_size].m_phone = temp;

		cout << "性别：";
		cin >> temp;
		Phone_book->b_personAddr[Phone_book->b_size].m_sex = temp;

		cout << "住址：";
		cin >> temp;
		Phone_book->b_personAddr[Phone_book->b_size].m_addr = temp;

		Phone_book->b_size++;

		system("pause");
		system("cls"); //清屏

		//cout << "name == " << Phone_book->b_personAddr[Phone_book->b_size].m_name << endl;
		//cout << "phone == " << Phone_book->b_personAddr[Phone_book->b_size].m_phone << endl;
		//cout << "sex == " << Phone_book->b_personAddr[Phone_book->b_size].m_sex << endl;
		//cout << "addr == " << Phone_book->b_personAddr[Phone_book->b_size].m_addr << endl;

		//cout << " temp == " << temp << endl;
	}
}

void show_person(Book *Phone_book)
{
	
	for (int i = 0; i < Phone_book->b_size; i++)
	{
		cout << "\n第 " << i+1 << " 个联系人: ";
		cout << " name  == " << Phone_book->b_personAddr[i].m_name << endl;
		cout << "\t\tphone == " << Phone_book->b_personAddr[i].m_phone << endl;
		cout << "\t\tsex   == " << Phone_book->b_personAddr[i].m_sex << endl;
		cout << "\t\taddr  == " << Phone_book->b_personAddr[i].m_addr << endl;
	}
	system("pause");
	system("cls"); //清屏
}

int find_person(Book *Phone_book, string *name)
{
	for (int i = 0; i < Phone_book->b_size; i++)
	{
		if (Phone_book->b_personAddr[i].m_name == *name)
		{
			return i;
		}
	}
	return -1;
}
void amend_person(Book *Phone_book)
{
	int i = 0;
	string amend_name;
	cout << "请输入需要修改人的名字：";
	cin >> amend_name;
	i = find_person(Phone_book, &amend_name);
	if (-1 != i)
	{
		cout << " 查到，名字改为(否:不修改)： ";
		cin >> amend_name;
		if (amend_name != "否")
		{
			Phone_book->b_personAddr[i].m_name = amend_name;
		}

		cout << " 电话改为：";
		cin >> amend_name;
		if (amend_name != "否")
		{
			Phone_book->b_personAddr[i].m_phone = amend_name;
		}

		cout << " 住址改为：";
		cin >> amend_name;
		if (amend_name != "否")
		{
			Phone_book->b_personAddr[i].m_addr = amend_name;
		}

		cout << " 性别改为：";
		cin >> amend_name;
		if (amend_name != "否")
		{
			Phone_book->b_personAddr[i].m_sex = amend_name;
		}
		cout << "修改成功！" << endl;
		cout << "\t名字：" << Phone_book->b_personAddr[i].m_name  << endl;
		cout << "\t性别：" << Phone_book->b_personAddr[i].m_sex   << endl;
		cout << "\t电话：" << Phone_book->b_personAddr[i].m_phone << endl;
		cout << "\t住址：" << Phone_book->b_personAddr[i].m_addr  << endl;
	}
	else
	{
		cout << " 查无此人 " << endl;
	}
	system("pause");
	system("cls"); //清屏
}
void del_person(Book *Phone_book)
{
	int i = 0;
	string amend_name;
	cout << "请输入需删除人的名字：";
	cin >> amend_name;
	i = find_person(Phone_book, &amend_name);
	if (-1 != i)
	{
		cout << "查到，正在删除！" << endl;
		for (int del = i; del < Phone_book->b_size; del++)
		{
			Phone_book->b_personAddr[i] = Phone_book->b_personAddr[i + 1];
		}
		cout << "删除完毕！" << endl;
		Phone_book->b_size--;
	}
	else
	{
		cout << "未查到此人！" << endl;
	}
	system("pause");
	system("cls"); //清屏

}
void creal_person(Book *Phone_book)
{
	Phone_book->b_size = 0;
	memset(&Phone_book->b_personAddr, 0, sizeof(Phone_book->b_personAddr));
	cout << "\n 已清空 \n" << endl;
	system("pause");
	system("cls"); //清屏
}

int dispose(Book *Phone_book)
{
	string person;
	int temp = 0;
	switch (Phone_book->b_in)
	{
	case 1:
		cout << "添加修改联系人！" << endl;
		add_phone(Phone_book);
		break;
	case 2:
		cout << "显示联系人！" << endl;
		show_person(Phone_book);
		break;
	case 3:
		cout << "查找联系人！" << endl;
		cout << "\n请输入查找人名字：";
		cin >> person;
		temp = find_person(Phone_book, &person);
		if (temp == -1)
		{
			cout << " 查无此人！" << endl;
			system("pause");
			system("cls"); //清屏
		}
		else
		{
			cout << "\n查到！位于第 " << temp + 1 << " 位 ";
			cout << " name == " << Phone_book->b_personAddr[temp].m_name << endl;
			cout << "\t\t   phone == " << Phone_book->b_personAddr[temp].m_phone << endl;
			cout << "\t\t   sex   == " << Phone_book->b_personAddr[temp].m_sex << endl;
			cout << "\t\t   addr  == " << Phone_book->b_personAddr[temp].m_addr << endl;

			system("pause");
			system("cls"); //清屏
		}
		break;
	case 4:
		cout << "修改联系人！" << endl;
		amend_person(Phone_book);
		break;
	case 5:
		cout << "删除联系人！" << endl;
		del_person(Phone_book);
		break;
	case 6:
		cout << "清空联系人！" << endl;
		creal_person(Phone_book);
		break;
	case 0:
		cout << "欢迎下次使用！" << endl;
		//system("pause");
		return 0;
	default:
		cout << "输入有误，请重新输入！" << endl;
		system("pause");
		system("cls"); //清屏
		break;
	}
}

int main(void)
{
	Book Phone_book;
	Phone_book.b_size = 0;
	Phone_book.b_in = 0;

	Menu Tab_Menu[7] = {
	{1, "添加联系人", "添加"},
	{2, "显示联系人", "显示"},
	{3, "查找联系人", "查找"},
	{4, "修改联系人", "修改"},
	{5, "删除联系人", "删除"},
	{6, "清空联系人", "清空"},
	{0, "退出通讯录", "退出"}
	};
	int len = sizeof(Tab_Menu) / sizeof(Tab_Menu[0]);  //7
	show_menu(Tab_Menu, len);
	cout << "请输入指令(添加/显示/查找/修改/清空/删除/退出)：";

	while (cin >> Phone_book.b_transform)
	{
		if (Phone_book.b_transform      == "添加")
		{
			Phone_book.b_in = 1;
			dispose(&Phone_book);
		}
		else if (Phone_book.b_transform == "显示")
		{
			Phone_book.b_in = 2;
			dispose(&Phone_book);
		}
		else if (Phone_book.b_transform == "查找")
		{
			Phone_book.b_in = 3;
			dispose(&Phone_book);
		}
		else if (Phone_book.b_transform == "修改")
		{
			Phone_book.b_in = 4;
			dispose(&Phone_book);
		}
		else if (Phone_book.b_transform == "删除")
		{
			Phone_book.b_in = 5;
			dispose(&Phone_book);
		}
		else if (Phone_book.b_transform == "清空")
		{
			Phone_book.b_in = 6;
			dispose(&Phone_book);
		}
		else if (Phone_book.b_transform == "退出")
		{
			//Phone_book.b_in = 0;
			return 0;
		}
		else
		{
			cout << "输入有误！请重新输入" << endl;

			system("pause");
			system("cls"); //清屏
		}
		//if ((dispose(&Phone_book)) == 0)//处理函数
		//{
		//	return 0;
		//}; 
		show_menu(Tab_Menu, len);
		cout << "请输入指令(添加/显示/查找/修改/清空/删除/退出)：";
	}
	return 0;
}

