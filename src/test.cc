#include <memory>
#include <iostream>

class A {
    public:
        virtual void F() = 0;
        virtual ~A() = default;
};

struct J {
    ~J() {
        std::cout << "J destructor\n";
    }
};

class B : public A {
    J j;
    public:
        void F() override {
            std::cout << "B::F()\n";
        }
        // ~B() {
        //     std::cout << "B Destructor\n";
        // }
};

class C : public A {
    J j;
    public:
        void F() override {
            std::cout << "C::F()\n";
        }
        // ~C() {
        //     std::cout << "C Destructor\n";
        // }
};

int main() {
    std::unique_ptr<A> a = std::make_unique<B>();
    a->F();
    a = std::make_unique<C>();
    a->F();

    return 0;
}
