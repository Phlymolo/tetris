#ifndef BLOCK_H
#define BLOCK_H

class Block
{
protected:
    int positionX, positionY;
    int shape[4][4];

public:
    Block(int posX, int posY);
    virtual void rotate() = 0; // abstract - implement in derived block classes

    // Getter methods
    int getPositionX() const;
    int getPositionY() const;
    const int (*getShape() const)[4];

    // Movement methods
    void moveLeft();
    void moveRight();
    void moveDown();
    void moveUp();
};

#endif // BLOCK_H
