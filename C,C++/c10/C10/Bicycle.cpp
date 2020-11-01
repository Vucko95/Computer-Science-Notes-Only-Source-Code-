//: C10:Bicycle.cpp {O}
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
// Defines classes to build bicycles
// Illustrates the Builder Design Pattern
#include <cassert>
#include <cstddef>
#include <iostream>
#include "Bicycle.h"
#include "../purge.h"
using namespace std;

// BicyclePart implementation
BicyclePart::BicyclePart(BPart bp) {
  id = bp;
}
ostream&
operator<<(ostream& os, const BicyclePart& bp) {
  return os << bp.names[bp.id];
}
std::string BicyclePart::names[NPARTS] = {
  "Frame", "Wheel", "Seat", "Derailleur",
  "Handlebar", "Sprocket", "Rack", "Shock"};

// Bicycle implementation
Bicycle::~Bicycle() {
  purge(parts);
}
void Bicycle::addPart(BicyclePart* bp) {
  parts.push_back(bp);
}
ostream&
operator<<(ostream& os, const Bicycle& b) {
  os << "{ ";
  for (size_t i = 0; i < b.parts.size(); ++i)
    os << *b.parts[i] << ' ';
  return os << '}';
}

// MountainBikeBuilder implementation
void MountainBikeBuilder::buildFrame() {
  product->addPart(new BicyclePart(BicyclePart::FRAME));
}
void MountainBikeBuilder::buildWheel() {
  product->addPart(new BicyclePart(BicyclePart::WHEEL));
}
void MountainBikeBuilder::buildSeat() {
  product->addPart(new BicyclePart(BicyclePart::SEAT));
}
void MountainBikeBuilder::buildDerailleur() {
  product->addPart(
    new BicyclePart(BicyclePart::DERAILLEUR));
}
void MountainBikeBuilder::buildHandlebar() {
  product->addPart(
    new BicyclePart(BicyclePart::HANDLEBAR));
}
void MountainBikeBuilder::buildSprocket() {
  product->addPart(new BicyclePart(BicyclePart::SPROCKET));
}
void MountainBikeBuilder::buildRack() {}
void MountainBikeBuilder::buildShock() {
  product->addPart(new BicyclePart(BicyclePart::SHOCK));
}

// TouringBikeBuilder implementation
void TouringBikeBuilder::buildFrame() {
  product->addPart(new BicyclePart(BicyclePart::FRAME));
}
void TouringBikeBuilder::buildWheel() {
  product->addPart(new BicyclePart(BicyclePart::WHEEL));
}
void TouringBikeBuilder::buildSeat() {
  product->addPart(new BicyclePart(BicyclePart::SEAT));
}
void TouringBikeBuilder::buildDerailleur() {
  product->addPart(new BicyclePart(BicyclePart::DERAILLEUR));
}
void TouringBikeBuilder::buildHandlebar() {
  product->addPart(
    new BicyclePart(BicyclePart::HANDLEBAR));
}
void TouringBikeBuilder::buildSprocket() {
  product->addPart(new BicyclePart(BicyclePart::SPROCKET));
}
void TouringBikeBuilder::buildRack() {
  product->addPart(new BicyclePart(BicyclePart::RACK));
}
void TouringBikeBuilder::buildShock() {}

// RacingBikeBuilder implementation
void RacingBikeBuilder::buildFrame() {
  product->addPart(new BicyclePart(BicyclePart::FRAME));
}
void RacingBikeBuilder::buildWheel() {
  product->addPart(new BicyclePart(BicyclePart::WHEEL));
}
void RacingBikeBuilder::buildSeat() {
  product->addPart(new BicyclePart(BicyclePart::SEAT));
}
void RacingBikeBuilder::buildDerailleur() {}
void RacingBikeBuilder::buildHandlebar() {
  product->addPart(
    new BicyclePart(BicyclePart::HANDLEBAR));
}
void RacingBikeBuilder::buildSprocket() {
  product->addPart(new BicyclePart(BicyclePart::SPROCKET));
}
void RacingBikeBuilder::buildRack() {}
void RacingBikeBuilder::buildShock() {}

// BicycleTechnician implementation
void BicycleTechnician::construct()
{
  assert(builder);
  builder->createProduct();
  builder->buildFrame();
  builder->buildWheel();
  builder->buildSeat();
  builder->buildDerailleur();
  builder->buildHandlebar();
  builder->buildSprocket();
  builder->buildRack();
  builder->buildShock();
}; ///:~
