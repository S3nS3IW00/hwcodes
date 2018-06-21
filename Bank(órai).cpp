#include <stdio.h>
#include <iostream>

using namespace std;

class Person{
  
  string name;
  int age, id;
  
  public:
  Person(){}
  Person(string name, int age, int id){
    this->name = name;
    this->age = age;
    this->id = id;
  }
  
  string getName(){
    return name;
  }
  
  void setName(string name){
    this->name = name;
  }
  
  int getAge(){
    return age;
  }
  
  void setAge(int age){
    this->age = age;
  }
  
  int getId(){
    this->id = id;
  }
  
  void setId(int id){
    this->id = id;
  }
  
  void toString(){
    std::cout << "Név: " << getName() << " | Kor: " << getAge() << " | ID: " << getId() << std::endl;
  }
  
};

class Account : public Person{
  
  Person owner;
  int amount;
  int pincode;
  
  public:
  Account(string name, int age, int id, int amount, int pincode){
    this->amount = amount;
    this->pincode = pincode;
    owner.setName(name);
    owner.setAge(age);
    owner.setId(id);
  }
  
  void in(int amount){
    this->amount += amount;
  }
  
  bool out(int amount){
    if(this->amount-amount > 0){
      this->amount -= amount;
      return true;
    }
    return false;
  }
  
  int getAmount(){
    return amount;
  }
  
  int getPincode(){
    return pincode;
  }
  
};

int main()
{
  Person p("Gazsi", 35, 2536);
  Account a(p.getName(), p.getAge(), p.getId(), 50000, 7263);
  std::cout << "Üdvözlöm " << p.getName() << "! Kérem adja meg a PIN kódját!" << std::endl;
  int pincode;
  std::cin >> pincode;
  if(pincode != a.getPincode()){ 
    std::cout << "Hibás PIN kód! Viszontlátásra!" << std::endl;
    return 0;
  } else {
    std::cout << "Sikeres bejelentkezés! Kérem adja meg mit szeretne tenni!" << std::endl;
    std::cout << "Egyenleg lekérdezés: 1 | Pénz felvétel: 2 | Pénz feltöltés: 3 | Kilépés: 4" << std::endl;
    int menu;
    std::cin >> menu;
    if(menu == 1){
      std::cout << "Egyenleg: " << a.getAmount() << "Ft" << std::endl;
    } else if(menu == 2){
      std::cout << "Kérem adja meg, hogy mennyi pénzt szeretne felvenni!" << std::endl;
      int amount;
      std::cin >> amount;
      if(a.out(amount)){
        std::cout << amount << "ft sikeresen felvéve! Jelenlegi egyenlege: " << a.getAmount() << "Ft" << std::endl;
      } else {
        std::cout << "Nem lehet felvenni " << amount << "Ft-ot, mert nincs elég pénz a számláján!" << std::endl;
      } 
    } else if(menu == 3){
      std::cout << "Kérem adja meg, hogy mennyi pénzt szeretne feltölteni!" << std::endl;
      int amount;
      std::cin >> amount;
      a.in(amount);
      std::cout << amount << "Ft hozzáadva a számlájához! Jelenlegi egyenlege: " << a.getAmount() << "Ft" << std::endl;
    } else if(menu == 4){
      std::cout << "Viszontlátásra!" << std::endl;
      return 0;
    } else {
      std::cout << "Ismeretlen menüpont!" << std::endl;
    }
    std::cout << "Egyenleg lekérdezés: 1 | Pénz felvétel: 2 | Pénz feltöltés: 3 | Kilépés: 4" << std::endl;
    std::cin >> menu;
  }

  return 0;
}
