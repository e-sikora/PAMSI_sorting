#pragma once
#include <iostream>

// Structure representing a movie with a name and a rating
struct Movie {
    std::string name;   // Name of the movie
    short rating;       // Rating of the movie

    // Overloaded less than operator for comparing movies based on rating
    bool operator<(Movie compared) { return (rating < compared.rating); }

    // Overloaded greater than operator for comparing movies based on rating
    bool operator>(Movie compared) { return (rating > compared.rating); }
};