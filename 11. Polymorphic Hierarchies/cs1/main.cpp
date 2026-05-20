#include <iostream>
#include <vector>

class Animal {
public:
  virtual void speak() const=0;
  virtual ~Animal()=default;
};

class Cat : public Animal {
public:
  virtual void speak() const {
    std::cout << "meow\n";
  }
};

class Anteater : public Animal {
public:
  virtual void speak() const {
    std::cout << "moo\n";
  }
};

int main() {

  Animal *animal = new Cat();
  animal->speak();

  delete animal;

  std::vector<Animal *> zoo;

  zoo.push_back(new Cat());
  zoo.push_back(new Cat());
  zoo.push_back(new Anteater());

  for (Animal *a : zoo)
    a->speak();

  unsigned aneaterCnt = 0;
  for (Animal *a : zoo) {
    if (dynamic_cast<Anteater *>(a)) {
      aneaterCnt++;
    }
  }

  std::cout << aneaterCnt << '\n';

  for (Animal *a : zoo)
    delete a;

  return 0;
}
