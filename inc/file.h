#pragma once
#include <string>
#include <fstream>
#include <filesystem>

// Function to load movie data from a file and store it in an array of Movie objects
template<typename T>
int Load(T* movies, int n){

    std::ifstream film_list;  // Input file stream object for reading data from file
    std::string line, temp, folder = "../files/";  // Strings to store lines from the file and folder path
    char identifier;  // Character to identify special characters like quotes
    int unrated = 0;  // Counter for unrated movies

    // Open the file containing movie data
    film_list.open(folder + "filmy.csv");

    // Check if the file is opened successfully
    if (film_list.is_open()) {
        std::cout << "Plik poprawnie otwarty" << std::endl;  // Success message
    } else {
        std::cout << "Nie ma poprawnego pliku" << std::endl;  // Error message
    }

    std::getline(film_list, line);  // Skip header line
    for (unsigned int i = 0; i < n; i++) {
        // Format of the file: index,name,rating
        std::getline(film_list, line);  // Read a line from the file
        std::stringstream split(line);  // Create a string stream to split the line

        // Read index and comma
        std::getline(split, temp, ',');
        
        // Read movie name - either enclosed in quotes or plain separated by comma
        std::stringstream::pos_type position = split.tellg();
        split >> identifier;
        if (identifier == '"') {
            std::getline(split, movies[i].name, '"');  // Read until closing quote
            split >> identifier;  // Ignore comma
        } else {
            split.seekg(position);  // Go back to the beginning of the name
            std::getline(split, movies[i].name, ',');  // Read until comma
        }
        
        // Read movie rating
        if (!(split >> movies[i].rating)) {  // Check if rating is successfully read
            unrated++;  // Increment unrated counter
            movies[i].rating = -1;  // Set rating to -1 to indicate unrated
        }
    }
    film_list.close();  // Close the file

    return unrated;  // Return the number of unrated movies
}

// Function to save movie data to a file
template<typename T>
void Save(T* movies, std::string name, int size){
    std::string folder = "../files/";  // Folder path
    std::ofstream sorted_list;  // Output file stream object for writing data to file
    std::filesystem::create_directories(folder);  // Create directory if it doesn't exist
    sorted_list.open(folder + name);  // Open file for writing

    if (sorted_list.is_open()) {
        sorted_list << ",movie,rating\n";  // Write header
        for (int i = 0; i < size; ++i) {
            // Write index, movie name, and rating separated by commas
            sorted_list << i << ",\"" << movies[i].name << "\"," << movies[i].rating << "\n";
        }
        sorted_list.close();  // Close the file
    } else {
        std::cout << "Nie można zapisać \n";  // Error message if file cannot be opened
    }
}
