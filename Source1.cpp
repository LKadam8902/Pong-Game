#include <GL/glut.h>

// Define constants for the game
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int PADDLE_WIDTH = 10;
const int PADDLE_HEIGHT = 50;
const int BALL_RADIUS = 5;

// Define variables for the game
float ballX = SCREEN_WIDTH / 2;
float ballY = SCREEN_HEIGHT / 2;
float ballDX = 2;
float ballDY = 2;
float paddle1Y = SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2;
float paddle2Y = SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2;

// Draw the game board and paddles
void drawBoard() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the paddles
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    glBegin(GL_QUADS);
    glVertex2f(0, paddle1Y);
    glVertex2f(PADDLE_WIDTH, paddle1Y);
    glVertex2f(PADDLE_WIDTH, paddle1Y + PADDLE_HEIGHT);
    glVertex2f(0, paddle1Y + PADDLE_HEIGHT);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(SCREEN_WIDTH - PADDLE_WIDTH, paddle2Y);
    glVertex2f(SCREEN_WIDTH, paddle2Y);
    glVertex2f(SCREEN_WIDTH, paddle2Y + PADDLE_HEIGHT);
    glVertex2f(SCREEN_WIDTH - PADDLE_WIDTH, paddle2Y + PADDLE_HEIGHT);
    glEnd();

    // Draw the ball
    glColor3f(1.0, 0.0, 0.0); // Set color to red
    glPointSize(10.0); // Set point size

    glBegin(GL_POINTS);
    glVertex3f(ballX, ballY, 0);
    // Add more vertices for additional points
    glEnd();

    glutSwapBuffers();
}

// Set up the game physics and ball movement
void update(int value) {
    // Move the ball
    ballX += ballDX;
    ballY += ballDY;

    // Check for collision with the top or bottom of the screen
    if (ballY + BALL_RADIUS >= SCREEN_HEIGHT || ballY - BALL_RADIUS <= 0) {
        ballDY = -ballDY;
    }

    // Check for collision with the paddles
    if ((ballX - BALL_RADIUS <= PADDLE_WIDTH && ballY >= paddle1Y && ballY <= paddle1Y + PADDLE_HEIGHT) ||
        (ballX + BALL_RADIUS >= SCREEN_WIDTH - PADDLE_WIDTH && ballY >= paddle2Y && ballY <= paddle2Y + PADDLE_HEIGHT)) {
        ballDX = -ballDX;
    }

    // Check for scoring
    if (ballX - BALL_RADIUS <= 0) {
        ballX = SCREEN_WIDTH / 2;
        ballY = SCREEN_HEIGHT / 2;
        ballDX = -ballDX;
    }
    if (ballX + BALL_RADIUS >= SCREEN_WIDTH) {
        ballX = SCREEN_WIDTH / 2;
        ballY = SCREEN_HEIGHT / 2;
        ballDX = -ballDX;
    }

    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

// Set up the keyboard controls for the game
void keyboard(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        paddle2Y += 10;
        if (paddle2Y + PADDLE_HEIGHT > SCREEN_HEIGHT) {
            paddle2Y = SCREEN_HEIGHT - PADDLE_HEIGHT;
        }
        break;
    case GLUT_KEY_DOWN:
        paddle2Y -= 10;
        if (paddle2Y < 0) {
            paddle2Y = 0;
        }
        break;
    case GLUT_KEY_RIGHT:
        paddle1Y += 10;
        if (paddle1Y + PADDLE_HEIGHT > SCREEN_HEIGHT) {
            paddle1Y = SCREEN_HEIGHT - PADDLE_HEIGHT;
        }
        break;
    case GLUT_KEY_LEFT:
        paddle1Y -= 10;
        if (paddle1Y < 0) {
            paddle1Y = 0;
        }
        break;
    }
}

// Set up the main function and game window
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("Pong Game"); glutDisplayFunc(drawBoard);
    glutSpecialFunc(keyboard);
    glutTimerFunc(10, update, 0);

    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT); // Set up 2D orthographic viewing

    glutMainLoop();
    return 0;
}

