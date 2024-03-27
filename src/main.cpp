#include "display.h"

int main(){
    // Create size of list of film to sort
    int sizes[] = {10000, 100000, 500000, 1000000};

    for(int n : sizes){
        // Create an array to store movie data
        Movie* movie = new Movie[n];

        // Load movie data from file
        int unrated = Load(movie, n);
        int real_size = n - unrated;

        // Filter out unrated movies
        Movie* rated_movies = Filtration(n, unrated, real_size, movie);

        // Display sorting using introspective sort algorithm
        IntroDisplay(n, unrated, real_size, rated_movies);

        // Display sorting using quicksort algorithm
        QuickDisplay(n, unrated, real_size, rated_movies);

        // Display sorting using mergesort algorithm
        MergeDisplay(n, unrated, real_size, rated_movies);

        delete[] rated_movies;  // Free memory allocated for rated_movies array
    }
    
    return 0;
}
