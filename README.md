# Pong Game

## Description

This is a simple implementation of the classic Pong game using OpenGL and GLUT. The game features two paddles and a ball that bounces around the screen. Players can control the paddles using the keyboard to keep the ball in play and try to score against their opponent.

## Features

- Two paddles controlled by the keyboard.
- A ball that bounces off the paddles and the edges of the screen.
- Scoring system that resets the ball position when a point is scored.
- Simple graphics with a black background, white paddles, and a red ball.

  ## Screenshot
![Game Screenshot](screenshot.png)

## Installation

1. **Prerequisites:**
   - Make sure you have OpenGL and GLUT installed on your system.
   - You may need to install development
2. **Compiling the Code:**
   - Save the provided code into a file named `pong.cpp`.
   - Open a terminal and navigate to the directory where `pong.cpp` is located.
   - Compile the code using the following command:

     ```sh
     g++ pong.cpp -o pong -lGL -lGLU -lglut
     ```

3. **Running the Game:**
   - Run the compiled program with the following command:

     ```sh
     ./pong
     ```

## Controls

- **Player 1 (Left Paddle):**
  - Move up: `Right Arrow Key`
  - Move down: `Left Arrow Key`

- **Player 2 (Right Paddle):**
  - Move up: `Up Arrow Key`
  - Move down: `Down Arrow Key`

