//: C10:Bicycle.h
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Defines classes to build bicycles
// Illustrates the Builder Design Pattern
#ifndef BICYCLE_H
#define BICYCLE_H

#include <iosfwd>
#include <string>
#include <vector>

class BicyclePart {
public:
  enum BPart {FRAME, WHEEL, SEAT, DERAILLEUR,
    HANDLEBAR, SPROCKET, RACK, SHOCK, NPARTS};
  BicyclePart(BPart);
  friend std::ostream&
  operator<<(std::ostream&, const BicyclePart&);
private:
  BPart id;
  static std::string names[NPARTS];
};

class Bicycle {
public:
  ~Bicycle();
  void addPart(BicyclePart*);
  friend std::ostream&
  operator<<(std::ostream&, const Bicycle&);
private:
  std::vector<BicyclePart*> parts;
};

class BicycleBuilder {
public:
  BicycleBuilder() {
    product = 0;
  }
  void createProduct() {
    product = new Bicycle;
  }
  virtual void buildFrame() = 0;
  virtual void buildWheel() = 0;
  virtual void buildSeat() = 0;
  virtual void buildDerailleur() = 0;
  virtual void buildHandlebar() = 0;
  virtual void buildSprocket() = 0;
  virtual void buildRack() = 0;
  virtual void buildShock() = 0;
  virtual std::string getBikeName() const = 0;
  Bicycle* getProduct() {
    Bicycle* temp = product;
    product = 0;  // relinquish product
    return temp;
  }
protected:
  Bicycle* product;
};

class MountainBikeBuilder : public BicycleBuilder {
public:
  void buildFrame();
  void buildWheel();
  void buildSeat();
  void buildDerailleur();
  void buildHandlebar();
  void buildSprocket();
  void buildRack();
  void buildShock();
  std::string getBikeName() const {
    return "MountainBike";
  }
};

class TouringBikeBuilder : public BicycleBuilder {
public:
  void buildFrame();
  void buildWheel();
  void buildSeat();
  void buildDerailleur();
  void buildHandlebar();
  void buildSprocket();
  void buildRack();
  void buildShock();
  std::string getBikeName() const {
    return "TouringBike";
  }
};

class RacingBikeBuilder : public BicycleBuilder {
public:
  void buildFrame();
  void buildWheel();
  void buildSeat();
  void buildDerailleur();
  void buildHandlebar();
  void buildSprocket();
  void buildRack();
  void buildShock();
  std::string getBikeName() const {
    return "RacingBike";
  }
};

class BicycleTechnician {
public:
  BicycleTechnician() {
    builder = 0;
  }
  void setBuilder(BicycleBuilder* b) {
    builder = b;
  }
  void construct();
private:
  BicycleBuilder* builder;
};

#endif ///:~
