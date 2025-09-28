#Для библиотек:
# Создание директории для сборки
mkdir build_vs_debug
cd build_vs_debug

# Генерация проектов Visual Studio
cmake .. -G "Visual Studio 17 2022" -A x64

# Сборка проекта
cmake --build . --config Debug

ТЕСТОВАЯ ПРОГРАММА У МЕНЯ СОБИРАНА В ПАПКЕ
