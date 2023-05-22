# Rock paper and scissors with WinUI3

![Main View](Screenshots/main.png)

# Description
The Rock, Paper, Scissors game is a classic two-player game where players choose one of three symbols: rock, paper or scissors to find out who is the winner of the round. The game was written in C# using the WinUI3 framework which provides a Windows user interface.

# Project aim
The aim of the project is to write a game rock paper scissors in C# using a modern WinUI 3 interface for Windows. At the beginning, the goal was to write an application in C++, but this WinUI 3 is not yet adapted to this language, so the best decision was to switch to C#.

# Game rules
1. Two-player game: Player 1 (You) and Player 2 (CPU).

2. Both players simultaneously make a move, choosing one of three elements: rock, paper or scissors.

3. A stone defeats scissors because it blunts them. Scissors beat paper because they cut it. Paper beats stone because it wraps around it.

4. If both players choose the same item, it is a tie and the game is repeated.

5. The winner gets one point and the loser gets no point.

#
The program includes variables to track players' performance and choices. The updatePhotos feature updates the hand images in the UI based on player choices. The Win function checks who won the round and sets the appropriate score. The Game function manages the main game logic by selecting player and computer movement and calling the updatePhotos and Win functions to update the interface and scores. There are also functions that handle clicks on the "Rock", "Paper", "Scissors" and "Reset" buttons, which invoke the Game function or reset the game state.

# Application diagram 
![Diagram!](/Screenshots/diagram.png)

# Application requirements
* The application should be compatible with the operating system Windows 10 or later.

* Support both 32-bit and 64-bit OS.

* Support for mouse, keyboard and touch screens.

    Support for gestures on touch screens.

# 

# Sourses
**Microsoft WinUI3 documentation:** https://learn.microsoft.com/en-us/windows/apps/winui/winui3/

**Random function:** https://www.tutorialsteacher.com/articles/generate-random-numbers-in-csharp

**User interface** https://apps.microsoft.com/store/detail/winui-3-gallery/9P3JFPWWDZRC

# Screenshots
## Light mode
![light mode](/Screenshots/main.png)
## Dark mode
![light mode](/Screenshots/main_dark.png)

# Author
**Name:** Mateusz Szelec

**Class:** 2AP

**Nick:** ITAM

**E-Mail:** szelec.mateusz@zs4.tychy.edu.pl
