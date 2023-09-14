int x = 0;
int y = 0;
int orient = 0;
int cell = 0;

int cells[14][14] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,}
};

int flood[14][14] = {
    {12,11,10,9,8,7,6,6,7,8,9,10,11,12},
    {11,10,9,8,7,6,5,5,6,7,8,9,10,11},
    {10,9,8,7,6,5,4,4,5,6,7,8,9,10},
    {9,8,7,6,5,4,3,3,4,5,6,7,8,9},
    {8,7,6,5,4,3,2,2,3,4,5,6,7,8},
    {7,6,5,4,3,2,1,1,2,3,4,5,6,7},
    {6,5,4,3,2,1,0,0,1,2,3,4,5,6},
    {6,5,4,3,2,1,0,0,1,2,3,4,5,6},
    {7,6,5,4,3,2,1,1,2,3,4,5,6,7},
    {8,7,6,5,4,3,2,2,3,4,5,6,7,8},
    {9,8,7,6,5,4,3,3,4,5,6,7,8,9},
    {10,9,8,7,6,5,4,4,5,6,7,8,9,10},
    {11,10,9,8,7,6,5,5,6,7,8,9,10,11},
    {12,11,10,9,8,7,6,6,7,8,9,10,11,12}
};

int flood2[14][14] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,}
};

// Define a queue
int queue[200]; // Adjust the size as needed

int orientation(int orient, char turning) {
    if (turning == 'L') {
        orient--;
        if (orient == -1) {
            orient = 3;
        }
    } else if (turning == 'R') {
        orient++;
        if (orient == 4) {
            orient = 0;
        }
    } else if (turning == 'B') {
        if (orient == 0) {
            orient = 2;
        } else if (orient == 1) {
            orient = 3;
        } else if (orient == 2) {
            orient = 0;
        } else if (orient == 3) {
            orient = 1;
        }
    }

    return orient;
}

void updateCoordinates(int &x, int &y, int orient) {
    if (orient == 0) {
        y++;
    } else if (orient == 1) {
        x++;
    } else if (orient == 2) {
        y--;
    } else if (orient == 3) {
        x--;
    }
}

void log(String string) {
    Serial.println(string);
}

void updateWalls(int x, int y, int orient, bool L, bool R, bool F) {
    if (L && R && F) {
        if (orient == 0) {
            cells[y][x] = 13;
        } else if (orient == 1) {
            cells[y][x] = 12;
        } else if (orient == 2) {
            cells[y][x] = 11;
        } else if (orient == 3) {
            cells[y][x] = 14;
        }
    } else if (L && R && !F) {
        if (orient == 0 || orient == 2) {
            cells[y][x] = 9;
        } else if (orient == 1 || orient == 3) {
            cells[y][x] = 10;
        }
    } else if (L && F && !R) {
        if (orient == 0) {
            cells[y][x] = 8;
        } else if (orient == 1) {
            cells[y][x] = 7;
        } else if (orient == 2) {
            cells[y][x] = 6;
        } else if (orient == 3) {
            cells[y][x] = 5;
        }
    } else if (R && F && !L) {
        if (orient == 0) {
            cells[y][x] = 7;
        } else if (orient == 1) {
            cells[y][x] = 6;
        } else if (orient == 2) {
            cells[y][x] = 5;
        } else if (orient == 3) {
            cells[y][x] = 8;
        }
    } else if (F) {
        if (orient == 0) {
            cells[y][x] = 2;
        } else if (orient == 1) {
            cells[y][x] = 3;
        } else if (orient == 2) {
            cells[y][x] = 4;
        } else if (orient == 3) {
            cells[y][x] = 1;
        }
    } else if (L) {
        if (orient == 0) {
            cells[y][x] = 1;
        } else if (orient == 1) {
            cells[y][x] = 2;
        } else if (orient == 2) {
            cells[y][x] = 3;
        } else if (orient == 3) {
            cells[y][x] = 4;
        }
    } else if (R) {
        if (orient == 0) {
            cells[y][x] = 3;
        } else if (orient == 1) {
            cells[y][x] = 4;
        } else if (orient == 2) {
            cells[y][x] = 1;
        } else if (orient == 3) {
            cells[y][x] = 2;
        }
    } else {
        cells[y][x] = 15;
    }
}

bool isAccessible(int x, int y, int x1, int y1) {
    if (x == x1) {
        if (y > y1) {
            if (cells[y][x] == 4 || cells[y][x] == 5 || cells[y][x] == 6 || cells[y][x] == 10 || cells[y][x] == 11 || cells[y][x] == 12 || cells[y][x] == 14 || cells[y1][x1] == 2 || cells[y1][x1] == 7 || cells[y1][x1] == 8 || cells[y1][x1] == 10 || cells[y1][x1] == 12 || cells[y1][x1] == 13 || cells[y1][x1] == 14) {
                return false;
            } else {
                return true;
            }
        } else {
            if (cells[y][x] == 2 || cells[y][x] == 7 || cells[y][x] == 8 || cells[y][x] == 10 || cells[y][x] == 12 || cells[y][x] == 13 || cells[y][x] == 14 || cells[y1][x1] == 4 || cells[y1][x1] == 5 || cells[y1][x1] == 6 || cells[y1][x1] == 10 || cells[y1][x1] == 11 || cells[y1][x1] == 12 || cells[y1][x1] == 14) {
                return false;
            } else {
                return true;
            }
        }
    } else if (y == y1) {
        if (x > x1) {
            if (cells[y][x] == 1 || cells[y][x] == 5 || cells[y][x] == 8 || cells[y][x] == 9 || cells[y][x] == 11 || cells[y][x] == 13 || cells[y][x] == 14 || cells[y1][x1] == 3 || cells[y1][x1] == 6 || cells[y1][x1] == 7 || cells[y1][x1] == 9 || cells[y1][x1] == 11 || cells[y1][x1] == 12 || cells[y1][x1] == 13) {
                return false;
            } else {
                return true;
            }
        } else {
            if (cells[y][x] == 3 || cells[y][x] == 6 || cells[y][x] == 7 || cells[y][x] == 9 || cells[y][x] == 11 || cells[y][x] == 12 || cells[y][x] == 13 || cells[y1][x1] == 1 || cells[y1][x1] == 5 || cells[y1][x1] == 8 || cells[y1][x1] == 9 || cells[y1][x1] == 11 || cells[y1][x1] == 13 || cells[y1][x1] == 14) {
                return false;
            } else {
                return true;
            }
        }
    }
    return false;
}

void getSurrounds(int x, int y, int &x0, int &y0, int &x1, int &y1, int &x2, int &y2, int &x3, int &y3) {
    x3 = x - 1;
    y3 = y;
    x0 = x;
    y0 = y + 1;
    x1 = x + 1;
    y1 = y;
    x2 = x;
    y2 = y - 1;
    if (x1 >= 14) {
        x1 = -1;
    }
    if (y0 >= 14) {
        y0 = -1;
    }
}

void changeDestination(int maze[14][14], int destinationx, int destinationy) {
    for (int j = 0; j < 14; j++) {
        for (int i = 0; i < 14; i++) {
            flood[i][j] = 255;
        }
    }

    int queueX[100]; // Use arrays for queue
    int queueY[100];
    maze[destinationy][destinationx] = 0;

    int front = 0;
    int rear = 0;

    queueY[rear] = destinationy;
    queueX[rear] = destinationx;
    rear++;

    while (front != rear) {
        int yrun = queueY[front];
        int xrun = queueX[front];
        front++;

        int x0, y0, x1, y1, x2, y2, x3, y3;
        getSurrounds(xrun, yrun, x0, y0, x1, y1, x2, y2, x3, y3);

        if (x0 >= 0 && y0 >= 0) {
            if (maze[y0][x0] == 255) {
                maze[y0][x0] = maze[yrun][xrun] + 1;
                queueY[rear] = y0;
                queueX[rear] = x0;
                rear++;
            }
        }
        if (x1 >= 0 && y1 >= 0) {
            if (maze[y1][x1] == 255) {
                maze[y1][x1] = maze[yrun][xrun] + 1;
                queueY[rear] = y1;
                queueX[rear] = x1;
                rear++;
            }
        }
        if (x2 >= 0 && y2 >= 0) {
            if (maze[y2][x2] == 255) {
                maze[y2][x2] = maze[yrun][xrun] + 1;
                queueY[rear] = y2;
                queueX[rear] = x2;
                rear++;
            }
        }
        if (x3 >= 0 && y3 >= 0) {
            if (maze[y3][x3] == 255) {
                maze[y3][x3] = maze[yrun][xrun] + 1;
                queueY[rear] = y3;
                queueX[rear] = x3;
                rear++;
            }
        }
    }
}

void floodFill2(int maze[14][14]) {
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++) {
            maze[i][j] = 0;
        }
    }

    int queueX[100]; // Use arrays for queue
    int queueY[100];

    flood2[6][6] = 1;
    flood2[7][6] = 1;
    flood2[6][7] = 1;
    flood2[7][7] = 1;

    int front = 0;
    int rear = 0;

    queueY[rear] = 6;
    queueX[rear] = 6;
    rear++;
    queueY[rear] = 7;
    queueX[rear] = 6;
    rear++;
    queueY[rear] = 6;
    queueX[rear] = 7;
    rear++;
    queueY[rear] = 7;
    queueX[rear] = 7;
    rear++;

    while (front != rear) {
        int yrun = queueY[front];
        int xrun = queueX[front];
        front++;

        int x0, y0, x1, y1, x2, y2, x3, y3;
        getSurrounds(xrun, yrun, x0, y0, x1, y1, x2, y2, x3, y3);

        if (x0 >= 0 && y0 >= 0 && cells[y0][x0] != 0) {
            if (maze[y0][x0] == 0) {
                if (isAccessible(xrun, yrun, x0, y0)) {
                    maze[y0][x0] = maze[yrun][xrun] + 1;
                    queueY[rear] = y0;
                    queueX[rear] = x0;
                    rear++;
                }
            }
        }
        if (x1 >= 0 && y1 >= 0 && cells[y1][x1] != 0) {
            if (maze[y1][x1] == 0) {
                if (isAccessible(xrun, yrun, x1, y1)) {
                    maze[y1][x1] = maze[yrun][xrun] + 1;
                    queueY[rear] = y1;
                    queueX[rear] = x1;
                    rear++;
                }
            }
        }
        if (x2 >= 0 && y2 >= 0 && cells[y2][x2] != 0) {
            if (maze[y2][x2] == 0) {
                if (isAccessible(xrun, yrun, x2, y2)) {
                    maze[y2][x2] = maze[yrun][xrun] + 1;
                    queueY[rear] = y2;
                    queueX[rear] = x2;
                    rear++;
                }
            }
        }
        if (x3 >= 0 && y3 >= 0 && cells[y3][x3] != 0) {
            if (maze[y3][x3] == 0) {
                if (isAccessible(xrun, yrun, x3, y3)) {
                    maze[y3][x3] = maze[yrun][xrun] + 1;
                    queueY[rear] = y3;
                    queueX[rear] = x3;
                    rear++;
                }
            }
        }
    }
}

void floodFill3(int maze[14][14], int queueX[], int queueY[], int &front, int &rear) {
    while (front != rear) {
        int yrun = queueY[front];
        int xrun = queueX[front];
        front++;

        int x0, y0, x1, y1, x2, y2, x3, y3;
        getSurrounds(xrun, yrun, x0, y0, x1, y1, x2, y2, x3, y3);

        if (x0 >= 0 && y0 >= 0) {
            if (maze[y0][x0] == 255) {
                if (isAccessible(xrun, yrun, x0, y0)) {
                    maze[y0][x0] = maze[yrun][xrun] + 1;
                    queueY[rear] = y0;
                    queueX[rear] = x0;
                    rear++;
                }
            }
        }
        if (x1 >= 0 && y1 >= 0) {
            if (maze[y1][x1] == 255) {
                if (isAccessible(xrun, yrun, x1, y1)) {
                    maze[y1][x1] = maze[yrun][xrun] + 1;
                    queueY[rear] = y1;
                    queueX[rear] = x1;
                    rear++;
                }
            }
        }
        if (x2 >= 0 && y2 >= 0) {
            if (maze[y2][x2] == 255) {
                if (isAccessible(xrun, yrun, x2, y2)) {
                    maze[y2][x2] = maze[yrun][xrun] + 1;
                    queueY[rear] = y2;
                    queueX[rear] = x2;
                    rear++;
                }
            }
        }
        if (x3 >= 0 && y3 >= 0) {
            if (maze[y3][x3] == 255) {
                if (isAccessible(xrun, yrun, x3, y3)) {
                    maze[y3][x3] = maze[yrun][xrun] + 1;
                    queueY[rear] = y3;
                    queueX[rear] = x3;
                    rear++;
                }
            }
        }
    }
}

char toMove(int maze[14][14], int x, int y, int xprev, int yprev, int orient) {
    int x0, y0, x1, y1, x2, y2, x3, y3;
    getSurrounds(x, y, x0, y0, x1, y1, x2, y2, x3, y3);
    int val = maze[y][x];
    int prev = 0;
    int minVals[4] = {1000, 1000, 1000, 1000};

    if (isAccessible(x, y, x0, y0)) {
        if (x0 == xprev && y0 == yprev) {
            prev = 0;
        }
        minVals[0] = maze[y0][x0];
    }

    if (isAccessible(x, y, x1, y1)) {
        if (x1 == xprev && y1 == yprev) {
            prev = 1;
        }
        minVals[1] = maze[y1][x1];
    }

    if (isAccessible(x, y, x2, y2)) {
        if (x2 == xprev && y2 == yprev) {
            prev = 2;
        }
        minVals[2] = maze[y2][x2];
    }

    if (isAccessible(x, y, x3, y3)) {
        if (x3 == xprev && y3 == yprev) {
            prev = 3;
        }
        minVals[3] = maze[y3][x3];
    }

    int minVal = minVals[0];
    int minCell = 0;
    int noMovements = 0;
    for (int i = 0; i < 4; i++) {
        if (minVals[i] != 1000) {
            noMovements++;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (minVals[i] < minVal) {
            if (noMovements == 1) {
                minVal = minVals[i];
                minCell = i;
            } else {
                if (i == prev) {
                    continue;
                } else {
                    minVal = minVals[i];
                    minCell = i;
                }
            }
        }
    }

    if (minCell == orient) {
        return 'F';
    } else if ((minCell == orient - 1) || (minCell == orient + 3)) {
        return 'L';
    } else if ((minCell == orient + 1) || (minCell == orient - 3)) {
        return 'R';
    } else {
        return 'B';
    }
}

char toMove2(int maze[14][14], int x, int y, int xprev, int yprev, int orient) {
    int x0, y0, x1, y1, x2, y2, x3, y3;
    getSurrounds(x, y, x0, y0, x1, y1, x2, y2, x3, y3);
    int val = maze[y][x];
    int minCell = 0;

    if (isAccessible(x, y, x0, y0)) {
        if (maze[y0][x0] == val - 1) {
            minCell = 0;
        }
    }

    if (isAccessible(x, y, x1, y1)) {
        if (maze[y1][x1] == val - 1) {
            minCell = 1;
        }
    }

    if (isAccessible(x, y, x2, y2)) {
        if (maze[y2][x2] == val - 1) {
            minCell = 2;
        }
    }

    if (isAccessible(x, y, x3, y3)) {
        if (maze[y3][x3] == val - 1) {
            minCell = 3;
        }
    }

    if (minCell == orient) {
        return 'F';
    } else if ((minCell == orient - 1) || (minCell == orient + 3)) {
        return 'L';
    } else if ((minCell == orient + 1) || (minCell == orient - 3)) {
        return 'R';
    } else {
        return 'B';
    }
}

void show(int flood[14][14], int variable) {
    for (int x = 0; x < 14; x++) {
        for (int y = 0; y < 14; y++) {
            int x0, y0, x1, y1, x2, y2, x3, y3;
            getSurrounds(x, y, x0, y0, x1, y1, x2, y2, x3, y3);
            String a = "";

            if (isAccessible(x, y, x0, y0)) {
                a += String(x0);
                a += String(y0);
            }

            if (isAccessible(x, y, x1, y1)) {
                a += String(x1);
                a += String(y1);
            }

            if (isAccessible(x, y, x2, y2)) {
                a += String(x2);
                a += String(y2);
            }

            if (isAccessible(x, y, x3, y3)) {
                a += String(x3);
                a += String(y3);
            }

            // API.setText(x, y, a);
            // API.setText(x, y, String(flood2[y][x]));
            // API.setText(x, y, String(variable));
        }
    }
}

void center(int x, int y, int &orient) {
    bool L = API.wallLeft();
    bool R = API.wallRight();
    bool F = API.wallFront();

    if (L) {
        updateWalls(x, y, orient, L, R, F);

        API.moveForward();
        int xprev = x;
        int yprev = y;
        x, y = updateCoordinates(x, y, orient);

        L = API.wallLeft();
        R = API.wallRight();
        F = API.wallFront();
        updateWalls(x, y, orient, L, R, F);

        API.turnRight();
        orient = orientation(orient, 'R');

        API.moveForward();
        xprev = x;
        yprev = y;
        x, y = updateCoordinates(x, y, orient);

        L = API.wallLeft();
        R = API.wallRight();
        F = API.wallFront();
        updateWalls(x, y, orient, L, R, F);

        API.turnRight();
        orient = orientation(orient, 'R');

        API.moveForward();
        xprev = x;
        yprev = y;
        x, y = updateCoordinates(x, y, orient);

        L = API.wallLeft();
        R = API.wallRight();
        F = API.wallFront();
        updateWalls(x, y, orient, L, R, F);

        API.turnRight();
        orient = orientation(orient, 'R');

        API.moveForward();
        xprev = x;
        yprev = y;
        x, y = updateCoordinates(x, y, orient);

        L = API.wallLeft();
        R = API.wallRight();
        F = API.wallFront();
        updateWalls(x, y, orient, L, R, F);

        return;
    } else {
        updateWalls(x, y, orient, L, R, F);

        API.moveForward();
        int xprev = x;
        int yprev = y;
        x, y = updateCoordinates(x, y, orient);

        L = API.wallLeft();
        R = API.wallRight();
        F = API.wallFront();
        updateWalls(x, y, orient, L, R, F);

        API.turnLeft();
        orient = orientation(orient, 'L');

        API.moveForward();
        xprev = x;
        yprev = y;
        x, y = updateCoordinates(x, y, orient);

        L = API.wallLeft();
        R = API.wallRight();
        F = API.wallFront();
        updateWalls(x, y, orient, L, R, F);

        API.turnLeft();
        orient = orientation(orient, 'L');

        API.moveForward();
        xprev = x;
        yprev = y;
        x, y = updateCoordinates(x, y, orient);

        L = API.wallLeft();
        R = API.wallRight();
        F = API.wallFront();
        updateWalls(x, y, orient, L, R, F);

        API.turnLeft();
        orient = orientation(orient, 'L');

        API.moveForward();
        xprev = x;
        yprev = y;
        x, y = updateCoordinates(x, y, orient);

        L = API.wallLeft();
        R = API.wallRight();
        F = API.wallFront();
        updateWalls(x, y, orient, L, R, F);

        return;
    }
}

void main() {
    int x = 0;
    int y = 0;
    int xprev = 0;
    int yprev = 0;
    int orient = 0;
    int state = 0;
    bool shortPath = false;

    while (true) {
        // API.setColor(x, y, 'red');
        bool L = API.wallLeft();
        bool R = API.wallRight();
        bool F = API.wallFront();
        updateWalls(x, y, orient, L, R, F);

        if (flood[y][x] != 0) {
            if (state == 0) {
                appendZero();
            } else if (state == 1) {
                appendDestination(13, 0);
                shortPath = false;
            } else if (state == 2) {
                appendDestination(0, 0);
                shortPath = false;
            } else if (state == 3) {
                appendZero();
                floodFill2(flood2);
                shortPath = true;
            } else if (state == 4) {
                appendDestination(0, 13);
                shortPath = false;
            } else if (state == 5) {
                appendDestination(0, 0);
                shortPath = false;
            } else if (state == 6) {
                appendZero();
                floodFill2(flood2);
                shortPath = true;
            }

            floodFill3(flood, queue);
        } else {
            if (state == 5) {
                appendZero();
                floodFill3(flood, queue);
                state++;
            } else if (state == 4) {
                changeDestination(flood, 0, 0);
                state++;
            } else if (state == 3) {
                x, y, xprev, yprev, orient = center(x, y, orient);
                changeDestination(flood, 0, 13);
                state++;
            } else if (state == 2) {
                appendZero();
                floodFill3(flood, queue);
                state++;
            } else if (state == 1) {
                changeDestination(flood, 0, 0);
                state++;
            } else if (state == 0) {
                x, y, xprev, yprev, orient = center(x, y, orient);
                changeDestination(flood, 13, 0);
                state++;
            }

            floodFill2(flood2);
        }

        String direction;

        if (shortPath) {
            direction = toMove2(flood2, x, y, xprev, yprev, orient);
        } else {
            direction = toMove(flood, x, y, xprev, yprev, orient);
        }

        if (direction == "L") {
            // API.turnLeft();
            orient = orientation(orient, 'L');
        } else if (direction == "R") {
            // API.turnRight();
            orient = orientation(orient, 'R');
        } else if (direction == "B") {
            // API.turnLeft();
            orient = orientation(orient, 'L');
            // API.turnLeft();
            orient = orientation(orient, 'L');
        }

        // show(flood, state);
        // API.moveForward();
        xprev = x;
        yprev = y;
        x, y = updateCoordinates(x, y, orient);
    }
}

void shortestPath(int x, int y, int xprev, int yprev, int orient, int state) {
  while (true) {
    show(flood2, state);
    bool L = API.wallLeft();
    bool R = API.wallRight();
    bool F = API.wallFront();
    // updateWalls(x, y, orient, L, R, F);

    if (flood2[y][x] != 1) {
      char direction = toMove2(flood2, x, y, xprev, yprev, orient);

      if (direction == 'L') {
        API.turnLeft();
        orient = orientation(orient, 'L');
      } else if (direction == 'R') {
        API.turnRight();
        orient = orientation(orient, 'R');
      } else if (direction == 'B') {
        API.turnLeft();
        orient = orientation(orient, 'L');
        API.turnLeft();
        orient = orientation(orient, 'L');
      }

      show(flood2, state);
      API.moveForward();
      xprev = x;
      yprev = y;
      // You'll need to implement the updateCoordinates function for Arduino
      // x, y = updateCoordinates(x, y, orient);
    } else {
      break;
    }
  }
}