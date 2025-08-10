#include <windows.h> // Основной заголовок WinAPI

// Функция обработки сообщений от Windows
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_CLOSE:          // Сообщение "закрыть окно"
			PostQuitMessage(0); // Завершить цикл сообщений
			return 0;
	}
	// Все остальные сообщения обрабатываем стандартно
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

// Точка входа для оконных приложений Windows
int WINAPI WinMain(HINSTANCE hInstance,     // Дескриптор текущего экземпляра программы
                   HINSTANCE hPrevInstance, // Устарело, всегда NULL
                   LPSTR lpCmdLine,         // Аргументы командной строки одной строкой
                   int nCmdShow             // Как показывать окно при запуске
)
{
	// 1. Описываем класс окна
	WNDCLASS wc = {0};
	wc.lpfnWndProc = WndProc;                      // Указываем обработчик сообщений
	wc.hInstance = hInstance;                      // Дескриптор программы
	wc.lpszClassName = "MyWindowClass";            // Имя класса (произвольное)
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);      // Курсор мыши
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // Цвет фона

	// 2. Регистрируем класс окна
	RegisterClass(&wc);

	// 3. Создаём окно
	HWND hwnd = CreateWindowEx(0,                            // Доп. стили
	                           wc.lpszClassName,             // Имя класса окна
	                           "Моё первое окно",            // Заголовок окна
	                           WS_OVERLAPPEDWINDOW,          // Стиль окна (с рамкой, заголовком, кнопками)
	                           CW_USEDEFAULT, CW_USEDEFAULT, // Позиция окна
	                           800, 600,                     // Размер окна
	                           NULL, NULL,                   // Родительское окно и меню
	                           hInstance, NULL               // Дескриптор программы и дополнительные данные
	);

	// 4. Показываем окно
	ShowWindow(hwnd, nCmdShow);

	// 5. Цикл обработки сообщений
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg); // Обработка клавиш
		DispatchMessage(&msg);  // Передача в WndProc
	}

	return 0; // Код завершения программы
}
