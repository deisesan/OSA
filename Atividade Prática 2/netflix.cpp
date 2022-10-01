#include "netflix.h"

// Construct
Netflix::Netflix()
{
}

// Getters
string Netflix::getShowId()
{
    return show_id;
}

string Netflix::getType()
{
    return type;
}

string Netflix::getTitle()
{
    return title;
}

string Netflix::getDirector()
{
    return director;
}

string Netflix::getCast()
{
    return cast;
}

string Netflix::getCountry()
{
    return country;
}

string Netflix::getDateAdded()
{
    return date_added;
}

string Netflix::getReleaseYear()
{
    return release_year;
}

string Netflix::getRating()
{
    return rating;
}

string Netflix::getDuration()
{
    return duration;
}

string Netflix::getListedIn()
{
    return listed_in;
}

string Netflix::getDescription()
{
    return description;
}

// Setters
void Netflix::setShowId(string show_id)
{
    this->show_id = show_id;
}

void Netflix::setType(string type)
{
    this->type = type;
}

void Netflix::setTitle(string title)
{
    this->title = title;
}

void Netflix::setDirector(string director)
{
    this->director = director;
}

void Netflix::setCast(string cast)
{
    this->cast = cast;
}

void Netflix::setCountry(string country)
{
    this->country = country;
}

void Netflix::setDateAdded(string date_added)
{
    this->date_added = date_added;
}

void Netflix::setReleaseYear(string release_year)
{
    this->release_year = release_year;
}

void Netflix::setRating(string rating)
{
    this->rating = rating;
}

void Netflix::setDuration(string duration)
{
    this->duration = duration;
}

void Netflix::setListedIn(string listed_in)
{
    this->listed_in = listed_in;
}

void Netflix::setDescription(string description)
{
    this->description = description;
}


void Netflix::split(string line)
{
    int i = 0;
    if (line != "")
    {
        while (line[i] != ';')
        {
            show_id += line[i];
            i++;
        }
        i++;

        while (line[i] != ';')
        {
            type += line[i];
            i++;
        }
        i++;

        while (line[i] != ';')
        {
            title += line[i];
            i++;
        }
        i++;

        while (line[i] != ';')
        {
            director += line[i];
            i++;
        }
        i++;

        while (line[i] != ';')
        {
            cast += line[i];
            i++;
        }
        i++;

        while (line[i] != ';')
        {
            country += line[i];
            i++;
        }
        i++;

        while (line[i] != ';')
        {
            date_added += line[i];
            i++;
        }
        i++;

        while (line[i] != ';')
        {
            release_year += line[i];
            i++;
        }
        i++;

        while (line[i] != ';')
        {
            rating += line[i];
            i++;
        }
        i++;

        while (line[i] != ';')
        {
            duration += line[i];
            i++;
        }
        i++;

        while (line[i] != ';')
        {
            listed_in += line[i];
            i++;
        }
        i++;

        while (line[i] != '\0')
        {
            description += line[i];
            i++;
        }
    }
}

void Netflix::clear()
{
    show_id.clear();
    type.clear();
    title.clear();
    director.clear();
    cast.clear();
    country.clear();
    date_added.clear();
    release_year.clear();
    rating.clear();
    duration.clear();
    listed_in.clear();
    description.clear();
}

void Netflix::print()
{
    cout 
        << show_id << "|"
        << type << "|"
        << title << "|"
        << director << "|"
        << cast << "|"
        << country << "|"
        << date_added << "|"
        << release_year << "|"
        << rating << "|"
        << duration << "|"
        << listed_in << "|"
        << description << endl;
}

int Netflix::size()
{
    int tam = 0;
    string delimitador = "|";

    tam = show_id.size() +
          type.size() +
          title.size() +
          director.size() +
          cast.size() +
          country.size() +
          date_added.size() +
          release_year.size() +
          rating.size() +
          duration.size() +
          listed_in.size() +
          description.size() +
          (delimitador.size() * 11);

    return tam;
}

//  Destructor
Netflix::~Netflix()
{
}