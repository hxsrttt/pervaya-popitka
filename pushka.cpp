#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

float randomFloat(float a, float b) {
    return ((b - a) * ((float) rand() / RAND_MAX)) + a;
}

int main() {
    // ����������� ��������� ��������
    srand(time(NULL));
    float targetPosition = randomFloat(0.0f, 100.0f);
    float cannonPosition = randomFloat(0.0f, 100.0f);
    float angle = 0.0f;
    float power = 0.0f;
    float distance = 0.0f;
    bool hit = false;

    while (!hit) {
        // ����������� ������� ��������
        cout << "Target position: " << targetPosition << endl;
        cout << "Cannon position: " << cannonPosition << endl;
        cout << "UGOL: " << angle << endl;
        cout << "SILA: " << power << endl << endl;

        // ������ ���������� �������� �� ������������
        cout << "Enter cannon angle (0 - 90 degrees): ";
        cin >> angle;
        cout << "Enter cannon power (0 - 100): ";
        cin >> power;

        // ���������� � ����������� ���������� ��������
        distance = power * cos(angle) * (cannonPosition / 10);
        if (distance > targetPosition - 5 && distance < targetPosition + 5) {
            cout << "HIT!" << endl;
            hit = true;
        } else {
            cout << "Missed! Distance: " << distance << endl;
        }
    }

    return 0;
}
