#include <iostream>
#include <random>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) :
            data(d),
            next(nullptr) { }
    };
    Node* head;
    Node* tail;

public:
    // Конструктор.
    LinkedList() :
        head(nullptr),
        tail(nullptr) { }

    // Деструктор.
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }

    // Функція, що додає новий вузол зі значенням "value" в початок списку.
    void push_front(const T& value) {
        Node* node = new Node(value); // Створюємо новий вузол з заданим значенням.
        if (head == nullptr) { // Якщо список порожній.
            head = node; // Головний вузол і хвістовий вузол стають новим вузлом.
            tail = node;
        }
        else {
            node->next = head; // Наступним за новим вузлом стає колишній головний вузол.
            head = node; // Новий вузол стає головним вузлом.
        }
    }

    // Функція, що додає новий вузол зі значенням "value" в кінець списку.
    void push_back(const T& value) {
        Node* node = new Node(value); // Створюємо новий вузол з заданим значенням.
        if (head == nullptr) { // Якщо список порожній.
            head = node; // Головний вузол і хвістовий вузол стають новим вузлом.
            tail = node;
        }
        else {
            tail->next = node; // Наступним за хвістовим вузлом стає новий вузол.
            tail = node; // Новий вузол стає хвістовим вузлом.
        }
    }

    // Функція, що видаляє зі списку вузол зі значенням, рівним параметру "value".
    void remove(const T& value) {
        Node* current = head; // Починаємо перебір списку з головного вузла.
        Node* previous = nullptr; // Попереднього вузла поки немає.
        while (current != nullptr) { // Продовжуємо перебір, поки не дійшли до кінця списку.
            if (current->data == value) { // Якщо знайдено вузол зі значенням, рівним параметру "value".
                if (previous == nullptr) { // Якщо це перший вузол у списку.
                    head = current->next; // Головний вузол стає наступним за поточним.
                }
                else {
                    previous->next = current->next; // Попередній вузол посилається на наступний за поточним.
                }
                if (current == tail) { // Якщо це останній вузол у списку.
                    tail = previous; // Хвіст стає попереднім за поточним.
                }
                delete current; // Видаляємо поточний вузол з пам'яті.
                return; // Завершуємо функцію.
            }
            previous = current; // Перехід до наступного вузла.
            current = current->next;
        }
    }

    // Ця функція виводить елементи зв'язаного списку в порядку їх слідування.
    void print() const {
        Node* current = head; // Вона починається з головного вузла і проходить через кожен вузол, поки не буде досягнутий кінець списку.
        while (current != nullptr) {
            std::cout << current->data << " "; // Значення даних кожного вузла виводиться на консоль, розділені пробілом.
            current = current->next;
        }
        std::cout << std::endl; // Наприкінці виводиться символ нового рядка, щоб завершити виведення.
    }
};

// Точка входу в програму.
int main(int argc, char* argv[])
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);

    LinkedList<int> list;

    // Додаємо елементи до списку.
    //list.push_back(10);
    //list.push_back(20);
    //list.push_front(5);
    //list.push_front(2);

    int a = 0;
    for (int i = 0; i < 5; i++) {
        if (i == 2) {
            a = dis(gen);
            list.push_back(a);
        }
        else {
            list.push_back(dis(gen));
        }
    }

    // Виводимо список на екран.
    std::cout << "List: ";
    list.print();

    // Видаляємо елемент зі списку.
    //list.remove(10);
    list.remove(a);

    // Виводимо список на екран знову.
    std::cout << "List after removing " << a << ": ";
    list.print();

    return 0;
}
