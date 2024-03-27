#pragma once
#include <chrono>

#include "math.h"
#include "intro.h"
#include "merge.h"
#include "file.h"

// Function to filter out unrated movies from the movie array
Movie* Filtration(int size, int unrated, int real_size, Movie* movie){

    std::cout << "------------------------------------------------------------" << std::endl << "Wielkość tablicy: " << size << std::endl << std::endl;
    if(unrated > 0){
        std::cout << "> Filmy bez oceny: " << unrated << '\n' << std::endl;
    }else{
        std::cout << "> Wszystkie filmy są poprawnie ocenione\n" << std::endl;
    }

    Movie* rated_movies = new Movie[real_size];  // Array to store rated movies

    int j = 0, i = 0;

    // Filtering out unrated movies
    auto duration_start = std::chrono::high_resolution_clock::now();  // Start measuring time
    while(j < size){
        if(movie[j].rating != -1){
            rated_movies[i++] = movie[j++];
        }else{
            j++;
        }
    }
    auto duration_end = std::chrono::high_resolution_clock::now();  // End measuring time
    auto duration = std::chrono::duration<double, std::milli>(duration_end - duration_start).count();  // Calculate duration

    // Print information about the filtration process
    if(unrated > 0)
        std::cout << "Po przefiltrowaniu zostało: " << real_size << ". Czas filtracji: " << duration << " ms." << std::endl;

    delete[] movie;  // Free memory allocated for the original movie array

    return rated_movies;  // Return array of rated movies
}

// Function to display sorting using introspective sort algorithm
void IntroDisplay(int size, int unrated, int real_size, Movie* rated_movies){
    Movie* intro_movie = new Movie[real_size];  // Array to store movies for introspective sort

    std::cout << std::endl << "Sortowanie przy użyciu algorytmu sortowania introspectywnego" << std::endl;
    
    // Copy rated movies array for sorting
    for(int i = 0; i < real_size; i++){
        intro_movie[i] = rated_movies[i];
    }

    auto duration_start = std::chrono::high_resolution_clock::now();  // Start measuring time
    HybridIntroSort(intro_movie, 0, size - unrated - 1);  // Perform sorting
    auto duration_end = std::chrono::high_resolution_clock::now();  // End measuring time
    auto duration_intro = std::chrono::duration<double, std::milli>(duration_end - duration_start).count();  // Calculate duration

    // Print sorting duration
    std::cout << "Czas trwania sortowania introspectywnego: " << duration_intro << " ms." << std::endl;

    // Calculate and display average and median ratings
    Average(intro_movie, real_size);
    Median(intro_movie, real_size);

    // Save sorted data to a file
    std::string file_name = "Introsort " + std::to_string(size) + ".csv";
    Save(intro_movie, file_name, real_size);

    delete[] intro_movie;  // Free memory allocated for intro_movie array
}

// Function to display sorting using quicksort algorithm
void QuickDisplay(int size, int unrated, int real_size, Movie* rated_movies){
    Movie* quick_movie = new Movie[real_size];  // Array to store movies for quicksort

    std::cout << std::endl << "Sortowanie przy użyciu algorytmu sortowania quicksort" << std::endl;

    // Copy rated movies array for sorting
    for(int i = 0; i < real_size; i++){
        quick_movie[i] = rated_movies[i];
    }
    
    auto duration_start = std::chrono::high_resolution_clock::now();  // Start measuring time
    Quicksort(quick_movie, 0, size - unrated - 1);  // Perform sorting
    auto duration_end = std::chrono::high_resolution_clock::now();  // End measuring time
    auto duration_quick = std::chrono::duration<double, std::milli>(duration_end - duration_start).count();  // Calculate duration

    // Print sorting duration
    std::cout << "Czas trwania sortowania quicksort: " << duration_quick << " ms." << std::endl;

    // Calculate and display average and median ratings
    Average(quick_movie, real_size);
    Median(quick_movie, real_size);

    // Save sorted data to a file
    std::string file_name = "Quicksort " + std::to_string(size) + ".csv";
    Save(quick_movie, file_name, real_size);

    delete[] quick_movie;  // Free memory allocated for quick_movie array
}

// Function to display sorting using mergesort algorithm
void MergeDisplay(int size, int unrated, int real_size, Movie* rated_movies){
    Movie* merge_movie = new Movie[real_size];  // Array to store movies for mergesort

    std::cout << std::endl << "Sortowanie przy użyciu algorytmu sortowania przez scalanie" << std::endl;

    // Copy rated movies array
}