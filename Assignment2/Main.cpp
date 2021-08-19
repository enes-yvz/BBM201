#include <fstream>
#include <iostream>
#include "LibrarySystem.h"

using namespace std;

int main(int argc, char **argv) {
    
    freopen(argv[2], "w", stdout);
    
    ifstream inFile;
    
    inFile.open(argv[1]);
    
    string lineFirst;
    
    string lineSecond;
    
    LibrarySystem librarySystem;
    
    cout << "===Movie Library System===" << endl;
    
    while (!inFile.eof()) {
        
        inFile >> lineFirst;
        
        if(lineFirst.find("addUser")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===addUser() method test===" << endl;
            }
            
            int userId;
            
            inFile >> userId;
            
            string userName ;
            
            inFile >> userName;
            
            string userSurname;
            
            inFile >> userSurname;
            
            librarySystem.addUser(userId,userName+" "+userSurname);
            
        }
        
        else if(lineFirst.find("addMovie")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===addMovie() method test===" << endl;
            }
            
            int movieId;
            
            inFile >> movieId;
            
            string movieTitle;
            
            getline(inFile,movieTitle);
            
            int year = 0;
            
            movieTitle.erase(movieTitle.find_last_not_of(" \n\r\t")+1);
            movieTitle = movieTitle.substr(movieTitle.find_first_not_of(" \n\r\t"),movieTitle.length());
            
            year += (movieTitle[movieTitle.length()-4]- '0') * 1000;
             
            year += (movieTitle[movieTitle.length()-3]- '0') * 100;
            
            year += (movieTitle[movieTitle.length()-2]- '0') * 10;
            
            year += (movieTitle[movieTitle.length()-1]- '0');
            
            movieTitle.erase(movieTitle.length()-5,movieTitle.length());
            
            librarySystem.addMovie(movieId,movieTitle,year);          
        }
        
        else if(lineFirst.find("showAllMovie")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===showAllMovie() method test===" << endl;
            }
            
            librarySystem.showAllMovies();
            
        }
        
        else if(lineFirst.find("checkoutMovie")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===checkoutMovie() method test===" << endl;
            }
            
            int movieId;
            
            inFile >> movieId;
            
            int userId;
            
            inFile >> userId;
            
            librarySystem.checkoutMovie(movieId,userId);
            
        }
        
        else if(lineFirst.find("showMovie")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===showMovie() method test===" << endl;
            }
   
            int movieId;
            
            inFile >> movieId;
         
            librarySystem.showMovie(movieId);
            
            
        }
        
        else if(lineFirst.find("showUser")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===showUser() method test===" << endl;
            }
            
            int userId;
            
            inFile >> userId;
         
            librarySystem.showUser(userId);
            
            
        }
        
        else if(lineFirst.find("deleteMovie")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===deleteMovie() method test===" << endl;
            }
            
            int movieId;
            
            inFile >> movieId;
         
            librarySystem.deleteMovie(movieId);
            
            
        }
        
        else if(lineFirst.find("returnMovie")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===returnMovie() method test===" << endl;
            }
            
            int movieId;
            
            inFile >> movieId;
            
            librarySystem.returnMovie(movieId);
            
            
        }
        
        else if(lineFirst.find("deleteUser")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===deleteUser() method test===" << endl;
            }

            int userId;
            
            inFile >> userId;
         
            librarySystem.deleteUser(userId);           
            
        }
        
        if (inFile.eof()) {
            
            break;
        }
        
        inFile >> lineSecond;
        
        if(lineSecond.find("addUser")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===addUser() method test===" << endl;
            }
            
            int userId;
            
            inFile >> userId;
            
            string userName ;
            
            inFile >> userName;
            
            string userSurname;
            
            inFile >> userSurname;
            
            librarySystem.addUser(userId,userName+" "+userSurname);
        }
        
        else if(lineSecond.find("addMovie")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===addMovie() method test===" << endl;
            }
            
            int movieId;
            
            inFile >> movieId;
            
            string movieTitle;
            
            getline(inFile,movieTitle);
            
            int year = 0 ;
            
            movieTitle.erase(movieTitle.find_last_not_of(" \n\r\t")+1);
            movieTitle = movieTitle.substr(movieTitle.find_first_not_of(" \n\r\t"),movieTitle.length());
            
            year += (movieTitle[movieTitle.length()-4]- '0') * 1000;
             
            year += (movieTitle[movieTitle.length()-3]- '0') * 100;
            
            year += (movieTitle[movieTitle.length()-2]- '0') * 10;
            
            year += (movieTitle[movieTitle.length()-1]- '0');
            
            movieTitle.erase(movieTitle.length()-5,movieTitle.length());
            
            librarySystem.addMovie(movieId,movieTitle,year);          
        }
        
        else if(lineSecond.find("showAllMovie")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===showAllMovie() method test===" << endl;
            }
            
            librarySystem.showAllMovies();
            
        }
        
        else if(lineSecond.find("checkoutMovie")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===checkoutMovie() method test===" << endl;
            }
            
            int movieId;
            
            inFile >> movieId;
            
            int userId;
            
            inFile >> userId;
            
            librarySystem.checkoutMovie(movieId,userId);
            
        }
        
        else if(lineSecond.find("showMovie")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===showMovie() method test===" << endl;
            }
   
            int movieId;
            
            inFile >> movieId;
         
            librarySystem.showMovie(movieId);
            
            
        }
        
        else if(lineSecond.find("showUser")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===showUser() method test===" << endl;
            }
            
            int userId;
            
            inFile >> userId;
         
            librarySystem.showUser(userId);
            
            
        }
        
        else if(lineSecond.find("deleteMovie")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===deleteMovie() method test===" << endl;
            }
            
            int movieId;
            
            inFile >> movieId;
         
            librarySystem.deleteMovie(movieId);
            
            
        }
        
        else if(lineSecond.find("returnMovie")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===returnMovie() method test===" << endl;
            }
            
            int movieId;
            
            inFile >> movieId;
            
            librarySystem.returnMovie(movieId);
            
            
        }
        
        else if(lineSecond.find("deleteUser")!=string::npos) {
            
            if (lineFirst!=lineSecond) {
                
                cout << "\n";
                
                cout << "===deleteUser() method test===" << endl;
            }

            int userId;
            
            inFile >> userId;
         
            librarySystem.deleteUser(userId);           
            
        }
    }
    
    return 0;
}
