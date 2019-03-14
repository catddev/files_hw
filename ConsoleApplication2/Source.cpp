#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<cstring>
#include<fstream>

using namespace std;

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "������ � ";
		cin >> tn; cin.get();

		switch (tn)
		{
		case 1:
			//��� ��������� ����.���������� ������� ����� ���� � �������� � ���� ��������� ���������� �� ��������� ����� :
			// 1 ���������� ��������
			// 2 ���������� �����
			// 3 ���������� ������� ����
			// 4 ���������� ��������� ����
			// 5 ���������� ����.
		{
			ifstream i1_file("1.txt");
			ofstream i2_file("2.txt");

			char buf[50];
			char sym;
			char vowels[13]= "AEIOUYaeiouy";
			int k1=0, k2=0, k3=0, k4=0, k5=0;
			int check = 0;
			
			while (i1_file.get(sym))
			{
				k1++;
				if (sym >= 48 && sym <= 57) k5++;
				else
				{
					check = 0;
					for (int i = 0; i < 13; i++)
					{
						if (sym == vowels[i])
						{
							k3++;
							check++;
							break;
						}
					}
					if (check == 0 && sym >= 65 && sym <= 122)
						k4++;
				}
			}
			i1_file.close();
			i1_file.open("1.txt");

			while (i1_file.getline(buf, 50))
				k2++;
			
			i2_file << "���������� ��������: " << k1 << endl;
			i2_file << "���������� �����: " << k2 << endl;
			i2_file << "���������� ������� ����: " << k3 << endl;
			i2_file << "���������� ��������� ����: " << k4 << endl;
			i2_file << "���������� ����: " << k5 << endl;
		}
		break;
		case 2:
			//���� ������ � ���� �� ���������� ������. ��� ���������� ������ ������ ���������� ������, ��������� �� ���� � �������� �� ������������� ����� �������.
			//������:
			//���������� � �������������� ����� : 3
			//������������ ����� : ����� �� ��� ���� ������ ����������� �����, �� ����� ���.
			//����������� ����� : ����� �� ��� ���� ����� ����������� �����, �� ����� ���.
			//��� ��������� ����.����������� ���, ��������� ���� ������.��������� �������� � ������ ����.
		{
			ifstream i3_file("3.txt");
			ofstream i4_file("4.txt");
			//����� ��������� ������� �������� �� ����� ������� ASCII �����, � ����� ���� ������ ��������
			char alphabet[34] = "��������������������������������";
			char sym;
			int key;
			cout << "Enter the key" << endl;
			cin >> key;

			while (i3_file.get(sym))
			{
				for (int i = 0; i <= 33; i++)
				{
					if (sym == alphabet[i])
					{
						if (i + key <= 32)
						{
							sym = alphabet[i + key];
							i4_file << sym;
							break;
						}
						else
						{
							sym = alphabet[i + key - 33];
							i4_file << sym;
							break;
						}
					}
					else if(i==33)
					{
						i4_file << sym;
						break;
					}
				}
			}
		}
		break;
		default:
			cout << "��� ����� ������" << endl << endl;
		}
	}
	system("pause");
	return 0;
}