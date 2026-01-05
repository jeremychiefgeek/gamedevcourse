# 🎮 Game Development Coursework – Project Assignments

> Each project below is written as a formal assignment.  
> **Assume each project is required coursework**, not an open-ended exercise.

---

## Phase 1 – C++ Fundamentals & Core Systems

### 📘 Project 1A – C++ Fundamentals Suite

**Objective**  
Write three independent command-line programs to demonstrate proficiency with basic C++ syntax, control flow, and standard library usage.

#### Assignment Requirements

You must implement the following three programs:

---

#### 1. Calculator

**Task**
- Read a mathematical expression from standard input
- Support the operators: `+`, `-`, `*`, `/`
- Evaluate the expression and print the result

**Constraints**
- Operands are integers or floating-point numbers
- Expressions are single-line and contain no parentheses
- Division by zero must be handled gracefully

**Required Concepts**
- Functions
- Control flow
- Error handling
- Basic string parsing

---

#### 2. Prime Number Tool

**Task**
- Implement:
  - A function to test whether a number is prime
  - A function that lists all prime numbers up to `N`
  - A Sieve of Eratosthenes implementation

**Constraints**
- `N` may be as large as 1,000,000
- The Sieve implementation must be asymptotically faster than naïve testing

**Required Concepts**
- Loops
- Arrays or vectors
- Algorithmic reasoning

---

#### 3. String Toolkit

**Task**  
Implement a `StringToolkit` class providing:
- Reverse string
- Convert to uppercase
- Convert to lowercase
- Count vowels

**Constraints**
- Must use `std::string`
- Must not use external libraries

---

**Evaluation Criteria**
- Compiles cleanly with warnings enabled
- Functions produce correct results
- Code is readable and well-structured
- Unit tests cover typical and edge cases

---

### ⚙️ Project 1B – Performance Analysis Toolkit

**Objective**  
Measure execution time and observe the effects of memory layout on CPU performance.

#### Assignment Requirements

---

#### 1. High-Resolution Timer

**Task**
- Implement a reusable timing utility using `std::chrono`
- Measure elapsed time in microseconds or milliseconds

**Constraints**
- Timer must work correctly in Release builds
- Timer must be reusable across multiple tests

---

#### 2. Cache Behavior Experiment

**Task**
- Implement two representations of vertex data:
  - Array of Structures (AoS)
  - Structure of Arrays (SoA)
- Update position data for 1,000,000 vertices
- Measure the time taken for each layout

**Constraints**
- The benchmark must isolate memory access (no I/O in timed region)
- Measurements must be repeated and averaged

---

#### 3. Memory Access Patterns

**Task**
- Compare sequential vs random access over a large array
- Measure and report timing differences

---

**Evaluation Criteria**
- Benchmarks run reliably
- Results show measurable trends
- Written explanation correctly interprets results

---

### 🧠 Project 1C – Custom Allocators & Containers

**Objective**  
Implement basic memory allocators and a dynamic container to understand allocation strategies.

#### Assignment Requirements

---

#### 1. Arena Allocator

**Task**
- Allocate a fixed block of memory up front
- Support aligned allocations
- Support fast reset via `clear()`

**Constraints**
- No calls to `new` or `malloc` after initialization
- No deallocation of individual objects

---

#### 2. Pool Allocator

**Task**
- Allocate a pool for fixed-size objects
- Reuse freed slots via a free list

**Constraints**
- Objects must all be the same size
- Allocation and deallocation must be constant time

---

#### 3. Dynamic Array

**Task**
- Implement a vector-like container
- Support `push`, indexing, and iteration

**Constraints**
- Must manage capacity growth manually
- Must support move semantics

---

**Evaluation Criteria**
- No memory leaks
- Correct handling of edge cases
- Behavior matches expectations under stress tests

---

## Phase 2 – Mathematics & Physics (Simulation Only)

> ⚠️ Phase 2 contains no rendering and no windowing.  
> All projects are CPU-side and headless.

---

### ➕ Project 2A – Math Library

**Objective**  
Implement foundational math types used by later systems.

#### Assignment Requirements

---

#### 1. Vector2

**Task**
- Implement 2D vector operations:
  - Addition, subtraction, scalar multiplication
  - Dot product
  - Length and normalization

---

#### 2. Vector3

**Task**
- Extend `Vector2` concepts to 3D
- Implement cross product

---

#### 3. Matrix4

**Task**
- Implement a 4×4 matrix
- Support:
  - Identity
  - Translation
  - Scale
  - Rotation
  - Matrix multiplication

---

#### 4. Quaternion

**Task**
- Represent rotations using quaternions
- Convert to rotation matrix

---

**Evaluation Criteria**
- Unit tests verify mathematical correctness
- Operations produce expected results
- Numerical stability is acceptable

---

### 🧲 Project 2B – 2D Physics Simulation

**Objective**  
Simulate rigid body motion and collision response in 2D.

#### Assignment Requirements

---

#### 1. Rigid Body

**Task**
- Store position, velocity, mass
- Integrate motion using fixed time steps

---

#### 2. Collision Detection

**Task**
- Detect circle-circle collisions
- Compute contact normal and penetration depth

---

#### 3. Collision Resolution

**Task**
- Apply impulse-based collision response
- Support restitution (bounciness)

---

**Performance Requirement**
- Must simulate ~1,000 circle bodies in a headless loop
- Each simulation step must complete in ≤16.6ms (average)
- Excludes rendering

---

**Evaluation Criteria**
- Simulation remains stable
- Objects do not tunnel under reasonable velocities
- Results are deterministic

---

## Phase 3 – Graphics & Rendering

### 🖼️ Project 3A – OpenGL Renderer Base

**Objective**  
Create a basic OpenGL rendering pipeline.

#### Assignment Requirements
- Create a window
- Compile and link shaders
- Render a colored quad

**Evaluation Criteria**
- Window opens correctly
- Rendering output matches expectations
- GPU resources are properly cleaned up

---

### 🧩 Project 3B – Texture & Sprite Rendering

**Objective**  
Render textured sprites using transformation matrices.

#### Assignment Requirements
- Load PNG textures
- Apply position, rotation, and scale
- Render multiple sprites

**Evaluation Criteria**
- Sprites appear correctly transformed
- Textures load without errors

---

### 🎯 Project 3C – Batch Rendering & Camera

**Objective**  
Optimize rendering by batching draw calls and introducing a camera.

#### Assignment Requirements
- Batch multiple sprites into one draw call
- Implement camera pan and zoom

**Evaluation Criteria**
- Draw call count decreases with batching
- Camera transformations behave correctly

---

## Phase 4 – Engine & Game Development

### 🧱 Project 4A – Engine Core

**Objective**  
Integrate all subsystems into a cohesive runtime loop.

#### Assignment Requirements
- Main loop with fixed update and render phases
- Subsystem initialization and shutdown

---

### 🧩 Project 4B – GameObject & Component System

**Objective**  
Implement a composition-based object model.

#### Assignment Requirements
- Add/remove components at runtime
- Update and render via components

---

### 🕹️ Project 4C – Complete Game

**Objective**  
Ship a playable game using all previous systems.

#### Assignment Requirements
- Player, enemies, scoring
- Menus and UI
- Packaged executable
