#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Function to sell a pet.
void addPets()
{
    char pet_type[100];
    char breed[100];
    int age;
    int rate;

    cout << "Enter Pet Type: ";
    cin.ignore(); // Clear the input buffer
    cin.getline(pet_type, 100);
    cout << "Enter Pet Breed: ";
    cin.getline(breed, 100);
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter desired Price: ";
    cin >> rate;

    ofstream outFile;
    outFile.open("pets.txt", ios::app); // Append to the file
    if (outFile)
    {
        outFile << pet_type << "\n"
                << breed << "\n"
                << age << "\n"
                << rate << "\n";
        outFile.close();
        cout << "Pet sold Successfully.\n";
    }
    else
    {
        cerr << "Unable to sell pet.\n";
    }
}

// Function to view all pets.
void viewInventory()
{
    ifstream inFile;
    inFile.open("pets.txt");
    if (inFile)
    {
        char pet_type[100];
        char breed[100];
        int age;
        int rate;

        while (inFile.getline(pet_type, 100))
        {
            inFile >> breed >> age >> rate;
            inFile.ignore(); // Ignore the newline character after rate

            cout << "\n\nPet Type: " << pet_type << "\n";
            cout << "Breed: " << breed << "\n";
            cout << "Age: " << age << "\n";
            cout << "Rate: " << rate << "\n";
        }
        inFile.close();
    }
    else
    {
        cerr << "Unable to view inventory.\n";
    }
}

// Function to adopt a pet
void deletePets()
{
    char nameToDelete[100];
    cout << "Enter the Pet to adopt: ";
    cin.ignore(); // Clear the input buffer
    cin.getline(nameToDelete, 100);

    ifstream inFile;
    ofstream tempFile;
    inFile.open("pets.txt");
    tempFile.open("temp.txt");

    bool found = false;

    if (inFile && tempFile)
    {
        char pet_type[100];
        char breed[100];
        int age;
        int rate;

        while (inFile.getline(pet_type, 100))
        {
            inFile >> breed >> age >> rate;
            inFile.ignore(); // Ignore the newline character after rate

            if (strcmp(pet_type, nameToDelete) != 0)
            {
                tempFile << pet_type << "\n"
                         << breed << "\n"
                         << age << "\n"
                         << rate << "\n";
            }
            else
            {
                found = true;
            }
        }

        inFile.close();
        tempFile.close();

        remove("pets.txt");
        rename("temp.txt", "pets.txt");

        if (found)
        {
            cout << "Yayy!!\n You've Adopted Your PETTTT!!\n";
        }
        else
        {
            cout << "Pet not found.\n";
        }
    }
    else
    {
        cerr << "Unable to open file.\n";
    }
}

// Main function
int main()
{
    int choice;
    do
    {
        cout << "\nPet Shop\n";
        cout << "1. Sell Pets\n";
        cout << "2. Adopt Pets\n";
        cout << "3. View Inventory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addPets();
            break;
        case 2:
            deletePets();
            break;
        case 3:
            viewInventory();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}