/*
#include "../Lists/DoublyLinkedList.hpp"
#include "../Models/User.hpp"
#include "../Models/Movie.hpp"
#include "../Services/IMovieRegister.hpp"
#include "../Services/IMovieRepository.hpp"
#include "../Services/RegisterMovieInTxt.hpp"
#include "../Services/RepositoryMovieInTxt.hpp"
*/
#include "../Manager/ManagerMovie.hpp"
int main(){
    /*
    std::function<void(Node<User>*)> _showUser = [](Node<User>* value) -> void {  value->getElement().printUser(); std::cout << std::endl;};
    std::function<void(Node<Movie>*)> _showMovie = [](Node<Movie>* value) -> void {  value->getElement().printMovie(); std::cout << std::endl;};
    
    DoublyLinkedList<User> listUser = DoublyLinkedList<User>();
    DoublyLinkedList<Movie> listMovie = DoublyLinkedList<Movie>();

    listUser.push_back(User("1", "123", "Juan", "Perez", "hola1@example.com"));
    listUser.push_back(User("2", "123", "Pedro", "Perez", "hola2@example.com"));
    listUser.push_back(User("3", "123", "Maria", "Perez", "hola3@example.com"));

    listMovie.push_back(Movie("1", "Titanic", "Drama", "3:00", "PG-13"));
    listMovie.push_back(Movie("2", "Avengers", "Action", "2:30", "PG-13"));
    listMovie.push_back(Movie("3", "The Godfather", "Drama", "3:00", "R"));


    listUser.printList(_showUser);
    listMovie.printList(_showMovie);
    */
   /*
    IMovieRegister* movieRegister = new RegisterMovieInTxt();
    IMovieRepository* movieRepository = new RepositoryMovieInTxt();

    movieRegister->registerMovie(Movie("1", "Titanic", "Drama", "3:00", "PG-13"));
    movieRegister->registerMovie(Movie("2", "Avengers", "Action", "2:30", "PG-13"));
    movieRegister->registerMovie(Movie("3", "The Godfather", "Drama", "3:00", "R"));

    DoublyLinkedList<Movie> movies = movieRepository->getAllMovies();

    movies.printList([](Node<Movie>* value) -> void {  value->getElement().printMovie(); std::cout << std::endl;});
    movies.bubleSort([](Movie a, Movie b) -> bool { return a.getName() < b.getName(); });
    movies.printList([](Node<Movie>* value) -> void {  value->getElement().printMovie(); std::cout << std::endl;});
    */

    ManagerMovie* managerMovie = ManagerMovie::getInstance();
    managerMovie->registerMovie(Movie("1", "Titanic", "Drama", "3:00", "PG-13"));
    managerMovie->registerMovie(Movie("2", "Avengers", "Action", "2:30", "PG-13"));
    managerMovie->registerMovie(Movie("3", "The Godfather", "Drama", "3:00", "R"));

    DoublyLinkedList<Movie> movies = managerMovie->getAllMovies();

    movies.printList([](Node<Movie>* value) -> void {  value->getElement().printMovie(); std::cout << std::endl;});
    movies.bubleSort([](Movie a, Movie b) -> bool { return a.getName() < b.getName(); });
    movies.printList([](Node<Movie>* value) -> void {  value->getElement().printMovie(); std::cout << std::endl;});
    return 0;
}