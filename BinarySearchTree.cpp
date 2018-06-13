#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    header = nullptr;
}

// удалить поддерево
void deleteTree(Element *element) {
    if (element != nullptr) {
        deleteTree(element->left);
        deleteTree(element->right);
        delete element;
    }
}

BinarySearchTree::~BinarySearchTree() {
    deleteTree(header);
}

// копируем
void copy(Element *pElement, Element *parent, bool isLeft) {
    if (pElement != nullptr) {
        Element *element = new Element(pElement->key, parent);
        element->value = pElement->value;
        if (parent != nullptr) {
            if (isLeft) {
                parent->left = element;
            } else {
                parent->right = element;
            }
        }
        copy(pElement->left, element, true);
        copy(pElement->right, element, false);
    }
}


// оператор присваивания (lvalue-ссылка на экземпляр этого же класса)
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &other) {
    deleteTree(header);
    if (other.header != nullptr) {
        header = new Element(other.header->key, nullptr);
        header->value = other.header->value;
        copy(other.header->left, header, true);
        copy(other.header->right, header, false);
    }
    return *this;
}

// оператор перемещения (rvalue-ссылка на экземпляр этого же класса)
BinarySearchTree &BinarySearchTree::operator=(BinarySearchTree &&other) {
    deleteTree(header);
    header = other.header;
    other.header = nullptr;
    return *this;
}

// поиск слова в словаре
Element *findElement(std::string key, Element *pElement) {
    if (pElement == nullptr) {
        return nullptr;
    }
    if (key == pElement->key) {
        return pElement;
    }
    return findElement(key, (key < pElement->key) ? pElement->left : pElement->right);
}

// поиск слова в словаре (возвращает количество вхождений (0 - если данного слова нет))
int BinarySearchTree::find(std::string key) {
    Element *pElement = findElement(key, header);
    return pElement == nullptr ? 0 : pElement->value;
}

// добавить слово в словарь (извество что его нет в словаре)
void addSheet(std::string key, Element *pElement) {
    if (key < pElement->key) {
        if (pElement->left == nullptr) {
            pElement->left = new Element(key, pElement);
        } else {
            addSheet(key, pElement->left);
        }
    } else {
        if (pElement->right == nullptr) {
            pElement->right = new Element(key, pElement);
        } else {
            addSheet(key, pElement->right);
        }
    }
}

// добавить слово в словарь
void BinarySearchTree::add(std::string key) {
    if (header == nullptr) {
        header = new Element(key, nullptr);
    } else {
        Element *pElement = findElement(key, header);
        if (pElement == nullptr) {
            addSheet(key, header);
        } else {
            // для слова увеличивается счетчик числа вхождений
            pElement->value++;
        }
    }
}

// найти максимальный элемент (элемент не может быть == nullptr)
Element *maxElement(Element *pElement) {
    return (pElement->right == nullptr) ? pElement : maxElement(pElement->right);
}

// найти минимальный элемент (элемент не может быть == nullptr)
Element *minElement(Element *pElement) {
    return (pElement->left == nullptr) ? pElement : maxElement(pElement->left);
}

// удаляем узел дерева
void deleteElement(Element *pElementDel) {
    Element *parent = pElementDel->parent;
    Element *pElementNew;
    if (pElementDel->left != nullptr) {
        pElementNew = pElementDel->left;
    } else if (pElementDel->right != nullptr) {
        pElementNew = pElementDel->right;
    } else {
        // нет детей
        pElementNew = nullptr;
    }

    if (pElementNew != nullptr) {
        pElementNew->parent = parent;
    }
    if (parent != nullptr) {
        if (parent->left == pElementDel) {
            parent->left = pElementNew;
        } else {
            parent->right = pElementNew;
        }
    }
    delete pElementDel;
}


// удалить слово из словаря
void BinarySearchTree::del(std::string key) {
    Element *pElementDel = findElement(key, header);
    if (pElementDel != nullptr) {
        // есть слово в словаре
        if (pElementDel->value > 1) {
            // уменьшаем счетчик
            pElementDel->value--;
        } else {
            // надо удалить узел дерева

            // указатель на новый узел, который копируем на данное место в дереве
            // это потомок удаляемого узла с наиболее близким значением (с лева - наибольшим, с права - наименьшим)
            Element *pElementNew;
            if (pElementDel->left != nullptr) {
                pElementNew = maxElement(pElementDel->left);
            } else if (pElementDel->right != nullptr) {
                pElementNew = minElement(pElementDel->right);
            } else {
                // нет детей
                pElementNew = nullptr;
                deleteElement(pElementDel);
            }
            if (pElementNew != nullptr) {
                // копируем содержимое
                pElementDel->key = pElementNew->key;
                pElementDel->value = pElementNew->value;
                deleteElement(pElementNew);
            }
        }
    }
}

// количество слов поддерева
int countValue(Element *element) {
    return (element == nullptr)
           ? 0
           : element->value
             + countValue(element->left)
             + countValue(element->right);
}

// общее количество слов в словаре с учетом числа вхождения слов
int BinarySearchTree::countAll() {
    return countValue(header);
}

// вывод дерева (как хранится)
void print(std::ostream &os, Element *element, int level, std::string info) {
    if (element != nullptr) {
        for (int i = 0; i < level; i++) os << "    ";
        os << info << " " << element->key << " - " << element->value << std::endl;
        print(os, element->left, level + 1, "left:");
        print(os, element->right, level + 1, "right:");
    }
}

// выводит слова в алфавитном порядке с указанием количества вхождений
void outLeft(std::ostream &os, Element *element) {
    if (element != nullptr) {
        if (element->left != nullptr) {
            outLeft(os, element->left);
        }
        os << element->key << " - " << element->value << std::endl;
        if (element->right != nullptr) {
            outLeft(os, element->right);
        }
    }
}

// operator вывода (выводит слова в алфавитном порядке с указанием количества вхождений)
std::ostream &operator<<(std::ostream &os, const BinarySearchTree &tree) {
    os << std::endl;
    print(os, tree.header, 0, "header:");

    os << std::endl;
    outLeft(os, tree.header);
    return os;
}
