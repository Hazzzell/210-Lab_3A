#include <iostream>
#include <fstream>
using namespace std;

struct Restaurant {
    string name;
    string address;
    string dishes;
    double rating; // 1 to 10
    int yearOpening;
};

Restaurant populateRestaurant();
void outputRestaurant(const Restaurant &);

int main() {
    //demonstrate with a single struct using console input
    Restaurant myRestaurant = populateRestaurant();
    cout << "\nOutputting single Restaurant in single struct:\n";
    outputRestaurant(myRestaurant);
    cout << endl << endl;

    //demonstrate with multiple structs using file input
    Restaurant RestaurantCollection[3];
    ifstream infile("restaurant.txt");
    string in_name, in_address, in_dishes;
    double in_rating;
    int in_year;
    int index = 0;

    while (infile >> in_rating >> in_year) {
        infile.ignore(); //clear line
        getline(infile, in_name);
        getline(infile, in_address);
        getline(infile, in_dishes);

        Restaurant temp;
        temp.name = in_name;
        temp.address = in_address;
        temp.dishes = in_dishes;
        temp.rating = in_rating;
        temp.yearOpening = in_year;

        //store the temp struct into the array
        RestaurantCollection[index++] = temp;
    }

    //output array of restaurants
    cout << "Outputting array of restaurants:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Restaurant #" << i + 1 << ":\n";
        outputRestaurant(RestaurantCollection[i]);
    }

    infile.close();

    return 0;
}

Restaurant populateRestaurant() {
    Restaurant temp;
    cout << "Enter Restaurant Name: ";
    getline(cin, temp.name);
    cout << "Enter Restaurant Address: ";
    getline(cin, temp.address);
    cout << "Enter Dishes: ";
    getline(cin, temp.dishes);
    cout << "Rating(1 to 10): ";
    cin >> temp.rating;
    cout << "Enter Years Opening: ";
    cin >> temp.yearOpening;
    return temp;
}

void outputRestaurant(const Restaurant&c) {
    cout << "\t> Name: " << c.name << endl;
    cout << "\t> Address: " << c.address << endl;
    cout << "\t> Dishes: " << c.dishes << endl;
    cout << "\t> Rating: " << c.rating << endl;
    cout << "\t> YearOpening: " << c.yearOpening << endl << endl;
}