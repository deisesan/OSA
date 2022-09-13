#include "registro.h"

// Construct
Registro::Registro()
{
}

// Getters
string Registro::getShowId()
{
    return show_id;
}

string Registro::getType()
{
    return type;
}

string Registro::getTitle()
{
    return title;
}

string Registro::getDirector()
{
    return director;
}

string Registro::getCast()
{
    return cast;
}

string Registro::getCountry()
{
    return country;
}

string Registro::getDateAdded()
{
    return date_added;
}

string Registro::getReleaseYear()
{
    return release_year;
}

string Registro::getRating()
{
    return rating;
}

string Registro::getDuration()
{
    return duration;
}

string Registro::getListedIn()
{
    return listed_in;
}

string Registro::getDescription()
{
    return description;
}

// Setters
void Registro::setShowId(string show_id)
{
    this->show_id = show_id;
}

void Registro::setType(string type)
{
    this->type = type;
}

void Registro::setTitle(string title)
{
    this->title = title;
}

void Registro::setDirector(string director)
{
    this->director = director;
}

void Registro::setCast(string cast)
{
    this->cast = cast;
}

void Registro::setCountry(string country)
{
    this->country = country;
}

void Registro::setDateAdded(string date_added)
{
    this->date_added = date_added;
}

void Registro::setReleaseYear(string release_year)
{
    this->release_year = release_year;
}

void Registro::setRating(string rating)
{
    this->rating = rating;
}

void Registro::setDuration(string duration)
{
    this->duration = duration;
}

void Registro::setListedIn(string listed_in)
{
    this->listed_in = listed_in;
}

void Registro::setDescription(string description)
{
    this->description = description;
}

//  Destructor
Registro::~Registro()
{
}