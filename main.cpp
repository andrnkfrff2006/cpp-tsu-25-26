#include <iostream>
#include <fstream>
#include <string>
#include <map>

// Удаление пробелов, отступов и переводы строк (\n) по краям строки
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n");  // Первый непробельный символ
    if (std::string::npos == first) return str;     // Если строка пустая или только пробелы
    size_t last = str.find_last_not_of(" \t\n");    // Последний непробельный символ
    return str.substr(first, (last - first + 1));   // Обрезанная подстрока
}

// Сохранение в формате .env
void saveFile(const std::string& filename, const std::map<std::string, int>& data) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& pair : data) {
            outFile << pair.first << "=" << pair.second << "\n";    // key=value
        }
        outFile.close();
    } else {
        std::cerr << "Ошибка записи файла " << filename << std::endl;
    }
}

// Чтение файла формата .env
void loadFile(const std::string& filename, std::map<std::string, int>& data) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            if (line.empty() || line[0] == '#') {   // Пропуск пустых строк и комментариев
                continue;
            }
            size_t delimiterPos = line.find('=');
            if (delimiterPos != std::string::npos) {    // Чтение ключа и его значения
                std::string key = trim(line.substr(0, delimiterPos));
                std::string valueStr = trim(line.substr(delimiterPos + 1));
                
                try {   // Преобразование значения в число
                    int value = std::stoi(valueStr);
                    data[key] = value;
                } catch (...) {
                    // Если valueStr - не число, игнор
                }
            }
        }
        inFile.close();
    }
}

int main(int argc, char* argv[]) {
    std::string filename;

    // Определение имени файла
    if (argc > 1) {
        filename = argv[1];
    } else {
        filename = "config.env";    // По умолчанию
    }

    std::map<std::string, int> data;
    loadFile(filename, data);   // Чтение файла

    // Чтение стандартного ввода
    std::string inputKey;
    int inputValue;

    while (std::cin >> inputKey >> inputValue) {
        data[inputKey] = inputValue;    // Ввод пар key=value или замена значения
    }

    saveFile(filename, data);   // Сохранение в файл

    return 0;
}