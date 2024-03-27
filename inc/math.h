#pragma once
#include "movie.h"

// Function to calculate the average rating of movies
void Average(Movie* movies, int size){
    float average = 0;  // Variable to store the sum of ratings
    for(int i = 0; i < size; i++){
        average += movies[i].rating;  // Adding up ratings
    }
    average /= size;  // Calculating the average by dividing the sum by the number of movies

    std::cout << "Średnia ocen: " << average << std::endl;  // Output the average rating
}

// Function to calculate the median rating of movies
void Median(Movie* movies, int size){
    int median;  // Variable to store the median rating
    if(size % 2 != 0){  // If the number of movies is odd
        median = movies[size / 2].rating;  // Median is the rating of the middle movie
    }else{  // If the number of movies is even
        median = (movies[(size - 1) / 2].rating + movies[size / 2].rating) / 2;  // Median is the average of two middle ratings
    }

    std::cout << "Mediana ocen: " << median << std::endl;  // Output the median rating
}