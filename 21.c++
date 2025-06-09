#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phone;
};

void showContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "Список контактов пуст!" << endl;
    } else {
        cout << "Ваши контакты:" << endl;
        for (size_t i = 0; i < contacts.size(); ++i) {
            cout << i + 1 << ". " << contacts[i].name << " - " << contacts[i].phone << endl;
        }
    }
}

int main() {
    vector<Contact> contacts;
    int choice;

    do {
        cout << "\nТелефонный справочник\n";
        cout << "1. Добавить контакт\n";
        cout << "2. Удалить контакт\n";
        cout << "3. Показать контакты\n";
        cout << "4. Искать контакт\n";
        cout << "5. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Contact newContact;
            cout << "Введите имя: ";
            getline(cin, newContact.name);
            cout << "Введите номер телефона: ";
            getline(cin, newContact.phone);
            contacts.push_back(newContact);
        } else if (choice == 2) {
            showContacts(contacts);
            if (!contacts.empty()) {
                int index;
                cout << "Введите номер контакта для удаления: ";
                cin >> index;
                if (index > 0 && index <= contacts.size()) {
                    contacts.erase(contacts.begin() + index - 1);
                } else {
                    cout << "Неверный номер!" << endl;
                }
            }
        } else if (choice == 3) {
            showContacts(contacts);
        } else if (choice == 4) {
            string searchName;
            cout << "Введите имя для поиска: ";
            getline(cin, searchName);
            bool found = false;
            for (const auto& contact : contacts) {
                if (contact.name == searchName) {
                    cout << "Найден: " << contact.name << " - " << contact.phone << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "Контакт не найден." << endl;
            }
        }

    } while (choice != 5);

    cout << "До свидания!" << endl;
    return 0;
}