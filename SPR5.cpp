#include <iostream>
#include <string>
using namespace std;

class Warhead {
private:
    int explosionForce;
public:
    Warhead(int _explosionForce) {
        explosionForce = _explosionForce;
    }
    int GetForce() { return explosionForce; }
};

class GuidanceSystem {
private:
    string typeOfSystem;
public:
    GuidanceSystem(string _typeOfSystem) {
        typeOfSystem = _typeOfSystem;
    }
    string GetTypeOfGuidanceSystem() { return typeOfSystem; }
};

class Rocket {
private:
    Warhead* warhead;
    GuidanceSystem* guidanceSystem;
public:
    void addWarhead(Warhead* _warhead) { warhead = _warhead; }
    void addGuidanceSystem(GuidanceSystem* _guidanceSystem) { guidanceSystem = _guidanceSystem; }
    void getInfo() {
        cout << "Rocket has charge power:" << warhead->GetForce() << " kilotons" << endl;
        cout << "The rocket is equipped with:" << guidanceSystem->GetTypeOfGuidanceSystem() << " type of guidance system" << endl;
    }
};

class RocketBuilder {
public:
    virtual Warhead* buildWarhead() = 0;
    virtual GuidanceSystem* buildGuidanceSystem() = 0;
    virtual ~RocketBuilder() {}
};

class Director {
private:
    RocketBuilder* rocketBuilder;
public:
    void setBuilder(RocketBuilder* newRocketBuilder) {
        rocketBuilder = newRocketBuilder;
    }
    Rocket* getRocket() {
        Rocket* rocket = new Rocket();
        rocket->addWarhead(rocketBuilder->buildWarhead());
        rocket->addGuidanceSystem(rocketBuilder->buildGuidanceSystem());
        return rocket;
    }
};

class Tamahawk : public RocketBuilder {
public:
    Warhead* buildWarhead() {
        return new Warhead(100);
    }
    GuidanceSystem* buildGuidanceSystem() {
        return new GuidanceSystem("Inertial and GPS");
    }
};

class AIM120 : public RocketBuilder {
public:
    Warhead* buildWarhead() {
        return new Warhead(50);
    }
    GuidanceSystem* buildGuidanceSystem() {
        return new GuidanceSystem("Radiolocational");
    }
};

int main() {
   
}