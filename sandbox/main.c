#include <GL/gl.h>
#include <windows.h>

// Глобальные переменные
HDC hDC;
HGLRC hRC;
HWND hWnd;
HINSTANCE hInstance;

// Прототипы
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void InitOpenGL()
{
	PIXELFORMATDESCRIPTOR pfd = {
	    sizeof(PIXELFORMATDESCRIPTOR),                              // Размер структуры
	    1,                                                          // Версия
	    PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, // Флаги
	    PFD_TYPE_RGBA,                                              // Цвета в RGBA
	    32,                                                         // Биты на пиксель
	    0,
	    0,
	    0,
	    0,
	    0,
	    0, // Игнор цвета
	    0, // Нет альфа-буфера
	    0, // Игнор альфы
	    0, // Нет аккамулятора
	    0,
	    0,
	    0,
	    0,              // Игнор аккамулятора
	    24,             // Глубина
	    8,              // Шаблон
	    0,              // Нет вспомогательного буфера
	    PFD_MAIN_PLANE, // Главный слой
	    0,              // Зарезервировано
	    0,
	    0,
	    0 // Игнор масок
	};

	hDC = GetDC(hWnd);
	int format = ChoosePixelFormat(hDC, &pfd);
	SetPixelFormat(hDC, format, &pfd);

	hRC = wglCreateContext(hDC);
	wglMakeCurrent(hDC, hRC);

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

void Render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.5f, -0.5f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.5f, -0.5f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 0.5f);
	glEnd();

	SwapBuffers(hDC);
}

int WINAPI WinMain(HINSTANCE hInstance_, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	hInstance = hInstance_;

	// Регистрируем класс окна
	WNDCLASS wc = {0};
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = "OGLWinClass";
	RegisterClass(&wc);

	// Создаём окно
	hWnd = CreateWindowEx(0, wc.lpszClassName, "OpenGL WinAPI Triangle", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
	                      CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);

	InitOpenGL();

	// Цикл сообщений
	MSG msg;
	while (1)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				goto exitLoop;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		Render();
	}
exitLoop:

	// Очистка
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hRC);
	ReleaseDC(hWnd, hDC);

	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_CLOSE:
			PostQuitMessage(0);
			return 0;
		case WM_SIZE:
			glViewport(0, 0, LOWORD(lParam), HIWORD(lParam));
			return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}