cmake_minimum_required(VERSION 3.13)
project(blackJack)

set(CMAKE_CXX_STANDARD 14)

add_executable(blackJack Main.cpp Player.cpp Player.h HumanPlayer.cpp HumanPlayer.h Deck.cpp Deck.h Game.h Game.cpp Dealer.cpp Dealer.h CustomDealer.cpp CustomDealer.h InputMenu.cpp InputMenu.h Wallet.cpp Wallet.h GameMenu.cpp GameMenu.h)
