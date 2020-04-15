#include<iostream>

using std::cout;
using std::endl;
using std::cin;



void ranNum(char* num)//������λ��
{
	int n[4]{-1,-1,-1,-1};
	char nu[5]{};
	char ch[2]{};
	for (int i{ 0 }; i < 4; i++)
	{
		int x{};
		do
		{
			x = (rand() % 10);
		} while (x == n[0] || x == n[1] || x == n[2] || x == n[3]);
		n[i] = x;
		_itoa_s(x, ch, 2, 10);
		num[i] = ch[0];
	}
}

int judge(char* g,char* num)//�ж�
{
	int result{};
	//if ((g / 10000 < 1) && (g / 1000 > 0))//�ж���λ���Ϸ������ǵ���һλ������0���Բ�����int����
	if (g[4] != '\0')return -1;
	for (int i{ 0 }; i < 4; i++)
	{
		if (g[i]<'0' || g[i]>'9')return -1;
	}
	for (int i{ 0 }; i < 4; i++)
	{
		for (int j{ 0 }; j < 4; j++)
		{
			if (g[i] == num[j])
			{
				if (i == j)result += 10;
				else result += 1;
			}
		}
	}
	return result;
}

int main()
{
	int start;
	cout << "��ӭʹ��1A2B������С��Ϸ~" << endl << endl << "  .-. __ _ .-.\n" << "  |  `  / \\  |\n" << "  /     '.()--\\\n" << " |         '._/\n" << "_| O   _   O |_\n" << "=\\    '-'    /=\n" << "  '-._____.-'\n" << "  /`/\\___/\\`\\\n" << " /\\/o     o\\/\\\n" << "(_|         |_)\n" << "  |____,____|\n" << "  (____|____)\n" << endl << "����0��ʼ��Ϸ������1�鿴��������2�˳���" << endl;
	cin >> start;
	while (start != 2)
	{
		if (start == 1)
		{
			cout << "��Ϸ����ϵͳѡ��һ����λ������λ���ֲ��ظ�(0-9)����Ϸ��ʼ����������ϵͳ��ѡ������λ��(���벻�ظ���4������)��ϵͳ����A��B����ʾ�����A����²�������У�������ͬ��λ��Ҳ��ȷ�ĸ�����B����²�������У�������ͬ��λ�ò�һ���ĸ�����\n������˵�����ϵͳ������Ϊ1234�����1245����Ϊ2A3B��" << endl << "����0��ʼ��Ϸ������2�˳���" << endl;
			cin >> start;
		}
		else if (start == 0)
		{
			char num[5]{};
			char guess[5]{};
			int result{};
			int a{};
			int b{};
			ranNum(num);
			cout << "��Ϸ��ʼ��������һ�����ظ�����λ����" << endl;
			do
			{
				cin >> guess;
				result = judge(guess,num);
				if (result < 0)cout << "��������" << endl;
				else
				{
					a = result / 10;
					b = result % 10;
					cout << "����������������" << guess << " = " << a << "A" << b << "B" << endl;
				}
			} while (result != 40);
			cout << "��ϲ��¶��������ǣ�" << num << endl << "����0����һ�֣�����1�鿴��������2�˳���" << endl;
			cin >> start;
		}
		else
		{
			cout << "����0��ʼ��Ϸ������1�鿴��������2�˳���" << endl;
			cin >> start;
		}
	}
	return 0;
}