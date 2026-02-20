#include <iostream>
#include <string>
using namespace std;

// Existing interface (Legacy system)
class OldPrinter {
public:
    virtual void printOld(string text) = 0;
    virtual ~OldPrinter() = default;
};

// New printer class with a different interface
class ModernPrinter {
public:
    void printData(string data) {
        cout << "Modern Printer printing: " << data << endl;
    }
};

// Adapter class that bridges OldPrinter and ModernPrinter
class PrinterAdapter : public OldPrinter {
private:
    ModernPrinter* modernPrinter;
public:
    PrinterAdapter(ModernPrinter* mp) : modernPrinter(mp) {}

    void printOld(string text) override {
        // Adapt the call
        modernPrinter->printData(text);
    }
};

// Client code
int main() {
    ModernPrinter newPrinter;
    PrinterAdapter adapter(&newPrinter);

    // Client expects OldPrinter interface
    OldPrinter* printer = &adapter;
    printer->printOld("Hello from Adapter Pattern!");

    return 0;
}




