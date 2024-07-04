# 3D Viewer

## Описание проекта

3D Viewer — программа для просмотра и визуализации каркасных 3D моделей, загружаемых из файлов формата .obj. Программа предоставляет возможность визуализации с функциями вращения, масштабирования и перемещения модели на экране.

Формат файла .obj — это простой формат данных для представления трехмерной геометрии. Он содержит информацию о положении вершин, UV координат текстуры каждой вершины, нормалей вершин и граней, определяющих каждый многоугольник как список вершин и вершин текстуры. В данном проекте реализована поддержка только списка вершин и поверхностей.



## Пример работы программы

![Запись работы программы](./static/Screencast.gif)


## Аффинные преобразования

Все вычисления координат, выполняются на процессоре. Программа поддерживает следующие преобразования:
    - перемещение
    - поворот
    - масштабирование


## Функциональные возможности

Программа поддерживает следующие функции:
  - загрузка каркасной модели из файла формата .obj (поддержка списка вершин и поверхностей)
  - перемещение модели относительно осей X, Y, Z
  - поворот модели относительно осей X, Y, Z
  - масштабирование модели
  - графический интерфейс для управления моделями и их преобразованиями
  - выбор типа проекции (параллельная и центральная)
  - настройка типа (сплошная, пунктирная), цвета и толщины ребер
  - настройка способа отображения (отсутствует, круг, квадрат), цвета и размера вершин
  - выбор цвет фона
  - сохранение и загрузка параметров настроек между перезапусками программы
  - создание снимка отображаемой каркасной модели в файл в форматах bmp и jpeg
  - созлдание "скринкаста" отображаемой каркасной модели в gif-анимацию (640x480, 10fps, 5s)


## Графический интерфейс
Отображение моделей осуществляется с использованием библиотеки Qt и графического API OpenGL, что обеспечивает высокую производительность и гибкость в визуализации 3D объектов.

Графический интерфейс разработан с использованием библиотеки Qt и графического API OpenGL, содержит следующие элементы:
  - кнопка для выбора файла с моделью и поле для вывода его названия
  - зона визуализации каркасной модели
  - кнопки и поля ввода для перемещения модели
  - кнопки и поля ввода для поворота модели
  - кнопки и поля ввода для масштабирования модели
  - информация о загруженной модели — название файла, количество вершин и рёбер
  - кнопка для создания снимка отображаемой каркасной модели
  - кнопка для создания аниации отображаемой каркасной модели


## Сборка и установка

Для сборки и установки программы используется Makefile со стандартным набором целей для GNU-программ:
  - **all** - сборка и установка проекта.
  - **dvi** - открытие файла документации.
  - **install** - сборка проекта.
  - **uninstall** - удаление собранных файлов.
  - **tests** - сборка и запуск тестов.
  - **clean_tests** - очистка тестовых файлов.
  - **clean** - очистка скомпилированных файлов и отчетов.
  - **autoformat** - автоформатирование исходного кода с использованием clang-format.
  - **dist** - создание дистрибутива проекта.
  - **leaks** - запуск тестов с проверкой утечек памяти.

### Установка проекта
Для установки проекта выполните следующую команду:
    `make install`
Эта команда создаст каталог build и скомпилирует проект с использованием qmake и make. Исполняемый файл будет перемещен в каталог build.

### Запуск проекта
После установки вы можете запустить проект, выполнив команду `./build/3d_viewer` или кликнув по файлу *3d_viewer* в директории *build*.

После завершения установки вы можете запустить проект одним из следующих способов:
  - выполните команду в терминале `./build/3d_viewer`
  - либо откройте каталог *build* и дважды щелкните по файлу *3d_viewer*.