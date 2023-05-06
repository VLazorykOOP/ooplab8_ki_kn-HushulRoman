/*
У цьому коді шаблон класу List містить структуру Node, яка містить дані і вказівник на наступний елемент списку.
List має методи push_back для додавання елементів до списку, begin і end, які повертають ітератори на початок і кінець списку відповідно.

Клас ітератора має член current, який вказує на поточний елемент списку, а також перевантажені оператори * і ++,
щоб можна було отримати дані поточного елементу і перейти до наступного елементу в списку. Оператор != перевіряє, чи рівний поточний елемент іншому елементу.

У функції main створюється список цілих чисел, заповнюється декількома елементами і проходиться весь список за допомогою ітератора. Кожен елемент списку виводиться на екран.
*/

#include <iostream>
#include <random>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d = T{}, Node* n = nullptr) :
            data{ d },
            next{ n } {}
    };
    Node* head;
    Node* tail;

public:
    // Конструктор.
    List() :
        head{ nullptr },
        tail{ nullptr } {}

    // Деструктор.
    ~List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Додавання елементів до списку.
    void push_back(const T& d) {
        Node* temp = new Node(d, nullptr);
        if (tail == nullptr) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    // Клас Ітератор.
    class Iterator {
    private:
        Node* current;

    public:
        // Конструктор.
        Iterator(Node* node = nullptr) :
            current{ node } {}

        T& operator*() const {
            return current->data;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    // Повертає ітератор на початок списку.
    Iterator begin() const {
        return Iterator(head);
    }

    // Повертає ітератор на кінець списку.
    Iterator end() const {
        return Iterator(nullptr);
    }
};

// Точка входу в програму.
int main(int argc, char* argv[])
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);

    List<int> l;

    for (int i = 0; i < 5; i++) {
        l.push_back(dis(gen));
    }

    for (List<int>::Iterator i = l.begin(); i != l.end(); ++i) {
        std::cout << *i << " ";
    }

    return 0;
}
