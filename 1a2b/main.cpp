#include<iostream>

using std::cout;
using std::endl;
using std::cin;



void ranNum(char* num)//产生四位数
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

int judge(char* g,char* num)//判断
{
	int result{};
	//if ((g / 10000 < 1) && (g / 1000 > 0))//判断四位数合法，考虑到第一位可能是0所以不能用int类型
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
	cout << "欢迎使用1A2B猜数字小游戏~" << endl << endl << "  .-. __ _ .-.\n" << "  |  `  / \\  |\n" << "  /     '.()--\\\n" << " |         '._/\n" << "_| O   _   O |_\n" << "=\\    '-'    /=\n" << "  '-._____.-'\n" << "  /`/\\___/\\`\\\n" << " /\\/o     o\\/\\\n" << "(_|         |_)\n" << "  |____,____|\n" << "  (____|____)\n" << endl << "输入0开始游戏，输入1查看规则，输入2退出。" << endl;
	cin >> start;
	while (start != 2)
	{
		if (start == 1)
		{
			cout << "游戏规则：系统选定一个四位数，各位数字不重复(0-9)。游戏开始后，由你来猜系统所选定的四位数(输入不重复的4个数字)，系统将以A和B来表示结果。A代表猜测的数字中，数字相同且位置也正确的个数。B代表猜测的数字中，数字相同但位置不一样的个数。\n举例来说，如果系统的数字为1234，你猜1245，则为2A3B。" << endl << "输入0开始游戏，输入2退出。" << endl;
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
			cout << "游戏开始，请输入一个不重复的四位数：" << endl;
			do
			{
				cin >> guess;
				result = judge(guess,num);
				if (result < 0)cout << "输入有误！" << endl;
				else
				{
					a = result / 10;
					b = result % 10;
					cout << "————————" << guess << " = " << a << "A" << b << "B" << endl;
				}
			} while (result != 40);
			cout << "恭喜你猜对啦！答案是：" << num << endl << "输入0再来一局，输入1查看规则，输入2退出。" << endl;
			cin >> start;
		}
		else
		{
			cout << "输入0开始游戏，输入1查看规则，输入2退出。" << endl;
			cin >> start;
		}
	}
	return 0;
}