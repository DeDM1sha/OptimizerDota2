#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <string>
#include <time.h>
void ConfigureConsoleWindow ()
{
    void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle,&structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo( handle, &structCursorInfo ); // Отключение каретки.
	setlocale (LC_CTYPE, "Russian"); // Русская кодировка текста.
	system ("color B"); // Светло-голубой цвет текста.
	system("mode con cols=126 lines=31"); // Отключение боковой меню с прокруткой.
	system ("title Dota 2 Optimizer"); // Заголовок программы.
} // Функция для настройки консольного окна.
void Center (std::string Stroke)
{
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo((GetStdHandle( STD_OUTPUT_HANDLE )), &consoleInfo);
		for (unsigned short int i = 0; i < ((consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1) / 2 - strlen(Stroke.c_str()) / 2); i++)
			std::cout << " ";
    std::cout << Stroke;
} // Функция для размещения введенного нами текста по центру экрана.
void TextInColor (std::string ColorName, std::string Text)
{
		if (ColorName == "Green")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));
		if (ColorName == "Red")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 12));
		if (ColorName == "Yellow")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 14));
	Center (Text);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 11));
} // Функция изменения цвета текста..
void padding (unsigned short int Count)
{
	for (unsigned short int i = 0; i < Count; i++)
		std::cout << "\n";
} // Функция для отступов.
void AnimationOfModuleOperation (std::string Text)
{
	unsigned short int C = 0;
	padding(1);
	Center (Text);
		for (unsigned short int i = 0; i < 4; i++) {
			clock_t end_time = clock() + 1000;
			while (clock() < end_time) {}
				if (C < 3) {
					std::cout << " . ";
					C++;
				}
		}
	std::cout << "\n";
} // Функция для анимации старта/завершения работы модуля.
void ActivationLinks (std::string LinkName)
{
	std::ofstream Write ("link.url");
		if (LinkName == "MyVkontakte")
			Write << "[InternetShortcut]\n URL=https://vk.com/m1shaowned";
		if (LinkName == "21PointGame")
			Write << "[InternetShortcut]\n URL=http://21pointgamelogs.esy.es/";
	Write.close ();
	system ("start link.url");
	system ("del /q link.url");
} // Функция для открытия веб-страниц по указанным ссылкам.
void HeaderText ()
{
	system ("cls");
    Center ("##########################################################################\n");
    Center ("#                                                                        #\n");
    Center ("#    Optimizer Dota 2 (ver 1.0) by Михаил Овнед  ( vk.com/m1shaowned )   #\n");
    Center ("#   Для перехода на личную страницу разработчика - нажмите клавишу Tab   #\n");
    Center ("#                                                                        #\n");
    Center ("  ##########################################################################\n\n");
} // Функция вывода шапки с заглавной информацией.
void TheEndOTheProgram (std::string TextError)
{
	if (TextError != " ")
	{
		HeaderText ();
		padding (3);
		TextInColor ("Red", TextError);
		TextInColor ("Red", "За дополнительной информацией обращайтесь к разработчику софта ВКонтакте - vk.com/m1shaowned \n\n");
		TextInColor ("Red", "Для выхода из программы нажмите любую клавишу . . .\n");
			if (getch () == 9)
				ActivationLinks ("MyVkontakte");
	}
	std::cout.flush ();
	exit (0);
} // Функция завершения программы, очищая буфер и возвращая код ошибки 0.
char Getch (std::string Window)
{
	char Button = 0;
		if (Window == "MainMenu")
			while (true)
			{
				Button = getch ();
					if (Button == 27)
						TheEndOTheProgram (" ");
                    if (Button == 9 || Button == 52)
                    {
							if (Button == 9)
								ActivationLinks ("MyVkontakte");
							if (Button == 52)
								ActivationLinks ("21PointGame");
						break;
					}
			}
	return Button;
} // Адаптивная функция для getch, которая работает по отдельным окнам (менюшкам) программы.
void CheckForAdminRights ()
{
	system ("mkdir C:\\Windows\\CheckFolder");
	std::ofstream Write ("C://Windows//CheckFolder//CheckFile.txt");
	Write << "1";
	Write.close ();
	bool Number = false;
	std::ifstream Read ("C://Windows//CheckFolder//CheckFile.txt");
	Read >> Number;
	Read.close ();
	system ("rmdir /q /s C:\\Windows\\CheckFolder");
		// Удаляем папку CheckFolder вместе с текстовым файлом.
		if (!Number)
			TheEndOTheProgram ("Программа не обладает правами администратора, перезапустите программу от имени администратора\n\n");
} // Функция для проверки на наличие прав администратора у этой программы.
/*void CheckCompatibility ()
{
	bool Number = false;
		if (!Number)
			TheEndOTheProgram ("Запуск программы прерван - не найден локальный путь игры\n\n");
} // Функция для проверки совместимости. */
// Необходимо дописать фукнционал функции..
int main ()
{
	ConfigureConsoleWindow ();
	CheckForAdminRights ();
	//CheckCompatibility ();
	char Button = 0;
	bool InformationAboutTheSuccessfulLaunch = false;
	while (true) // Жизненный цикл программы
	{
		HeaderText ();
			if (!InformationAboutTheSuccessfulLaunch)
			{
				TextInColor ("Green", "Проверка на совместимость пройдена успешно!\n");
				InformationAboutTheSuccessfulLaunch = true;
			}
		Center ("__________________________________\n");
		Center ("|         Меню программы:        |\n");
		Center ("|                                |\n");
		Center ("|--------------------------------|\n");
		Center ("| 4. Скачать веселую игрушку от  |\n");
		Center ("| этого же разработчика :)       |\n");
		Center ("|--------------------------------|\n");
		Center ("| 5. Настройки                   |\n");
		Center ("|                                |\n");
		Center ("|--------------------------------|\n");
		Center ("|                                |\n");
		Center ("| Esc. Выйти из программы        |\n");
		Center ("|________________________________|\n");
		Button = Getch ("MainMenu");
	}
}
