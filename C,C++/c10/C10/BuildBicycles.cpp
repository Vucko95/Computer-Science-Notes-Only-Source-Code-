//: C10:BuildBicycles.cpp
// From "Thinking in C++, 2nd Edition, Volume 2"
// by Bruce Eckel & Chuck Allison, (c) 2003 MindView, Inc.
// Available at www.BruceEckel.com.
//{L} Bicycle
#include <cstddef>
#include <iostream>
#include <map>
#include <vector>
#include "../purge.h"
#include "Bicycle.h"
using namespace std;

// Constructs a bike via a concrete builder
Bicycle*
buildMeABike(BicycleTechnician& t, BicycleBuilder* builder) {
  t.setBuilder(builder);
  t.construct();
  Bicycle* b = builder->getProduct();
  cout << "Built a " << builder->getBikeName() << endl;
  return b;
}

int main() {
  // Create an order for some bicycles
  map <string, size_t> order;
  order["mountain"] = 2;
  order["touring"] = 1;
  order["racing"] = 3;

  // Build bikes
  vector<Bicycle*> bikes;
  BicycleBuilder* m = new MountainBikeBuilder;
  BicycleBuilder* t = new TouringBikeBuilder;
  BicycleBuilder* r = new RacingBikeBuilder;
  BicycleTechnician tech;
  map<string, size_t>::iterator it = order.begin();
  while (it != order.end()) {
    BicycleBuilder* builder;
    if (it->first == "mountain")
      builder = m;
    else if (it->first == "touring")
      builder = t;
    else if (it->first == "racing")
      builder = r;
    for (size_t i = 0; i < it->second; ++i)
      bikes.push_back(buildMeABike(tech, builder));
    ++it;
  }
  delete m;
  delete t;
  delete r;

  // Display inventory
  for (size_t i = 0; i < bikes.size(); ++i)
    cout << "Bicycle: " << *bikes[i] << endl;
  purge(bikes);
}

/* Output:
Built a MountainBike
Built a MountainBike
Built a RacingBike
Built a RacingBike
Built a RacingBike
Built a TouringBike
Bicycle: { Frame Wheel Seat Derailleur Handlebar Sprocket Shock }
Bicycle: { Frame Wheel Seat Derailleur Handlebar Sprocket Shock }
Bicycle: { Frame Wheel Seat Handlebar Sprocket }
Bicycle: { Frame Wheel Seat Handlebar Sprocket }
Bicycle: { Frame Wheel Seat Handlebar Sprocket }
Bicycle: { Frame Wheel Seat Derailleur Handlebar Sprocket Rack } */ ///:~
