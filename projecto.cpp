#include <bits/stdc++.h>
using namespace std;

// FoodItem class
class FoodItem {
private:
    string name;
    vector<pair<string, float>> ingredients; // Ingredient name and percentage
    bool isHealthy;

public:
    FoodItem(string name, vector<pair<string, float>> ingredients, bool isHealthy)
        : name(name), ingredients(ingredients), isHealthy(isHealthy) {}

    string getName() const {
        return name;
    }

    void displayDetails() const {
        cout << "\nFood Name: " << name << endl;
        cout << "Ingredients (with percentages):" << endl;
        for (auto &ingredient : ingredients) {
            cout << "- " << ingredient.first << ": " << ingredient.second << "%" << endl;
        }
        cout << "Health Status: " << (isHealthy ? "Healthy" : "Unhealthy") << endl;
    }
};

// FoodCategory class
class FoodCategory {
private:
    string categoryName;
    vector<FoodItem> items;

public:
    FoodCategory(string name) : categoryName(name) {}

    void addFoodItem(const FoodItem &item) {
        items.push_back(item);
    }

    void displayItems() const {
        cout << "\nCategory: " << categoryName << endl;
        for (size_t i = 0; i < items.size(); i++) {
            cout << i + 1 << ". " << items[i].getName() << endl;
        }
    }

    FoodItem getItem(int index) const {
        return items[index];
    }

    string getCategoryName() const {
        return categoryName;
    }

    size_t getItemsCount() const {
        return items.size();
    }
};

// Function to load food categories from files
vector<FoodCategory> loadCategories(const vector<string> &fileNames) {
    vector<FoodCategory> categories;

    for (const string &fileName : fileNames) {
        ifstream file(fileName);
        if (!file.is_open()) {
            cerr << "Error opening file: " << fileName << endl;
            continue;
        }

        string categoryName;
        getline(file, categoryName);
        FoodCategory category(categoryName);

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string foodName, ingredient, healthStatus;
            vector<pair<string, float>> ingredients;
            float percentage;
            bool isHealthy;

            getline(ss, foodName, '|');
            while (getline(ss, ingredient, ':')) {
                ss >> percentage;
                ss.ignore(); // Ignore ',' or whitespace
                ingredients.push_back({ingredient, percentage});
            }
            getline(ss, healthStatus, '|');
            isHealthy = (healthStatus == "Healthy");

            category.addFoodItem(FoodItem(foodName, ingredients, isHealthy));
        }

        categories.push_back(category);
        file.close();
    }

    return categories;
}

int main() {
    vector<string> fileNames = {
        "snacks.txt", "chocolates.txt", "meals.txt", "pickles.txt", "ice_cream.txt"
    };

    vector<FoodCategory> categories = loadCategories(fileNames);

    if (categories.empty()) {
        cout << "No categories loaded. Please check the data files.\n";
        return 0;
    }

    // Main menu
    cout << "Welcome to Food Ingredients Checker!\n";
    cout << "Select a Food Category:\n";

    for (size_t i = 0; i < categories.size(); i++) {
        cout << i + 1 << ". " << categories[i].getCategoryName() << endl;
    }

    int categoryChoice;
    cin >> categoryChoice;

    if (categoryChoice < 1 || categoryChoice > categories.size()) {
        cout << "Invalid category choice!" << endl;
        return 0;
    }

    // Display food items in the selected category
    FoodCategory selectedCategory = categories[categoryChoice - 1];
    selectedCategory.displayItems();

    cout << "\nSelect a food item by number: ";
    int foodChoice;
    cin >> foodChoice;

    if (foodChoice < 1 || foodChoice > selectedCategory.getItemsCount()) {
        cout << "Invalid food item choice!" << endl;
        return 0;
    }

    // Display details of the selected food item
    FoodItem selectedItem = selectedCategory.getItem(foodChoice - 1);
    selectedItem.displayDetails();

    return 0;
}
