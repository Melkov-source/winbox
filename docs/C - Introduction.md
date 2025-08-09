Установка компилятора GCC через [msys2](https://www.msys2.org/)

Это настройки для .clang-format.
```yaml
BasedOnStyle: LLVM
IndentWidth: 4
TabWidth: 4
UseTab: ForIndentation
BreakBeforeBraces: Allman
AllowShortIfStatementsOnASingleLine: false
AllowShortLoopsOnASingleLine: false
AllowShortFunctionsOnASingleLine: Inline
SpaceBeforeParens: ControlStatements
SpacesInParentheses: false
PointerAlignment: Right
ColumnLimit: 80
IndentCaseLabels: true
```
Для его запуска, требуется установить расширение  [Clang-Format](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format)
Список всех расширений для VSCode
1. [Clang-Format](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format) - `xaver.clang-format`
2. [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) - `ms-vscode.cpptools`
3. [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) - `ms-vscode.cpptools-extension-pack`
4. [C/C++ Themes](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-themes) - `ms-vscode.cpptools-themes`