## JSF Compliant Linear Algebra Engine
## Features
### Core Matrix & Vector Mathematics
* **N-Dimensional Vector Spaces:** Full implementation of multi-dimensional vector operations, including Euclidean norms, dot products, cross products, and vector projections.
* **Comprehensive Matrix Algebra:** Complete support for basic arithmetic (addition, subtraction, scalar multiplication) and advanced matrix operations (matrix-matrix multiplication, transposition, determinants, matrix inversion, and trace evaluation).
* **Structured Matrix Types:** Optimized storage and algorithms for specialized matrix representations, including dense, sparse, symmetric, band, tridiagonal, and identity structures.

### Numerical Methods & Factorizations
* **Systems of Linear Equations:** Direct and iterative solvers for linear systems $Ax = b$, optimized for computational efficiency and error propagation mitigation.
* **Matrix Reduction:** Stable Gaussian Elimination with partial and complete pivoting mechanisms to prevent catastrophic cancellation and numerical instability.
* **Matrix Factorizations:** Advanced matrix decompositions for structural analysis and efficient backend calculation:
    * **LU Decomposition:** (with pivoting, $PA = LU$) for fast subsequent solves.
    * **QR Factorization:** via Householder reflections or Gram-Schmidt orthonormalization for least-squares approximations.
    * **Cholesky Decomposition:** for symmetric positive-definite systems.

## Project Structure
```text
linear-algebra-engine/
├── .github/                     # CI/CD pipelines and compilation workflows
├── build/                       # Compiled binaries, static archives, and object targets
├── docs/                        # API specifications, mathematical proofs, and JSF matrices
├── include/                     # Public API headers (.hpp / .h)
│   ├── core/                    # Fundamental vector and matrix definitions
│   │   ├── matrix.hpp           # Matrix class template and structural definition
│   │   └── vector.hpp           # N-dimensional vector template and inline arithmetic
│   ├── memory/                  # Safety-critical allocation layer
│   │   ├── arena_allocator.hpp  # Monolithic bump allocator implementation
│   │   └── memory_block.hpp     # Statically sized arena block templates
│   ├── methods/                 # Numerical solver implementations
│   │   ├── decomposition.hpp    # LU, QR, and Cholesky factorization interfaces
│   │   ├── elimination.hpp      # Gaussian elimination and pivoting logic
│   │   └── solvers.hpp          # Direct and iterative system solvers (Ax = b)
│   └── structures/              # Specialized matrix structural layouts
│       ├── sparse_matrix.hpp    # Compressed Sparse Row (CSR) implementation
│       └── tridiagonal.hpp      # Highly optimized tridiagonal matrix storage
├── src/                         # Source implementation files (.cpp / .c)
│   ├── core/
│   │   ├── matrix.cpp
│   │   └── vector.cpp
│   ├── memory/
│   │   └── arena_allocator.cpp
│   └── methods/
│       ├── decomposition.cpp
│       ├── elimination.cpp
│       └── solvers.cpp
├── demos/                       # Reference implementations and modeling sandboxes
│   ├── ode_solver/
│   │   ├── main.cpp             # Main executable for RK4 mass-spring system
│   │   └── state_space.cpp      # Linear state-space vector differential maps
│   └── pde_heat_diffusion/
│       └── heat_solver.cpp      # Finite difference matrix mesh simulation
├── tests/                       # Unit testing suite and validation frameworks
│   ├── test_matrix_ops.cpp      # Validation profiles for algebraic compliance
│   ├── test_solvers.cpp         # Accuracy verification against ill-conditioned systems
│   └── test_memory.cpp          # Boundary testing for bump allocator allocations
├── CMakeLists.txt               # Main project build orchestration script
├── LICENSE                      # Licensing documentation
└── README.md                    # Project documentation overview
