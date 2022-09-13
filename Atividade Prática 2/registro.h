#ifndef REGISTRO_H
#define REGISTRO_H

#include "biblioteca.h"

class Registro
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
    Registro();

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

    // Destructor
    ~Registro();
};

#endif // REGISTRO_H