#include "ghost.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>

ghost::ghost() {
    ghostTex.loadFromFile("Assets/images/enemy_spritethis1.png");
    ghostSprite.setTexture(ghostTex);
    ghostSprite.setTextureRect(IntRect(0, 0, 30, 30));
    ghostSprite.setScale(1.5, 1.5);
    ghostSprite.setPosition(50, 50);
    frame = 0;
    speed = 0.05f;  //shoujd be less than or equal to pacman's speed for easy mode(morein hard)
    status = -1;
    moveCounter = 0;
}

<<<<<<< Updated upstream
void ghost::movement(pacman& player, Graph& g) {
    // get char current pos
=======
void ghost::setVulnerable() {
    vulnerable = true;
    vulnerableClock.restart();    
    ghostSprite.setTexture(ghostWeakShape);
    ghostSprite.setTextureRect(IntRect(0, 0, 30, 30));
}
void ghost::movement(pacman& player, Graph& g,int level) {
>>>>>>> Stashed changes
    Vector2f ghostPos = ghostSprite.getPosition();
    Vector2f pacmanPos = player.pacsprite.getPosition();

    // positions to node indices(adj list)
    int ghostI = static_cast<int>(ghostPos.y) / Graph::NODESIZE;
    int ghostJ = static_cast<int>(ghostPos.x) / Graph::NODESIZE;
    int pacmanI = static_cast<int>(pacmanPos.y) / Graph::NODESIZE;
    int pacmanJ = static_cast<int>(pacmanPos.x) / Graph::NODESIZE;

    int ghostNodeId = ghostI * Graph::COLS + ghostJ;
    int pacmanNodeId = pacmanI * Graph::COLS + pacmanJ;
<<<<<<< Updated upstream
=======

    //this is to detect ghost stuck in a node
    if (ghostNodeId == lastVisitedNode) {
        stationaryCounter++;
    }
    else {
        stationaryCounter = 0;
        lastVisitedNode = ghostNodeId;
    }  

    if (checkCollision(player)) {
            if (vulnerable) {
                isDying = 1;
                path = g.bfs(ghostNodeId, homeId, level);
                moveCounter = 20;
                ghostSprite.setTexture(ghostEyes);
            }
            else {
                ghost::isVisible = false;
                player.pacsprite.setTexture(player.pacDeath);
                player.isDying = 1;
            }
        
    }   
>>>>>>> Stashed changes

    moveCounter++;
    if (moveCounter >= 20) {  // calc new path every 20 frames(3shan el ghost maydokhsh)
<<<<<<< Updated upstream
        path = g.bfs(ghostNodeId, pacmanNodeId);
        moveCounter = 0;
=======
        int targetNodelId; 
        if (vulnerable && !isDying) {
            float maxDist = -1;
            int farthestNode = ghostNodeId;
            for (int i = 0; i < Graph::ROWS; i++) {
                for (int j = 0; j < Graph::COLS; j++) {
                    if (g.pacmanMatrix[i][j] != 0) {
                        float distX = static_cast<float> (j * Graph::NODESIZE) - pacmanPos.x;
                        float distY = static_cast<float> (i * Graph::NODESIZE) - pacmanPos.y;
                        float dist = distX * distX + distY * distY;
                        if (dist > maxDist) {
                            maxDist = dist;
                            farthestNode = i * Graph::COLS + j;
                        }
                    }
                }
            }
            targetNodelId = farthestNode;
            path = g.bfs(ghostNodeId, targetNodelId, level);
            moveCounter = 0;
        }
        else if (isDying) {
            targetNodelId = homeId;
            speed = 1.0f;
            if (ghostNodeId == homeId) {
                isFrozen = 1;
                isDying = 0;
                freezeClock.restart();
                ghostSprite.setTexture(ghostTex);
				path.clear();
            }
            else {
                path = g.bfs(ghostNodeId, targetNodelId, level);
                moveCounter = 0;
            }
        }
        else if (isFrozen) {
            ghostSprite.move(0, 0);
            speed = 0.0f;
			cout << counttime << endl;
            if (freezeClock.getElapsedTime().asSeconds() >= 0.5f) {
                counttime++;
                freezeClock.restart();
            }
            if (counttime>10)
            {
                speed = 1.0f;
                isFrozen = 0;
                vulnerable = 0;
                counttime = 0;
            }
        }
        else {
            targetNodelId = pacmanNodeId;
            path = g.bfs(ghostNodeId, targetNodelId, level);
            moveCounter = 0;
        }

        if (level == 0) {
            path = g.bfs(ghostNodeId, targetNodelId, level);
        }
        else if (level == 1)
            path = g.a_star(ghostNodeId, targetNodelId);
>>>>>>> Stashed changes
    }

    // a valid path with at lEAST one node
    if (!path.empty() && path.size() > 1) {
        // get the next node
        int nextNodeId = path[1];
        int nextI = nextNodeId / Graph::COLS;
        int nextJ = nextNodeId % Graph::COLS;

        
        if (nextJ > ghostJ) {
            status = 0;  // right
        }
        else if (nextJ < ghostJ) {
            status = 1;  // left
            
        }
        else if (nextI < ghostI) {
            status = 2;  // up
        }
        else if (nextI > ghostI) {
            status = 3;  // down
        }
        

        if (status == 0) { 
            frame++;
            int frameIndex = frame % 2;
            ghostSprite.setTextureRect(IntRect(frameIndex* 30, 0, 30, 30));
            ghostSprite.move(speed, 0);
        }
        else if (status == 1) {  
            frame++;
            int frameIndex = frame % 2;
            ghostSprite.setTextureRect(IntRect((frameIndex+6) * 30, 0, 30, 30));
            ghostSprite.move(-speed, 0);
        }
        else if (status == 2) {  
            frame++;
            int frameIndex = frame % 2;
            ghostSprite.setTextureRect(IntRect((frameIndex+4) * 30, 0, 30, 30));
            ghostSprite.move(0, -speed);
        }
        else if (status == 3) {  
            frame++;
            int frameIndex = frame % 2;
            ghostSprite.setTextureRect(IntRect((frameIndex+2) * 30, 0, 30, 30));
            ghostSprite.move(0, speed);
        }
    }
}

bool ghost::checkCollision(pacman& player) {
    FloatRect ghostBounds = ghostSprite.getGlobalBounds();
    FloatRect pacmanBounds = player.pacsprite.getGlobalBounds();

    // very basic logic i'll edit it soon
    return ghostBounds.intersects(pacmanBounds);
}
int ghost::countRemainingFood(const std::vector<std::unique_ptr<Food>>& foodList) {
    int count = 0;
    for (const auto& food : foodList) {
        if (!food->eaten()) count++;
    }
    return count;
}

bool ghost::isStuck() const {
    return stationaryCounter > 100;
}

void ghost::draw(RenderWindow& window) {
    window.draw(ghostSprite);
}