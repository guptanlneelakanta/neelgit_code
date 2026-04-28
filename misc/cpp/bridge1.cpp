#include <iostream>
#include <memory>
using namespace std;

// Implementation hierarchy
class TV {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void setChannel(int channel) = 0;
    virtual ~TV() = default;
};

class SonyTV : public TV {
public:
    void turnOn() override { cout << "Sony TV is ON\n"; }
    void turnOff() override { cout << "Sony TV is OFF\n"; }
    void setChannel(int channel) override {
        cout << "Sony TV: Channel set to " << channel << endl;
    }
};

class LGTV : public TV {
public:
    void turnOn() override { cout << "LG TV is ON\n"; }
    void turnOff() override { cout << "LG TV is OFF\n"; }
    void setChannel(int channel) override {
        cout << "LG TV: Channel set to " << channel << endl;
    }
};

// Abstraction hierarchy
class RemoteControl {
protected:
    TV* tv;  // Bridge to implementation
public:
    RemoteControl(TV* t) : tv(t) {}
    virtual void on() { tv->turnOn(); }
    virtual void off() { tv->turnOff(); }
    virtual void setChannel(int channel) { tv->setChannel(channel); }
    virtual ~RemoteControl() = default;
};

// Extended abstraction
class AdvancedRemote : public RemoteControl {
public:
    AdvancedRemote(TV* t) : RemoteControl(t) {}
    void nextChannel() { 
        cout << "Switching to next channel...\n";
        tv->setChannel(10); // example
    }
    void previousChannel() {
        cout << "Switching to previous channel...\n";
        tv->setChannel(5); // example
    }
};

// Client code
int main() {
    SonyTV sony;
    LGTV lg;

    AdvancedRemote sonyRemote(&sony);
    AdvancedRemote lgRemote(&lg);

    sonyRemote.on();
    sonyRemote.setChannel(7);
    sonyRemote.nextChannel();
    sonyRemote.off();

    cout << "-----------------\n";

    lgRemote.on();
    lgRemote.previousChannel();
    lgRemote.off();

    return 0;
}

