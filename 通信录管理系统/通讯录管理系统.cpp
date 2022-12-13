#include <iostream>
#include<array>
//#include<cctype>
#include <string>
using namespace std;
#define MAX 1000

struct Linkman { //��ϵ��
	string m_name;
	string m_sex;
	string m_phone;
	string m_addr;
};
struct Book {
	struct Linkman b_personAddr[MAX];
	int b_size;
	int b_in;
	string b_transform; //ת�� Ϊ b_in
};

struct Menu {
	int number;
	string Tab;
	string Hz; //����
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
		cout << "\n ��ϵ������ " << endl;
		return 0;
	}
	else
	{
		cout << "���֣�";
		cin >> temp;
		Phone_book->b_personAddr[Phone_book->b_size].m_name = temp;

		cout << "�绰��";
		cin >> temp;
		Phone_book->b_personAddr[Phone_book->b_size].m_phone = temp;

		cout << "�Ա�";
		cin >> temp;
		Phone_book->b_personAddr[Phone_book->b_size].m_sex = temp;

		cout << "סַ��";
		cin >> temp;
		Phone_book->b_personAddr[Phone_book->b_size].m_addr = temp;

		Phone_book->b_size++;

		system("pause");
		system("cls"); //����

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
		cout << "\n�� " << i+1 << " ����ϵ��: ";
		cout << " name  == " << Phone_book->b_personAddr[i].m_name << endl;
		cout << "\t\tphone == " << Phone_book->b_personAddr[i].m_phone << endl;
		cout << "\t\tsex   == " << Phone_book->b_personAddr[i].m_sex << endl;
		cout << "\t\taddr  == " << Phone_book->b_personAddr[i].m_addr << endl;
	}
	system("pause");
	system("cls"); //����
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
	cout << "��������Ҫ�޸��˵����֣�";
	cin >> amend_name;
	i = find_person(Phone_book, &amend_name);
	if (-1 != i)
	{
		cout << " �鵽�����ָ�Ϊ(��:���޸�)�� ";
		cin >> amend_name;
		if (amend_name != "��")
		{
			Phone_book->b_personAddr[i].m_name = amend_name;
		}

		cout << " �绰��Ϊ��";
		cin >> amend_name;
		if (amend_name != "��")
		{
			Phone_book->b_personAddr[i].m_phone = amend_name;
		}

		cout << " סַ��Ϊ��";
		cin >> amend_name;
		if (amend_name != "��")
		{
			Phone_book->b_personAddr[i].m_addr = amend_name;
		}

		cout << " �Ա��Ϊ��";
		cin >> amend_name;
		if (amend_name != "��")
		{
			Phone_book->b_personAddr[i].m_sex = amend_name;
		}
		cout << "�޸ĳɹ���" << endl;
		cout << "\t���֣�" << Phone_book->b_personAddr[i].m_name  << endl;
		cout << "\t�Ա�" << Phone_book->b_personAddr[i].m_sex   << endl;
		cout << "\t�绰��" << Phone_book->b_personAddr[i].m_phone << endl;
		cout << "\tסַ��" << Phone_book->b_personAddr[i].m_addr  << endl;
	}
	else
	{
		cout << " ���޴��� " << endl;
	}
	system("pause");
	system("cls"); //����
}
void del_person(Book *Phone_book)
{
	int i = 0;
	string amend_name;
	cout << "��������ɾ���˵����֣�";
	cin >> amend_name;
	i = find_person(Phone_book, &amend_name);
	if (-1 != i)
	{
		cout << "�鵽������ɾ����" << endl;
		for (int del = i; del < Phone_book->b_size; del++)
		{
			Phone_book->b_personAddr[i] = Phone_book->b_personAddr[i + 1];
		}
		cout << "ɾ����ϣ�" << endl;
		Phone_book->b_size--;
	}
	else
	{
		cout << "δ�鵽���ˣ�" << endl;
	}
	system("pause");
	system("cls"); //����

}
void creal_person(Book *Phone_book)
{
	Phone_book->b_size = 0;
	memset(&Phone_book->b_personAddr, 0, sizeof(Phone_book->b_personAddr));
	cout << "\n ����� \n" << endl;
	system("pause");
	system("cls"); //����
}

int dispose(Book *Phone_book)
{
	string person;
	int temp = 0;
	switch (Phone_book->b_in)
	{
	case 1:
		cout << "����޸���ϵ�ˣ�" << endl;
		add_phone(Phone_book);
		break;
	case 2:
		cout << "��ʾ��ϵ�ˣ�" << endl;
		show_person(Phone_book);
		break;
	case 3:
		cout << "������ϵ�ˣ�" << endl;
		cout << "\n��������������֣�";
		cin >> person;
		temp = find_person(Phone_book, &person);
		if (temp == -1)
		{
			cout << " ���޴��ˣ�" << endl;
			system("pause");
			system("cls"); //����
		}
		else
		{
			cout << "\n�鵽��λ�ڵ� " << temp + 1 << " λ ";
			cout << " name == " << Phone_book->b_personAddr[temp].m_name << endl;
			cout << "\t\t   phone == " << Phone_book->b_personAddr[temp].m_phone << endl;
			cout << "\t\t   sex   == " << Phone_book->b_personAddr[temp].m_sex << endl;
			cout << "\t\t   addr  == " << Phone_book->b_personAddr[temp].m_addr << endl;

			system("pause");
			system("cls"); //����
		}
		break;
	case 4:
		cout << "�޸���ϵ�ˣ�" << endl;
		amend_person(Phone_book);
		break;
	case 5:
		cout << "ɾ����ϵ�ˣ�" << endl;
		del_person(Phone_book);
		break;
	case 6:
		cout << "�����ϵ�ˣ�" << endl;
		creal_person(Phone_book);
		break;
	case 0:
		cout << "��ӭ�´�ʹ�ã�" << endl;
		//system("pause");
		return 0;
	default:
		cout << "�����������������룡" << endl;
		system("pause");
		system("cls"); //����
		break;
	}
}

int main(void)
{
	Book Phone_book;
	Phone_book.b_size = 0;
	Phone_book.b_in = 0;

	Menu Tab_Menu[7] = {
	{1, "�����ϵ��", "���"},
	{2, "��ʾ��ϵ��", "��ʾ"},
	{3, "������ϵ��", "����"},
	{4, "�޸���ϵ��", "�޸�"},
	{5, "ɾ����ϵ��", "ɾ��"},
	{6, "�����ϵ��", "���"},
	{0, "�˳�ͨѶ¼", "�˳�"}
	};
	int len = sizeof(Tab_Menu) / sizeof(Tab_Menu[0]);  //7
	show_menu(Tab_Menu, len);
	cout << "������ָ��(���/��ʾ/����/�޸�/���/ɾ��/�˳�)��";

	while (cin >> Phone_book.b_transform)
	{
		if (Phone_book.b_transform      == "���")
		{
			Phone_book.b_in = 1;
			dispose(&Phone_book);
		}
		else if (Phone_book.b_transform == "��ʾ")
		{
			Phone_book.b_in = 2;
			dispose(&Phone_book);
		}
		else if (Phone_book.b_transform == "����")
		{
			Phone_book.b_in = 3;
			dispose(&Phone_book);
		}
		else if (Phone_book.b_transform == "�޸�")
		{
			Phone_book.b_in = 4;
			dispose(&Phone_book);
		}
		else if (Phone_book.b_transform == "ɾ��")
		{
			Phone_book.b_in = 5;
			dispose(&Phone_book);
		}
		else if (Phone_book.b_transform == "���")
		{
			Phone_book.b_in = 6;
			dispose(&Phone_book);
		}
		else if (Phone_book.b_transform == "�˳�")
		{
			//Phone_book.b_in = 0;
			return 0;
		}
		else
		{
			cout << "������������������" << endl;

			system("pause");
			system("cls"); //����
		}
		//if ((dispose(&Phone_book)) == 0)//������
		//{
		//	return 0;
		//}; 
		show_menu(Tab_Menu, len);
		cout << "������ָ��(���/��ʾ/����/�޸�/���/ɾ��/�˳�)��";
	}
	return 0;
}

