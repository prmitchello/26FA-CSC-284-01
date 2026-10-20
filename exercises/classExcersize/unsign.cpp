#include <iostream>

template <typename T>
class Storage {
public:
    Storage(T value) : m_value{value} {}

    void set(T value) { m_value = value; }
    T get() const { return m_value; }

    void print() const {
        std::cout << m_value << '\n';
    }

private:
T m_value;
};

template <>
class Storage<bool> {
public:
    Storage(bool value) { set(value); }

    void set(bool value) { m_value = value ? 1u : 0u; }
    bool get() const { return m_value != 0u; }

    void print() const {
        std::cout << (get() ? "true" : "false") << '\n';
    }

private:
    unsigned m_value; // store as 0/1 (demonstrating different implementation)
};
int main() {
    Storage<int> si{42};
    si.print();              // 42

    Storage<std::string> ss{"hello"};
    ss.print();              // hello

    Storage<bool> sb{true};
    sb.print();              // true
    sb.set(false);
    sb.print();              // false
}
