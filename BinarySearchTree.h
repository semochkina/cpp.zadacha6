// двоичное дерево

#include <istream>
#include <vector>

// элемент дерева
struct Element {
    Element(std::string key, Element *parent) : key(key),
                                                parent(parent),
                                                left(nullptr),
                                                right(nullptr),
                                                value(1) {}
    // слово
    std::string key;
    // количество вхождений
    int value;
    // указатель на родителя (null - начальный элемент)
    Element *parent;
    // указатель на левый поток (соответствует 0) null - пусто
    Element *left;
    // указатель на правый поток (соответствует 1)
    Element *right;
};

class BinarySearchTree {
public:
    BinarySearchTree();

    virtual ~BinarySearchTree();

    // оператор присваивания (lvalue-ссылка на экземпляр этого же класса)
    BinarySearchTree &operator=(const BinarySearchTree &other);

    // оператор перемещения (rvalue-ссылка на экземпляр этого же класса)
    BinarySearchTree &operator=(BinarySearchTree &&other);


    // поиск слова в словаре (возвращает количество вхождений (0 - если данного слова нет))
    int find(std::string key);

    // добавить слово в словарь
    void add(std::string key);

    // удалить слово из словаря
    void del(std::string key);

    // общее количество слов в словаре с учетом числа вхождения слов
    int countAll();

    // operator вывода
    friend std::ostream &operator<<(std::ostream &os, const BinarySearchTree &tree);

private:
    // указатель на начальный элемент
    Element *header;
};
