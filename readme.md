# Game Development Learning Path: 12-Month Roadmap (REVISED)

**Goal:** Build a complete 2D game with a custom engine from scratch  
**Time Commitment:** 10-16 hours/week (2-4 hours M-F)  
**Platform:** Windows  
**Languages:** C → C++

---

## Phase 1: Foundation - C Programming & Computer Systems (Weeks 1-8)

### Primary Resources

- C Programming Language, 2nd Edition (Kernighan & Ritchie)
- Computer Systems: A Programmer's Perspective, 3rd Edition

### Learning Objectives

- Master C fundamentals with focus on pointers, memory, and systems programming
- Understand computer architecture, memory hierarchy, and performance
- Build foundation for low-level programming

---

### Weeks 1-2: C Language Fundamentals

**Read:** K&R Chapters 1-4  
**Focus:** Types, operators, control flow, functions, pointers, arrays

#### Project 1A: Mathematical & Array Utilities Collection

**REVISED:** This project now focuses on computation and arrays without file I/O.

Create a suite of 4 command-line tools that demonstrate C fundamentals:

##### 1. `calc` - Command-Line Calculator

**Usage:** `calc <expression>`

```c
// Examples:
calc 5 + 3        // Output: 8
calc 10 * 4       // Output: 40
calc 100 / 5      // Output: 20
calc 7 - 2        // Output: 5
```

**Requirements:**

- Parse simple arithmetic expressions (two operands, one operator)
- Support: +, -, \*, /
- Handle integer operations
- Display error for invalid input

**Success criteria:**

- Correctly evaluates all basic arithmetic operations
- Handles edge cases (division by zero, invalid operators)

##### 2. `array_ops` - Array Statistics Calculator

**Usage:** `array_ops <size> <numbers...>`

```c
// Example:
array_ops 5 10 20 30 40 50
// Output:
// Sum: 150
// Average: 30.0
// Min: 10
// Max: 50
```

**Requirements:**

- Accept array size and values as command-line arguments
- Calculate sum, average, minimum, maximum
- Use arrays and pointer arithmetic
- Handle up to 1000 elements

**Success criteria:**

- Correctly processes arrays of various sizes
- Accurate calculations for all statistics

##### 3. `str_ops` - String Manipulation Tool

**Usage:** `str_ops <operation> <string>`

```c
// Examples:
str_ops reverse "Hello World"     // dlroW olleH
str_ops length "Testing"          // 7
str_ops upper "hello"             // HELLO
str_ops lower "WORLD"             // world
```

**Requirements:**

- String reversal (in-place)
- String length calculation
- Uppercase/lowercase conversion
- Use character arrays and pointers

**Success criteria:**

- All string operations work correctly
- Handles empty strings and special characters

##### 4. `prime_check` - Prime Number Utilities

**Usage:** `prime_check <operation> <number>`

```c
// Examples:
prime_check test 17       // 17 is prime
prime_check test 18       // 18 is not prime
prime_check list 20       // List all primes up to 20: 2 3 5 7 11 13 17 19
prime_check count 100     // Number of primes up to 100: 25
```

**Requirements:**

- Implement primality test function
- Generate list of primes up to N (Sieve of Eratosthenes)
- Count primes in range
- Use arrays for sieve algorithm

**Success criteria:**

- Correctly identifies primes
- Efficiently generates prime lists
- Handles numbers up to 10,000

**Test Scenarios:**

1. Run calculator with various operations including edge cases
2. Test array operations with 100-element array
3. Reverse a 100-character string
4. Find all primes up to 1000

---

### Weeks 3-4: Advanced C & Data Representation

**Read:** K&R Chapters 5-6, Computer Systems Chapter 2  
**Focus:** Pointers deep dive, structures, bit manipulation, data representation

#### Project 1B: Bit Manipulation Library and Complex Data Structures

**REVISED:** Now focuses purely on in-memory operations with structures and bit manipulation.

Create a library (`bitlib.h` and `bitlib.c`) with the following:

##### 1. Bit Vector Operations

```c
typedef struct {
    uint8_t* data;
    size_t bit_count;
} BitVector;

BitVector* bitvec_create(size_t num_bits);
void bitvec_set(BitVector* bv, size_t index);
void bitvec_clear(BitVector* bv, size_t index);
int bitvec_get(BitVector* bv, size_t index);
void bitvec_toggle(BitVector* bv, size_t index);
size_t bitvec_count_set(BitVector* bv);     // Count set bits
void bitvec_print(BitVector* bv);            // Print as binary string
void bitvec_destroy(BitVector* bv);
```

##### 2. In-Memory Data Encoding

```c
// Compress sequences of repeated values in memory
typedef struct {
    uint8_t value;
    uint8_t count;
} RLEPair;

typedef struct {
    RLEPair* pairs;
    size_t pair_count;
    size_t capacity;
} RLEBuffer;

RLEBuffer* rle_create(void);
void rle_compress(RLEBuffer* buffer, const uint8_t* input, size_t input_len);
void rle_decompress(RLEBuffer* buffer, uint8_t* output, size_t* output_len);
void rle_print(RLEBuffer* buffer);
void rle_destroy(RLEBuffer* buffer);
```

##### 3. Image Data Structure (In-Memory Only)

```c
typedef struct {
    uint32_t width;
    uint32_t height;
    uint8_t* pixels;  // RGB format (width * height * 3 bytes)
} Image;

Image* image_create(uint32_t width, uint32_t height);
void image_set_pixel(Image* img, uint32_t x, uint32_t y,
                     uint8_t r, uint8_t g, uint8_t b);
void image_get_pixel(Image* img, uint32_t x, uint32_t y,
                     uint8_t* r, uint8_t* g, uint8_t* b);
void image_fill(Image* img, uint8_t r, uint8_t g, uint8_t b);
void image_create_gradient(Image* img);  // Red gradient left-to-right
void image_print_info(Image* img);       // Print dimensions and memory size
void image_destroy(Image* img);
```

##### 4. Structure Memory Layout Analysis

```c
// Demonstrate structure padding and alignment
typedef struct {
    char a;      // 1 byte
    int b;       // 4 bytes
    char c;      // 1 byte
} UnalignedStruct;

typedef struct {
    char a;      // 1 byte
    char c;      // 1 byte
    int b;       // 4 bytes
} AlignedStruct;

void print_struct_sizes(void);
void print_struct_offsets(void);
void demonstrate_padding(void);
```

**Test Scenarios:**

1. **Bit Vector Tests**
   - Create a 1000-bit vector, set every prime-numbered bit
   - Verify count_set returns correct number of primes < 1000
   - Toggle all bits and verify count changes correctly
   - Print bit patterns

2. **RLE Compression Tests**
   - Create a large array with pattern "AAAAABBBBBCCCCC" repeated
   - Compress it - should be dramatically smaller
   - Decompress and verify byte-for-byte match
   - Success criteria: >90% compression ratio on repetitive data

3. **Image Structure Tests**
   - Create a 256x256 gradient image programmatically
   - Verify all pixel values are correct
   - Calculate expected memory size: 256 _ 256 _ 3 = 196,608 bytes
   - Verify structure padding doesn't waste space

4. **Memory Layout Tests**
   - Print sizes of aligned vs unaligned structures
   - Demonstrate padding effects
   - Calculate memory savings from proper alignment

**Deliverable Checklist:**

- [ ] All functions implemented with proper error handling
- [ ] Test suite with at least 20 test cases
- [ ] Demonstration program showing all features
- [ ] README explaining memory layouts and bit operations

---

### Weeks 5-6: Memory Architecture & Assembly Basics

**Read:** Computer Systems Chapters 3-4  
**Focus:** Machine-level representation, processor architecture, memory hierarchy

#### Project 1C: Performance Profiling and Optimization Toolkit

**UNCHANGED** - This project is already well-aligned with the chapter content.

Build a performance measurement library and use it to explore memory hierarchy effects.

##### 1. High-Resolution Timer

```c
typedef struct {
    uint64_t start;
    uint64_t end;
} PerfTimer;

void perf_timer_start(PerfTimer* timer);
void perf_timer_end(PerfTimer* timer);
double perf_timer_get_ms(PerfTimer* timer);
uint64_t perf_timer_get_cycles(PerfTimer* timer);
```

**Implementation notes:**

- Use `QueryPerformanceCounter` on Windows
- Store CPU cycles using `__rdtsc()` intrinsic

##### 2. Cache Performance Experiments

Implement and benchmark these scenarios:

**Experiment A: Array Traversal Patterns**

```c
#define ARRAY_SIZE (64 * 1024 * 1024)  // 64M integers
int32_t* array = malloc(ARRAY_SIZE * sizeof(int32_t));

// Test 1: Sequential access (cache-friendly)
for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = array[i] * 2;
}

// Test 2: Strided access (various stride sizes: 1, 2, 4, 8, 16, 32, 64)
for (int i = 0; i < ARRAY_SIZE; i += STRIDE) {
    array[i] = array[i] * 2;
}

// Test 3: Random access (cache-hostile)
for (int i = 0; i < ARRAY_SIZE; i++) {
    int idx = random_indices[i];
    array[idx] = array[idx] * 2;
}
```

**Experiment B: Structure Layout Impact (AOS vs SOA)**

```c
// Array of Structures (AOS)
typedef struct {
    float x, y, z;      // position
    float r, g, b;      // color
    float nx, ny, nz;   // normal
} Vertex_AOS;

// Structure of Arrays (SOA)
typedef struct {
    float* x;  float* y;  float* z;   // positions
    float* r;  float* g;  float* b;   // colors
    float* nx; float* ny; float* nz;  // normals
} VertexArray_SOA;

// Benchmark: Update only positions for 1M vertices
// AOS: touches all 36 bytes per vertex
// SOA: touches only 12 bytes per vertex (3 position floats)
```

**Test Scenarios and Success Criteria:**

1. **Timer Accuracy Test**
   - Measure a Sleep(100ms) call - should be within ±2ms
   - Measure 1000 iterations of empty loop - should be consistent
   - Success: Timer resolution < 1 microsecond

2. **Cache Performance Expectations**
   - Sequential array access: ~20-50 cycles per element
   - Stride-16 access: 2-3x slower than sequential
   - Random access: 10-20x slower than sequential
   - Document your actual results with CPU specs

3. **AOS vs SOA Comparison**
   - Position-only update on SOA: 2-3x faster than AOS
   - Full vertex update: similar performance
   - Success: Clear performance difference when accessing subset of data

**Deliverables:**

- [ ] Working performance timer with microsecond precision
- [ ] All experiments implemented with 5+ variations each
- [ ] Comprehensive report with timing results, graphs, and explanations

---

### Weeks 7-8: Linking, Loading & I/O

**Read:** K&R Chapter 7 (Input/Output), Computer Systems Chapters 7, 10  
**Focus:** File I/O, linking, loading, system-level I/O, virtual memory concepts

#### Project 1D: File I/O and Build System

**REVISED:** Now properly introduces file I/O when K&R Chapter 7 is covered.

This project has two parts:

##### Part 1: File Utilities (K&R Chapter 7)

Now that you've learned file I/O, implement the utilities from Week 1-2 with file operations:

**1. `wc_custom` - Word/Line/Character Counter**

```c
// Usage: wc_custom [-l] [-w] [-c] <filename>
// Count lines (-l), words (-w), or characters (-c) in a file
// If no flags, output all three counts
```

**Success criteria:** Matches output of Unix `wc` command on test files

**2. `file_copy` - Efficient File Copier**

```c
// Usage: file_copy <source> <destination>
// Copy file using buffered I/O (4KB buffer minimum)
// Display progress for files > 1MB
```

**Success criteria:** Copy a 50MB file, verify byte-for-byte match with original

**3. `grep_lite` - Simple Pattern Finder**

```c
// Usage: grep_lite <pattern> <filename>
// Print all lines containing the pattern string
// Include line numbers in output
```

**Success criteria:** Find "TODO" in your source code, match results manually

**4. `hex_dump` - Binary File Viewer**

```c
// Usage: hex_dump <filename>
// Display file contents in hexadecimal format
// Show both hex values and ASCII representation
// Format: address | hex bytes | ASCII
```

**Test Scenarios:**

- Run wc_custom on a large text file (War and Peace)
- Copy your entire project directory and verify integrity
- Use grep_lite to find all function definitions in your C code
- View binary executable with hex_dump

##### Part 2: Mini Build System (Computer Systems Ch 7)

Create a simple build tool called `cbuild` that compiles multi-file C projects with dependency tracking.

**Core Features:**

**1. Project Configuration File (build.cfg)**

```
project_name: MyGame
output: bin/MyGame.exe
compiler: gcc
flags: -Wall -O2 -g
include_dirs: include, src/common
sources:
    src/main.c
    src/game.c
    src/renderer.c
```

**2. Build Tool Functionality**

```c
// Your tool should handle:
cbuild           // Build entire project
cbuild clean     // Remove all build artifacts
cbuild rebuild   // Clean + build
cbuild -v        // Verbose output
```

**3. Dependency Tracking**

- Parse `#include` directives from source files
- Track file modification times
- Only recompile files whose dependencies changed
- Store dependency graph in `.cbuild/deps.cache`

**Test Scenarios:**

1. **Initial Build Test**
   - Create a project with 10 .c files that include common headers
   - Run `cbuild` - should compile all files and link
   - Verify executable is created

2. **Incremental Build Test**
   - Run `cbuild` again immediately
   - Should output "Nothing to do - up to date"
   - Touch one source file
   - Run `cbuild` - should recompile only that file

3. **Header Change Test**
   - Modify a header file included by 3 source files
   - Run `cbuild`
   - Should recompile exactly those 3 files

**Deliverables:**

- [ ] All file utilities working correctly
- [ ] Build system with dependency tracking
- [ ] Test suite demonstrating all features
- [ ] Documentation on how to use cbuild

---

### Phase 1 Checkpoint:

- [ ] Can you explain the memory layout of a C program?
- [ ] Can you debug segmentation faults confidently?
- [ ] Do you understand the cost of memory operations?
- [ ] Can you work with files efficiently?

---

## Phase 2: Memory Management & Data Structures (Weeks 9-14)

### Primary Resources

- Computer Systems: A Programmer's Perspective (Chapter 9)
- Data Oriented Design (Richard Fabian) - Selected chapters
- Handmade Hero supplementary: Episodes 1-30

### Learning Objectives

- Implement custom memory allocators
- Build cache-friendly data structures
- Understand data-oriented design principles

---

### Weeks 9-10: Memory Allocation

**Read:** Computer Systems Chapter 9, Data Oriented Design Chapters 1-3

#### Project 2A: Custom Memory Allocator Suite

**UNCHANGED** - This project is properly scoped.

Implement three fundamental allocator types:

##### 1. Arena/Linear Allocator

```c
typedef struct {
    void* memory;
    size_t size;
    size_t used;
} Arena;

Arena* arena_create(size_t size);
void* arena_alloc(Arena* arena, size_t size);
void arena_clear(Arena* arena);      // Reset, no individual free
void arena_destroy(Arena* arena);
```

**Use Case:** Perfect for per-frame allocations

- Allocate all frame data
- At end of frame, clear entire arena
- No fragmentation

**Test Scenario:**

```c
Arena* frame_arena = arena_create(MEGABYTES(16));
for (int frame = 0; frame < 1000; frame++) {
    // Allocate 10,000 entities' transform data
    for (int i = 0; i < 10000; i++) {
        Matrix4x4* transform = arena_alloc(frame_arena, sizeof(Matrix4x4));
    }
    arena_clear(frame_arena);  // Instant free
}
// Success: No memory leaks, consistent frame times
```

##### 2. Stack Allocator

```c
typedef struct {
    void* memory;
    size_t size;
    size_t used;
} StackAllocator;

typedef struct { size_t offset; } StackMarker;

StackAllocator* stack_create(size_t size);
void* stack_alloc(StackAllocator* stack, size_t size);
StackMarker stack_get_marker(StackAllocator* stack);
void stack_free_to_marker(StackAllocator* stack, StackMarker marker);
```

**Use Case:** Scope-based temporary memory

##### 3. Pool Allocator

```c
typedef struct {
    void* memory;
    size_t chunk_size;
    size_t chunk_count;
    void* free_list;
} PoolAllocator;

PoolAllocator* pool_create(size_t chunk_size, size_t chunk_count);
void* pool_alloc(PoolAllocator* pool);
void pool_free(PoolAllocator* pool, void* ptr);
```

**Use Case:** Fixed-size object allocation (particles, entities)

- O(1) allocation and deallocation
- No fragmentation
- Cache-friendly

**Benchmark Results You Should See:**

| Allocator | Sequential Alloc | Sequential Free | Random Mix |
| --------- | ---------------- | --------------- | ---------- |
| malloc    | 100ns            | 50ns            | 120ns      |
| Arena     | 10ns             | 0ns (clear)     | N/A        |
| Stack     | 15ns             | 5ns (marker)    | N/A        |
| Pool      | 5ns              | 5ns             | 5ns        |

**Success Criteria:**

- [ ] All three allocators fully implemented
- [ ] Valgrind reports no memory leaks
- [ ] Arena 10x faster than malloc
- [ ] Pool 20x faster for fixed-size objects

---

### Weeks 11-12: Data Structures - Cache Conscious Design

**Read:** Data Oriented Design Chapters 4-6

#### Project 2B: Cache-Optimized Data Structure Library

**UNCHANGED** - Well-scoped for data structure learning.

##### 1. Dynamic Array (Vector)

```c
typedef struct {
    void* data;
    size_t element_size;
    size_t count;
    size_t capacity;
    Arena* allocator;
} DynamicArray;

DynamicArray* dynarr_create(size_t element_size, size_t initial_capacity, Arena* allocator);
void dynarr_push(DynamicArray* arr, void* element);
void* dynarr_get(DynamicArray* arr, size_t index);
```

**Growth Strategy:** When capacity reached, grow by 1.5x or 2x

##### 2. Hash Table (Open Addressing)

```c
typedef struct {
    uint64_t hash;
    void* key;
    void* value;
    uint8_t occupied;
} HashEntry;

typedef struct {
    HashEntry* entries;
    size_t capacity;
    size_t count;
} HashMap;
```

**Collision Resolution:** Linear probing  
**Load Factor:** Rehash at 70% full

##### 3. Data-Oriented Entity Storage (SOA)

Compare these layouts:

```c
// Array of Structures (Traditional - AOS)
typedef struct {
    Vector3 position;
    Vector3 velocity;
    Vector3 color;
    float mass;
    int active;
} Entity_AOS;

Entity_AOS entities_aos[10000];

// Structure of Arrays (Data-Oriented - SOA)
typedef struct {
    Vector3* positions;
    Vector3* velocities;
    Vector3* colors;
    float* masses;
    int* actives;
    size_t count;
} EntityArray_SOA;
```

**Test Scenario - Cache Performance:**

```c
// Update loop - only touches position and velocity
void update_soa(EntityArray_SOA* entities, float dt) {
    for (size_t i = 0; i < entities->count; i++) {
        if (entities->actives[i]) {
            entities->positions[i].x += entities->velocities[i].x * dt;
            // ...
        }
    }
}
// Expected: SOA 2-3x faster due to better cache utilization
```

**Success Criteria:**

- [ ] All data structures pass test suite (50+ tests)
- [ ] Dynamic array push: <10ns average
- [ ] Hash table lookup: <100ns
- [ ] SOA update: 2x+ faster than AOS

---

### Weeks 13-14: Advanced Data Structures

#### Project 2C: Entity Component System (ECS) Prototype

**UNCHANGED** - Excellent capstone for Phase 2.

Build a simple but functional ECS architecture.

**Core Architecture:**

```c
// Entity is just an ID
typedef uint32_t Entity;

// Component type enumeration
typedef enum {
    COMPONENT_TRANSFORM = 1 << 0,
    COMPONENT_VELOCITY  = 1 << 1,
    COMPONENT_SPRITE    = 1 << 2,
    COMPONENT_COLLIDER  = 1 << 3,
} ComponentType;

// Component data (SOA layout)
typedef struct {
    float x, y;
    float rotation;
} Transform;

typedef struct {
    float dx, dy;
} Velocity;
```

**Entity Manager:**

```c
typedef struct {
    uint32_t mask;   // Bitmask of components
    uint32_t index;  // Index into component arrays
} EntityRecord;

Entity entity_create(EntityManager* mgr);
void entity_destroy(EntityManager* mgr, Entity entity);
void entity_add_component(EntityManager* mgr, Entity entity, ComponentType type);
```

**System Interface:**

```c
typedef void (*SystemUpdateFn)(ComponentStorage* storage, EntityManager* mgr, float dt);

void movement_system_update(ComponentStorage* storage, EntityManager* mgr, float dt);
void collision_system_update(ComponentStorage* storage, EntityManager* mgr, float dt);
```

**Movement System Implementation:**

```c
void movement_system_update(ComponentStorage* storage, EntityManager* mgr, float dt) {
    // Iterate only entities that have BOTH components
    for (size_t i = 0; i < storage->transforms.count; i++) {
        Entity entity = storage->transforms.entity_map[i];
        if (entity_has_component(mgr, entity, COMPONENT_VELOCITY)) {
            Transform* transform = &storage->transforms.data[i];
            Velocity* velocity = get_velocity(storage, mgr, entity);

            transform->x += velocity->dx * dt;
            transform->y += velocity->dy * dt;
        }
    }
}
```

**Test Scenarios:**

1. **Entity Creation Test**
   - Create 1000 entities with random component combinations
   - Verify: entity count, component counts, no memory leaks

2. **System Processing Performance**
   - Benchmark movement system: should process 10,000 entities in < 1ms
   - Only iterates entities with required components

3. **Realistic Game Simulation**
   - Mini asteroids-like game
   - 1 player, 50 asteroids, bullets spawn/despawn dynamically
   - Run 3600 frames (1 minute at 60fps)
   - Success: stable memory, consistent frame times

**Success Criteria:**

- [ ] Entities are just IDs (32-bit integers)
- [ ] Components stored in SOA layout
- [ ] Systems iterate only relevant entities
- [ ] Process 10,000 entities per system: < 1ms

---

### Phase 2 Checkpoint:

- [ ] Can you implement a custom allocator from scratch?
- [ ] Do you understand cache misses and how to minimize them?
- [ ] Can you explain SOA vs AOS tradeoffs?

---

## Phase 3: Mathematics Foundation (Weeks 15-20)

### Primary Resources

- Introduction to Linear Algebra (Gilbert Strang, 5th Edition) - Selected chapters
- Foundations of Game Engine Development, Volume 1: Mathematics
- Calculus: An Intuitive and Physical Approach - As needed reference

### Learning Objectives

- Master vectors, matrices, and transformations
- Understand coordinate systems and spaces
- Build intuition for game physics math

---

### Weeks 15-16: Vectors & Basic Linear Algebra

**Read:** Strang Chapters 1-3, FGED Volume 1 Chapters 1-2  
**Focus:** Vector operations, dot product, cross product, linear independence

#### Project 3A: 2D Math Library with Visualization

**REVISED:** Added console-based visualization since we don't have graphics yet.

Build a comprehensive 2D math library.

##### 1. Vector2 Structure and Operations

```c
typedef struct {
    float x, y;
} Vector2;

// Construction
Vector2 vec2(float x, float y);
Vector2 vec2_zero(void);
Vector2 vec2_one(void);
Vector2 vec2_up(void);     // (0, 1)
Vector2 vec2_right(void);  // (1, 0)

// Basic operations
Vector2 vec2_add(Vector2 a, Vector2 b);
Vector2 vec2_sub(Vector2 a, Vector2 b);
Vector2 vec2_mul(Vector2 v, float scalar);
Vector2 vec2_negate(Vector2 v);

// Vector math
float vec2_length(Vector2 v);
float vec2_length_squared(Vector2 v);  // Faster, avoids sqrt
float vec2_distance(Vector2 a, Vector2 b);
float vec2_dot(Vector2 a, Vector2 b);
float vec2_cross(Vector2 a, Vector2 b);  // Returns scalar in 2D
Vector2 vec2_normalize(Vector2 v);
Vector2 vec2_perpendicular(Vector2 v);   // Rotate 90 degrees CCW

// Interpolation
Vector2 vec2_lerp(Vector2 a, Vector2 b, float t);
Vector2 vec2_reflect(Vector2 v, Vector2 normal);
Vector2 vec2_project(Vector2 v, Vector2 onto);

// Rotation
Vector2 vec2_rotate(Vector2 v, float angle_radians);

// Utility
int vec2_equals(Vector2 a, Vector2 b, float epsilon);
void vec2_print(Vector2 v);
```

##### 2. Matrix3x3 (2D Homogeneous Coordinates)

```c
typedef struct {
    float m[3][3];  // Row-major
} Matrix3;

Matrix3 mat3_identity(void);
Matrix3 mat3_translation(float tx, float ty);
Matrix3 mat3_rotation(float angle_radians);
Matrix3 mat3_scale(float sx, float sy);
Matrix3 mat3_trs(Vector2 translation, float rotation, Vector2 scale);

// Operations
Matrix3 mat3_mul(Matrix3 a, Matrix3 b);
Vector2 mat3_mul_vec2(Matrix3 m, Vector2 v);  // Treats v as (x, y, 1)
Matrix3 mat3_inverse(Matrix3 m);
void mat3_print(Matrix3 m);
```

##### 3. Console Visualization Functions (NEW)

```c
// Print a 2D coordinate system to console
void draw_2d_grid(int width, int height);
void draw_vector(Vector2 v, char symbol);
void draw_point(Vector2 p);
void draw_line(Vector2 start, Vector2 end);

// Example usage:
void visualize_reflection() {
    draw_2d_grid(40, 20);
    Vector2 incident = vec2(5, 3);
    Vector2 normal = vec2(0, 1);
    Vector2 reflected = vec2_reflect(incident, normal);

    draw_vector(incident, '>');
    draw_vector(normal, '^');
    draw_vector(reflected, '<');
}
```

##### 4. Comprehensive Unit Tests

Create a test suite with at least 50 tests:

```c
void test_vec2_normalize(void) {
    Vector2 v = vec2(3, 4);
    Vector2 n = vec2_normalize(v);
    assert(fabs(vec2_length(n) - 1.0f) < 0.0001f);
    assert(vec2_equals(n, vec2(0.6f, 0.8f), 0.0001f));
}

void test_vec2_dot(void) {
    Vector2 a = vec2(1, 0);
    Vector2 b = vec2(1, 0);
    assert(fabs(vec2_dot(a, b) - 1.0f) < 0.0001f);

    Vector2 c = vec2(0, 1);
    assert(fabs(vec2_dot(a, c) - 0.0f) < 0.0001f);  // Perpendicular
}

void test_mat3_trs(void) {
    Vector2 pos = vec2(10, 20);
    float rot = M_PI / 4;  // 45 degrees
    Vector2 scale = vec2(2, 2);

    Matrix3 m = mat3_trs(pos, rot, scale);

    // Transform a point
    Vector2 local_point = vec2(1, 0);
    Vector2 world_point = mat3_mul_vec2(m, local_point);
    // Verify result matches expected
}
```

**Test Scenarios:**

1. **Physics Simulation Validation**

```c
// Simulate a bouncing ball
Vector2 position = vec2(0, 100);
Vector2 velocity = vec2(50, -50);
Vector2 gravity = vec2(0, -98);
float dt = 1.0f / 60.0f;

for (int i = 0; i < 600; i++) {  // 10 seconds
    velocity = vec2_add(velocity, vec2_mul(gravity, dt));
    position = vec2_add(position, vec2_mul(velocity, dt));

    // Bounce off ground
    if (position.y < 0) {
        position.y = 0;
        velocity.y = -velocity.y * 0.8f;  // 80% restitution
    }
}
// Verify: ball loses energy and settles on ground
```

2. **Reflection Test (Pool Ball)**

```c
Vector2 velocity = vec2(10, 5);
Vector2 wall_normal = vec2(0, 1);  // Horizontal wall
Vector2 reflected = vec2_reflect(velocity, wall_normal);
// Should be (10, -5) - x unchanged, y flipped
assert(vec2_equals(reflected, vec2(10, -5), 0.001f));
```

3. **Console Visualization Test**

- Visualize vector addition
- Show rotation of a vector through 360 degrees
- Demonstrate reflection off various surfaces
- Plot trajectory of projectile motion

**Success Criteria:**

- [ ] All 50+ unit tests pass
- [ ] No math functions use degrees (always radians internally)
- [ ] Proper epsilon comparison for floating point
- [ ] Physics simulation produces realistic motion
- [ ] Console visualizations help understand operations

---

### Weeks 17-18: Matrices & Transformations

**Read:** Strang Chapters 4-5, FGED Volume 1 Chapters 3-4  
**Focus:** Matrix multiplication, transformations, homogeneous coordinates

#### Project 3B: 3D Math Library Foundation

**UNCHANGED** - This project is well-structured.

Extend your math library to 3D.

##### 1. Vector3 Implementation

```c
typedef struct {
    float x, y, z;
} Vector3;

Vector3 vec3(float x, float y, float z);
Vector3 vec3_zero(void);
Vector3 vec3_up(void);       // (0, 1, 0)
Vector3 vec3_right(void);    // (1, 0, 0)
Vector3 vec3_forward(void);  // (0, 0, 1)

// All Vector2 operations plus:
Vector3 vec3_cross(Vector3 a, Vector3 b);  // Returns Vector3 in 3D
Vector3 vec3_rotate_around_axis(Vector3 v, Vector3 axis, float angle);
```

##### 2. Matrix4x4 (The Workhorse)

```c
typedef struct {
    float m[4][4];  // Row-major: m[row][col]
} Matrix4;

// Construction
Matrix4 mat4_identity(void);
Matrix4 mat4_translation(Vector3 translation);
Matrix4 mat4_scale(Vector3 scale);
Matrix4 mat4_rotation_x(float angle);
Matrix4 mat4_rotation_y(float angle);
Matrix4 mat4_rotation_z(float angle);
Matrix4 mat4_rotation_axis(Vector3 axis, float angle);

// TRS composition
Matrix4 mat4_trs(Vector3 translation, Quaternion rotation, Vector3 scale);

// Operations
Matrix4 mat4_mul(Matrix4 a, Matrix4 b);
Vector3 mat4_mul_point(Matrix4 m, Vector3 p);      // Treats as (x,y,z,1)
Vector3 mat4_mul_direction(Matrix4 m, Vector3 d);  // Treats as (x,y,z,0)
Matrix4 mat4_transpose(Matrix4 m);
Matrix4 mat4_inverse(Matrix4 m);

// View matrix (camera)
Matrix4 mat4_look_at(Vector3 eye, Vector3 target, Vector3 up);

// Projection matrices
Matrix4 mat4_perspective(float fov_y, float aspect, float near, float far);
Matrix4 mat4_orthographic(float left, float right, float bottom, float top,
                          float near, float far);
```

##### 3. Quaternion (For Rotations)

```c
typedef struct {
    float x, y, z, w;  // w is the scalar part
} Quaternion;

Quaternion quat_identity(void);  // (0, 0, 0, 1)
Quaternion quat_from_axis_angle(Vector3 axis, float angle);
Quaternion quat_from_euler(float pitch, float yaw, float roll);

// Operations
Quaternion quat_mul(Quaternion a, Quaternion b);  // Composition
Quaternion quat_normalize(Quaternion q);

// Interpolation
Quaternion quat_slerp(Quaternion a, Quaternion b, float t);  // Spherical lerp
Quaternion quat_nlerp(Quaternion a, Quaternion b, float t);  // Normalized lerp (faster)

// Conversion
Vector3 quat_rotate_vec3(Quaternion q, Vector3 v);
Matrix4 quat_to_matrix(Quaternion q);
```

**Test Scenarios:**

1. **Matrix Multiplication Order Test:**

```c
void test_matrix_multiplication_order(void) {
    Matrix4 translate = mat4_translation(vec3(10, 0, 0));
    Matrix4 scale = mat4_scale(vec3(2, 2, 2));

    // Scale then translate
    Matrix4 st = mat4_mul(translate, scale);
    Vector3 p1 = vec3(1, 0, 0);
    Vector3 result1 = mat4_mul_point(st, p1);
    // Expected: scale to (2,0,0), then translate to (12,0,0)
    assert(vec3_equals(result1, vec3(12, 0, 0), 0.001f));

    // Translate then scale
    Matrix4 ts = mat4_mul(scale, translate);
    Vector3 result2 = mat4_mul_point(ts, p1);
    // Expected: translate to (11,0,0), then scale to (22,0,0)
    assert(vec3_equals(result2, vec3(22, 0, 0), 0.001f));

    // They're different! Order matters!
}
```

2. **Quaternion SLERP Test:**

```c
void test_quaternion_slerp(void) {
    // Smooth rotation from 0° to 180° around Y axis
    Quaternion q_start = quat_identity();
    Quaternion q_end = quat_from_axis_angle(vec3_up(), M_PI);

    for (int i = 0; i <= 10; i++) {
        float t = i / 10.0f;
        Quaternion q_interp = quat_slerp(q_start, q_end, t);
        Vector3 forward = quat_rotate_vec3(q_interp, vec3_forward());
        printf("t=%.1f: ", t);
        vec3_print(forward);
    }
    // Should show smooth rotation, no flipping
}
```

3. **View Matrix Test (Camera):**

```c
void test_view_matrix(void) {
    // Camera at (0, 0, 10), looking at origin
    Vector3 eye = vec3(0, 0, 10);
    Vector3 target = vec3_zero();
    Vector3 up = vec3_up();

    Matrix4 view = mat4_look_at(eye, target, up);

    // Transform world origin to view space
    Vector3 origin_view = mat4_mul_point(view, target);

    // Origin should be at (0, 0, -10) in view space
    assert(vec3_equals(origin_view, vec3(0, 0, -10), 0.001f));
}
```

**Success Criteria:**

- [ ] All 60+ unit tests pass with epsilon < 0.001
- [ ] Matrix multiplication order is correct and documented
- [ ] Quaternions interpolate smoothly (no flipping)
- [ ] View matrix correctly transforms world to view space
- [ ] No gimbal lock with quaternions

**Performance Benchmarks:**

- `mat4_mul`: ~20ns per operation
- `quat_slerp`: ~50ns per operation
- `quat_nlerp`: ~20ns (3x faster!)
- `mat4_inverse`: ~100ns per operation

---

### Weeks 19-20: Applied Math - Physics & Collision

**Read:** FGED Volume 1 Chapters 5-6, Calculus book as needed  
**Focus:** Derivatives for motion, integration, basic collision detection

#### Project 3C: 2D Physics Sandbox with Collision Detection

**UNCHANGED** - Excellent applied mathematics project.

Build a complete 2D physics system.

##### 1. Physics Core - Rigid Body Dynamics

```c
typedef struct {
    // Kinematics
    Vector2 position;
    float rotation;
    Vector2 velocity;
    float angular_velocity;

    // Dynamics
    Vector2 force;
    float torque;
    Vector2 acceleration;

    // Physical properties
    float mass;
    float inverse_mass;
    float inertia;
    float inverse_inertia;

    // Material properties
    float restitution;  // Bounciness (0-1)
    float friction;
    int is_static;
} RigidBody2D;

RigidBody2D rigidbody_create(Vector2 position, float mass);
void rigidbody_apply_force(RigidBody2D* body, Vector2 force);
void rigidbody_apply_impulse(RigidBody2D* body, Vector2 impulse);
void rigidbody_integrate(RigidBody2D* body, float dt);
void rigidbody_clear_forces(RigidBody2D* body);
```

**Integration Implementation:**

```c
void rigidbody_integrate(RigidBody2D* body, float dt) {
    if (body->is_static) return;

    // F = ma => a = F/m
    body->acceleration = vec2_mul(body->force, body->inverse_mass);

    // Semi-implicit Euler (more stable)
    body->velocity = vec2_add(body->velocity, vec2_mul(body->acceleration, dt));
    body->position = vec2_add(body->position, vec2_mul(body->velocity, dt));

    // Angular motion
    body->angular_acceleration = body->torque * body->inverse_inertia;
    body->angular_velocity += body->angular_acceleration * dt;
    body->rotation += body->angular_velocity * dt;

    // Apply drag
    body->velocity = vec2_mul(body->velocity, 0.99f);
    body->angular_velocity *= 0.98f;
}
```

##### 2. Collision Detection

**Circle vs Circle:**

```c
typedef struct {
    int colliding;
    Vector2 normal;
    float penetration;
    Vector2 contact_point;
} CollisionInfo;

CollisionInfo collision_circle_circle(Collider2D* a, Collider2D* b) {
    CollisionInfo info = {0};
    Vector2 delta = vec2_sub(b->body->position, a->body->position);
    float dist_sq = vec2_length_squared(delta);
    float radius_sum = a->circle.radius + b->circle.radius;

    if (dist_sq < radius_sum * radius_sum) {
        info.colliding = 1;
        float dist = sqrtf(dist_sq);
        info.normal = vec2_div(delta, dist);
        info.penetration = radius_sum - dist;

        Vector2 offset = vec2_mul(info.normal,
                                  a->circle.radius - info.penetration * 0.5f);
        info.contact_point = vec2_add(a->body->position, offset);
    }
    return info;
}
```

##### 3. Collision Response

```c
void resolve_collision(CollisionInfo* info, RigidBody2D* a, RigidBody2D* b) {
    if (!info->colliding) return;

    // Position correction
    float percent = 0.8f;
    float slop = 0.01f;
    float correction_mag = fmaxf(info->penetration - slop, 0.0f) /
                          (a->inverse_mass + b->inverse_mass) * percent;
    Vector2 correction = vec2_mul(info->normal, correction_mag);

    a->position = vec2_sub(a->position, vec2_mul(correction, a->inverse_mass));
    b->position = vec2_add(b->position, vec2_mul(correction, b->inverse_mass));

    // Velocity correction (impulse)
    Vector2 relative_velocity = vec2_sub(b->velocity, a->velocity);
    float velocity_along_normal = vec2_dot(relative_velocity, info->normal);

    if (velocity_along_normal > 0) return;  // Separating

    float e = fminf(a->restitution, b->restitution);
    float j = -(1 + e) * velocity_along_normal;
    j /= a->inverse_mass + b->inverse_mass;

    Vector2 impulse = vec2_mul(info->normal, j);
    a->velocity = vec2_sub(a->velocity, vec2_mul(impulse, a->inverse_mass));
    b->velocity = vec2_add(b->velocity, vec2_mul(impulse, b->inverse_mass));
}
```

**Test Scenarios:**

1. **Bouncing Ball**
   - Ball with 80% restitution bouncing on ground
   - Should bounce multiple times, each lower than last
   - Eventually comes to rest

2. **Newton's Cradle**
   - 5 balls in a row with perfect restitution
   - Pull first ball back and release
   - Energy should transfer through middle balls to last ball

3. **Box Stacking**
   - Stack 10 boxes with friction
   - Simulate for 10 seconds
   - Stack should remain stable (not collapse or explode)

**Success Criteria:**

- [ ] Bouncing ball loses energy each bounce
- [ ] Newton's cradle transfers energy correctly
- [ ] Box stack remains stable
- [ ] No tunneling (fast objects passing through walls)

---

### Phase 3 Checkpoint:

- [ ] Can you implement matrix multiplication from scratch?
- [ ] Do you understand transformation matrices for 2D graphics?
- [ ] Can you derive basic physics equations?

---

## Phase 4: C++ Transition (Weeks 21-26)

### Primary Resources

- A Tour of C++, 2nd Edition (Primary learning)
- Effective Modern C++ (Reference for best practices)
- Professional C++ (Comprehensive reference)

### Learning Objectives

- Learn modern C++11/14/17 features
- Understand RAII, move semantics, templates
- Transition from C mindset to C++ best practices

---

### Weeks 21-22: C++ Fundamentals

**Read:** Tour of C++ Chapters 1-6  
**Focus:** Classes, constructors/destructors, RAII, references, namespaces

#### Project 4A: C++ Math Library Refactor

**UNCHANGED** - Perfect for learning C++ fundamentals.

Transform your C math library into idiomatic C++.

##### 1. Vector Classes with Operators

```cpp
namespace math {

class Vector2 {
public:
    float x, y;

    // Constructors
    Vector2() : x(0), y(0) {}
    Vector2(float x, float y) : x(x), y(y) {}

    // Static factory methods
    static Vector2 zero() { return Vector2(0, 0); }
    static Vector2 up() { return Vector2(0, 1); }

    // Operator overloading
    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator-(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 operator*(float scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    Vector2& operator+=(const Vector2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    bool operator==(const Vector2& other) const {
        return std::abs(x - other.x) < 0.0001f &&
               std::abs(y - other.y) < 0.0001f;
    }

    // Member functions (const-correct!)
    float length() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2 normalized() const {
        float len = length();
        return (len > 0) ? (*this / len) : Vector2::zero();
    }

    float dot(const Vector2& other) const {
        return x * other.x + y * other.y;
    }

    // Stream output
    friend std::ostream& operator<<(std::ostream& os, const Vector2& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};

} // namespace math
```

##### 2. Matrix4 with RAII

```cpp
class Matrix4 {
private:
    float m_data[16];  // Column-major for OpenGL

public:
    // Constructors
    Matrix4() {
        std::fill(m_data, m_data + 16, 0.0f);
        m_data[0] = m_data[5] = m_data[10] = m_data[15] = 1.0f;
    }

    // Copy/Move (defaulted)
    Matrix4(const Matrix4& other) = default;
    Matrix4(Matrix4&& other) noexcept = default;
    Matrix4& operator=(const Matrix4& other) = default;
    Matrix4& operator=(Matrix4&& other) noexcept = default;

    // Element access (const-correct)
    float& operator()(size_t row, size_t col) {
        return m_data[col * 4 + row];
    }

    const float& operator()(size_t row, size_t col) const {
        return m_data[col * 4 + row];
    }

    // Static factory methods
    static Matrix4 translation(const Vector3& t);
    static Matrix4 scale(const Vector3& s);
    static Matrix4 rotationX(float angle);

    // Operators
    Matrix4 operator*(const Matrix4& other) const;
    Vector3 operator*(const Vector3& v) const;
};
```

##### 3. RAII Example - Scoped Resource

```cpp
class ScopedArena {
private:
    Arena* m_arena;
    size_t m_marker;

public:
    explicit ScopedArena(Arena* arena)
        : m_arena(arena)
        , m_marker(arena->getUsed())
    {}

    ~ScopedArena() {
        m_arena->freeToMarker(m_marker);
    }

    // Delete copy, allow move
    ScopedArena(const ScopedArena&) = delete;
    ScopedArena& operator=(const ScopedArena&) = delete;

    ScopedArena(ScopedArena&& other) noexcept
        : m_arena(other.m_arena)
        , m_marker(other.m_marker)
    {
        other.m_arena = nullptr;
    }

    void* alloc(size_t size) {
        return m_arena->alloc(size);
    }
};

// Usage:
void someFunction() {
    Arena* arena = getArena();
    {
        ScopedArena scoped(arena);
        float* data = (float*)scoped.alloc(1000 * sizeof(float));
        // Use data...
    }  // Destructor automatically frees!
}
```

**Test Scenarios:**

1. **Operator Overloading Natural Usage**

```cpp
Vector2 a(3, 4);
Vector2 b(1, 2);

// C++ version is much cleaner
Vector2 result = (a - b) + Vector2::up() * 2;
result += a;
result *= 2;
```

2. **Const-Correctness Test**

```cpp
void processVector(const Vector2& v) {
    float len = v.length();  // OK: const method
    // v.normalize();  // ERROR: non-const method on const object
}
```

3. **RAII Resource Management**

```cpp
void test_raii() {
    Arena* arena = arena_create(1024 * 1024);
    {
        ScopedArena scope1(arena);
        float* data1 = (float*)scope1.alloc(1000 * sizeof(float));
    }  // scope1 freed here automatically
    arena_destroy(arena);
}
```

**Success Criteria:**

- [ ] All C functionality preserved
- [ ] Operators work naturally
- [ ] Const-correctness enforced
- [ ] RAII prevents resource leaks
- [ ] Performance matches C in Release mode

---

### Weeks 23-24: Modern C++ Features

**Read:** Tour of C++ Chapters 7-12, Effective Modern C++ Items 1-14  
**Focus:** Move semantics, smart pointers, templates, auto, lambdas

#### Project 4B: Modern C++ Allocator Library

**UNCHANGED** - Excellent for modern C++ features.

Refactor allocators with modern C++ features.

##### 1. Template-Based Allocator Interface

```cpp
class IAllocator {
public:
    virtual ~IAllocator() = default;

    virtual void* allocate(size_t size, size_t alignment) = 0;
    virtual void deallocate(void* ptr) = 0;

    // Typed allocation with perfect forwarding
    template<typename T, typename... Args>
    T* construct(Args&&... args) {
        void* mem = allocate(sizeof(T), alignof(T));
        return new (mem) T(std::forward<Args>(args)...);
    }

    template<typename T>
    void destroy(T* ptr) {
        if (ptr) {
            ptr->~T();
            deallocate(ptr);
        }
    }
};
```

##### 2. RAII Smart Pointer Wrapper

```cpp
template<typename T>
class UniquePoolPtr {
private:
    T* m_ptr;
    PoolAllocator* m_pool;

public:
    UniquePoolPtr(T* ptr, PoolAllocator* pool)
        : m_ptr(ptr), m_pool(pool) {}

    ~UniquePoolPtr() {
        if (m_ptr && m_pool) {
            m_ptr->~T();
            m_pool->deallocate(m_ptr);
        }
    }

    // No copy, allow move
    UniquePoolPtr(const UniquePoolPtr&) = delete;
    UniquePoolPtr& operator=(const UniquePoolPtr&) = delete;

    UniquePoolPtr(UniquePoolPtr&& other) noexcept
        : m_ptr(other.m_ptr)
        , m_pool(other.m_pool)
    {
        other.m_ptr = nullptr;
        other.m_pool = nullptr;
    }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    explicit operator bool() const { return m_ptr != nullptr; }
};

// Factory function
template<typename T, typename... Args>
UniquePoolPtr<T> makePoolUnique(PoolAllocator& pool, Args&&... args) {
    T* ptr = pool.construct<T>(std::forward<Args>(args)...);
    return UniquePoolPtr<T>(ptr, &pool);
}
```

##### 3. Lambda Usage Examples

```cpp
template<typename T, typename Predicate>
void filterVector(Vector<T>& vec, Predicate pred) {
    size_t writeIndex = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (pred(vec[i])) {
            if (writeIndex != i) {
                vec[writeIndex] = std::move(vec[i]);
            }
            ++writeIndex;
        }
    }
    while (vec.size() > writeIndex) {
        vec.pop_back();
    }
}

// Usage:
Vector<int> numbers;
int threshold = 50;
filterVector(numbers, [threshold](int x) {
    return x >= threshold;
});
```

**Test Scenarios:**

1. **Move Semantics Performance**

```cpp
struct LargeObject {
    std::array<float, 1000> data;

    LargeObject(const LargeObject& other) {
        std::cout << "Expensive copy\n";
        data = other.data;
    }

    LargeObject(LargeObject&& other) noexcept {
        std::cout << "Cheap move\n";
        data = std::move(other.data);
    }
};

Vector<LargeObject> objects;
objects.push_back(LargeObject());  // Should use move!
```

2. **Perfect Forwarding**

```cpp
struct Entity {
    std::string name;
    int id;

    Entity(const std::string& n, int i) : name(n), id(i) {
        std::cout << "Constructed: " << name << "\n";
    }
};

// Construct in-place with perfect forwarding
Entity* e = allocator.construct<Entity>("Player", 1);
// No temporaries created!
```

**Success Criteria:**

- [ ] Move semantics prevent unnecessary copies
- [ ] Perfect forwarding constructs in-place
- [ ] RAII wrappers prevent leaks
- [ ] Performance matches C in Release

---

### Weeks 25-26: Templates & Generic Programming

**Read:** Tour of C++ Chapters 13-15, Effective Modern C++ Items 15-42  
**Focus:** Template metaprogramming, SFINAE, STL understanding

#### Project 4C: Template-Based Data Structure Library

**UNCHANGED** - Comprehensive template programming project.

Create fully generic, type-safe data structures.

##### 1. Type Traits and SFINAE

```cpp
// Enable function only for trivially copyable types
template<typename T>
typename std::enable_if<std::is_trivially_copyable<T>::value, void>::type
fastCopy(T* dest, const T* src, size_t count) {
    std::memcpy(dest, src, count * sizeof(T));
}

template<typename T>
typename std::enable_if<!std::is_trivially_copyable<T>::value, void>::type
fastCopy(T* dest, const T* src, size_t count) {
    for (size_t i = 0; i < count; ++i) {
        new (&dest[i]) T(src[i]);
    }
}
```

##### 2. Template Dynamic Array

```cpp
template<typename T, typename Allocator = ArenaAllocator>
class DynamicArray {
private:
    T* m_data;
    size_t m_size;
    size_t m_capacity;
    Allocator* m_allocator;

public:
    using value_type = T;
    using iterator = T*;

    explicit DynamicArray(Allocator* allocator, size_t capacity = 16);
    ~DynamicArray();

    // Perfect forwarding
    template<typename... Args>
    void emplace_back(Args&&... args) {
        if (m_size >= m_capacity) {
            reserve(m_capacity * 2);
        }
        new (&m_data[m_size]) T(std::forward<Args>(args)...);
        ++m_size;
    }

    iterator begin() { return m_data; }
    iterator end() { return m_data + m_size; }
};
```

##### 3. Custom Hash Map

```cpp
template<typename Key, typename Value,
         typename Hash = std::hash<Key>,
         typename KeyEqual = std::equal_to<Key>>
class HashMap {
private:
    struct Entry {
        Key key;
        Value value;
        bool occupied;
    };

    Entry* m_entries;
    size_t m_capacity;
    size_t m_size;
    Hash m_hasher;

public:
    void insert(const Key& key, const Value& value);
    Value* find(const Key& key);
    bool contains(const Key& key) const;
};
```

**Test Scenarios:**

1. **Type Trait Optimization**

```cpp
struct TrivialStruct { int x, y, z; };
struct NonTrivialStruct { std::string name; };

// Trivial should use memcpy (10-100x faster)
// Non-trivial uses move construction
```

2. **STL Compatibility**

```cpp
DynamicArray<int> numbers;
for (int i = 0; i < 100; ++i) {
    numbers.push_back(i);
}

// Works with STL algorithms
std::sort(numbers.begin(), numbers.end());
auto it = std::find(numbers.begin(), numbers.end(), 50);
```

**Success Criteria:**

- [ ] Template containers work with any type
- [ ] SFINAE optimization for trivial types
- [ ] Full STL algorithm compatibility
- [ ] Zero runtime overhead vs hand-written code

---

### Phase 4 Checkpoint:

- [ ] Do you understand RAII and move semantics?
- [ ] Can you write template functions and classes?
- [ ] Are you comfortable with modern C++ idioms?

---

## Phase 5: Graphics Foundation (Weeks 27-36)

### Primary Resources

- Learn OpenGL (learnopengl.com) - Core sections
- OpenGL Programming Guide (Red Book) - Reference
- Real-Time Rendering, 4th Edition - Theory

### Learning Objectives

- Understand graphics pipeline
- Master OpenGL API
- Implement 2D sprite rendering
- Handle textures, shaders, and batching

---

### Weeks 27-28: OpenGL Setup & Fundamentals

**Read:** Learn OpenGL: Getting Started, Shaders, Textures  
**Focus:** Window creation, OpenGL context, triangle rendering

#### Project 5A: OpenGL Renderer Foundation

Create a basic OpenGL renderer with window management.

##### 1. Window and Context Setup

```cpp
class Window {
private:
    GLFWwindow* m_window;
    int m_width, m_height;

public:
    Window(int width, int height, const char* title);
    ~Window();

    bool shouldClose() const;
    void swapBuffers();
    void pollEvents();

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
};
```

##### 2. Shader System

```cpp
class Shader {
private:
    GLuint m_programID;

public:
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void use() const;

    // Uniform setters
    void setInt(const char* name, int value);
    void setFloat(const char* name, float value);
    void setVec2(const char* name, const Vector2& value);
    void setVec3(const char* name, const Vector3& value);
    void setVec4(const char* name, const Vector4& value);
    void setMat4(const char* name, const Matrix4& value);
};
```

##### 3. Basic Rendering

```cpp
class Renderer {
private:
    GLuint m_VAO, m_VBO, m_EBO;
    Shader* m_shader;

public:
    Renderer();
    ~Renderer();

    void clear(float r, float g, float b, float a);
    void drawTriangle(Vector2 p1, Vector2 p2, Vector2 p3, Vector3 color);
    void drawQuad(Vector2 position, Vector2 size, Vector3 color);
};
```

**Test Scenarios:**

1. Open window and clear to blue
2. Render colored triangle
3. Render rotating quad
4. Multiple quads with different colors

**Success Criteria:**

- [ ] Window opens at specified resolution
- [ ] Triangle renders correctly
- [ ] Shader compilation errors handled
- [ ] Clean OpenGL resource cleanup

---

### Weeks 29-30: Textures & Sprite Rendering

**Read:** Learn OpenGL: Textures, Transformations  
**Focus:** Texture loading, UV coordinates, sprite rendering

#### Project 5B: 2D Sprite Renderer

##### 1. Texture System

```cpp
class Texture {
private:
    GLuint m_textureID;
    int m_width, m_height;
    int m_channels;

public:
    Texture(const char* path);
    ~Texture();

    void bind(int slot = 0) const;
    void unbind() const;

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
};
```

##### 2. Sprite Structure

```cpp
struct Sprite {
    Texture* texture;
    Vector2 position;
    Vector2 size;
    float rotation;
    Vector4 color;  // Tint color

    // UV coordinates (for texture atlas)
    Vector2 uvMin = {0, 0};
    Vector2 uvMax = {1, 1};
};
```

##### 3. Sprite Renderer

```cpp
class SpriteRenderer {
private:
    Shader* m_shader;
    GLuint m_VAO, m_VBO;
    Matrix4 m_projection;

public:
    SpriteRenderer(int screenWidth, int screenHeight);
    ~SpriteRenderer();

    void drawSprite(const Sprite& sprite);
    void setProjection(const Matrix4& projection);
};
```

**Test Scenarios:**

1. Load and render single sprite
2. Render 100 sprites at different positions
3. Rotate and scale sprites
4. Apply color tint to sprites

**Success Criteria:**

- [ ] Textures load correctly (PNG support)
- [ ] Sprites render at correct positions
- [ ] Rotation works properly
- [ ] Color tinting functional

---

### Weeks 31-32: Batch Rendering & Performance

**Read:** Learn OpenGL: Advanced topics, Real-Time Rendering Ch 5  
**Focus:** Batching, instancing, performance optimization

#### Project 5C: Optimized Batch Renderer

##### 1. Batch Renderer Architecture

```cpp
struct Vertex {
    Vector2 position;
    Vector2 texCoords;
    Vector4 color;
    float texIndex;  // Texture slot
};

class BatchRenderer {
private:
    static const int MAX_SPRITES = 10000;
    static const int MAX_TEXTURES = 32;

    Vertex* m_vertexBuffer;
    Vertex* m_vertexPtr;

    Texture* m_textures[MAX_TEXTURES];
    int m_textureSlotIndex = 1;  // 0 = white texture

    GLuint m_VAO, m_VBO, m_EBO;
    Shader* m_shader;

    int m_spriteCount = 0;

public:
    BatchRenderer();
    ~BatchRenderer();

    void begin();
    void submit(const Sprite& sprite);
    void end();
    void flush();
};
```

##### 2. Statistics Tracking

```cpp
struct RenderStats {
    int drawCalls;
    int spriteCount;
    int vertexCount;
    float frameTime;

    void reset();
    void print() const;
};
```

**Test Scenarios:**

1. Render 10,000 sprites in one draw call
2. Compare: individual draws vs batched
3. Render sprites with multiple textures
4. Measure draw calls and performance

**Success Criteria:**

- [ ] 10,000 sprites render in < 5 draw calls
- [ ] 60 FPS maintained with 10,000+ sprites
- [ ] Correct sprite ordering (z-depth)
- [ ] Multiple textures supported

---

### Weeks 33-34: Camera & Viewport

**Read:** FGED Volume 1 Ch 4 (View transformations)  
**Focus:** 2D camera, viewport, world-to-screen

#### Project 5D: 2D Camera System

##### 1. Camera Implementation

```cpp
class Camera2D {
private:
    Vector2 m_position;
    float m_zoom;
    float m_rotation;

    int m_viewportWidth;
    int m_viewportHeight;

    Matrix4 m_viewMatrix;
    Matrix4 m_projectionMatrix;
    Matrix4 m_viewProjectionMatrix;

    bool m_needsUpdate;

public:
    Camera2D(int viewportWidth, int viewportHeight);

    void setPosition(const Vector2& position);
    void move(const Vector2& delta);
    void setZoom(float zoom);
    void setRotation(float rotation);

    const Matrix4& getViewProjectionMatrix();
    Vector2 screenToWorld(const Vector2& screenPos);
    Vector2 worldToScreen(const Vector2& worldPos);

private:
    void updateMatrices();
};
```

##### 2. Camera Controller

```cpp
class CameraController {
private:
    Camera2D* m_camera;
    float m_moveSpeed = 200.0f;
    float m_zoomSpeed = 0.1f;

public:
    CameraController(Camera2D* camera);

    void update(float dt);
    void handleInput(/* input system */);
};
```

**Test Scenarios:**

1. Pan camera with arrow keys
2. Zoom in/out with mouse wheel
3. Click sprite to select (screen-to-world)
4. Camera follows player smoothly

**Success Criteria:**

- [ ] Camera movement smooth
- [ ] Zoom maintains center point
- [ ] Screen-to-world conversions accurate
- [ ] Camera bounds enforced

---

### Weeks 35-36: Text Rendering & UI Basics

**Read:** Learn OpenGL: Text Rendering  
**Focus:** Font rendering, bitmap fonts, basic UI

#### Project 5E: Text Rendering System

##### 1. Bitmap Font Loader

```cpp
struct Glyph {
    Vector2 position;     // Position in atlas
    Vector2 size;         // Size in atlas
    Vector2 offset;       // Render offset
    float advance;        // Horizontal advance
};

class Font {
private:
    Texture* m_atlas;
    Glyph m_glyphs[128];  // ASCII characters
    float m_size;

public:
    Font(const char* path, float size);
    ~Font();

    const Glyph& getGlyph(char c) const;
    float getStringWidth(const char* text) const;
    Texture* getAtlas() const { return m_atlas; }
};
```

##### 2. Text Renderer

```cpp
class TextRenderer {
private:
    BatchRenderer* m_batchRenderer;

public:
    TextRenderer(BatchRenderer* batchRenderer);

    void drawText(Font* font, const char* text,
                  Vector2 position, float scale, Vector4 color);
    void drawTextCentered(Font* font, const char* text,
                         Vector2 position, float scale, Vector4 color);
};
```

##### 3. Simple UI Elements

```cpp
struct Button {
    Vector2 position;
    Vector2 size;
    const char* text;
    Vector4 color;
    bool hovered;
    bool pressed;

    bool contains(Vector2 point) const;
    void update(Vector2 mousePos, bool mouseDown);
    void render(SpriteRenderer* renderer, TextRenderer* textRenderer);
};
```

**Test Scenarios:**

1. Render "Hello World" at 24pt
2. Display FPS counter
3. Create button that responds to clicks
4. Multi-line text rendering

**Success Criteria:**

- [ ] Text renders clearly
- [ ] Multiple font sizes supported
- [ ] Buttons respond to mouse
- [ ] Text alignment (left, center, right)

---

### Phase 5 Checkpoint:

- [ ] Can you render 10,000+ sprites at 60 FPS?
- [ ] Do you understand the graphics pipeline?
- [ ] Can you implement efficient batching?

---

## Phase 6: 2D Game Engine Architecture (Weeks 37-42)

[Content from original, appears well-structured]

---

## Phase 7: First Complete 2D Game (Weeks 43-52)

[Content from original, appears well-structured]

---

## Key Changes Summary

### Week 1-2 Changes:

- **Removed:** File I/O operations (wc_custom, file_copy, grep_lite, str_reverse)
- **Added:** Calculator, array statistics, string operations, prime checking
- **Reason:** K&R Chapters 1-4 don't cover file I/O

### Week 3-4 Changes:

- **Removed:** Binary file format save/load operations
- **Modified:** RLE compression to work in-memory only
- **Modified:** Image structure to be in-memory only (no file I/O)
- **Added:** Structure padding/alignment demonstration
- **Reason:** File I/O still not covered at this point

### Week 7-8 Changes:

- **Moved:** Original Week 1-2 file utilities to here (Part 1)
- **Added:** Hex dump utility (uses file I/O)
- **Kept:** Build system project (Part 2)
- **Reason:** K&R Chapter 7 now covered, file I/O appropriate

### Weeks 15-16 Changes:

- **Added:** Console-based visualization functions
- **Reason:** Makes math library more interactive without requiring graphics

### All Other Projects:

- **Status:** UNCHANGED - properly scoped to their chapter content

---

## Success Metrics

By the end of this revised roadmap, you will have:

- [ ] Built 20+ substantial projects from scratch
- [ ] Complete understanding of memory management
- [ ] Mastery of both C and C++
- [ ] Strong mathematical foundation
- [ ] Graphics programming expertise
- [ ] Complete 2D game engine
- [ ] Shippable 2D game

**Most importantly:** Every project aligns with the reading material, ensuring you have the knowledge needed before attempting each challenge.
