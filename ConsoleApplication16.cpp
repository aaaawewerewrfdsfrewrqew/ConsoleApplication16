#include <iostream>
#include <string>
using namespace std;


struct Vagon {
    int number;
    int seats;
    int passengers;
};

class Train {
private:
    string model;
    int vagonCount;
    Vagon* vagon;

public:
    Train() {
        model = "N\A";
        vagonCount = 0;
        vagon = nullptr;
    }

    Train(string modelName, int count) {
        model = modelName;
        vagonCount = count;
        vagon = new Vagon[vagonCount];

        for (int i = 0; i < vagonCount; i++) {
            vagon[i].number = i + 1;
            vagon[i].seats = 50;
            vagon[i].passengers = 0;
        }
    }

    Train(const Train& other) {
        model = other.model;
        vagonCount = other.vagonCount;
        vagon = new Vagon[vagonCount];

        for (int i = 0; i < vagonCount; i++) {
            vagon[i] = other.vagon[i];
        }
    }

    ~Train() {
        delete[] vagon;
    }

    void Show() const {
        cout << "Модель потяга: " << model << endl;
        cout << "Кількість вагонів: " << vagonCount << endl;

        for (int i = 0; i < vagonCount; i++) {
            cout << "Вагон №" << vagon[i].number
                << " | Місць: " << vagon[i].seats
                << " | Пасажирів: " << vagon[i].passengers << endl;
        }
    }

    void AddVagon(int seats) {
        Vagon* temp = new Vagon[vagonCount + 1];

        for (int i = 0; i < vagonCount; i++) {
            temp[i] = vagon[i];
        }

        temp[vagonCount].number = vagonCount + 1;
        temp[vagonCount].seats = seats;
        temp[vagonCount].passengers = 0;

        delete[] vagon;
        vagon = temp;
        vagonCount++;
    }

    void AddPassenger(int vagonNumber) {
        for (int i = 0; i < vagonCount; i++) {
            if (vagon[i].number == vagonNumber) {
                if (vagon[i].passengers < vagon[i].seats) {
                    vagon[i].passengers++;
                }
                else {
                    cout << "Вагон заповнений!" << endl;
                }
                return;
            }
        }
        cout << "Вагон не знайдено!" << endl;
    }
};

int main() {
    Train t1("Hyundai", 2);
    t1.AddPassenger(1);
    t1.AddPassenger(1);
    t1.AddVagon(60);

    t1.Show();

    cout << "\nКопія потяга:\n";
    Train t2 = t1;
    t2.Show();

    return 0;
}
