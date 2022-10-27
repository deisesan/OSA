#ifndef NETFLIX_H
#define NETFLIX_H

#include "biblioteca.h"

class Netflix
{
private:
    string show_id;
    string type;
    string title;
    string director;
    string cast;
    string country;
    string date_added;
    string release_year;
    string rating;
    string duration;
    string listed_in;
    string description;

public:
    // Constructor
    Netflix();

    // Getters
    string getShowId();
    string getType();
    string getTitle();
    string getDirector();
    string getCast();
    string getCountry();
    string getDateAdded();
    string getReleaseYear();
    string getRating();
    string getDuration();
    string getListedIn();
    string getDescription();

    // Setters
    void setShowId(string show_id);
    void setType(string type);
    void setTitle(string title);
    void setDirector(string director);
    void setCast(string cast);
    void setCountry(string country);
    void setDateAdded(string date_added);
    void setReleaseYear(string release_year);
    void setRating(string rating);
    void setDuration(string duration);
    void setListedIn(string listed_in);
    void setDescription(string description);

    void split(string line);
    void clear();
    void print();
    int size();

    // Destructor
    ~Netflix();
};

#endif // NETFLIX_H