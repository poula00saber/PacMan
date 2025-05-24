# Pac-Man Game with Advanced AI Ghosts 👻

A modern C++ implementation of the classic Pac-Man game featuring intelligent ghost AI using different pathfinding algorithms. Built with SFML (Simple and Fast Multimedia Library) and advanced graph algorithms.


## Project Decumentation

Project Video: [https://youtu.be/0M5LkG5rUYM)]
![Game Screenshot](ConsoleApplication1/Assets/screen1)
![Game Screenshot](ConsoleApplication1/Assets/screen2)
![Game Screenshot](ConsoleApplication1/Assets/screen3)
![Game Screenshot](ConsoleApplication1/Assets/screen4)
![Game Screenshot](ConsoleApplication1/Assets/screen5)

## 🎮 Features

### Game Mechanics
- Classic Pac-Man gameplay with smooth movement
- Food collection system with score tracking
- Multiple ghost types with unique AI behaviors
- Anti-camping mechanisms to prevent ghost stalling
- Dynamic difficulty adjustment based on remaining food

### Advanced Ghost AI
- **BFS Ghost**: Uses Breadth-First Search for direct pursuit with random movement elements
- **A Ghost (A-Star Search)**: Intelligent pursuit of Pac-Man using heuristic-guided pathfinding
- **Dijkstra Ghost**: Uses Dijkstra's algorithm with weighted edges based on food positions for optimal pathfinding

### Technical Features
- Graph-based maze representation
- Multiple pathfinding algorithms (BFS, DFS, Dijkstra)
- Object-oriented design with inheritance and polymorphism
- Strategy pattern for AI behavior
- SFML graphics with sprite animation

## 🛠️ Technologies Used

- **C++17** - Core programming language
- **SFML 2.5+** - Graphics, audio, and input handling
- **Graph Theory** - Maze representation and pathfinding
- **Object-Oriented Programming** - Clean architecture with inheritance

## 📋 Prerequisites

Before running this project, make sure you have:

- C++ compiler with C++17 support (GCC 7+, Clang 5+, or MSVC 2017+)
- SFML 2.5 or higher
- CMake 3.10+ (recommended for building)

### Installing SFML

#### Windows (vcpkg)
```bash
vcpkg install sfml
```

#### macOS (Homebrew)
```bash
brew install sfml
```

#### Ubuntu/Debian
```bash
sudo apt-get install libsfml-dev
```

## 🚀 Getting Started

### Clone the Repository
```bash
git clone https://github.com/yourusername/pacman-ai-game.git
cd pacman-ai-game
```

### Build the Project

#### Using CMake (Recommended)
```bash
mkdir build
cd build
cmake ..
make
```

#### Manual Compilation
```bash
g++ -std=c++17 -o pacman *.cpp -lsfml-graphics -lsfml-window -lsfml-system
```

### Run the Game
```bash
./pacman
```

## 🎯 How to Play

- **Arrow Keys** or **WASD** - Move Pac-Man
- **ESC** - Pause/Exit game
- **R** - Restart game

### Objective
- Collect all food items while avoiding the ghosts
- Each ghost has different behavior patterns:
  - **Red Ghost (BFS)**: Direct pursuer with occasional random moves
  - **Blue Ghost (DFS)**: Patrols between food items unpredictably  
  - **Green Ghost (Dijkstra)**: Uses optimal pathfinding considering food positions

## 🏗️ Project Structure

```
pacman-ai-game/
├── src/
│   ├── ghost.h                 # Base ghost class
│   ├── ghost.cpp              
│   ├── bfsGhost.h             # BFS pathfinding ghost
│   ├── bfsGhost.cpp           
│   ├── dfsGhost.h             # DFS pathfinding ghost
│   ├── dfsGhost.cpp           
│   ├── dijkstraGhost.h        # Dijkstra pathfinding ghost
│   ├── dijkstraGhost.cpp      
│   ├── pacman.h               # Player class
│   ├── pacman.cpp             
│   ├── Graph.h                # Graph representation and algorithms
│   ├── Graph.cpp              
│   ├── Food.h                 # Food item class
│   ├── Food.cpp               
│   └── main.cpp               # Main game loop
├── Assets/
│   ├── images/                # Sprite images
│   └── sounds/                # Audio files
├── CMakeLists.txt             # CMake build configuration
└── README.md                  # This file
```

## 🤖 AI Algorithm Details

### Ghost Base Class
- **Anti-camping system**: Detects when ghosts are stuck and forces movement
- **Polymorphic movement**: Uses strategy pattern for different AI behaviors
- **Shared movement logic**: Common pathfinding execution and sprite animation

### BFS Ghost (Breadth-First Search)
- **Behavior**: Direct pursuit of Pac-Man
- **Features**: 
  - 20% chance of random movement for unpredictability
  - Guaranteed shortest path when chasing
  - More aggressive when few food items remain

### A Ghost (A-Star Search)*

- **Behavior**: Intelligent pursuit of Pac-Man using heuristic-guided pathfinding
- **Features**:
   - 20% chance of random movement for unpredictability
   - Guaranteed optimal path with improved efficiency over BFS
   - Uses Manhattan distance heuristic to prioritize promising directions
   - More aggressive when few food items remain
   - Faster pathfinding compared to pure BFS while maintaining shortest path guarantee

### Dijkstra Ghost (Dijkstra's Algorithm)
- **Behavior**: Optimal pathfinding with weighted edges
- **Features**:
  - Considers food positions when calculating paths
  - Uses weighted graph based on food density
  - Most sophisticated AI with strategic positioning

## 🔧 Customization

### Adding New Ghost Types
1. Inherit from the `ghost` base class
2. Override the `findPath()` methods
3. Implement your pathfinding strategy
4. Add to the game's ghost vector

Example:
```cpp
class MyCustomGhost : public ghost {
protected:
    std::vector<int> findPath(int ghostNodeId, int pacmanNodeId, Graph& g) override {
        // Your custom pathfinding logic here
        return customAlgorithm(ghostNodeId, pacmanNodeId, g);
    }
};
```

### Modifying Game Parameters
- **Ghost speed**: Adjust `speed` member in ghost constructors
- **Path recalculation frequency**: Modify `moveCounter` threshold in `movement()` 
- **Anti-camping sensitivity**: Change `stationaryCounter` threshold in `isStuck()`

## 🤝 Contributing

Contributions are welcome! Here are some ways you can help:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/AmazingFeature`)
3. **Commit** your changes (`git commit -m 'Add some AmazingFeature'`)
4. **Push** to the branch (`git push origin feature/AmazingFeature`)
5. **Open** a Pull Request

## 🙏 Acknowledgments

- Classic Pac-Man game by Namco for inspiration
- SFML community for excellent documentation
- Graph algorithm implementations adapted from computer science literature

---

⭐ **Star this repository if it helped you learn about game AI or graph algorithms!**
