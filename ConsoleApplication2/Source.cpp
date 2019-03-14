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
		cout << "Задача № ";
		cin >> tn; cin.get();

		switch (tn)
		{
		case 1:
			//Дан текстовый файл.Необходимо создать новый файл и записать в него следующую статистику по исходному файлу :
			// 1 количество символов
			// 2 количество строк
			// 3 количество гласных букв
			// 4 количество согласных букв
			// 5 количество цифр.
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
			
			i2_file << "количество символов: " << k1 << endl;
			i2_file << "количество строк: " << k2 << endl;
			i2_file << "количество гласных букв: " << k3 << endl;
			i2_file << "количество согласных букв: " << k4 << endl;
			i2_file << "количество цифр: " << k5 << endl;
		}
		break;
		case 2:
			//Шифр Цезаря — один из древнейших шифров. При шифровании каждый символ заменяется другим, отстоящим от него в алфавите на фиксированное число позиций.
			//Пример:
			//Шифрование с использованием ключа : 3
			//Оригинальный текст : Съешь же ещё этих мягких французских булок, да выпей чаю.
			//Шифрованный текст : Фэзыя йз зьи ахлш пвёнлш чугрщцкфнлш дцосн, жг еютзм ъгб.
			//Дан текстовый файл.Зашифровать его, используя шифр Цезаря.Результат записать в другой файл.
		{
			ifstream i3_file("3.txt");
			ofstream i4_file("4.txt");
			//чтобы зациклить алфавит придется не через таблицу ASCII кодов, а через свой массив символов
			char alphabet[34] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
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
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}