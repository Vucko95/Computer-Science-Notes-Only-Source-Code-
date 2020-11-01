from Map import Map

def main():
    # Create a map
    map = Map()
    map.put("Smith", 30)
    map.put("Anderson", 31)
    map.put("Lewis", 29)
    map.put("Cook", 29)
    map.put("Cook", 129)
    
    print("Entry set in map: " + str(map.items()))
    print("The age for Lewis is " + str(map.get("Lewis")))
    print("Is Smith in the map? " + str(map.containsKey("Smith")))
    print("Is Johnson in the map? " + 
         str(map.containsKey("Johnson")))
    print("Is value 30 in the map? " + str(map.containsValue(30)))
    print("Is value 33 in the map? " + str(map.containsValue(33)))
    print("Is age 33 in the map? " + str(map.containsValue(33)))
    print("All values for Cook? " + str(map.getAll("Cook")))
    print("keys are " + str(map.keys()))
    print("values are " + str(map.values()))

    map.remove("Smith")
    print("The map is " + map.getTable())

    map.clear()
    print("The map is " + map.getTable())

main()