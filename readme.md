# Game Development Learning Path: 6-Month Roadmap
**Goal:** Build a complete 2D game with a custom engine from scratch  
**Time Commitment:** 15-20 hours/week  
**Platform:** Windows, Linux  
**Language:** C++

---

## Phase 1: C++ Fundamentals & Core Systems (Weeks 1-6)

### Primary Resources
- LearnCPP.com (Chapters 0-16)
- Computer Systems: A Programmer's Perspective (Chapters 2-4)

### Learning Objectives
- Master modern C++ fundamentals
- Understand memory, performance, and computer architecture
- Build foundation for game programming

---

### Weeks 1-2: C++ Basics & Memory

**Read:** LearnCPP.com Chapters 0-9  
**Focus:** Types, control flow, functions, arrays, pointers, references

#### Project 1A: C++ Fundamentals Suite
Build 3 command-line tools demonstrating C++ basics:

**1. Calculator** - Expression parser with +, -, *, /
**2. Prime Checker** - Test primality, list primes, Sieve of Eratosthenes
**3. String Toolkit** - Reverse, case conversion, analysis

```cpp
// Example: String toolkit
class StringToolkit {
public:
    std::string reverse(const std::string& str);
    std::string toUpper(const std::string& str);
    std::string toLower(const std::string& str);
    size_t countVowels(const std::string& str);
};
```

**Success Criteria:**
- [ ] Clean, modern C++ code
- [ ] Proper use of std::string and std::vector
- [ ] Error handling
- [ ] 20+ unit tests

---

### Weeks 3-4: OOP, Memory Architecture & Performance

**Read:** LearnCPP.com Chapters 10-16, Computer Systems Chapters 2-4  
**Focus:** Classes, operator overloading, memory hierarchy, cache performance

#### Project 1B: Performance Analysis Toolkit

**1. High-Resolution Timer Class**
```cpp
class PerfTimer {
private:
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;

public:
    void startTimer();
    void endTimer();
    double getMilliseconds() const;
};
```

**2. Cache Performance Experiments**
```cpp
// Test: Array of Structures vs Structure of Arrays
struct Vertex_AOS {
    float x, y, z;
    float r, g, b;
    float nx, ny, nz;
};

struct VertexArray_SOA {
    std::vector<float> x, y, z;
    std::vector<float> r, g, b;
    std::vector<float> nx, ny, nz;
};

// Benchmark: Update only positions for 1M vertices
// Expected: SOA 2-3x faster
```

**3. Memory Layout Analysis**
- Compare aligned vs unaligned structures
- Measure padding impact
- Benchmark sequential vs random access

**Success Criteria:**
- [ ] Timer with microsecond precision
- [ ] Clear performance differences demonstrated
- [ ] Written report with graphs and analysis

---

### Weeks 5-6: Data Structures & Memory Management

**Read:** LearnCPP.com Chapters 17-20

#### Project 1C: Custom Allocators & Data Structures

**1. Arena Allocator**
```cpp
class Arena {
private:
    std::unique_ptr<uint8_t[]> memory;
    size_t size;
    size_t used;

public:
    explicit Arena(size_t size);
    void* allocate(size_t bytes, size_t alignment = 8);
    void clear();  // Fast reset
    
    template<typename T, typename... Args>
    T* construct(Args&&... args);
};
```

**2. Pool Allocator**
```cpp
template<typename T>
class PoolAllocator {
private:
    struct FreeNode { FreeNode* next; };
    std::unique_ptr<uint8_t[]> memory;
    FreeNode* freeList;

public:
    explicit PoolAllocator(size_t count);
    T* allocate();
    void deallocate(T* ptr);
};
```

**3. Dynamic Array (Custom Vector)**
```cpp
template<typename T>
class DynamicArray {
private:
    T* data;
    size_t count;
    size_t capacity;

public:
    void push(const T& element);
    void push(T&& element);
    T& operator[](size_t index);
    
    // Iterator support
    T* begin() { return data; }
    T* end() { return data + count; }
};
```

**Benchmarks Required:**
- Arena: 10x faster than new/delete
- Pool: 20x faster for fixed-size objects
- Custom vector: Match std::vector performance

**Success Criteria:**
- [ ] All allocators working correctly
- [ ] No memory leaks (verify with sanitizers)
- [ ] Performance targets met
- [ ] STL-compatible interfaces

---

### Phase 1 Checkpoint:
- [ ] Comfortable with modern C++ features
- [ ] Understand memory architecture
- [ ] Can write performant code
- [ ] Custom allocators working

---

## Phase 2: Mathematics & Physics (Weeks 7-10)

### Primary Resources
- LearnCPP.com Chapter 21 (Operator overloading)
- Foundations of Game Engine Development, Volume 1: Mathematics
- Introduction to Linear Algebra (Strang) - Selected chapters

### Learning Objectives
- Master vector and matrix mathematics
- Implement physics simulation
- Build complete math library

---

### Weeks 7-8: 2D & 3D Math Library

**Read:** FGED Vol 1 Chapters 1-4, LearnCPP Chapter 21

#### Project 2A: Complete Math Library

**1. Vector2 with Operator Overloading**
```cpp
class Vector2 {
public:
    float x, y;
    
    Vector2() : x(0), y(0) {}
    Vector2(float x, float y) : x(x), y(y) {}
    
    // Operators
    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;
    Vector2 operator*(float scalar) const;
    Vector2& operator+=(const Vector2& other);
    
    // Vector operations
    float length() const;
    float lengthSquared() const;
    float dot(const Vector2& other) const;
    float cross(const Vector2& other) const;
    Vector2 normalized() const;
    Vector2 rotate(float angleRadians) const;
    Vector2 reflect(const Vector2& normal) const;
    
    static Vector2 lerp(const Vector2& a, const Vector2& b, float t);
};
```

**2. Vector3 Implementation**
```cpp
class Vector3 {
public:
    float x, y, z;
    
    // All Vector2 operations plus:
    Vector3 cross(const Vector3& other) const;
    Vector3 rotateAroundAxis(const Vector3& axis, float angle) const;
};
```

**3. Matrix4 (3D Transformations)**
```cpp
class Matrix4 {
private:
    float m[4][4];

public:
    static Matrix4 identity();
    static Matrix4 translation(const Vector3& t);
    static Matrix4 scale(const Vector3& s);
    static Matrix4 rotationX(float angle);
    static Matrix4 rotationY(float angle);
    static Matrix4 rotationZ(float angle);
    
    Matrix4 operator*(const Matrix4& other) const;
    Vector3 transformPoint(const Vector3& p) const;
    Vector3 transformDirection(const Vector3& d) const;
    
    Matrix4 inverse() const;
    
    // Camera matrices
    static Matrix4 lookAt(const Vector3& eye, 
                         const Vector3& target, 
                         const Vector3& up);
    static Matrix4 perspective(float fovY, float aspect, 
                              float near, float far);
};
```

**4. Quaternion (Rotations)**
```cpp
class Quaternion {
public:
    float x, y, z, w;
    
    static Quaternion identity();
    static Quaternion fromAxisAngle(const Vector3& axis, float angle);
    
    Quaternion operator*(const Quaternion& other) const;
    Vector3 rotate(const Vector3& v) const;
    Matrix4 toMatrix() const;
    
    static Quaternion slerp(const Quaternion& a, const Quaternion& b, float t);
};
```

**Success Criteria:**
- [ ] 100+ unit tests passing
- [ ] All operations mathematically correct
- [ ] Natural C++ syntax with operators
- [ ] Performance: Matrix multiply <20ns

---

### Weeks 9-10: 2D Physics Engine

**Read:** FGED Vol 1 Chapters 5-6

#### Project 2B: 2D Physics System

**1. Rigid Body**
```cpp
class RigidBody2D {
private:
    Vector2 position;
    float rotation;
    Vector2 velocity;
    float angularVelocity;
    
    Vector2 force;
    float torque;
    
    float mass;
    float inverseMass;
    float inertia;
    float inverseInertia;
    
    float restitution;  // Bounciness
    bool isStatic;

public:
    RigidBody2D(const Vector2& pos, float mass);
    
    void applyForce(const Vector2& force);
    void applyImpulse(const Vector2& impulse);
    void integrate(float dt);  // Semi-implicit Euler
    void clearForces();
};
```

**2. Circle Collider**
```cpp
struct CollisionInfo {
    bool colliding;
    Vector2 normal;
    float penetration;
    Vector2 contactPoint;
};

class CircleCollider {
public:
    RigidBody2D* body;
    float radius;
    
    static CollisionInfo checkCollision(const CircleCollider& a,
                                        const CircleCollider& b);
};
```

**3. Physics World**
```cpp
class PhysicsWorld {
private:
    std::vector<std::unique_ptr<RigidBody2D>> bodies;
    std::vector<std::unique_ptr<CircleCollider>> colliders;
    Vector2 gravity;

public:
    PhysicsWorld() : gravity(0, -98.0f) {}
    
    RigidBody2D* createBody(const Vector2& position, float mass);
    CircleCollider* createCircleCollider(RigidBody2D* body, float radius);
    
    void step(float dt);  // Update physics

private:
    void resolveCollision(const CollisionInfo& info,
                         CircleCollider* a, CircleCollider* b);
};
```

**Test Scenarios:**
1. Bouncing ball - should lose energy and settle
2. Stack 10 circles - should remain stable
3. Newton's cradle - energy transfer

**Success Criteria:**
- [ ] Realistic physics simulation
- [ ] Stable stacking
- [ ] No tunneling (objects passing through)
- [ ] 1000+ objects at 60 FPS

---

### Phase 2 Checkpoint:
- [ ] Complete math library working
- [ ] Physics engine functional
- [ ] Understand transformations deeply

---

## Phase 3: Graphics & Rendering (Weeks 11-16)

### Primary Resources
- Learn OpenGL (learnopengl.com) - Core sections
- Real-Time Rendering (4th Edition) - Chapters 2, 3, 5, 23

### Learning Objectives
- Master OpenGL fundamentals
- Implement efficient 2D renderer
- Handle textures, shaders, batching

---

### Weeks 11-12: OpenGL Foundations

**Read:** Learn OpenGL: Getting Started, Shaders, Textures  
**Read:** Real-Time Rendering Chapter 2 (The Graphics Rendering Pipeline), Chapter 3 (The Graphics Processing Unit)

#### Project 3A: OpenGL Renderer Base

**1. Window Management**
```cpp
class Window {
private:
    GLFWwindow* window;
    int width, height;

public:
    Window(int w, int h, const std::string& title);
    ~Window();
    
    // RAII: delete copy, allow move
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    Window(Window&& other) noexcept;
    
    bool shouldClose() const;
    void swapBuffers();
    void pollEvents();
};
```

**2. Shader System**
```cpp
class Shader {
private:
    GLuint programID;
    std::unordered_map<std::string, GLint> uniformCache;

public:
    Shader(const std::string& vertexPath, 
           const std::string& fragmentPath);
    ~Shader();
    
    void use() const;
    
    void setInt(const std::string& name, int value);
    void setFloat(const std::string& name, float value);
    void setVec2(const std::string& name, const Vector2& value);
    void setVec3(const std::string& name, const Vector3& value);
    void setMat4(const std::string& name, const Matrix4& value);

private:
    GLint getUniformLocation(const std::string& name);
};
```

**3. Basic Renderer**
```cpp
class Renderer {
private:
    GLuint VAO, VBO, EBO;
    std::unique_ptr<Shader> shader;

public:
    Renderer();
    ~Renderer();
    
    void clear(float r, float g, float b, float a);
    void drawQuad(const Vector2& position, const Vector2& size,
                  const Vector3& color);
};
```

**Test Scenarios:**
1. Clear screen to blue
2. Render colored quad
3. Render 100 quads with different colors

**Success Criteria:**
- [ ] Window opens and displays correctly
- [ ] Shaders compile successfully
- [ ] Quads render at correct positions
- [ ] Clean resource management

---

### Weeks 13-14: Textures & Sprite Rendering

**Read:** Learn OpenGL: Textures, Transformations  
**Read:** Real-Time Rendering Chapter 6 (Texturing)

#### Project 3B: Sprite Renderer

**1. Texture Loading**
```cpp
class Texture {
private:
    GLuint textureID;
    int width, height;

public:
    explicit Texture(const std::string& path);
    ~Texture();
    
    void bind(int slot = 0) const;
    int getWidth() const { return width; }
    int getHeight() const { return height; }
};
```

**2. Sprite Structure**
```cpp
struct Sprite {
    std::shared_ptr<Texture> texture;
    Vector2 position;
    Vector2 size;
    float rotation;
    Vector4 color;  // Tint
    Vector2 uvMin{0, 0};
    Vector2 uvMax{1, 1};
};
```

**3. Sprite Renderer**
```cpp
class SpriteRenderer {
private:
    std::unique_ptr<Shader> shader;
    GLuint VAO, VBO;
    Matrix4 projection;

public:
    SpriteRenderer(int screenWidth, int screenHeight);
    
    void drawSprite(const Sprite& sprite);
    void setProjection(const Matrix4& proj);
};
```

**Success Criteria:**
- [ ] Load PNG textures
- [ ] Render sprites at any position/rotation
- [ ] Color tinting works
- [ ] 100+ sprites at 60 FPS

---

### Weeks 15-16: Batch Rendering & Camera

**Read:** Learn OpenGL: Advanced topics  
**Read:** Real-Time Rendering Chapter 5 (Shading Basics), Chapter 23 (Graphics Hardware)

#### Project 3C: Optimized Batch Renderer + Camera

**1. Batch Renderer**
```cpp
struct Vertex {
    Vector2 position;
    Vector2 texCoords;
    Vector4 color;
    float texIndex;
};

class BatchRenderer {
private:
    static constexpr int MAX_SPRITES = 10000;
    static constexpr int MAX_TEXTURES = 32;
    
    std::vector<Vertex> vertexBuffer;
    std::array<std::shared_ptr<Texture>, MAX_TEXTURES> textureSlots;
    int textureSlotIndex = 1;
    
    GLuint VAO, VBO, EBO;
    std::unique_ptr<Shader> shader;

public:
    void begin();
    void submit(const Sprite& sprite);
    void end();
    void flush();
};
```

**2. 2D Camera**
```cpp
class Camera2D {
private:
    Vector2 position;
    float zoom;
    float rotation;
    
    Matrix4 viewMatrix;
    Matrix4 projectionMatrix;
    Matrix4 viewProjectionMatrix;
    bool needsUpdate;

public:
    Camera2D(int viewportWidth, int viewportHeight);
    
    void setPosition(const Vector2& pos);
    void setZoom(float z);
    const Matrix4& getViewProjectionMatrix();
    
    Vector2 screenToWorld(const Vector2& screenPos) const;
    Vector2 worldToScreen(const Vector2& worldPos) const;
};
```

**3. Text Rendering**
```cpp
class Font {
private:
    std::shared_ptr<Texture> atlas;
    std::array<Glyph, 128> glyphs;

public:
    Font(const std::string& path, float size);
    const Glyph& getGlyph(char c) const;
};

class TextRenderer {
public:
    void drawText(const Font& font, const std::string& text,
                  const Vector2& position, float scale,
                  const Vector4& color);
};
```

**Success Criteria:**
- [ ] 10,000+ sprites in <5 draw calls
- [ ] 60 FPS maintained
- [ ] Camera pan/zoom works smoothly
- [ ] Text renders clearly

---

### Phase 3 Checkpoint:
- [ ] Can render 10,000+ sprites efficiently
- [ ] Understand batching and draw calls
- [ ] Camera system working

---

## Phase 4: Game Engine & First Game (Weeks 17-26)

### Primary Resources
- Game Engine Architecture (Jason Gregory)
- Game Programming Patterns (Robert Nystrom)

### Learning Objectives
- Build modular game engine
- Complete full game development cycle
- Polish and ship a game

---

### Weeks 17-18: Core Engine Architecture

**Read:** Game Engine Architecture Chapters 5-7

#### Project 4A: Engine Core Systems

**1. Engine Core**
```cpp
class Engine {
private:
    std::unique_ptr<Window> window;
    std::unique_ptr<BatchRenderer> renderer;
    std::unique_ptr<InputManager> input;
    std::unique_ptr<ResourceManager> resources;
    std::unique_ptr<SceneManager> scenes;
    std::unique_ptr<AudioManager> audio;
    
    bool running = false;
    float deltaTime = 0;

public:
    Engine(int width, int height, const std::string& title);
    
    void run();
    void stop();
    
    // Accessors for subsystems
    Window& getWindow() { return *window; }
    BatchRenderer& getRenderer() { return *renderer; }
    // ... etc
};
```

**2. Input System**
```cpp
class InputManager {
private:
    std::unordered_map<Key, bool> keyStates;
    std::unordered_map<Key, bool> prevKeyStates;
    Vector2 mousePosition;

public:
    void update();
    
    bool isKeyPressed(Key key) const;
    bool isKeyDown(Key key) const;
    bool isKeyReleased(Key key) const;
    
    const Vector2& getMousePosition() const;
};
```

**3. Resource Manager**
```cpp
template<typename T>
class ResourceCache {
private:
    std::unordered_map<std::string, std::shared_ptr<T>> resources;

public:
    std::shared_ptr<T> load(const std::string& path);
    void unload(const std::string& path);
    void clear();
};

class ResourceManager {
private:
    ResourceCache<Texture> textures;
    ResourceCache<Font> fonts;

public:
    std::shared_ptr<Texture> loadTexture(const std::string& path);
    std::shared_ptr<Font> loadFont(const std::string& path, float size);
};
```

**Success Criteria:**
- [ ] Engine runs at consistent 60 FPS
- [ ] Input system responsive
- [ ] Resources cached properly
- [ ] Clean shutdown

---

### Weeks 19-20: Scene Management & Components

#### Project 4B: GameObject System

**1. Game Object**
```cpp
class GameObject {
private:
    Vector2 position;
    float rotation;
    Vector2 scale;
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;

public:
    virtual void update(float dt);
    virtual void render(BatchRenderer& renderer);
    
    template<typename T, typename... Args>
    T* addComponent(Args&&... args);
    
    template<typename T>
    T* getComponent();
};
```

**2. Component System**
```cpp
class Component {
protected:
    GameObject* owner = nullptr;

public:
    virtual ~Component() = default;
    virtual void update(float dt) {}
    virtual void render(BatchRenderer& renderer) {}
    
    void setOwner(GameObject* obj) { owner = obj; }
};

class SpriteComponent : public Component {
private:
    std::shared_ptr<Texture> texture;
    Vector2 size;
    Vector4 color;

public:
    void render(BatchRenderer& renderer) override;
};

class PhysicsComponent : public Component {
private:
    RigidBody2D* body;

public:
    void update(float dt) override;
};
```

**3. Scene Management**
```cpp
class Scene {
protected:
    std::vector<std::unique_ptr<GameObject>> gameObjects;

public:
    virtual void load() {}
    virtual void unload() {}
    virtual void update(float dt);
    virtual void render(BatchRenderer& renderer);
    
    GameObject* createGameObject();
    void destroyGameObject(GameObject* obj);
};
```

**Success Criteria:**
- [ ] Components can be added/removed dynamically
- [ ] Scene switching works
- [ ] No memory leaks

---

### Weeks 21-26: Complete Game Development

#### Project 4C: Top-Down Shooter Game

**Game Design:**
- Genre: Top-down shooter (Asteroids/Vampire Survivors style)
- Core Loop: Survive waves of enemies, collect power-ups
- Duration: 10-15 minutes per run
- Polish: Particles, screen shake, juice

**Week 21: Core Gameplay**
```cpp
class Player : public GameObject {
private:
    float moveSpeed = 200.0f;
    float shootCooldown = 0;
    int health = 100;
    int score = 0;

public:
    void update(float dt) override;
    void handleInput(const InputManager& input, float dt);
    void shoot();
    void takeDamage(int amount);
};

class Enemy : public GameObject {
private:
    float moveSpeed = 100.0f;
    GameObject* target = nullptr;

public:
    void update(float dt) override;
    void moveTowardsTarget(float dt);
};

class Bullet : public GameObject {
private:
    Vector2 velocity;
    float lifetime = 3.0f;

public:
    void update(float dt) override;
};
```

**Week 22: Game Systems**
- Weapon system (3+ weapon types)
- Power-up system
- Wave spawning
- Score/health UI

**Week 23: Polish**
```cpp
class ParticleEmitter {
private:
    std::vector<Particle> particles;

public:
    void emit(int count);
    void update(float dt);
    void render(BatchRenderer& renderer);
};

class CameraShake {
public:
    void shake(float duration, float intensity);
    Vector2 getOffset() const;
};
```

- Particle effects on explosions
- Screen shake on hits
- Sound effects
- Background music

**Week 24: UI & Menus**
```cpp
enum class GameState {
    MainMenu,
    Playing,
    Paused,
    GameOver
};

class UIButton {
private:
    Vector2 position, size;
    std::string text;
    std::function<void()> onClick;

public:
    void update(const InputManager& input);
    void render(BatchRenderer& renderer, TextRenderer& text);
};
```

- Main menu
- Pause menu
- Game over screen
- HUD (health, score, wave)

**Week 25: Balance & Testing**
- Difficulty curve tuning
- Wave progression
- Enemy variety
- Power-up balance
- Bug fixes

**Week 26: Final Polish & Release**
- Save/load high scores
- Settings menu (volume, fullscreen)
- Tutorial/instructions
- Credits screen
- Build executable
- Package for distribution

**Final Deliverables:**
- [ ] Complete, playable game
- [ ] 10+ minutes of gameplay
- [ ] Main menu, pause, game over screens
- [ ] Sound effects and music
- [ ] High score saving
- [ ] Polished visuals
- [ ] Windows executable

---

### Phase 4 Checkpoint:
- [ ] Complete game engine working
- [ ] First game shipped
- [ ] Comfortable with full development cycle

---

## Final Summary

### What You've Built:

**Phase 1 (Weeks 1-6):**
- Modern C++ fundamentals
- Custom allocators
- Performance profiling toolkit
- Data structures

**Phase 2 (Weeks 7-10):**
- Complete 2D/3D math library
- 2D physics engine
- Collision detection

**Phase 3 (Weeks 11-16):**
- OpenGL renderer
- Batch rendering system
- 2D camera
- Text rendering

**Phase 4 (Weeks 17-26):**
- Complete game engine
- First shipped game

### Skills Acquired:

**C++ Programming:**
- Modern C++11/14/17 features
- RAII and resource management
- Templates and generic programming
- Operator overloading
- Smart pointers

**Performance:**
- Memory architecture
- Cache optimization
- Data-oriented design
- Profiling and benchmarking

**Mathematics:**
- Vector and matrix operations
- Transformations
- Physics simulation
- Collision detection

**Graphics:**
- OpenGL API
- Shaders (GLSL)
- Batch rendering
- Camera systems

**Game Development:**
- Engine architecture
- Component systems
- Scene management
- Input handling
- Audio integration
- UI systems
- Game loop
- Polish and juice

### Portfolio:

- [ ] Custom game engine on GitHub
- [ ] 1 complete, polished game
- [ ] 10+ substantial projects
- [ ] Performance analysis reports
- [ ] Technical documentation

---

## Success Metrics

By the end of 6 months, you should be able to:

**Technical:**
- [ ] Write production-quality C++ code
- [ ] Optimize for cache performance
- [ ] Build complete systems from scratch
- [ ] Render 10,000+ sprites at 60 FPS
- [ ] Implement physics simulation

**Game Development:**
- [ ] Complete full game development cycle
- [ ] Design and balance mechanics
- [ ] Polish games professionally
- [ ] Create intuitive UI/UX

**Career:**
- [ ] Strong portfolio for junior positions
- [ ] Can discuss technical topics confidently
- [ ] Ready for technical interviews

---

## Next Steps

### After Completion:

**Immediate (Week 27-28):**
1. Portfolio website with game demo
2. Upload engine to GitHub with docs
3. Post game on itch.io
4. Update resume

**Short-term (Months 7-9):**
1. Participate in game jam
2. Study advanced topics (3D, networking, AI)
3. Build second game with new mechanics
4. Join game dev communities

**Long-term (Months 10-12):**
1. Start learning 3D graphics
2. Build 3D game prototype
3. Apply for junior positions
4. Contribute to open source

---

## Time Management Tips

**Weekly Schedule (15-20 hours):**
- Monday-Friday: 2-3 hours daily
- Weekend: 5-10 hours total

**Study Strategy:**
- 40% Reading/Learning
- 50% Coding/Projects
- 10% Testing/Debugging

**Stay on Track:**
- Set weekly goals
- Track progress in journal
- Don't skip projects
- Ask for help when stuck
- Take breaks to avoid burnout

---

## Resources

### Essential:
- **LearnCPP.com** - Free C++ tutorial
- **learnopengl.com** - OpenGL tutorials
- **Game Programming Patterns** - Free online book

### Books:
- Computer Systems: A Programmer's Perspective
- Foundations of Game Engine Development Vol 1
- Game Engine Architecture
- Real-Time Rendering

### Tools:
- Visual Studio Community (IDE)
- Git/GitHub (version control)
- CMake (build system)
- GLFW (windowing)
- stb_image (texture loading)

### Communities:
- r/gamedev
- Game Dev Discord servers
- HandmadeHero community
- LearnCPP Discord

---

## Final Notes

**This roadmap is intensive** - 15-20 hours per week for 6 months requires commitment. But if you complete it, you'll have:

- Strong C++ skills
- Complete game engine
- Shipped game
- Portfolio ready for jobs

**The key is consistency.** Missing a week sets you back. Stay disciplined, ask for help, and remember why you started this journey.

**Good luck!** 🎮🚀

---

## Quick Reference Checklist

### Month 1 (Weeks 1-4):
- [ ] C++ fundamentals mastered
- [ ] Command-line tools completed
- [ ] Performance toolkit built
- [ ] Memory concepts understood

### Month 2 (Weeks 5-8):
- [ ] Custom allocators working
- [ ] Data structures implemented
- [ ] Math library complete
- [ ] Physics engine functional

### Month 3 (Weeks 9-12):
- [ ] Physics thoroughly tested
- [ ] OpenGL renderer working
- [ ] Textures loading
- [ ] Sprites rendering

### Month 4 (Weeks 13-16):
- [ ] Batch renderer optimized
- [ ] Camera system complete
- [ ] Text rendering working
- [ ] 10,000+ sprites at 60 FPS

### Month 5 (Weeks 17-20):
- [ ] Engine architecture solid
- [ ] Input system responsive
- [ ] Resources managed
- [ ] GameObject/Component systems

### Month 6 (Weeks 21-26):
- [ ] Game prototype playable
- [ ] Core mechanics fun
- [ ] Polish added
- [ ] Game shipped!

---

**Remember:** Every expert was once a beginner. You've got this! 💪
