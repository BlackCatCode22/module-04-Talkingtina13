#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

// Animal class
class Animal {
protected:
    std::string name;
    int age;
    std::string species;
public:
    Animal(std::string name, int age, std::string species) : name(name), age(age), species(species) {}
    // Getters
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getSpecies() const { return species; }
};

// Subclasses
class Hyena : public Animal {
public:
    Hyena(std::string name, int age) : Animal(name, age, "Hyena") {}
};

class Lion : public Animal {
public:
    Lion(std::string name, int age) : Animal(name, age, "Lion") {}
};

class Tiger : public Animal {
public:
    Tiger(std::string name, int age) : Animal(name, age, "Tiger") {}
};

class Bear : public Animal {
public:
    Bear(std::string name, int age) : Animal(name, age, "Bear") {}
};

int main() {
    std::vector<Animal*> animals;
    std::map<std::string, int> speciesCount;

    // Read animal names from animalNames.txt
    std::ifstream animalNamesFile("animalNames.txt");
    std::vector<std::string> animalNames;
    std::string name;
    while (animalNamesFile >> name) {
        animalNames.push_back(name);
    }
    animalNamesFile.close();

    // Generate random ages for animals
    srand(time(NULL)); // Seed for random number generator
    int maxAge = 15; // Maximum age for animals
    int minAge = 1;  // Minimum age for animals

    // Read animal details from arrivingAnimals.txt
    std::ifstream arrivingAnimalsFile("arrivingAnimals.txt");
    std::string animalType;
    while (arrivingAnimalsFile >> animalType) {
        // Generate random age
        int age = rand() % (maxAge - minAge + 1) + minAge;

        // Create animal object based on type
        if (animalType == "Hyena") {
            animals.push_back(new Hyena(animalNames[rand() % animalNames.size()], age));
        } else if (animalType == "Lion") {
            animals.push_back(new Lion(animalNames[rand() % animalNames.size()], age));
        } else if (animalType == "Tiger") {
            animals.push_back(new Tiger(animalNames[rand() % animalNames.size()], age));
        } else if (animalType == "Bear") {
            animals.push_back(new Bear(animalNames[rand() % animalNames.size()], age));
        }

        // Count species
        speciesCount[animalType]++;
    }
    arrivingAnimalsFile.close();

    // Write report to newAnimals.txt
    std::ofstream reportFile("newAnimals.txt");
    for (auto& animal : animals) {
        reportFile << "Name: " << animal->getName() << ", Age: " << animal->getAge() << ", Species: " << animal->getSpecies() << std::endl;
        delete animal; // Free memory
    }
    reportFile << "Species Count:\n";
    for (const auto& pair : speciesCount) {
        reportFile << pair.first << ": " << pair.second << std::endl;
    }
    reportFile.close();

    return 0;
}
