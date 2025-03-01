#include <iostream>
#include <vector>


class Suit {
private:
    std::vector<bool> states;

public:
    Suit() : states(5, false) {} // Изначально все состояния неактивны

    // Изменяет состояние на противоположное
    void toggleState(int index) {
        if (index >= 0 && index < states.size()) {
            states[index] = !states[index];
        }
    }

    // Проверяет, активно ли состояние
    bool isStateActive(int index) const {
        if (index >= 0 && index < states.size()) {
            return states[index];
        }
        return false;
    }

    // Считает количество активных состояний
    int countActiveStates() const {
        int count = 0;
        for (bool state : states) {
            if (state) {
                count++;
            }
        }
        return count;
    }

    // Логика обнаружения
    void detect() const {
        int activeCount = countActiveStates();
        if (activeCount >= 2) {
            std::cout << "Робопёс, патрулирующий периметр базы мармеладовых ослов, обнаруживает активность!" << std::endl;
        } else {
            std::cout << "Активность не обнаружена." << std::endl;
        }
    }

    // Функция для демонстрации
    void demo() {
        std::cout << "Активация режима невидимости..." << std::endl;
        toggleState(0); // Невидимость
        detect(); // Проверка на активность

        std::cout << "Активация режима беззвучия..." << std::endl;
        toggleState(1); // Беззвучие
        detect(); 

        std::cout << "Активация подавления инфракрасного спектра..." << std::endl;
        toggleState(2); // Подавление волн инфракрасного спектра
        detect(); 

        std::cout << "Отключение режима беззвучия..." << std::endl;
        toggleState(1); // Отключаем беззвучие
        detect(); 
    }
};

int main() {
    Suit mySuit;
    mySuit.demo(); // Запуск демонстрации
    return 0;
}