#include "Game.cpp"
#include <chrono>
#include <thread>

int main() {
    char c;
    Game* game = new Game (10 );
    std::thread gameloop(&Game::mainLoop, &game);
    while (1){
        std::cin >> c;
        game->snake.changeDir(c);
        if (c == 'p') {
            printf("\nxD\n");
            game->endGame();
            gameloop.join();
            break;
        }
    }
}
void Game::mainLoop(){
    while(gameRuning){
            snake.clearBoard(BOARD);
            snake.move(BOARD);
            food.fPlace(BOARD);
            snake.placePieces(BOARD);
            system("stty cooked");
            showBoard();
            system("stty raw");
            std::this_thread::sleep_for(std::chrono::milliseconds(144));
        }
}