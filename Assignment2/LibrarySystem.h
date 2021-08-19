#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H
#include <string>

using namespace std;

class LibrarySystem
{
    struct NodeFirst* startUser;
    struct NodeSecond* startChecked;
    struct NodeThird* startNonChecked;
    
public:
    LibrarySystem();
    ~LibrarySystem();
    
    void addMovie( const int movielId, const string movieTitle, const int year );
    void deleteMovie( const int movield );

    void addUser( const int userId, const string userName );
    void deleteUser( const int userId );

    void checkoutMovie( const int movieId, const int userId );
    void returnMovie( const int movield );

    void showAllMovies();
    void showMovie( const int movield );
    void showUser( const int userId );
    
    bool foundUser( const int userId );
    bool foundNonCheckedMovie( const int userId );
    bool foundCheckedMovie( const int userId );
    NodeThird* deleteNonCheckedMovie( const int movieId );
    NodeSecond* deleteCheckedMovie( const int movieId );
    void checkedMovies( const int userId );
    void returnCheckedMovie( const int movieId );

};

#endif // LIBRARYSYSTEM_H